#include<stdio.h>
int main()
{
	int sum=0;
	for(int i=1;i<=20;i++)
	{
		for(int j=1;j<=i;j++)
		sum+=j;
	}
	printf("%d",sum);
}
