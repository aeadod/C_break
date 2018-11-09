#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int top=-1;
void push(int stack[],int MAX,int val)
{
	if(top>=MAX-1)
		printf("[堆栈已经满了]\n");
	else
	{
		top++;
		stack[top]=val;
	}
}
int pop(int stack[])
{
	if(top<0)
		printf("[堆栈已经空了]\n");
	else
		top--;
	return stack[top];
}
void Swap(int* a,int* b)
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}

int main(void)
{  
	int card[52],stack[52]={0};
	int i,j,k=0, ascVal;
	char suit[4][10]={"草花","方块","红桃","黑桃"};
	int style;
	srand((unsigned)time(NULL));
	for (i=0;i<52;i++)
		card[i]=i+1;
	printf("[洗牌中...请稍后!]\n");
	while(k<30)
	{
		for(i=0;i<51;i++)
			for(j=i+1;j<52;j++)
				if(rand()%52==2)
					Swap(&card[i],&card[j]);//洗牌
		k++;
	}
	i=0;
	while(i!=52)
	{
		push(stack,52,card[i]);//将52张牌压入堆栈
		i++;
	}
	printf("[逆时针发牌]\n");
	printf("[显示各家拿到的牌]\n");
 	printf("\t\t东家\t 北家\t 西家\t 南家\n");
	printf("=========================================================\n");
	while (top >=0)
	{  
		style = stack[top]/13;	//计算扑克牌的花色
		switch(style)			//扑克牌花色对应的图标
		{
			case 0:			//梅花
				ascVal=0;
				break;
			case 1:			//方块
				ascVal=1;
				break;
			case 2:			//红心
				ascVal=2;
				break;
			case 3:			//黑桃
				ascVal=3;
				break;
		}
		printf("[%s\t%d]\t", suit[ascVal], stack[top]%13+1);
		if(top%4==0)
			printf("\n");
		top--;
	}
	system("pause");      
    return 0;
}
