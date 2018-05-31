#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 5

void MergeSort(int a[], int s, int mid, int n, int temp[])
{
	int i = s, j = mid + 1;
	int k = 0, l = 0;

	while(i<=mid && j<=n)
	{
		if(a[i] < a[j])
			temp[k++] = a[i++];
		else
			temp[k++] = a[j++];
	}

	while(i <= mid)
		temp[k++] = a[i++];

	while(j <= n)
		temp[k++] = a[j++];

	for(l = 0; l < k; l++)
		a[s+l] = temp[l];
}

void MSort(int a[], int s, int n, int temp[])
{
	if(s < n)
	{
		int mid = (s + n)/2;
		MSort(a, s, mid, temp);
		MSort(a, mid+1, n, temp);
		MergeSort(a, s, mid, n, temp);
	}
}

int main(void)
{
	int a[MAXSIZE] = {5, 2, 4, 1, 3};
	int *p = (int *)malloc(sizeof(int) * MAXSIZE);

	printf("ÅÅÐòÇ°: ");
	for(int i = 0; i < MAXSIZE; i++)
		printf("%d ", a[i]);
	printf("\n");

	MSort(a, 0, 4, p);

	printf("ÅÅÐòºó: ");
	for(int i = 0; i < MAXSIZE; i++)
		printf("%d ", a[i]);
	printf("\n");

	free(p);

	return 0;
}