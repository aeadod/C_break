#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int top=-1;
void push(int stack[],int MAX,int val)
{
	if(top>=MAX-1)
		printf("[��ջ�Ѿ�����]\n");
	else
	{
		top++;
		stack[top]=val;
	}
}
int pop(int stack[])
{
	if(top<0)
		printf("[��ջ�Ѿ�����]\n");
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
	char suit[4][10]={"�ݻ�","����","����","����"};
	int style;
	srand((unsigned)time(NULL));
	for (i=0;i<52;i++)
		card[i]=i+1;
	printf("[ϴ����...���Ժ�!]\n");
	while(k<30)
	{
		for(i=0;i<51;i++)
			for(j=i+1;j<52;j++)
				if(rand()%52==2)
					Swap(&card[i],&card[j]);//ϴ��
		k++;
	}
	i=0;
	while(i!=52)
	{
		push(stack,52,card[i]);//��52����ѹ���ջ
		i++;
	}
	printf("[��ʱ�뷢��]\n");
	printf("[��ʾ�����õ�����]\n");
 	printf("\t\t����\t ����\t ����\t �ϼ�\n");
	printf("=========================================================\n");
	while (top >=0)
	{  
		style = stack[top]/13;	//�����˿��ƵĻ�ɫ
		switch(style)			//�˿��ƻ�ɫ��Ӧ��ͼ��
		{
			case 0:			//÷��
				ascVal=0;
				break;
			case 1:			//����
				ascVal=1;
				break;
			case 2:			//����
				ascVal=2;
				break;
			case 3:			//����
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
