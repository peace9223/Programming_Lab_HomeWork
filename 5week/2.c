#include <stdio.h>

void isPerfectNumber(int n)
{
	int sumOfDivisors = 0;
	int divisorsArrays[100];
	int count = 0;
	if (n != 1 && n != 2)
	{
		for (int i = 1; i < n; i++)
		{
			if (n % i == 0)
			{
				sumOfDivisors += i;
				divisorsArrays[count++] = i;
			}
		}
		if (sumOfDivisors == n)
		{
			printf("%d = ", n);
			for (int i = 0; i < count; i++)
			{
				printf("%d ", divisorsArrays[i]);
				if (i != count - 1)
					printf("+ ");
			}
			printf("\n");
		}
		
	}
}

int main()
{
	for (int i = 1; i <= 10000; i++)
	{
		isPerfectNumber(i);
	}
	return;
}