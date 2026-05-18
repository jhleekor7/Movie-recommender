`timescale 1ns / 1ps
module tb_half_adder;

reg a, b;
wire sum, carry;

half_adder uut (
.x(a),
.y(b),
.s(sum),
.c(carry)
);

initial begin
$dumpfile("tb_half_adder.vcd");
$dumpvars(0, tb_half_adder);

a = 0; b = 0;
#100;
a = 0; b = 1;
#100;
a = 1; b = 0;
#100;
a = 1; b = 1;
#100;
end

endmodule