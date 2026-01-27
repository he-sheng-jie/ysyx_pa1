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
  output [31:0] debug_rf [0:32]  //这个是用于暴露寄存器和PC
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
  .is_ebreak  (is_ebreak)
);




always @(posedge clk or posedge rst) begin
  if(rst) begin
    pc <= 32'h80000000;
  end
  else begin
    pc <= pc_next;
    break_test(is_ebreak);
  end
end



always @(posedge clk) begin
  if(reg_to_mem)
    pmem_write(reg_to_mem_addr,reg_to_mem_data,wmask);
end

endmodule


