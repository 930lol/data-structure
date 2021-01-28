#include<stdio.h>
struct TreeHeight
{
	int feet;
	int inches;
} tree1[100];
int main()
{
	int n;
	printf("enter the no. of tree:");
	scanf("%d",&n);
	int r=tree(tree1,n);
	printf("%d",r);
	return 0;
}
int tree(struct TreeHeight tree1[],int n)
{
	if(n==0)
	{
		return -1;
	}
	else
	{
		int i,j,t;
		int a[10];
		for(i=0;i<n;i++)
		{
			scanf("%d",&tree1[i].feet);
			scanf("%d",&tree1[i].inches);
			a[i]=(tree1[i].feet*12)+tree1[i].inches;
		}
		for(i=0;i<n;i++)
		{
			for(j=i+1;j<n;j++)
			{
				if(a[i]>a[j])
				{
					t=a[i];
					a[i]=a[j];
					a[j]=t;
				}
			}
		}
		return a[n-1];
	}
}
