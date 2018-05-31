#include <stdio.h>


void swap(int *a, int *b)
{
	int tmp = *b;
	*b = *a;
	*a = tmp;
}

int Partition(int a[], int low, int high)
{
    int flag;
    flag = low + (high - low)/2;
    if(a[low] > a[high])
        swap(&a[low], &a[high]);
    if(a[flag] > a[high])
        swap(&a[flag], &a[high]);
    if(a[flag] > a[low])
        swap(&a[flag], &a[low]);

    flag = a[low];
    while(low < high)
    {
        while(low < high && a[high] > flag)
            high--;
        a[low] = a[high];

        while(low < high && a[low] < flag)
            low++;
        a[high] = a[low];
    }
    a[low] = flag;

    return low;
}

void QSort(int a[], int low, int high)
{
    int tmp;

    while(low < high)
    {
        tmp = Partition(a, low, high);
        QSort(a, low, tmp-1);
        low = tmp + 1;
    }
}


int main(void)
{
	int a[10] = {0, 5, 8, 1, 3, 6, 7, 9, 4, 2};

	printf("排序前: ");
	for(int i = 1; i < 10; i++)
		printf("%d ", a[i]);
	printf("\n");

	QSort(a, 1, 9);

	printf("排序后: ");
	for(int i = 1; i < 10; i++)
		printf("%d ", a[i]);
	printf("\n");

	return 0;
}
