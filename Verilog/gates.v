module a
(
input a,
input b,
output f
);
assign {f}=a&&b; // !a+b XNOR, & AND, a+b XOR, || OR
endmodule

module x;
reg a1;
reg b1;
wire c1;

a y(.a(a1),.b(b1),.f(c1));

initial begin
a1=0;
b1=0;
$monitor("a=%1b, b=%1b, f= %1b",a1,b1,c1);
#10 b1=1;
$monitor("a=%1b, b=%1b, f= %1b",a1,b1,c1);
#10 a1=1;
$monitor("a=%1b, b=%1b, f= %1b",a1,b1,c1);
#10 b1=0;
$monitor("a=%1b, b=%1b, f= %1b",a1,b1,c1);
end

endmodule



