#include<stdio.h>
int main()
{
	int num=0;
	scanf("%d",&num);
	switch(num)
	{
		case 1:
		case 4:
		case 5:
			printf("A");
			break;
		case 2:
		case 6:
			printf("B");
			break;
		case 3: 
			printf("C");
			break;
		
		default:
			printf("D");
			break;
		
	}
 } 
