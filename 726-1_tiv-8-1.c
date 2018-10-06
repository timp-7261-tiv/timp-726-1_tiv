#include <stdlib.h> 
#include <stdio.h>

void hoar_qs (int *arr, int left, int right)
{
	int i=left;
	int j=right;
	int tmp=0;
	int base=arr[(left+right)/2];
	
	do {
		while (arr[i]<base) i++;
		while (arr[j]>base) j--;
		
		if (i<=j)
		{
			if (i<j)
			{
				tmp=arr[i];
				arr[i]=arr[j];
				arr[j]=tmp;
			}
			i++;
			j--;
		}
	} while (i<=j);
	
	if (i<right)
		hoar_qs(arr, i, right);
	if (left<j)
		hoar_qs(arr, left, j);
}

int main()
{
	int n=0;

	scanf("%i",&n);
	int *arr=malloc (n*sizeof(int));

	for (int i=0;i<n;i++)
		scanf("%i",&arr[i]);

	hoar_qs(arr,0,n-1);

	for (int i=0;i<n;i++)
		printf("%i ",arr[i]);
	printf("\n");

	return 0;
}


