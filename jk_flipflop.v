module p
(	input j,
	input k,
	input q1,
	output q
);

assign {q} = (j*!(q1)) ||  ((!k)*q1);

endmodule

module x;
reg j;
reg k;
reg q1;
wire q;

p obj (.j(j), .k(k), .q1(q1), .q(q));

initial begin

j=0;
k=0;
q1=0;
#10 k=1;
#10 j=1;
#10 k=0;
#10 q1=1;
#10 k=1;
#10 j=0;
#10 k=0;
#10 j=0;

end

initial begin

$monitor ("j=%1b, k=%1b, q1=%1b, q=%1b", j, k , q1, q);
end
endmodule

