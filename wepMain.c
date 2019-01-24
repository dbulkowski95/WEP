/*
 * wepMain.c
 *
 *  Created on: Jan 24, 2019
 *      Author: bulkodaw
 */
/*****************************Incldues*****************************/
#include <stdio.h>
#include "common.h"
#include <stdbool.h>

/*****************************Defines*****************************/
int main(const int argc, char* argv[])
{
	defineInputArgument(argc, argv);
	char key = 0;
	bool exit = true;
	printf("Choose operation:\n");
	printf("1. Code WEP\n");
	printf("2. Decode WEP\n");
	printf("3. Exit\n");
	printf("> ");
	key = getchar();
	switch (key)
	{
	case '1':
		//code(SECRET KEY, PLAINTEXT (ASCII))
		codeWEP(argv[1], argv[2]);
		break;
	case '2':
		//decode(SECRET KEY, PLAINTEXT (HEX))
		decodeWEP(argv[1], argv[2]);
		break;
	default:
		printf("Unknown case!\n");
		break;
	}
	return 0;
}
