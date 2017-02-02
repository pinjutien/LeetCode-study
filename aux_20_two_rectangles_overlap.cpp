// check if two rectangle overlap
// http://www.geeksforgeeks.org/find-two-rectangles-overlap/

#include <stdio.h>
#include <stdlib.h>

struct point {
  int x;
  int y;
};


bool overlap(point l1, point r1, point l2, point r2) {

  // l1, r1 : 1st rectangle
  // l2, r2 : 2nd rectangle


  // either 1st rectangle is in the left/right-hand side of 2nd rectangle
  if ((r1.x < l2.x) | (l1.x > r2.x)) {
    return false;
  }

  // either 1st rectangle is in the upper/down side of 2nd rectangle  
  if ((r1.y > l2.y) | (l1.y < r2.y)) {
    return false;
  }
  
  return true;
}

