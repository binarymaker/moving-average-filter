# Moving-average-filter
Average filter based on FIFO buffer
##Library files [link](https://github.com/binarymaker/Moving-average-filter/tree/master/sw-moving-average/User-Library/moving-average-library)
 
# Concept block 

                             input
                               +
                               |
                               v
            +------------------+--------------------+
  index +-->+                 DEMUX                 |
            +----+------+------+----------------+---+
                 |      |      |                |
              +--+-+ +--+-+ +--+-+           +--+-+
              | B0 | | B1 | | B3 | . . . . . | Bn |   <- buffer
              +-+--+ +-+--+ +-+--+           +-+--+      n is size-1
                |      |      |                |         
            +---+------+------+----------------+----+
            |              ACCUMULATOR              |
            +------------------+--------------------+
                               | <---------------------- sum
                               v
                      +--------+--------+
                      | divided by fill | 
                      +--------+--------+
                               |
                               v
                            filtered
                             result
                             

 
 
