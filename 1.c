#include <stdio.h>

int main()
{
	int sum = 0;
	int i;
	printf("(1) for 사용 : ");
	for (i = 1; i <= 10; i++)
	{
		printf("%d ", i);
		sum += i;
	}
	printf("sum=%d\n", sum);

	i = 1;
	sum = 0;
	printf("(2) while 사용 : ");
	while (i <= 10)
	{
		printf("%d ", i);
		sum += i;
		i++;
	}
	printf("sum=%d\n", sum);

	i = 1;
	sum = 0;
	printf("(3) do ~ while 사용 : ");
	do
	{
		printf("%d ", i);
		sum += i;
		i++;
	} while (i < 11);
	printf("sum=%d\n", sum);
	return 0;
}