#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void make_calender(int mon)
{
	int sum = 0;
	int day = 0;
	printf("%s %2s %2s %2s %2s %2s %2s\n","일","월","화","수","목","금","토");
	int month_day[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	//각 달의 시작요일을 구하는 과정
	for (int i = 0; i < mon-1; i++)
		sum += month_day[i];

	if (mon == 1)
		sum = 0;
	
	sum %= 7; //sum 은 0(일) 1(월) 2(화) 3(수) 4(목) 5(금) 6(토)
	day = sum; // day가 6이 되면 줄바꿈 >> 7로 나눈나머지가 6이면 줄바꿈
	
	//각 달의 시작요일 구하고 인터페이스 맞추는 과정
	if (sum != 6)
	{
		for (int j = 0; j <= sum*3+1; j++)
			printf(" ");
	}

	//날짜 작성 시작
	for (int k = 1; k <= month_day[mon - 1]; k++)
	{
		
		if ((day+1) % 7 == 0)
		{
			if ((sum) == 6)
				sum++;
			else
				printf("\n");
			printf("%2d", k);
			
			
		}
		else
		{
			printf("%3d", k);	
		}
		
		day++;
		
	}
}

int main()
{
	int month;
	printf("출력 월을 입력 : ");
	scanf("%d", &month);
	make_calender(month);
}