`timescale 1ns/1ps
module tb_selectAdd8;

reg [7:0] a, b;
reg cin;
wire [7:0] sum;
wire cout;

selectAdd8 uut(a, b, cin, sum, cout);

initial begin
$dumpfile("tb_selectAdd8.vcd");
$dumpvars(0, tb_selectAdd8);

a = 8'd10; b = 8'd5; cin = 0;
#100;

a = 8'd20; b = 8'd15; cin = 1;
#100;

a = 8'd100; b = 8'd50; cin = 0;
#100;

end

endmodule