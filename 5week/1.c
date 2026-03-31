#include <stdio.h>

int isPrime(int n)
{
	int count = 0;
	for (int i = 1; i <= n; i++)
	{
		if (n % i == 0)
		{
			count++;
		}
	}
	if (count == 2)
		return 1;
	else
		return 0;
}

main()
{
	int i, sum = 0;
	for (i = 2; i <= 100; i++)
	{
		if (isPrime(i) == 1)
		{
			sum += i;
			printf("%d ", i);
		}
	}
	printf("\n");
	printf("sum=%d\n", sum);
}