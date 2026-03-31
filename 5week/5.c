#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void main()
{
	int i, n_test, x, y;
	FILE* in = fopen("input2.txt", "r");
	FILE* out = fopen("output2.txt", "w");
	if (in == NULL || out == NULL)
	{
		printf("파일을 열수가 없습니다\n");
		return;
	}
	fscanf(in,"%d", &n_test);
	for (i = 0; i < n_test; i++)
	{
		fscanf(in,"%d %d", &x, &y);
		fprintf(out,"%d %d\n", x + y, x * y);
	}

	fclose(in);
	fclose(out);

}