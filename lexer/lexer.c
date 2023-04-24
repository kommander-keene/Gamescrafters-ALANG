#include "lexer.h"

/// @brief 
/// @param stack, stack to convert into tokens
/// @return list composed of tokens
TokenStack* tokenize(CharStack **stack) {
    bool endOfToken = false;

    TokenStack* tokens = ts_init();
    while (!cs_isEmpty(stack)) {
        char id = cs_pop(stack);
        // printf("id=%c \n", id);
        switch (id)
        {
        case 'm':
            // printf("Started Token of Type m \n");
            /* move */
            // m(t)_r1_r2
            readDirectToken(stack, &tokens, 'm');
            break;
        case 'r':
            /* rotate */
            // r(t)_r1_a
            readDirectToken(stack, &tokens, 'r');
            break;
        case 's':
            /* scale */
            // s(t)_r1_f
            readDirectToken(stack, &tokens, 's');
            break;
        case 'o':
            /* fade out */
            // o(t)_r1
            readDirectToken(stack, &tokens, 'o');
            break;
        case 'i':
            /* fade in */
            // i(t)_x_r2
             readDirectToken(stack, &tokens, 'i');
            break;
        case 'w':
            /* wait */
            // w(t)
            readSingleToken(stack, &tokens, 'w');
            break;
        case ',':
            /* separator */
            break;
        // case 'c':
        //     startOfToken = true;
        //     /* spline */
        //     printf("SPLINE TOKENS NOT SUPPORTED \n");
        //     break;
        // case 'j':
        //     startOfToken = true;
        //     /* random */
        //     printf("JUMP TOKENS NOT SUPPORTED \n");
        //     break; 
        case '[':
            /* sequential */
            printf("SEQUENCES NOT SUPPORTED \n");

            break;
        case '(':
            printf("GROUPS NOT SUPPORTED \n");
            /* group */
            break;
        default:
            assert("Error Syntax" == "");
            break;
        }
    }
    free(*stack);
    return tokens;
}
float extractFloatParameter(CharStack **stack) {
    char* buf = (char*) malloc(sizeof(char));
    buf[0] = '\0';
    bool dots = false;
    while (isdigit(cs_peek(stack)) || (cs_peek(stack) == '.' && !dots)) {
        char c = cs_pop(stack);
        int nextPosition = strlen(buf);
        buf = realloc(buf, strlen(buf)+2);
        buf[nextPosition] = c;
        buf[nextPosition+1] = '\0';
        if (c == '.') {
            dots = true;
        }
    }
    float output = atof(buf);
    free(buf);
    return output;
}
int extractIntParameter(CharStack **stack) {
    char* buf = (char*) malloc(sizeof(char));
    buf[0] = '\0';
    while (isdigit(cs_peek(stack))) {
        char c = cs_pop(stack);
        int nextPosition = strlen(buf);
        buf = realloc(buf, strlen(buf)+2);
        buf[nextPosition] = c;
        buf[nextPosition+1] = '\0';
    }
    int output = atof(buf);
    free(buf); // Just in case...
    return output;
}
void readDirectToken(CharStack** chars, TokenStack** tokens, const char tag) {
    char paren = cs_pop(chars); // (
    assert(paren == '(');
    // Extract parameters
    float time = extractFloatParameter(chars);
    assert(cs_pop(chars) == ')');
    assert(cs_pop(chars) == '_');

    int r1 = extractIntParameter(chars);
    int r2 = 0;
    if (tag != 'o'&& tag != 'i') {
        assert(cs_pop(chars) == '_');
        r2 = extractIntParameter(chars);
    }
    // Form token
    Token* t = (Token*) malloc(sizeof(Token));
    t->type = 0;
    t->value.direct.time = time;
    t->value.direct.a = r1;
    t->value.direct.b = r2;
    t->value.direct.tag = tag;
    ts_push(tokens, t);
}
void readSingleToken(CharStack** chars, TokenStack** tokens, const char tag) {
    char paren = cs_pop(chars); // (
    assert(paren == '(');
    // Extract parameters
    float time = extractFloatParameter(chars);
    assert(cs_pop(chars) == ')');
    int r1 = 0;
    if (tag != 'w') {
        assert((cs_pop(chars) == '_'));
        r1 = extractIntParameter(chars);
    }
    // Form token
    Token* t = (Token*)malloc(sizeof(Token));
    t->type = 1;
    t->value.single.t = time;
    t->value.single.a = r1;
    t->value.single.tag = tag;
    ts_push(&tokens, t);
}
void readSplineToken(TokenStack** stack, const char tag) {
    return;
    
    // char paren = cs_pop(stack); // (
    // if (paren != '(') {
    //     // error
    //     // free character stack later
    // }
    // int n = extractIntParameter(stack);
    // if (ts_pop(stack) != ')') {
    //     // error
    //     // free character stack later
    // }
    // float time = extractFloatParameter(stack);
    // if (ts_pop(stack) != '_') {
    //         // error
    //         // free character stack later
    // }
    // Token* t = (Token*)malloc(sizeof(Token));
    // t->spline.t = time;
    // t->spline.len = n;
    
    // for (int i = 0; i < n; i++) {

    // }

}