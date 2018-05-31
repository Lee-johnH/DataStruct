#include <stdio.h>

void HeapAdjust(int arr[], int s, int length)
{
	int temp, j;

	temp = arr[s];
	for(j = 2*s; j<=length; j *= 2)
	{
		if(j<length && arr[j] < arr[j+1])
			j = j+1;

		if(temp > arr[j])
			break;
		arr[s] = arr[j];
		s = j;
	}
	arr[s] = temp;
}

void HeapSort(int arr[], int s, int length)
{
	int i, tmp;

	for(i = length/2; i > 0; --i)
		HeapAdjust(arr, i, length);

	for(i = length; i > 1; --i)
	{
		tmp = arr[i];
		arr[i] = arr[1];
		arr[1] = tmp;
		HeapAdjust(arr, 1, i-1);
	}
}

int main(void)
{
	int i = 0;
	int arr[] = {0, 50, 10, 90, 30, 70, 40, 80, 60, 20};

	printf("ÅÅĞòÇ°: ");
	for(i = 1; i < 10; ++i)
		printf("%d ", arr[i]);
	printf("\n");

	HeapSort(arr, 1, 9);

	printf("ÅÅĞòºó: ");
	for(i = 1; i < 10; ++i)
		printf("%d ", arr[i]);
	printf("\n");

	return 0;
}