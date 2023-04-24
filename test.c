#include "general.h"
#include "test.h"

int main(int argc, char *argv[]) {
  // Setup test cases
  initialize_tests();

  // char example1[] = "m(1.04)_1_2, r(4.04)_1_2, r(2.44)_1_2, r(4.04)_1_2";
  // char example2[] = "m(1.04)_1_2";
  // char error1[]  = "r(0.34)_2_4, s(1.4)_4, fake";

  // Test Data Structures
  CharStack* stack = cs_init(); 
  cs_push(&stack, 'A');
  assertTrue(cs_peek(&stack) == 'A'); // 1
  cs_push(&stack, 'B');
  assertTrue(cs_peek(&stack) == 'B'); // 2
  assertTrue(cs_len(&stack) == 2); // 3
  cs_push(&stack, 'C');
  assertTrue(cs_peek(&stack) == 'C'); // 4
  assertTrue(cs_len(&stack) == 3); // 5
  cs_delHead(&stack);
  assertTrue(cs_len(&stack) == 2); // 4
  assertTrue(cs_peek(&stack) == 'B'); // 5
  assertTrue(cs_pop(&stack) == 'B'); // 6
  assertTrue(cs_len(&stack) == 1); // 7
  cs_push(&stack, 'B');
  cs_push(&stack, 'C');
  cs_push(&stack, 'D');
  cs_reverse(&stack);
  assertTrue(cs_pop(&stack) == 'A'); // 1
  assertTrue(cs_pop(&stack) == 'B'); // 1
  assertTrue(cs_pop(&stack) == 'C'); // 1
  assertTrue(cs_pop(&stack) == 'D'); // 1

  // Example Tokens
  Token A, B, C;
  A.value.direct.tag = 'A';
  A.value.direct.a = 0;
  A.value.direct.a = 1;
  A.value.direct.time = 1.0;
  B.value.direct.tag = 'B';
  B.value.direct.a = 0;
  B.value.direct.a = 1;
  B.value.direct.time = 1.0;
  C.value.direct.tag = 'C';
  C.value.direct.a = 0;
  C.value.direct.b = 1;
  C.value.direct.time = 1.0;
  
  TokenStack* stack2 = ts_init(); 
  ts_push(&stack2, &B);
  assertTrue(ts_peek(&stack2) == &B); // 1
  ts_push(&stack2, &C);
  assertTrue(ts_peek(&stack2) == &C); // 2
  assertTrue(ts_len(&stack2) == 2); // 3
  ts_delHead(&stack2);
  assertTrue(ts_len(&stack2) == 1); // 4
  assertTrue(ts_peek(&stack2) == &B); // 5
  assertTrue(ts_pop(&stack2) == &B); // 6
  assertTrue(ts_len(&stack2) == 0); // 7

  ts_push(&stack2, &A);
  ts_push(&stack2, &B);
  ts_push(&stack2, &C);
  ts_reverse(&stack2);

  assertTrue(ts_pop(&stack2) == &A); // 1
  assertTrue(ts_pop(&stack2) == &B); // 1
  assertTrue(ts_pop(&stack2) == &C); // 1
  // Test Readers
  char example1[] = "m(1.04)_1_2, r(4.04)_1_2,\n o(2.44)_1, s(4.04)_1_2";
  char* cleaned = clean(example1, strlen(example1));
  int cleanedString = strlen(cleaned);
  CharStack* stream = initStream(cleaned, cleanedString);
  assertTrue(cleanedString == cs_len(&stream));
  // Test Lexer  
  CharStack* griddy = cs_init(); 
  cs_push(&griddy, 'C');
  cs_push(&griddy, '1');
  cs_push(&griddy, '2');
  cs_push(&griddy, '3');
  int output = extractIntParameter(&griddy); 
  assertTrue(output == 321);
  assertTrue(cs_len(&griddy) == 1);
  cs_delHead(&griddy);

  cs_push(&griddy, '_');
  cs_push(&griddy, '4');
  cs_push(&griddy, '.');
  cs_push(&griddy, '3'); 
  float uoi = extractFloatParameter(&griddy); 
  // printf("%f", uoi);
  assertTrue((uoi - 3.4) < 0.001 || -(uoi - 3.4) < 0.001);
  // printf("%i", cs_len(&griddy));
  assertTrue(cs_len(&griddy) == 1);
  cs_delHead(&griddy);
  
  TokenStack* tokens = tokenize(&stream);

  // m(1.04)_1_2, r(4.04)_1_2,\n o(2.44)_1, s(4.04)_1_2
  // printf("%d", ts_peek(&tokens)->direct.a);
  assertTrue(ts_peek(&tokens)->value.direct.a==1);
  assertTrue(ts_peek(&tokens)->value.direct.b==2);
  assertTrue(ts_peek(&tokens)->value.direct.tag=='s');
  assertTrue(fabs(ts_peek(&tokens)->value.direct.time - 4.04) < 0.001);
  ts_delHead(&tokens);

  assertTrue(ts_peek(&tokens)->value.direct.a==1);
  assertTrue(ts_peek(&tokens)->value.direct.tag=='o');
  assertTrue(fabs(ts_peek(&tokens)->value.direct.time - 2.44) < 0.001);
 

  return 0;
}

void initialize_tests() {
  test_completed = 0;
  test_id = 0;
}

bool assertTrue(bool stuff) {
  test_id++;
  if (stuff) {
    test_completed++;
    return true;
  } else {
    printf("TEST %i HAS FAILED. EXPECTED CONDITION TO BE TRUE \n", test_id);
    return false;
  }
  
}

bool assertFalse(bool stuff) {
  test_id++;
  if (!stuff) {
    test_completed++;
    return true;
  } else {
    printf("TEST %i HAS FAILED. EXPECTED CONDITION TO BE FALSE \n", test_id);
    return false;
  }
}
