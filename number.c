#include<stdio.h>
int main()
{
	int n;
	printf("Enter the navin number:");
	scanf("%d",&n);
	int r=check(n);
	printf("%d",r);
	return 0;
}
int check(int n)
{
	int r,s=0;
	int a=n;
	while(a!=0)
	{
		r=a%10;
		s=s+r;
		a=a/10;
	}
	if(n%s==0)
	{
		return n/s;
	}
	else 
	{
		return 0;
	}
}
