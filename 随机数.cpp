#include<stdio.h>
#include<stdlib.h>
#include<time.h>
//产生任意区间【a，b）的随机数：
//rand（）%（b-a）+a; 
int main()
{
	srand(time(0));//time(0)表示当前时间，srand设置随机数种子。 
	int input; 
	
	int num=rand()%100;
	while(1)
	{
		printf("请输入1-100的数字：");
		scanf("%d",&input);
		fflush(stdin);
		if(input>num) 
		printf("dale");
		else if (input<num)
		printf("xiaole");
		else
		{
		
		printf("dui");
		break;
		}
	
	
	
	}
}
