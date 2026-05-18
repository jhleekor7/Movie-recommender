module divisible_6(
input [3:0] a,
output out
);

wire d2, d3;

divisible_2 u1(.a(a), .out(d2));
divisible_3 u2(.a(a), .out(d3));

assign out = d2 & d3;

endmodule