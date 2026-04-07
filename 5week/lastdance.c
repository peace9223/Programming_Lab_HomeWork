#define _CRT_SECURE_NO_WARNINGS
#define MAX_HOTEL_FLOOR 100
#define MAX_HOTEL_ROOM 100
#include <stdio.h>

int main()
{
	FILE* input = fopen("input.txt", "r");
	FILE* output = fopen("output.txt", "w");
	if (input == NULL || output == NULL)
	{
		printf("파일이 없습니다!\n");
		return 0;
	}
	int number;
	fscanf(input, "%d", &number);

	for (int i = 0; i < number; i++)
	{
		int floor = 0; // 층수
		int room = 0; // 방수
		int guest = 0; // 몇번째 손님인지
		fscanf(input, "%d %d %d", &floor, &room, &guest);
		int hotel[MAX_HOTEL_FLOOR][MAX_HOTEL_ROOM];
		// 101 102 103 104 105 106 ...
		// 101 201 301 401.. 901 1001 1101
		// 201 202 203  .. 299
		hotel[0][0] = 101;
		int i; //i = 0~99
		int j; // j = 0~99
		for (i = 0; i < MAX_HOTEL_FLOOR; i++)
		{
			if (i != 0)
			{
				hotel[i][0] = hotel[i - 1][0] + 100;
			}
			else if (i == 0)
			{
				hotel[i][0] = 101;
			}
			for (j = 1; j < MAX_HOTEL_ROOM; j++)
			{
				hotel[i][j] = hotel[i][j - 1] + 1;
			}
		}
		int groom = guest / floor; // 15  6 2
		int gfloor = guest % floor - 1; // 15 6 3
		fprintf(output, "손님의 객실은 %d호 입니다\n", hotel[gfloor][groom]);
	}
	return 0;
}
