import "DPI-C" function int pmem_read(input int raddr,input byte rmask);
import "DPI-C" function void pmem_write(
  input int waddr, input int wdata, input byte wmask);
import "DPI-C" function void break_test(input logic is_ebreak);
import "DPI-C" function void inst_get(input int inst);
module top(
  input clk,
  input [31:0] inst,
  input rst, 
  output reg [31:0] pc,
  output [31:0] pc_before,
  output [4:0] num, 
  output [31:0] debug_rf [0:32],  //这个是用于暴露寄存器和PC
  output [31:0] my_mtvec,
  output [31:0] my_mepc,
  output [31:0] my_mcause,
  output [31:0] my_mstatus
);

  assign debug_rf[32] = pc;

  reg [31:0] pc_before_reg;//这个是用于保存上一条指令对应的pc
  always @(posedge clk or posedge rst) begin
  if (rst)
    pc_before_reg <= 32'h00000000;
  else
    pc_before_reg <= pc;  
  end

  assign pc_before = pc_before_reg;


  wire [4:0] rd;
  wire [4:0] rs1;
  wire [4:0] rs2;
  wire [31:0] imm_i;
  wire [31:0] imm_u;
  wire [31:0] imm_s;
  wire [31:0] imm_b;
  wire [31:0] imm_j;
  wire [6:0] opcode;
  wire [2:0] funct3;
  wire [6:0] funct7;

IDU my_IDU(
  .inst  (inst),
  .rd  (rd),
  .rs1  (rs1),
  .rs2  (rs2),
  .imm_i  (imm_i),
  .imm_s  (imm_s),
  .imm_u  (imm_u),
  .imm_j  (imm_j),
  .imm_b  (imm_b),
  .opcode  (opcode),
  .funct3  (funct3),
  .funct7  (funct7)
);


  wire wen;
  reg [31:0] wdata;
  wire [31:0] rdata1; 
  wire [31:0] rdata2;

RegisterFile GPR (
  .clk   (clk),
  .wdata (wdata),
  .waddr (rd),
  .wen   (wen),
  .raddr1 (rs1),
  .raddr2 (rs2),
  .rdata1 (rdata1),
  .rdata2 (rdata2),
  .debug_rf(debug_rf[0:31])
);



wire mem_to_reg;
wire reg [7:0] mem_to_reg_mask;

//i指令接口
wire [31:0] mem_to_reg_addr = rdata1 + imm_i;
wire [31:0] mem_read_data = mem_to_reg ? pmem_read(mem_to_reg_addr,mem_to_reg_mask) : 32'h0;

wire [31:0] pc_next;

wire reg_to_mem;
wire reg [7:0] wmask;
wire [31:0] reg_to_mem_addr;
wire [31:0] reg_to_mem_data;
    
reg is_ebreak;
CU my_CU(
  .inst  (inst),
  .pc  (pc),
  .rdata1  (rdata1),
  .rdata2  (rdata2),
  .pc_next  (pc_next),
  .imm_i  (imm_i),
  .imm_s  (imm_s),
  .imm_u  (imm_u),
  .imm_j  (imm_j),
  .imm_b  (imm_b),
  .opcode  (opcode),
  .funct3  (funct3),
  .funct7  (funct7),
  .mem_read_data  (mem_read_data),
  .wen  (wen),
  .wdata  (wdata),
  .reg_to_mem  (reg_to_mem),
  .wmask  (wmask),
  .reg_to_mem_addr  (reg_to_mem_addr),
  .reg_to_mem_data  (reg_to_mem_data),
  .mem_to_reg  (mem_to_reg),
  .mem_to_reg_mask  (mem_to_reg_mask),

  .csr_to_reg_en(csr_w_en),
  .csr_to_reg_data(csr_tmpdata),
  .is_ebreak  (is_ebreak)
);


reg [31:0] mcycle;
reg [31:0] mcycleh;
reg [31:0] mvendorid;
reg [31:0] marchid;
reg [31:0] mstatus;
reg [31:0] mepc;
reg [31:0] mcause;
reg [31:0] mtvec;

assign my_mepc = mepc;
assign my_mstatus = mstatus;
assign my_mcause = mcause;
assign my_mtvec = mtvec;

wire csr_w_en;
assign csr_w_en = (opcode == 7'b1110011) && (funct3 != 3'b0);

wire is_ecall = (inst == 32'h00000073);
wire is_mret = (inst == 32'h30200073);

wire [31:0]csr_no;
assign csr_no = imm_i;

wire [31:0]csr_cdata;
assign csr_cdata = (funct3[2]) ? {27'h0,inst[19:15]}:rdata1;
wire [31:0]csr_wdata;
reg [31:0]csr_tmpdata;
always @(*) begin
    case (csr_no)
        32'h300: csr_tmpdata = mstatus;   
        32'h305: csr_tmpdata = mtvec;    
        32'h341: csr_tmpdata = mepc;     
        32'h342: csr_tmpdata = mcause;    
        32'hF11: csr_tmpdata = mvendorid;      
        32'hF12: csr_tmpdata = marchid;     
        32'hB00: csr_tmpdata = mcycle;     
        32'hB80: csr_tmpdata = mcycleh; 
        default: csr_tmpdata = 32'h0;     
    endcase
end

CSR_ALU my_CSR_ALU(
  .data1(csr_tmpdata),
  .data2(csr_cdata),
  .funct(funct3[1:0]),
  .csrdata(csr_wdata)
);

reg mcycle_write_en;
reg mcycleh_write_en;

assign mcycle_write_en  = csr_w_en && (csr_no == 32'hB00);
assign mcycleh_write_en = csr_w_en && (csr_no == 32'hB80);


always @(posedge clk or posedge rst) begin
  if(rst) begin
    pc <= 32'h80000000;
    mcycle <= 32'h0;
    mcycleh <= 32'h0;
    mvendorid <= 32'h79737978;
    marchid <= 32'h18ce196;
    mstatus <= 32'h0;
    mepc <= 32'h0;
    mcause <= 32'h0;
    mtvec <= 32'h0;
  end
  else begin
    if(is_mret) begin
      pc <= mepc;
      mcause <= mcause;
      mepc <= mepc;
      mstatus <= mstatus;
    end
    else if(is_ecall) begin
      pc <= mtvec;
      mcause <= 32'hb;
      mepc <= pc;
      mstatus <= 32'h1800;
    end
    else begin
      pc <= pc_next;
      mepc    <= (csr_w_en && (csr_no == 32'h341)) ? csr_wdata : mepc;
      mcause  <= (csr_w_en && (csr_no == 32'h342)) ? csr_wdata : mcause;
      mstatus <= (csr_w_en && (csr_no == 32'h300)) ? csr_wdata : mstatus;
    end
        if (mcycle_write_en)
            mcycle <= csr_wdata;
        else
            mcycle <= mcycle + 1;

        if (mcycleh_write_en) begin
            mcycleh <= csr_wdata;
        end else if (!mcycle_write_en && mcycle == 32'hFFFFFFFF) begin
            mcycleh <= mcycleh + 1;
        end
    mtvec   <= (csr_w_en && (csr_no == 32'h305)) ? csr_wdata : mtvec;
    mvendorid <= 32'h79737978;
    marchid <= 32'h18ce196;  
    break_test(is_ebreak);
  end
end



always @(posedge clk) begin
  if(reg_to_mem)
    pmem_write(reg_to_mem_addr,reg_to_mem_data,wmask);
end

endmodule


