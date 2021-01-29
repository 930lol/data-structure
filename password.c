#include<stdio.h>
#include<string.h>
int main()
{
	char ch[100];
	gets(ch);
	int n=strlen(ch);
	int r=check(ch,n);
	printf("%d",r);
	return 0;
}
int check(char ch[],int n)
{
	int i,c=0;
	if(n<4)
	{
		return 0;
	}
	else 
	{
		for(i=0;i<n;i++)
		{
			if(ch[i]>=97 && ch[i]<=122)
			{
				c++;
				break;
			}
		}
		for(i=0;i<n;i++)
		{
			 if(ch[i]>=65 && ch[i]<=90)
			{
				c++;
				break;
			}
		}
		for(i=0;i<n;i++)
		{
			 if(ch[i]>='0'&&ch[i]<='9')
			{
				c++;
				break;
			}
		}	
		for(i=0;i<n;i++)
		{
			 if(ch[i]=='_')
			{
				c++;
				break;
			}
		}
		for(i=0;i<n;i++)	
		{
			 if(ch[i]=='/')
			{
				return 0;
			}
			 if(ch[i]==' ')
			{
				return 0;
			}
		}		
	}
	if(ch[0]>='0'&&ch[0]<='9')
	{
		return 0;
	}
	else if(c>=3)
	{
		return 1;
		
	}
	else 
	{
		return 0;
	}
}
