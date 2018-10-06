#include <stdio.h>
 
int main()
{
    int a,b,c;
a=0;
b=0;
c=0;
scanf("%d", &a);
do
{
scanf ("%d", &b);
if (b>=0)
c=c+1;
a=a-1;
} 
while (a!=0);
printf ("%d\n", c);
return 0;
}
