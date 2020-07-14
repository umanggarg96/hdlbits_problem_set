module top ( 
  input [4:0] a, b, c, d, e, f, // 5 * 6 = 30 bits
  output [7:0] w, x, y, z // 8 * 4 = 32 bits
);

  assign {w,x,y,z} = {a,b,c,d,e,f,2'b11};

endmodule
