/*
 * common.h
 *
 *  Created on: Jan 24, 2019
 *      Author: bulkodaw
 */

#ifndef COMMON_H_
#define COMMON_H_
/* > Defines ******************************************************************/
#define SIZE 256

/* > Defines ******************************************************************/
typedef unsigned char U8;

void defineInputArgument(const int argc, char* argv[]);
void codeWEP(char* key, char* plainText);
void decodeWEP(char* key, char* plainText);
#endif /* COMMON_H_ */
