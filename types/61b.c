#include "61b.h"

void cs_push(CharStack** stack, char value) {
    CharStack* newElt = (CharStack*) malloc(sizeof(CharStack));
    newElt->length = 1;
    newElt->prev = *stack;
    newElt->value = value;
    if (!cs_isEmpty(stack)) {
        newElt->length = (*stack)->length+1;
    }
    //Increment pointer to head
    *stack = newElt;
}
void cs_delHead(CharStack** stack) {
    CharStack* prev = (*stack)->prev;
    free(*stack); // Free the memory associated with the position
    *stack = prev;
}
char cs_pop(CharStack** stack) {
    char c = (*stack)->value;
    CharStack* pastPtr = (*stack)->prev; // pastPtr points to the prev, which points to the previous node.
    free(*stack); // Free the struct at the head
    *stack = pastPtr; // Set the previous head to the correct one
    return c;
}
bool cs_isEmpty(CharStack** stack) {
    return (*stack) == NULL;
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

void ts_push(TokenStack** stack, Token* value) {
    TokenStack* newElt = (TokenStack*) malloc(sizeof(CharStack));
    newElt->length = 1;
    newElt->prev = *stack;
    newElt->value = value;
    if (!ts_isEmpty(stack)) {
        newElt->length = (*stack)->length+1;
    }
    //Increment pointer to head
    *stack = newElt;
}
void ts_delHead(TokenStack** stack) {
    TokenStack* prev = (*stack)->prev;
    free(*stack); // Free the memory associated with the position
    *stack = prev;
}
bool ts_isEmpty(TokenStack** stack) {
    return (*stack) == NULL;
}
int ts_len(TokenStack** stack) {
    return (*stack)->length;
}
Token* ts_pop(TokenStack** stack) {
    Token* c = (*stack)->value;
    TokenStack* pastPtr = (*stack)->prev; // pastPtr points to the prev, which points to the previous node.
    free(*stack); // Free the struct at the head
    *stack = pastPtr; // Set the previous head to the correct one
    return c;
}
Token* ts_peek(TokenStack** stack) {
    return (*stack)->value;
}