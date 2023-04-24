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

  // Demo Stuff
  printf("Supported Commands:\n m(t)_r1_r2 \n r(t)_r1_a \n s(t)_r1_f \n o(t)_r1 \n i(t)_r1 \n j(m)_b \n");
  printf("See comments in main.c for further information");
  printf("Type In Code Please! \n");
  
  char str[1000];

  gets(str); // Bad
  printf("Typed in %s\n", str);
  char* cleaned = clean(str, strlen(str));
  printf("Resulting cleaned command %s. It is %d characters long\n", cleaned, strlen(cleaned));
  CharStack *stream = initStream(cleaned, strlen(cleaned));
  printf("Tokenizing....\n");
  TokenStack* tokens = tokenize(&stream);
  while (!ts_isEmpty(&tokens)) {
    Token* token = ts_pop(&tokens);
    printf(token->type);
    if (token->type == 0) {
      TokenDirect direct = token->value.direct;
      switch(direct.tag) {
      case 'm':
        printf("moving (m) with duration %f from position %d to %d\n", direct.time, direct.a, direct.b);
        break;
      case 'r':
        printf("rotating (r) piece at %d with duration %f by an angle of %d degrees\n", direct.a, direct.time, direct.b);
        break;
      case 's':
        printf("scaling (s) piece at %d with duration %f by a factor of %d\n", direct.a, direct.time, direct.b);
        break;
      case 'o':
        printf("fade out (o) piece at %d with duration %f\n", direct.a, direct.time);
        break;
      case 'i':
        printf("fade in (i) piece with type at %d with duration %f\n", direct.a, direct.time);
        break;
      }
    } else {
      TokenSingle single = token->value.single;
      // Only one case of this
      printf("waiting (w) for duration of %f s\n", single.t);
    }
  }

  // Make a main function. Do like "parse" then do stuff.
  return 0;
}

void testInit() {

}

