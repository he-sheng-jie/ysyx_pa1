import "DPI-C" function int pmem_read(input int raddr);
import "DPI-C" function void pmem_write(
  input int waddr, input int wdata, input byte wmask);
import "DPI-C" function void break_test(input logic is_ebreak);
import "DPI-C" function void inst_get(input int inst);
module top(
  input clk,
  input [31:0] inst,
  input rst, 
  output [31:0] pc,
  output [31:0] pc_before,
  output [4:0] num, 
  output [31:0] debug_rf [0:32]
);

  assign debug_rf[32] = pc;

  reg [31:0] pc_before_reg;
  always @(posedge clk or posedge rst) begin
  if (rst)
    pc_before_reg <= 32'h00000000;
  else
    pc_before_reg <= pc;  
  end

  assign pc_before = pc_before_reg;
  reg [31:0] pc_next;
  always @(*) begin
    pc_next = (pc + 4);
  end
 
  reg is_ebreak;
  always @(*) begin
    break_test(is_ebreak);
    inst_get(inst);
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
  .rst  (rst),
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
  .debug_rf (debug_rf[0:31])
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
      default:
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


module WBU #(ADDR_WIDTH = 5, DATA_WIDTH = 32)(
  input clk,
  input rst,
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
  output [DATA_WIDTH-1:0] debug_rf [0 : 2**ADDR_WIDTH-1] 
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
  .debug_rf(debug_rf)
);

always @(posedge clk or posedge rst) begin
  if (rst) begin
    pc <= 32'h80000000;
  end else if (is_jalr_ok) begin
    pc <= (ALU_result & 32'hFFFFFFFC);
  end else begin
    pc <= pc_next;
  end
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
  output [DATA_WIDTH-1:0] debug_rf [0 : 2**ADDR_WIDTH-1] 
);

  reg [DATA_WIDTH-1:0] rf [0:2**ADDR_WIDTH-1];

  initial rf[0] = 0;

  always @(posedge clk) begin
    if (wen) rf[waddr] <= wdata;  
  end

  assign rdata1 = raddr1 == 0 ? 0 : rf[raddr1];
  assign rdata2 = raddr2 == 0 ? 0 : rf[raddr2];
  assign debug_rf = rf;  

endmodule
