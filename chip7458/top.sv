module top ( 
    input   wire p1a, p1b, p1c, p1d, p1e, p1f,
    output  wire p1y,
    input   wire p2a, p2b, p2c, p2d,
    output  wire p2y
);
  
  assign p1y = ( p1a & p1b & p1c ) |  ( p1d & p1e & p1f);
  assign p2y = ( p2a & p2b ) |  ( p2c & p2d );

endmodule
