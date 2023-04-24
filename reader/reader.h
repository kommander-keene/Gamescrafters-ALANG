#ifndef READER_H
#define READER_H
#include "../general.h"

/**
 * @brief Initializes the stream 
 * 
 * @param clean 
 * @return * CharStack 
 */
CharStack* initStream(char* clean, int length);
/**
 * @brief Cleans the string and outputs it into a more compiler-readable format.
 * 
 * @param dirty - the string to be passed in to be cleaned
 * @param length - length of the string to be cleaned
 * @return char* - the cleaned string
 */
char* clean(char* dirty, const int length);

#endif