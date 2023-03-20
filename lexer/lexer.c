#include "lexer.h"

/// @brief 
/// @param stack, stack to convert into tokens
/// @return list composed of tokens
TokenStack* tokenize(CharStack *stack) {
    bool startOfToken = false;
    bool endOfToken = false;

    TokenStack* tokens = (TokenStack*) malloc(sizeof(TokenStack));
    while (!cs_isEmpty(&stack)) {
        char id = cs_pop(&stack);
        switch (id)
        {
        case 'm':
            startOfToken = true;
            /* move */
            // m(t)_r1_r2
            readDirectToken(tokens, 'm');
            break;
        case 'r':
            startOfToken = true;
            /* rotate */
            // r(t)_r1_a
            readDirectToken(tokens, 'r');
            break;
        case 's':
            startOfToken = true;
            /* scale */
            // s(t)_r1_f
            readDirectToken(tokens, 's');
            break;
        case 'o':
            startOfToken = true;
            /* fade out */
            // o(t)_r1
            readDirectToken(tokens, 'o');
            break;
        case 'i':
            startOfToken = true;
            /* fade in */
            // i(t)_x_r2
            readDirectToken(tokens, 'i');
            break;
        case 'w':
            startOfToken = true;
            /* wait */
            // w(t)
            readSingleToken(tokens, 'w');
            break;
        case ',':
            startOfToken = false;
            /* separator */
            
        case 'c':
            startOfToken = true;
            /* spline */
            print("SPLINE TOKENS NOT SUPPORTED \n");
            break;
        case 'j':
            startOfToken = true;
            /* random */
            print("JUMP TOKENS NOT SUPPORTED \n");
            break; 
        case '[':
            startOfToken = true;
            /* sequential */
            print("SEQUENCES NOT SUPPORTED \n");
            break;
        case '(':
            startOfToken = true;
            print("GROUPS NOT SUPPORTED \n");
            /* group */
            break;
        default:
            /* error*/
            break;
        }
    }
}


float extractFloatParameter(CharStack *stack) {
    char * buf = ""; // points to an empty string
    while (isdigit(cs_peek(&stack)) || cs_peek(&stack) == '.') {
        buf = strcat(buf, cs_pop(&stack));
    }
    int output = atof(buf);
    free(buf); // Just in case...
    return output;
}
int extractIntParameter(CharStack *stack) {
    char * buf = ""; // points to an empty string
    while (isdigit(cs_peek(&stack))) {
        buf = strcat(buf, cs_pop(&stack));
    }
    int output = atoi(buf);
    free(buf);
    return output;
}
void readDirectToken(TokenStack* stack, const char tag) {
    char paren = ts_pop(&stack); // (
    if (paren != '(') {
        // error
        // free character stack later
    }
    // Extract parameters
    float time = extractFloatParameter(stack);
    if (ts_pop(&stack) != ')' && ts_pop(&stack) != '_') {
        // error
        // free character stack later
    }
    int r1 = extractIntParameter(stack);
    if (ts_pop(&stack) != '_') {
        // error
        // free character stack later
    }
    int r2 = 0;
    if (tag != 'o') {
        if (ts_pop(&stack) != '_') {
        // error
        // free character stack later
        }
        int r2 = extractIntParameter(stack);
    }
    // Form token
    Token* t = (Token*)malloc(sizeof(Token));
    t->direct.time = time;
    t->direct.a = r1;
    t->direct.b = r2;
    t->direct.tag = tag;
    ts_push(&stack, t);
}
void readSingleToken(TokenStack* stack, const char tag) {
    char paren = cs_pop(&stack); // (
    if (paren != '(') {
        // error
        // free character stack later
    }
    // Extract parameters
    float time = extractFloatParameter(stack);
    if (ts_pop(&stack) != ')') {
        // error
        // free character stack later
    }
    int r1 = 0;
    if (tag != 'w') {
        if (ts_pop(&stack) != '_') {
            // error
            // free character stack later
        }
        r1 = extractIntParameter(stack);
    }
    // Form token
    Token* t = (Token*)malloc(sizeof(Token));
    t->single.t = time;
    t->single.a = r1;
    t->single.tag = tag;
    ts_push(&stack, t);
}
void readSplineToken(TokenStack* stack, const char tag) {
    // TODO 
    return;

    char paren = cs_pop(&stack); // (
    if (paren != '(') {
        // error
        // free character stack later
    }
    int n = extractIntParameter(stack);
    if (ts_pop(&stack) != ')') {
        // error
        // free character stack later
    }
    float time = extractFloatParameter(stack);
    if (ts_pop(&stack) != '_') {
            // error
            // free character stack later
    }
    Token* t = (Token*)malloc(sizeof(Token));
    t->spline.t = time;
    t->spline.len = n;
    
    for (int i = 0; i < n; i++) {

    }

}