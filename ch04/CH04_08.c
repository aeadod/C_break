#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define MAX 10			/*定义队列的大小*/

int main()
{
	int front,rear,val,queue[MAX]={0};
	char choice;
	front=rear=-1;
	while(rear<MAX-1 && choice!='e')
	{  
		printf("[a]表示加入一个数值 [d]表示取出一个数值 [e]表示跳出此程序: ");
		choice=getche();
		switch(choice)
		{
			case 'a':
				printf("\n[请输入数值]: ");
				scanf("%d",&val);
				rear++;
				queue[rear]=val;
				break;
			case 'd':
				if(rear>front)
				{  
					front++;
					printf("\n[取出数值为]: [%d]\n",queue[front]);
					queue[front]=0;
				}
				else
				{  
					printf("\n[队列已经空了]\n");
					exit(0);
				}
				break;
			default:
				printf("\n");
				break;
		}
	}
	printf("\n------------------------------------------\n");
	printf("[输出队列中的所有元素]:");
	
    if(rear==MAX-1) 
     printf("[队列已满]\n");
	else if (front>=rear)
	{
		printf("没有\n");
		printf("[队列已空]\n");
	}
	else
	{
        while (rear>front)
		{  
			front++;
			printf("[%d] ",queue[front]);
		}
		printf("\n");
		printf("------------------------------------------\n");
	}
	printf("\n");
	system("pause");
	return 0;
}
