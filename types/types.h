#ifndef TYPES
#define TYPES

typedef struct Token Token;

typedef struct TokenDirect {
    // Defines a token for a direct move that takes in two tokens.
    // 'o' is a direct, just keep b = 0 or something.
    char tag;
    float time;
    int a, b;
} TokenDirect;

typedef struct TokenSingle {
    // Defines a token with a singular token
    // wait is defined here too
    char tag;
    float t, a;
}  TokenSingle;

typedef struct TokenSpline {
    // Defines a token for a splined move.
    char tag;
    float t;
    int len;
    int* pointList;
} TokenSpline;

/// @brief Wrapper for grouping together different types of tokens
typedef struct TokenSeq {
    // Sequence of tokens
    int len;
    Token* seq;
} TokenSeq;

typedef struct TokenGroup {
    // A group of tokens. Parses initial positions first
    int len;
    Token* group; // Group of tokens
} TokenGroup;

/// @brief Grouped together tokens. can be a sequence or a set
typedef union TokenSet {
    TokenSeq seq;
    TokenGroup group;
} TokenSet; 
union TokenUnion {
    TokenDirect direct;
    TokenSingle single;
    TokenSpline spline;
    TokenSet set;
};
struct Token {
    union TokenUnion value;
    int type;
};
#endif