#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define MAX 10			/*������еĴ�С*/

int main()
{
	int front,rear,val,queue[MAX]={0};
	char choice;
	front=rear=-1;
	while(rear<MAX-1 && choice!='e')
	{  
		printf("[a]��ʾ����һ����ֵ [d]��ʾȡ��һ����ֵ [e]��ʾ�����˳���: ");
		choice=getche();
		switch(choice)
		{
			case 'a':
				printf("\n[��������ֵ]: ");
				scanf("%d",&val);
				rear++;
				queue[rear]=val;
				break;
			case 'd':
				if(rear>front)
				{  
					front++;
					printf("\n[ȡ����ֵΪ]: [%d]\n",queue[front]);
					queue[front]=0;
				}
				else
				{  
					printf("\n[�����Ѿ�����]\n");
					exit(0);
				}
				break;
			default:
				printf("\n");
				break;
		}
	}
	printf("\n------------------------------------------\n");
	printf("[��������е�����Ԫ��]:");
	
    if(rear==MAX-1) 
     printf("[��������]\n");
	else if (front>=rear)
	{
		printf("û��\n");
		printf("[�����ѿ�]\n");
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
