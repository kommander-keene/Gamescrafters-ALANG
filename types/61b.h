#ifndef B61
#define B61
#endif

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include <ctype.h>
#include "types.h"

/// @brief Define a Charstack: A structure used to store characters!
typedef struct CharStack {
    // Stack Datastructure to deal with characters from the string
    char value;
    struct CharStack* prev;
    int length;
} CharStack;

CharStack* cs_init();
void cs_push(CharStack** stack, char value);
void cs_delHead(CharStack** stack);
bool cs_isEmpty(CharStack** stack);
char cs_pop(CharStack** stack);
int cs_len(CharStack** stack);
char cs_peek(CharStack** stack);

void cs_reverse(CharStack** stack);

/// @brief Define a Tokenstack: a structure used to store characters in a list. Stores pointers to save space
typedef struct TokenStack {
    Token* value;
    struct TokenStack* prev;
    int length;
} TokenStack;

TokenStack* ts_init();
void ts_push(TokenStack** stack, Token* value);
void ts_delHead(TokenStack** stack);
Token* ts_pop(TokenStack** stack);
bool ts_isEmpty(TokenStack** stack);
int ts_len(TokenStack** stack);
Token* ts_peek(TokenStack** stack);

void ts_reverse(TokenStack** stack);