#include <stdio.h>
int main(void)
{  
	int front,rear,val,queue[5]={0};
	front=rear=-1;
	while(rear<5&&val!=-1)
	{  
		printf("������һ��ֵ�Լ�����У���ȡ��ֵ������0��(��������-1)��");
		scanf("%d",&val);
		if(val==0)
		{  
			if(front==rear)
			{  
				printf("[�����Ѿ�����]\n");
				break;
			}
			front++;
			if (front==5)
				front=0;
			printf("ȡ������ֵ [%d]\n",queue[front]);
			queue[front]=0;
		}
		else if(val!=-1&&rear<5)
		{  
			if(rear+1==front||rear==4&&front<=0)
			{  
				printf("[�����Ѿ�����]\n");
				break;
			}
			rear++;
			if(rear==5)
				rear=0;
			queue[rear]=val;
		}
	}
	printf("\n����ʣ�����ݣ�\n");
	if (front==rear)
		printf("�����ѿ�!!\n");
	else 
	{ 
		while(front!=rear)
		{  
			front++;
			if (front==5)
				front=0;
			printf("[%d]",queue[front]);
			queue[front]=0;
		}
	}
	printf("\n");
	system("pause");
	return 0;
}
