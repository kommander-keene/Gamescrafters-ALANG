#include "61b.h"
CharStack* cs_init() {
    CharStack* newElt = (CharStack*) malloc(sizeof(CharStack));
    newElt->length = 0;
    newElt->prev = NULL;
    newElt->value = '\0';
    return newElt;
}
void cs_push(CharStack** stack, char value) {
    bool isEmpty = cs_isEmpty(stack);
    CharStack* newElt = (CharStack*) malloc(sizeof(CharStack));
    newElt->prev = *stack;
    newElt->value = value;
    *stack = newElt;
    // Something wrong here. Not sure why isEmpty is changing!
    newElt->length = newElt->prev->length + 1; 
}
void cs_delHead(CharStack** stack) {
    if (cs_isEmpty(stack)) {
        return;
    }
    
    CharStack* previous = (*stack)->prev;
    free(*stack); // Free the memory associated with the position
    *stack = previous; 
}
char cs_pop(CharStack** stack) {
    char c = cs_peek(stack);
    cs_delHead(stack);
    return c;
}
bool cs_isEmpty(CharStack** stack) {
    return (*stack) == NULL || (*stack)->length == 0 || (*stack)->value == '\0';
}
int cs_len(CharStack** stack) {
    if ((*stack) == NULL) {
        return 0;
    }
    return (*stack)->length;
}
char cs_peek(CharStack** stack) {
    return (*stack)->value;
}

void cs_reverse(CharStack** stack) {
    CharStack* reversi = cs_init();
    while(!cs_isEmpty(stack)) {
        char c = cs_pop(stack);
        if (c == '\0') {
            printf(" OH NO! ");
        }
        cs_push(&reversi, c);
        
    }
    *stack = reversi;
}

TokenStack* ts_init() {
    TokenStack* newElt = (TokenStack*) malloc(sizeof(TokenStack));
    newElt->length = 0;
    newElt->prev = NULL;
    newElt->value = NULL;
    return newElt;
}
void ts_push(TokenStack** stack, Token* value) {
    bool isEmpty = cs_isEmpty(stack);
    TokenStack* newElt = (TokenStack*) malloc(sizeof(TokenStack));
    newElt->prev = *stack;
    newElt->value = value;
    *stack = newElt;
    // Something wrong here. Not sure why isEmpty is changing!
    newElt->length = newElt->prev->length + 1;
}
void ts_delHead(TokenStack** stack) {
    TokenStack* previous = (*stack)->prev;
    free(*stack); // Free the memory associated with the position
    *stack = previous;
}
Token* ts_pop(TokenStack** stack) {
    Token* c = ts_peek(stack);
    ts_delHead(stack);
    return c;
}
bool ts_isEmpty(TokenStack** stack) {
    return (*stack) == NULL || (*stack)->length == 0;
}
int ts_len(TokenStack** stack) {
    if ((*stack) == NULL) {
        return 0;
    }
    return (*stack)->length;
}
Token* ts_peek(TokenStack** stack) {
    return (*stack)->value;
}

void ts_reverse(TokenStack** stack) {
    TokenStack* reversi = ts_init();
    while(!ts_isEmpty(stack)) {
        Token* c = ts_pop(stack);
        if (c == NULL) {
            printf(" OH NO! ");
        }
        ts_push(&reversi, c);
    }
    *stack = reversi;
}

