module two_input_and(
input a,
input b,
output reg a_and_b);
always @ (*) begin
a_and_b = a & b;
end
endmodule