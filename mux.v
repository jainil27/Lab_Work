module p
(
input a,
input b,
input s1,
input s2,
output o);

assign {o} = (s1==0)?(s2==0)?a&&b:a||b:(s2==0)?a+b:(!(a||b));

endmodule

module x;
reg a;
reg b;
reg s1;
reg s2;
wire o;

p obj(.a(a),.b(b),.s1(s1),.s2(s2),.o(o));

initial begin 
a=1;b=0;
s1=0;
s2=0;
#10 s2=1;
#10 s1=1;
#10 s2=0; 	
end

initial begin

$monitor("s1=%1b,s2=%1b, outpt=%1b",s1,s2,o);

end

endmodule
