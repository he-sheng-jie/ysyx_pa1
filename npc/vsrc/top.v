import "DPI-C" function int pmem_read(input int raddr);
import "DPI-C" function void pmem_write(
  input int waddr, input int wdata, input byte wmask);
import "DPI-C" function void break_test(input logic is_ebreak);

module top(
  input clk,
  input [31:0] inst,
  output reg [31:0] pc,
  output [31:0] out_pc,
  output [4:0] num, 
  output [31:0] result
);
  //initial pc = 32'h00000000;
  initial pc = 32'h80000000 ;
  assign out_pc = pc - 32'h80000000;
  reg [31:0] pc_next;
  always @(*) begin
    pc_next = (pc + 4) ;
  end
 
  reg is_ebreak;
  always @(*) begin
    break_test(is_ebreak);
  end
  wire wen;
  reg [31:0] wdata;
  wire [4:0] waddr;
  wire [31:0] rdata1;
  wire [4:0] raddr1;  
  wire [31:0] rdata2;
  wire [4:0] raddr2;

  wire [4:0] rd;
  wire [4:0] rs1;
  wire [4:0] rs2;
  wire [31:0] imm_i;
  wire [31:0] imm_u;
  wire [31:0] imm_s;

  wire is_addi_ok;
  wire is_jalr_ok;
  wire is_add_ok;
  wire is_lui;
  wire is_lw;
  wire is_lbu;
  wire is_sw;
  wire is_sb;
  wire is_memtoreg;
  wire [31:0] ALU_result;
assign num = rd;
IDU my_IDU(
  .inst  (inst),
  .rd  (rd),
  .rs1  (rs1),
  .rs2  (rs2),
  .imm_i  (imm_i),
  .imm_s  (imm_s),
  .imm_u  (imm_u),
  .is_addi_ok  (is_addi_ok),
  .is_add_ok  (is_add_ok),
  .is_jalr_ok  (is_jalr_ok),
  .is_lui   (is_lui),
  .is_lw   (is_lw),
  .is_lbu   (is_lbu),
  .is_sw   (is_sw),
  .is_sb   (is_sb),
  .is_ebreak  (is_ebreak),
  .wen  (wen)
);

WBU my_WBU (
  .clk   (clk),
  .pc   (pc),
  .ALU_result  (ALU_result),
  .wdata (wdata),
  .waddr (waddr),
  .wen   (wen),
  .is_jalr_ok  (is_jalr_ok),
  .raddr1 (raddr1),
  .raddr2 (raddr2),
  .rdata1 (rdata1),
  .rdata2 (rdata2),
  .pc_next  (pc_next),
  .result (result)
);


EXU my_EXU(
  // .is_addi_ok  (is_addi_ok),
  .is_add_ok  (is_add_ok),
  // .is_jalr_ok  (is_jalr_ok),
  .is_lui   (is_lui),
  // .is_lw   (is_lw),
  // .is_lbu   (is_lbu),
  .is_sw   (is_sw),
  .is_sb   (is_sb),
  .rdata1 (rdata1),
  .rdata2 (rdata2),
  .imm_i  (imm_i),
  .imm_s  (imm_s),
  .imm_u  (imm_u),
  .ALU_result  (ALU_result)
);



assign waddr = rd;
assign raddr1 = rs1;
assign raddr2 = rs2;
assign is_memtoreg = is_lw || is_lbu;

reg [31:0] pmemdata;
always @(posedge clk) begin
  if(is_memtoreg) 
    pmemdata = pmem_read(ALU_result);
  else
    pmemdata = 32'h0;
end

reg [31:0] memdata;
always @(*) begin
  if(is_lw) 
    memdata = pmemdata;
  else begin
    case(ALU_result[1:0])
      2'b00: memdata = pmemdata & 32'hFF;
      2'b01: memdata = (pmemdata >> 8 )& 32'hFF;
      2'b10: memdata = (pmemdata >> 16)& 32'hFF;
      2'b11: memdata = (pmemdata >> 24)& 32'hFF;
      default 
        memdata = 32'h0;
    endcase
  end
end

always @(*) begin
  if(is_memtoreg) wdata = memdata;
  else if(is_jalr_ok) wdata = pc_next;
  else  wdata = ALU_result;
end


wire writrtomem;
reg [7:0] wmask;
assign writrtomem = is_sb || is_sw;

always @(*) begin
  if(writrtomem) begin
    if(is_sw) wmask = 8'hFF;
    else begin
      case (ALU_result[1:0])
        2'b00: wmask = 8'h01;
        2'b01: wmask = 8'h02;
        2'b10: wmask = 8'h04;
        2'b11: wmask = 8'h08;                
        default: 
          wmask = 8'h0;
      endcase
    end
  end
  else 
    wmask = 8'b0;
end

always @(posedge clk) begin
  if(writrtomem)
    pmem_write(ALU_result,rdata2,wmask);
end

endmodule




module EXU(
  // input is_addi_ok,
  input is_add_ok,
  // input is_jalr_ok,
  input is_lui,
  // input is_lw,
  // input is_lbu,
  input is_sw,
  input is_sb,
  input [31:0] rdata1,
  input [31:0] rdata2,
  input [31:0] imm_i,
  input [31:0] imm_u,
  input [31:0] imm_s,
  output [31:0] ALU_result
);
wire [31:0] num1;

assign num1 = (is_lui == 0) ? rdata1 : 32'h0;
wire [31:0] num2;
reg [31:0] imm_c;

always@(*) begin
  if(is_sw == 1 || is_sb == 1)
    imm_c = imm_s;
  else if(is_lui == 1)
    imm_c = imm_u;
  else
    imm_c = imm_i;
end

assign num2 = (is_add_ok ==0) ? imm_c : rdata2;

assign ALU_result = num1 + num2;

endmodule


module IDU(
    input [31:0] inst,
    output [4:0] rd,
    output [4:0] rs1,
    output [4:0] rs2,
    output [31:0] imm_i,
    output [31:0] imm_u,
    output [31:0] imm_s,
    output is_addi_ok,
    output is_add_ok,
    output is_jalr_ok,
    output is_lui,
    output is_lw,
    output is_lbu,
    output is_sw,
    output is_sb,
    output is_ebreak, 
    output wen
);

    wire [6:0] opcode;
    wire [2:0] funct3;
    wire [6:0] funct7;

    //Decode
    assign opcode = inst[6:0];

    assign rd = inst[11:7];
    assign rs1 = inst[19:15];
    assign rs2 = inst[24:20];

    assign imm_i = { {20{inst[31]}}, inst[31:20]};
    assign imm_s = {{20{inst[31]}},inst[31:25],inst[11:7]};
    assign imm_u = {inst[31:12],12'b0};


    assign funct3 = inst[14:12];
    assign funct7 = inst[31:25];

    wire is_addi;
    wire is_jalr;
    wire is_add;
    wire is_load;
    wire is_store;

    assign is_addi = (opcode == 7'h13);
    assign is_jalr = (opcode == 7'h67);
    assign is_add  = (opcode == 7'h33);
    assign is_lui  = (opcode == 7'h37);
    assign is_load = (opcode == 7'h03);
    assign is_store= (opcode == 7'h23);

    wire f30;
    wire f32;
    wire f34;

    assign f30 = (funct3 == 3'h0);
    assign f32 = (funct3 == 3'h2);
    assign f34 = (funct3 == 3'h4);

    wire f70;
    assign f70 = (funct7 == 7'h0);


    
    assign is_addi_ok = is_addi && f30;
    assign is_add_ok = is_add && f70;
    assign is_jalr_ok = is_jalr && f30;
    assign is_lw = is_load && f32;
    assign is_lbu = is_load && f34;
    assign is_sb = is_store && f30;
    assign is_sw = is_store && f32;

    assign wen = is_addi_ok || is_jalr_ok||is_lui||is_load||is_add_ok;
    assign is_ebreak = (inst == 32'h100073);
  
endmodule


module WBU #(ADDR_WIDTH = 5, DATA_WIDTH = 32)(
  input clk,
  input [DATA_WIDTH-1:0] pc_next,
  input [DATA_WIDTH-1:0] wdata,
  input [DATA_WIDTH-1:0] ALU_result,
  input [ADDR_WIDTH-1:0] waddr,
  input wen,
  input  is_jalr_ok,
  input [ADDR_WIDTH-1:0] raddr1,
  input [ADDR_WIDTH-1:0] raddr2,
  output [DATA_WIDTH-1:0] rdata1,
  output [DATA_WIDTH-1:0] rdata2,
  output reg [DATA_WIDTH-1:0]  pc,
  output [DATA_WIDTH-1:0] result
);


RegisterFile GPR (
  .clk   (clk),
  .wdata (wdata),
  .waddr (waddr),
  .wen   (wen),
  .raddr1 (raddr1),
  .raddr2 (raddr2),
  .rdata1 (rdata1),
  .rdata2 (rdata2),
  .result (result)
);

always @(posedge clk) begin
  if(is_jalr_ok) pc <= (ALU_result & 32'hFFFFFFFC);
  else  pc <= pc_next ;
end

endmodule 




module RegisterFile #(ADDR_WIDTH = 5, DATA_WIDTH = 32) (
  input clk,
  input [DATA_WIDTH-1:0] wdata,
  input [ADDR_WIDTH-1:0] waddr,
  input wen,
  input [ADDR_WIDTH-1:0] raddr1,
  input [ADDR_WIDTH-1:0] raddr2,
  output [DATA_WIDTH-1:0] rdata1,
  output [DATA_WIDTH-1:0] rdata2,
  output [DATA_WIDTH-1:0] result
);

  reg [DATA_WIDTH-1:0] rf [2**ADDR_WIDTH-1:0];

  initial rf[0] = 0;

  always @(posedge clk) begin
    if (wen) rf[waddr] <= wdata;  
  end

  assign rdata1 = raddr1 == 0 ? 0 : rf[raddr1];
  assign rdata2 = raddr2 == 0 ? 0 : rf[raddr2];
  assign result = rf[10];
endmodule
