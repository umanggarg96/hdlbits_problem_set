module top ( 
    input a,
    input b,
    input sel_b1,
    input sel_b2,
    output wire out_assign,
    output reg out_always   ); 

  always @*
      if(sel_b2 & sel_b1) 
        out_always = b;
      else
        out_always = a;

  assign out_assign = (sel_b1 & sel_b2) ? b : a;

endmodule
