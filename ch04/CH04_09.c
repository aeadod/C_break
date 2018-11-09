#include <stdio.h>
int main(void)
{  
	int front,rear,val,queue[5]={0};
	front=rear=-1;
	while(rear<5&&val!=-1)
	{  
		printf("请输入一个值以加入队列，欲取出值请输入0。(结束输入-1)：");
		scanf("%d",&val);
		if(val==0)
		{  
			if(front==rear)
			{  
				printf("[队列已经空了]\n");
				break;
			}
			front++;
			if (front==5)
				front=0;
			printf("取出队列值 [%d]\n",queue[front]);
			queue[front]=0;
		}
		else if(val!=-1&&rear<5)
		{  
			if(rear+1==front||rear==4&&front<=0)
			{  
				printf("[队列已经满了]\n");
				break;
			}
			rear++;
			if(rear==5)
				rear=0;
			queue[rear]=val;
		}
	}
	printf("\n队列剩余数据：\n");
	if (front==rear)
		printf("队列已空!!\n");
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
