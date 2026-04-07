#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int t = 0;
	FILE* in = fopen("input3.txt", "r");
	FILE* out = fopen("output3.txt", "w");
	if (in == NULL || out == NULL)
	{
		printf("ÆÄÀÏÀ» ¸ø¿°\n");
		return;
	}
	fscanf(in,"%d", &t);
	for (int i = 0; i < t; i++)
	{
		int k = 0;
		fscanf(in,"%d", &k);
		int* p = (int*)malloc(k * sizeof(int));
		int sum = 0, max = 0, min = 100;
		for (int m = 0; m < k; m++)
		{
			fscanf(in,"%d", &p[m]);
			sum += p[m];
			if (max < p[m]) max = p[m];
			if (min > p[m]) min = p[m];
		}
		fprintf(out,"%d %d %d\n", sum, max, min);
		free(p);
	} // 5-6번 문제

}
