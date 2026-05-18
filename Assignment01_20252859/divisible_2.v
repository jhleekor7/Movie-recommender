module divisible_2(
input [3:0] a,
output out
);

assign out = (a % 2 == 0);

endmodule