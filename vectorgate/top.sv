module top ( 
  input  [2:0] a,
  input  [2:0] b,
  output [2:0] out_or_bitwise,
  output       out_or_logical,
  output [5:0] out_not
);
  assign out_or_bitwise = a | b;
  assign out_or_logical = a[0] || a[1] || a[2] || b[0] || b[1] || b[2];
  assign out_not        = ~ {b, a};

endmodule
