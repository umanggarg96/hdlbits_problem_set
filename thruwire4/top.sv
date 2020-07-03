module top ( 
  input wire a,b,c,
  output wire w,x,y,z
);

  assign {w,x,y,z} = {a,b,b,c};

endmodule
