#include "general.h"
#include "test.h"

int main(int argc, char *argv[]) {
  // Setup test cases
  initialize_tests();

  char example1[] = "m(1.04)_1_2, r(4.04)_1_2, r(2.44)_1_2, r(4.04)_1_2";
  char example2[] = "m(1.04)_1_2";
  char error1[]  = "r(0.34)_2_4, s(1.4)_4, fake";

  // Test Data Structures
  CharStack* stack;
  printf("Testing Pushes \n");
  cs_push(&stack, 'A');
  assertTrue(cs_peek(&stack) == 'A');
  cs_push(&stack, 'B');
  assertTrue(cs_peek(&stack) == 'B');
  assertTrue(cs_len(&stack) == 2);

  printf("Testing Deletes \n");
  cs_delHead(&stack);
  assertTrue(cs_len(&stack) == 1);
  assertTrue(cs_peek(&stack) == 'B');
  assertTrue(cs_pop(&stack) == 'A');

  printf("Sizes \n");
  assertTrue(cs_len(&stack) == 0);

  printf("TEST %i HAS FAILED. EXPECTED CONDITION TO BE FALSE \n", test_id);

  // Test Readers
  

  // Test Lexer  


  // Test Parser


  return 0;
}

void initialize_tests() {
  test_completed = 0;
  test_id = 0;
}

bool assertTrue(bool stuff) {
  if (stuff) {
    test_completed++;
  } else {
    printf("TEST %i HAS FAILED. EXPECTED CONDITION TO BE TRUE \n", test_id);
  }
  test_id++;
}

bool assertFalse(bool stuff) {
  if (!stuff) {
    test_completed++;
  } else {
    printf("TEST %i HAS FAILED. EXPECTED CONDITION TO BE FALSE \n", test_id);
  }
}
