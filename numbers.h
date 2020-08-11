#include <stdio.h>
#include <stdlib.h>

enum {outNotExist, outExist}; /* Specifies whether or not an output file was received */

FILE *input, *output; /* pointer to input and output files */

/*
This method obtains an integer between 0 and 99 and converts each number into English words and prints them into output
@param num - integer between 0 and 99
@param out - out =1 if output file received, out =0 no if output file received
*/
void convert_numbers(int num, int out);

