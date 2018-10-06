#include <stdlib.h> 
#include <stdio.h>

void comb_sort(int *arr, int n)
{
	float f=1.24733; 
	int step=n-1;
	int tmp=0;
	int k=1;
	while (step>=1)
	{
		for (int i=0; i+step<n;i++)
		{
			if (arr[i]>arr[i+step])
			{
				tmp=arr[i];
				arr[i]=arr[i+step];
				arr[i+step]=tmp;
			}
		}
		
		step=step/f;
	}
	step=1;
	while (k!=0)
	{
		k=0;
		for (int i=0; i+step<n;i++)
		{
			if (arr[i]>arr[i+step])
			{
				tmp=arr[i];
				arr[i]=arr[i+step];
				arr[i+step]=tmp;
				k=1;
			}
		}
	}
	
	
}


int main()
{
	int n=0;
	int buff=0;

	scanf("%i",&n);
	int *arr=malloc (n*sizeof(int));

	for (int i=0;i<n;i++)
		scanf("%i",&arr[i]);

	comb_sort(arr,n);

	for (int i=0;i<n;i++)
		printf("%i ",arr[i]);
	printf("\n");

	return 0;
}

