module p
(
input a,
input b,
input s,
output o);

assign {o} = (s==0)?a:b;

endmodule

module x;
reg a;
reg b;
reg s;
wire o;

p obj(.a(a),.b(b),.s(s),.o(o));

initial begin 
a=1;b=0;
s=0;
#10 s=1;
end

initial begin

$monitor("s=%1b, outpt=%1b",s,o);

end

endmodule
