module top ( 
    input a, b, c, d, e,
    output [24:0] out
);

  wire [4:0] abcde;
  assign abcde = {a,b,c,d,e};

  assign out[ 4: 0] = ~ ( {5{e}} ^ abcde ); 
  assign out[ 9: 5] = ~ ( {5{d}} ^ abcde ); 
  assign out[14:10] = ~ ( {5{c}} ^ abcde ); 
  assign out[19:15] = ~ ( {5{b}} ^ abcde ); 
  assign out[24:20] = ~ ( {5{a}} ^ abcde ); 

endmodule
