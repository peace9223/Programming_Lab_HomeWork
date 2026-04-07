#include <stdio.h>
#include <math.h>

#define ABS(a) (a>0 ? a: -a)
double myexp(int x)
{
	int i;
	double term, sum, oldsum;
	oldsum = 0.0;
	sum = 1.0;
	term = 1.0;
	for (i = 1;ABS(sum-oldsum) > 0.0000001; i++)
	{
		term *= (double)x / i;
		oldsum = sum;
		sum += term;
	}
	return sum;
}

void main()
{
	int i;
	printf("  exp() : ");
	for (i = 1; i <= 5; i++)
		printf("%lf ", exp((double)i));
	printf("\n");
	printf("myexp() : ");
	for (i = 1; i <= 5; i++)
		printf("%lf ", myexp(i));
	printf("\n");
}