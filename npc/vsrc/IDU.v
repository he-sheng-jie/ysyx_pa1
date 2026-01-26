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

