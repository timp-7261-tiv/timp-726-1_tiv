#include <stdlib.h> 
#include <stdio.h>

void shell_sort(int *arr, int n)
{
	int tmp=0;
	int d=n/2;
	int j=0;
	while (d>0)
	{
		for (int i=0; i+d<=n;i++)
		{
			tmp=arr[i+d];
			for (j=i;j>=0;j-=d)
			{
				if (tmp<arr[j])
					arr[j+d]=arr[j];
				else
					break;
			}
			arr[j+d]=tmp;
		}
		
		for (int i=0;i<n;i++)
		printf("%i ",arr[i]);
		printf("\n");
		printf("\n");
		d=d/2;
		
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

	shell_sort(arr,n);

	for (int i=0;i<n;i++)
		printf("%i ",arr[i]);
	printf("\n");

	return 0;
}

