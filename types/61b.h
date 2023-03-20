#ifndef 61B
#define 61B
#endif
#include "general.h"
#include "types.h"

/// @brief Define a Charstack: A structure used to store characters!
typedef struct CharStack {
    // Stack Datastructure to deal with characters from the string
    char value;
    CharStack* prev;
    int length;

} CharStack;

void cs_push(CharStack** stack, char value);
void cs_delHead(CharStack** stack);
bool cs_isEmpty(CharStack** stack);
char cs_pop(CharStack** stack);
int cs_len(CharStack** stack);
char cs_peek(CharStack** stack);

/// @brief Define a Tokenstack: a structure used to store characters in a list. Stores pointers to save space
typedef struct TokenStack {
    Token* value;
    TokenStack* prev;
    int length;
} TokenStack;

void ts_push(TokenStack** stack, Token* value);
void ts_delHead(TokenStack** stack);
Token* ts_pop(TokenStack** stack);
bool ts_isEmpty(TokenStack** stack);
int ts_len(TokenStack** stack);
Token* ts_peek(TokenStack** stack);