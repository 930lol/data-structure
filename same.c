#include <stdio.h>
int check(int a,int b);
int main()
{
	int n,c=0,i;
	printf("Enter the size of the array:");
	scanf("%d",&n);
	int f[n],s[n];
	printf("Enter the elements of the first array");
	for(i=0;i<n;i++)
	{
		scanf("%d",&f[i]);
	}
	printf("Enter the elements of the second array");
	for(i=0;i<n;i++)
	{
		scanf("%d",&s[i]);
	}
	for(i=0;i<n;i++)
	{
		if(check(f[i],s[i])==1)
		{
			c++;
		}
	}	
	printf("Number of equal item in both the array:%d",c);
}
int check(int a,int b)
{
	if(a==b)
	{
		return 1;
	}
	return 0;
}
