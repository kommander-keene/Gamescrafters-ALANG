#include "reader.h"

char* clean(char* dirty, const int length) {
    int trueLength = length;
    for(int i = 0; i < length; i++) {
        // remove \n, add null EOF
        if (dirty[i] == '\n') {
            trueLength--;
        } else if (dirty[i] == ' ') {
            trueLength--;
        }
    }
    if (trueLength == length) {
        return dirty; // return same pointer because no changes needed
    }
    char* newArray = (char*) malloc(trueLength * sizeof(char)); // make a new pointer
    int iter = 0;
    for(int i = 0; i < length; i++) {
        // iterate through and remove all iters
        if (dirty[i] != '\n' && dirty[i] != ' ') {
            newArray[iter] = dirty[i];
            iter++;
        }
    }
    return newArray;
}

CharStack* initStream(char* clean, int length) {
    // TODO make sure that when you pop the character, it is reading from the top!
    CharStack* m = cs_init();
    for (int i = 0; i < length; i++) {
        // printf("%c", clean[i]);
        cs_push(&m, clean[i]);
    }
    cs_reverse(&m);
    return m;
}
