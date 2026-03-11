#include <stdio.h>
void main()
{
	/*
		문장의 길이는 바깥 반복문에서 시작
	*/
	//4-1번문제
	printf("...(1)\n");
	char c1, c2;
	for (c1 = 'Z'; c1 >= 'A'; c1--) {
		for (c2 = 'Z'; c2 >= c1; c2--) {
			printf("%c", c2);
		}
		printf("\n");
	}

	//4-2번문제
	printf("...(2)\n");
	for (c1 = 'Z'; c1 >= 'A'; c1--) {
		for (c2 = 'A'; c2 <= c1; c2++) {
			printf("%c", c2);
		}
		printf("\n");
	}

	//4-3번문제
	printf("...(3)\n");
	for (c1 = 'A'; c1 <= 'Z'; c1++) {
		for (c2 = 'Z'; c2 >= c1; c2--) {
			printf("%c", c2);
		}
		printf("\n");
	}

	//4번문제
	int c3;
	printf("...(4)\n");
	for (c1 = 'A'; c1 <= 'Z'; c1++) {
		for(c3 = c1-'A'; c3 <= 'Z' - 'A'; c3++)
		{
			printf(" ");
		}
			
		for (c2 = 'A'; c2 <= c1; c2++) {
			printf("%c", c2);
		}
		printf("\n");
	}
}