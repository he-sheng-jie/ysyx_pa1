module ALU(
    input [3:0] alu_op,
    input [31:0] num1,
    input [31:0] num2,
    output reg [31:0] alu_result
);
always @(*) begin
    case (alu_op)
        4'h0: alu_result = num1 + num2;                     // ADD
        4'h1: alu_result = num1 - num2;                     // SUB
        4'h2: alu_result = num1 & num2;                     // AND
        4'h3: alu_result = num1 | num2;                     // OR
        4'h4: alu_result = num1 ^ num2;                     // XOR
        4'h5: alu_result = num1 << (num2 & 32'h1F);          // SLL
        4'h6: alu_result = num1 >> (num2 & 32'h1F);          
        4'h7: alu_result = $signed(num1) >>> (num2 & 32'h1F); 
        4'h8: alu_result = ($signed(num1) < $signed(num2)) ? 32'h1 : 32'h0;   
        4'h9: alu_result = ($signed(num1) >= $signed(num2)) ? 32'h1 : 32'h0;   
        4'ha: alu_result = ($unsigned(num1) < $unsigned(num2)) ? 32'h1 : 32'h0; 
        4'hb: alu_result = ($unsigned(num1) >= $unsigned(num2)) ? 32'h1 : 32'h0; 
        4'hc: alu_result = (num1 == num2) ? 32'h1 : 32'h0; 
        4'hd: alu_result = (num1 != num2) ? 32'h1 : 32'h0; 
        4'he: alu_result = num1 * num2; 
        4'hf: alu_result = num1 / num2; 
        default: alu_result = num1 + num2;                   
    endcase
end


endmodule