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

	if (mon == 1) //1월이면 시작일이 월요일이므로 sum을 0으로 바꿈 ( 나중에 1을 더함 )
		sum = 0;
	
	sum %= 7; //sum 은 0(일) 1(월) 2(화) 3(수) 4(목) 5(금) 6(토)
	day = sum; // day가 6이 되면 줄바꿈 >> 7로 나눈나머지가 6이면 줄바꿈
	
	//각 달의 시작요일 구하고 인터페이스 맞추는 과정
	if (sum != 6) // 시작요일이 일요일이면 처음줄 띄어지므로 그거 방지(줄바꾸는거 방지가 아님)
	{
		for (int j = 0; j <= sum*3+1; j++)
			printf(" ");
	}

	//날짜 작성 시작
	for (int k = 1; k <= month_day[mon - 1]; k++)
	{
		if ((day+1) % 7 == 0) //sum은 전달의 마지막요일을 나타내므로 이번달의 시작요일을 나타내기 위해 +1 을 해줌(day = sum) 
			// 이 조건은 day+1 => 이번달 시작요일이 마지막요일인 토요일이 되면 줄바꿈을 일으키기위해 만듬
		{
			if ((sum) == 6) // 근데 만약 시작요일이 일요일이면 줄을 바꾸면 안되니까 sum을 바꿔서 줄바꿈 방지
				sum++;
			else
				printf("\n"); // 줄바꿈
			printf("%2d", k);// 문자 출력
			/*
				일요일이 앞에 한칸이 안띄어져있음 그니까 /일/ 월/ 화/ 수/ 목/ 금/ 토/ 글자는 2칸 차지하니까 일 2칸 나머지는 3칸을 가짐
			*/
		}
		else
		{
			printf("%3d", k);//3d는 3칸을 만들고 오른쪽 정렬
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