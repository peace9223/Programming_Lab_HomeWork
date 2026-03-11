#include <stdio.h>

int oddsum1(int n)
{
	int sum = 0;
	for (int i = 1; i <= n; i++)
	{
		if (i % 2 != 0)
		{
			sum += i;
		}
	}
	return sum;
}

int oddsum2(int n)
{
	int i = 1;
	int sum = 0;
	while (i < n)
	{
		if (i % 2 != 0)
		{
			sum += i;
		}
		i++;
	}
	return sum;
}

int oddsum3(int n)
{
	int sum = 0;
	if (n > 0)
	{
		sum = n - 1 + oddsum3(n - 2);
	}
	return sum;
}

int main()
{
	int n = 100;
	int SUM = 0;
	int i;
	printf("(1) for oddsum1<%d> = %d\n", n, oddsum1(n));
	printf("(2) while oddsum2<%d> = %d\n", n, oddsum2(n));
	printf("(3) 재귀 oddsum3<%d> = %d\n", n, oddsum3(n));
	// SUM 을 구한다.
	for (i = 100; i > 0; i--)
	{
		if (i % 2 != 0)
			SUM += oddsum1(i);
	}
	printf("(4) SUM = %d\n", SUM);
}