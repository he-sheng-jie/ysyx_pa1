module CSR_ALU (
    input  [31:0] data1,   // 当前 CSR 的值（从寄存器读出）
    input  [31:0] data2,   // 源操作数（来自 rs1 或立即数）
    input  [1:0]  funct,    // funct3[1:0]: 01=CSRRW, 10=CSRRS, 11=CSRRC
    output [31:0] csrdata
);
    assign csrdata = 
        (funct == 2'b01) ? data2            :  // CSRRW: 直接写入 data2
        (funct == 2'b10) ? (data1 | data2)  :  // CSRRS: set bits
        (funct == 2'b11) ? (data1 & ~data2) :  // CSRRC: clear bits
                          data1;               // default: 保持原值（安全兜底）
endmodule