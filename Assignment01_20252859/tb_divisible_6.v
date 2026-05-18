`timescale 1ns/1ps

module tb_divisible_6;

reg [3:0] a;
wire out;

divisible_6 uut(.a(a), .out(out));

integer i;

initial begin
    $dumpfile("tb_divisible_6.vcd");
    $dumpvars(0, tb_divisible_6);

    for (i = 0; i < 16; i = i + 1) begin
        a = i;
        #50;
    end

    $finish;
end

endmodule