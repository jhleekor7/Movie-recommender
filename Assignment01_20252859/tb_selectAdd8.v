`timescale 1ns/1ps

module tb_selectAdd8;

reg [7:0] a, b;
reg cin;
wire [7:0] sum;
wire cout;

// UUT (Unit Under Test)
selectAdd8 uut (
    .a(a),
    .b(b),
    .cin(cin),
    .sum(sum),
    .cout(cout)
);

initial begin
    $dumpfile("tb_selectAdd8.vcd");
    $dumpvars(0, tb_selectAdd8);

    // 테스트 케이스 (실습지 기준)

    // 1
    a = 0;   b = 0;   cin = 0;
    #100;

    // 2
    a = 255; b = 1;   cin = 0;
    #100;

    // 3
    a = 135; b = 45;  cin = 1;
    #100;

    // 4
    a = 7;   b = 47;  cin = 0;
    #100;

    // 5
    a = 7;   b = 28;  cin = 0;
    #100;

    // 6
    a = 120; b = 7;   cin = 0;
    #100;

    $finish;
end

endmodule