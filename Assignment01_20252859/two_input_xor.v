module two_input_xor(
input a,
input b,
output reg a_xor_b);
always @ (*) begin
a_xor_b = a ^ b;
end
endmodule