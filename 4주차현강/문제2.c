#include <stdio.h>
#define N 4
#define ABS(x) ((x) < 0 ? (x)*-1 : (x))
struct Point
{
		int x;
		int y;
};

void print_point(struct Point *pp)
{
		printf("(%d, %d)",pp->x ,pp->y);
}

int main()
{
		struct Point p[N] = { {1,2},{6,1},{3,4},{4,5} };
		struct Point P1, P2;
		int area;
		int i;
		for (i = 0; i < N; i++)
		{
				printf("p[%d]=",i);
				print_point(&p[i]);
				printf("\n");
		}
		P1.x = p[0].x; P1.y = p[0].y;
		P2.x = p[0].x; P2.y = p[0].y;
		for (i = 0; i < N; i++)
		{
				if (P2.x < p[i].x) P2.x = p[i].x;
				if (P2.y < p[i].y) P2.y = p[i].y;
				if (P1.x > p[i].x) P1.x = p[i].x;
				if (P1.y > p[i].y) P1.y = p[i].y;
		}

		area = ABS(P2.y - P1.y) * ABS(P2.x - P1.x);
		printf("P1="); print_point(&P1);
		printf(" P2="); print_point(&P2);

		printf("  ¸éÀû=%d\n", area);
}


