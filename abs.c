#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n,diff,num,c=0;
	scanf("%d",&n);
	int a[n],i;
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("enter number:");
	scanf("%d",&num);
	printf("enter diff check:");
	scanf("%d",&diff);
	for(i=0;i<n;i++)
	{
		if(abs(a[i]-num)<=diff)
		{
			c++;
		}
	}
	printf("%d",c, );
}
