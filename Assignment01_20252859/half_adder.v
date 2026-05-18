module half_adder (
input x,
input y,
output s,
output c);
two_input_and and1(x, y, c);
two_input_xor xor1(x, y, s);
endmodule