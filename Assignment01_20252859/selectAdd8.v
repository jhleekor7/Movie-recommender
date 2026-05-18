module selectAdd8(
input [7:0] a,
input [7:0] b,
input cin,
output [7:0] sum,
output cout
);

wire [3:0] sum_low, sum_high0, sum_high1;
wire c_low, c_high0, c_high1;

// 하위 4bit
add4 adder_low(
.a(a[3:0]),
.b(b[3:0]),
.cin(cin),
.sum(sum_low),
.cout(c_low)
);

// 상위 4bit (carry=0)
add4 adder_high0(
.a(a[7:4]),
.b(b[7:4]),
.cin(1'b0),
.sum(sum_high0),
.cout(c_high0)
);

// 상위 4bit (carry=1)
add4 adder_high1(
.a(a[7:4]),
.b(b[7:4]),
.cin(1'b1),
.sum(sum_high1),
.cout(c_high1)
);

// 선택
assign sum[3:0] = sum_low;
assign sum[7:4] = (c_low) ? sum_high1 : sum_high0;
assign cout = (c_low) ? c_high1 : c_high0;

endmodule