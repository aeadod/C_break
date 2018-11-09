#include<stdio.h>
int main()
{
	int n=0;
	scanf("%d",&n);
	if(n%3==0)
	{
		if(n%5==0)
		{
			if(n%7==0)
			
				printf("能被3.5.7整除"); 
			
			else
				printf("能被3.5整除"); 
		}
		else if(n%7==0)
		printf("能被3.7整除"); 
		else 
		printf("能被三整除");	
		}
		else
		if(n%5==0){
			if(n%7==0){
				printf("能被5.7整除"); 
			}
			else printf("能被5整除"); 
		}
		else if(n%7==0)
		printf("能被7整除");
		else 
		printf("不行"); 
}
