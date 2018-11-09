#include<stdio.h>
int main()
{
	for(int k=0;k<5;k++)
	{
		if(k==1||k==2||k==3)
		{
			printf("*");
			for(int j=0;j<28;j++)
			printf(" ");
			printf("*");
	
		}
	
	
		else for(int i=0;i<30;i++)
		{	
			printf("*");
		}
		printf("\n");
	}
}
