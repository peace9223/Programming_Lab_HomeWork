#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void main()
{
	int x, y;
	FILE* in = fopen("input.txt", "r");
	FILE* out = fopen("output.txt", "w");
	if (in == NULL || out == NULL)
	{
		printf("파일을 열수 없습니다\n");
		return;
	}
	fscanf(in, "%d %d", &x, &y);
	fprintf(out, "%d %d", x+y, x*y);

	fclose(in);
	fclose(out);

	
}