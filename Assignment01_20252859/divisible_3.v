module divisible_3(
input [3:0] a,
output out
);

assign out = (a % 3 == 0);

endmodule