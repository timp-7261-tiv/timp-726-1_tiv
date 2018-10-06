#include <stdlib.h> 
#include <stdio.h>

void swap (int *a, int *b)
{
  int t = *a;
  *a = *b;
  *b = t;
}

int refresh(int *arr, int n)
{
	int i = n-1;
	for(;;)
	{
	if (i<0)
		break;
		int no_op=0;
			if (i<n && i+1<n)
		{
			if (arr[(i-1)/2]<arr[i])
			{
				swap(&arr[(i-1)/2], &arr[i]);
				no_op=1;
			}
			if (arr[(i-1)/2]<arr[i+1])
			{
				swap(&arr[(i-1)/2], &arr[i+1]);
				no_op=1;
			}	
			if (no_op==1 && 2*i+1<n)
				i=i*2+1;
			else	
				i-=2;
		}
		else
		{
			if (arr[(i-1)/2]<arr[i])
				swap(&arr[(i-1)/2], &arr[i]);
			i-=2;
		}
		
	}
}

void heap_sort(int *arr, int n)
{
	refresh(arr, n);
	
	for (int i=0;i<n-1;i++)
	{
		swap(&arr[0], &arr[n-(i+1)]);
		refresh(arr, n-(i+1));
	}
}

int main()
{
	int n=0;

	scanf("%i",&n);
	int *arr=malloc (n*sizeof(int));

	for (int i=0;i<n;i++)
		scanf("%i",&arr[i]);

	heap_sort(arr,n);

	for (int i=0;i<n;i++)
		printf("%i ",arr[i]);
	printf("\n");

	return 0;
}

