#ifndef LEXER_H
#define LEXER_H
#include "../general.h"

/**
 * @brief Converts a stack of characters into a list of readable tokens
 * @param stack - character list in the form of a stack.
 * @return returns a list of tokens. To be imported into the parser
 */

TokenStack* tokenize(CharStack** stack);

// Helper functions for automatically reading and pushing a character
void readDirectToken(CharStack** chars, TokenStack** tokens, const char tag);
void readSingleToken(CharStack** chars, TokenStack** tokens, const char c);
void readSplineToken(TokenStack **stack, const char c);

// Methods for extracting parameters
int extractIntParameter(CharStack** stack);
float extractFloatParameter(CharStack** stack);

#endif