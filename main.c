#include "general.h"

int main(int argc, char *argv[]) {
  /*
  Syntax:

  m(t)_r1_r2 -- move from r1 to r2 (direct)
  r(t)_r1_a –- rotate piece at r1 by angle a (degrees) in t seconds (direct)

  s(t)_r1_f -- scale piece at r1 by f in t seconds (direct)
  o(t)_r1  -- fade out  piece at r1 (direct)
  i(t)_x_r2 -- fade in piece type x at r2 (direct)

  c(n)_t_p1_p2_p3_…_pn -- define a spline with n points that plays out over t seconds

  j(m)_b -- generate random number from [0*m + b,1*m + b]

  -- comment
  () -- group
  [] -- sequential
  , -- separator
  w(t) -- wait for t seconds
  */

  // Make a main function. Do like "parse" then do stuff.
  return 0;
}

void testInit() {

}

