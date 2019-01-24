/*
 * common.c
 *
 *  Created on: Jan 24, 2019
 *      Author: bulkodaw
 */
/* > Incldues ******************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "common.h"
#include <string.h>

static void
swap (U8 *a, U8 *b)
{
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

/* > Local Function Declarations **********************************************/
static void
KSA(char* key, U8* ksaTab)
{
	U8 len = strlen (key);
	U8 j = 0;

	for (int i = 0; i < SIZE; i++)
	{
		ksaTab[i] = i;
	}

	for (int i = 0; i < SIZE; i++)
	{
		j = (j + ksaTab[i] + key[i % len]) % SIZE;

		swap(&ksaTab[i], &ksaTab[j]);
	}
}

static U8*
PRGA(char* plainText, U8* ksaTab)
{
	U8 i = 0;
	U8 j = 0;
	U8 plainTextLength = strlen(plainText);
	U8* K = calloc(plainTextLength, sizeof(U8));

	for (U8 counter = 0; counter < plainTextLength; counter++)
	{
		i = (i + 1) % SIZE;
		j = (j + ksaTab[i]) % SIZE;
		swap(&ksaTab[i], &ksaTab[j]);
		K[counter] = ksaTab[(ksaTab[i] + ksaTab[j]) % SIZE];
		K[counter] ^= plainText[counter];
	}
	return K;
}

static void
hexToAscii(char* plainText)
{
	const U8 byte = 2;
	U8 plainTextCpByte[2];
	U8 plainTextLength = strlen(plainText);
	U8* returnAsciiText = calloc(plainTextLength/2, sizeof(U8));

	for (U8 i =0 ; i < plainTextLength; i+=2)
	{
		strncpy(plainTextCpByte, plainText + i,  byte);
		printf("%s ", plainTextCpByte);
		strcat(returnAsciiText, plainTextCpByte);
	}
	printf("\n ");
	for (U8 i =0 ; i < strlen(returnAsciiText); i++)
	{
		printf("%c ", (char)returnAsciiText[i]);
	}
//	U8 plainTextLength = strlen(plainText);
//	char* returnAsciiText;
//	long ret;
//	ret = strto(plainText, returnAsciiText, 16);
//	printf("%p", returnAsciiText);
}

void
defineInputArgument(const int argc, char* argv[])
{
	if(argc != 3)
	{
		fprintf(stderr, "Invalid ammount of input argument's\n");
		exit(1);
	}
	for (U8 i = 0; i < argc; i++)
	{
		if(argv[i] == NULL)
		{
			fprintf(stderr, "%c is empty\n", i);
			exit(1);
		}
	}
}

void
codeWEP(char* key, char* plainText)
{
	U8 ksaTab[SIZE] = {0};
	KSA(key, ksaTab);

	U8* cipherText = PRGA(plainText, ksaTab);
	for (U8 i = 0; i < strlen(plainText); i++)
	{
		if(cipherText[i] < 15)
			printf("0%hhx ", cipherText[i]);
		else
			printf("%hhx ", cipherText[i]);
	}
	printf("\n");
}

void
decodeWEP(char* key, char* plainText)
{
	U8 ksaTab[SIZE] = {0};
	KSA(key, ksaTab);

	hexToAscii(plainText);

//	char* try = plainText & 0xff;
}
