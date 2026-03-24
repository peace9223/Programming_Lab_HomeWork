#include <stdio.h>


void print_array(int arr[] , int len)
{
		for (int i = 0; i < len; i++)
		{
				printf("%d ", arr[i]);
		}
		printf("\n");
}

double compute_avg(int arr[], int len)
{
		int sum = 0;
		for (int i = 0; i < len; i++)
		{
				sum += arr[i];
		}
		return sum / len;
}

int find_max(int arr[], int len)
{
		int max = arr[0];
		for (int i = 0; i < len; i++)
		{
				if (max < arr[i]) max = arr[i];
		}
		return max;
}

int find_min(int arr[], int len)
{
		int min = arr[0];
		for (int i = 0; i < len; i++)
		{
				if (min > arr[i]) min = arr[i];
		}
		return min;
}

void main()
{
		int arr[10] = { 10,30,5,20,44,3,100,88,9,101 };

		print_array(arr, 10);
		printf("평균 = %lf\n", compute_avg(arr, 10));
		printf("최대 = %d\n", find_max(arr, 10));
		printf("최소 = %d\n", find_min(arr, 10));
}