module CU(
    input [31:0] inst,
    input [31:0] pc,
    input [31:0] rdata1,
    input [31:0] rdata2,
    input [31:0] imm_i,
    input [31:0] imm_u,
    input [31:0] imm_s,
    input [31:0] imm_b,
    input [31:0] imm_j,
    input [6:0] opcode,
    input [2:0] funct3,
    input [6:0] funct7,
    input [31:0] mem_read_data,
    input  csr_to_reg_en, 
    input  [31:0] csr_to_reg_data,

    output wen,
    output [31:0] wdata,

    output [31:0] pc_next,

    output reg_to_mem,
    output reg [7:0] wmask,
    output [31:0] reg_to_mem_addr,
    output [31:0] reg_to_mem_data,
    
    output mem_to_reg,
    output reg [7:0] mem_to_reg_mask,

    output is_ebreak 
);

// 中间信号声明
wire is_lui, is_auipc, is_jal, is_jalr, is_r, is_i_r, is_b, is_alu;
wire branch_eq;
wire [31:0] alu_num2;

assign is_ebreak = (inst == 32'h00100073);

//实现S类型指令
assign reg_to_mem = (opcode == 7'b0100011);
assign reg_to_mem_addr = imm_s + rdata1;
assign reg_to_mem_data = rdata2;
always @(*) begin
    case(funct3)
    3'b000:
      case (reg_to_mem_addr[1:0])
            2'b00: wmask = 8'h01;
            2'b01: wmask = 8'h02;
            2'b10: wmask = 8'h04;
            2'b11: wmask = 8'h08;                
            default: 
                wmask = 8'h0;
      endcase
    3'b010:
        wmask = 8'hff;
    3'b001:
        case (reg_to_mem_addr[1])
            1'b0: wmask = 8'h03;
            1'b1: wmask = 8'h0c;               
        default: 
          wmask = 8'h0;
      endcase
    default:
        wmask = 8'h0;
    endcase
end


//实现I类型指令
assign mem_to_reg = (opcode == 7'b0000011);
reg [31:0] mem_to_reg_data;
always @(*) begin
    case(funct3)
    3'b000: begin
        mem_to_reg_mask = 8'h1;
        mem_to_reg_data = {{24{mem_read_data[7]}},mem_read_data[7:0]};
        end
    3'b001: begin
        mem_to_reg_mask = 8'h2;
        mem_to_reg_data = {{16{mem_read_data[15]}},mem_read_data[15:0]};
        end
    3'b010: begin
        mem_to_reg_mask = 8'hff;
        mem_to_reg_data = mem_read_data;
        end
    3'b100: begin
        mem_to_reg_mask = 8'h1;
        mem_to_reg_data = {24'h0,mem_read_data[7:0]};
        end
    3'b101: begin
        mem_to_reg_mask = 8'h2;
        mem_to_reg_data = {16'h0,mem_read_data[15:0]};
        end
    default: begin
        mem_to_reg_mask = 8'h00;
        mem_to_reg_data = 32'h0;
        end
    endcase
end


//实现J类型指令
assign is_jal = (opcode == 7'b1101111);


//实现U类型指令
assign  is_lui = (opcode == 7'b0110111);
assign  is_auipc = (opcode == 7'b0010111);


//实现R类型指令
assign  is_r = (opcode == 7'b0110011);


//实现B类型指令
assign  is_b = (opcode == 7'b1100011);
assign  branch_eq  = (rdata1 == rdata2);
wire branch_ne  = (rdata1 != rdata2);
wire branch_lt  = ($signed(rdata1) < $signed(rdata2));
wire branch_ge  = ($signed(rdata1) >= $signed(rdata2));
wire branch_ltu = ($unsigned(rdata1) < $unsigned(rdata2));
wire branch_geu = ($unsigned(rdata1) >= $unsigned(rdata2));

wire branch_taken = is_b && (
    (funct3 == 3'b000 && branch_eq)  || // BEQ
    (funct3 == 3'b001 && branch_ne)  || // BNE
    (funct3 == 3'b100 && branch_lt)  || // BLT
    (funct3 == 3'b101 && branch_ge)  || // BGE
    (funct3 == 3'b110 && branch_ltu) || // BLTU
    (funct3 == 3'b111 && branch_geu)    // BGEU
);


//实现I类型指令
assign  is_i_r = (opcode == 7'b0010011);
assign  is_jalr = (opcode == 7'b1100111) && (funct3 == 3'b0);

assign wen = is_lui || is_auipc || mem_to_reg || 
            is_jal || is_r|| is_i_r || is_jalr || csr_to_reg_en;

assign  is_alu = is_i_r || is_r;

reg [3:0] alu_op;
wire [31:0] alu_result;
//判断运算类型
always @(*) begin
    alu_op = 4'h0; // 默认 ADD
    if (is_r) begin
        case ({funct7[5], funct3})
            {1'b0, 3'b000}: alu_op = 4'h0; // ADD
            {1'b1, 3'b000}: alu_op = 4'h1; // SUB
            {1'b0, 3'b111}: alu_op = 4'h2; // AND
            {1'b0, 3'b110}: alu_op = 4'h3; // OR
            {1'b0, 3'b100}: alu_op = 4'h4; // XOR
            {1'b0, 3'b001}: alu_op = 4'h5; // SLL
            {1'b0, 3'b101}: alu_op = 4'h6; // SRL
            {1'b1, 3'b101}: alu_op = 4'h7; // SRA
            {1'b0, 3'b010}: alu_op = 4'h8; // SLT
            {1'b0, 3'b011}: alu_op = 4'ha; // SLTU
            default: alu_op = 4'h0;
        endcase
    end else if (is_i_r) begin
        case (funct3)
            3'b000: alu_op = 4'h0; // ADDI
            3'b010: alu_op = 4'h8; // SLTI
            3'b011: alu_op = 4'ha; // SLTIU
            3'b111: alu_op = 4'h2; // ANDI
            3'b110: alu_op = 4'h3; // ORI
            3'b100: alu_op = 4'h4; // XORI
            3'b001: alu_op = 4'h5; // SLLI
            3'b101: begin
                if (imm_i[10]) alu_op = 4'h7; // SRAI
                else           alu_op = 4'h6; // SRLI
            end
            default: alu_op = 4'h0;
        endcase
    end
end


assign  alu_num2 = is_i_r ? imm_i : rdata2 ;

ALU my_ALU(
    .alu_op(alu_op),
    .num1(rdata1),
    .num2(alu_num2),
    .alu_result(alu_result)
);

assign pc_next = 
    is_jal  ? (imm_j + pc) :
    is_jalr ? (imm_i + rdata1) & 32'hfffffffe:
    branch_taken ? (imm_b + pc) :
    (pc + 32'h4);


assign wdata = 
    mem_to_reg          ? mem_to_reg_data :
    is_lui              ? imm_u :
    is_auipc            ? (pc + imm_u) :
    is_alu              ? alu_result :
    is_jal || is_jalr   ? (pc + 32'h4) :
    csr_to_reg_en       ? csr_to_reg_data :
                            32'h0;

endmodule