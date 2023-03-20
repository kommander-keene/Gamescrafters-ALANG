#ifndef READER_H
#define READER_H
#include "general.h"
#include "61b.h"
#endif

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
void clean(char** dirty, const int length);
/**
 * @brief Take a peek at the most recent upcoming character
 * 
 * @return char 
 */
char peek(CharStack* seq);
/**
 * @brief Peek the ith most recent character
 * 
 * @param i
 * @return char 
 */
char peek_i(CharStack* seq, int len, int i);
/**
 * @brief pop the most recent upcoming character
 * 
 * @return char 
 */
char pop(CharStack** seq, int len);
/**
 * @brief pop the ith most recent upcoming character
 * 
 * @return char 
 */
char pop_i(CharStack** seq, int len, int i);

/**
 * @brief Check to see if I finished reading the file. Specified by the EOF char.
 * 
 * @return true 
 * @return false 
 */
bool isEOF(CharStack* seq);