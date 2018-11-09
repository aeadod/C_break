#include <stdio.h>
#include <stdlib.h>

struct employee
{  
	int num,score;
	char name[10];
	struct employee *next;
};
typedef struct employee node;
typedef node *link;

link findnode(link head,int num)
{
     link ptr;
     ptr=head;
     while(ptr->next!=head)
     {
        if(ptr->num==num)
           return ptr;
        ptr=ptr->next;
     }
     ptr=NULL;   
     return ptr;
}

link deletenode(link head,link del)   
{
     link CurNode=NULL;  
     link PreNode=NULL;
     link TailNode=NULL;
     if(head==NULL)
     {
        printf("[环状链表已经空了]");
        return NULL;
     }
     else
     {
         if(del==head) /*要删除的节点是链表头*/
         {
            CurNode=head;
            while(CurNode->next!=head)
               CurNode=CurNode->next;
               /*找到最后一个节点并记录下来*/
               TailNode=CurNode;
               /*(1)将链表头移到下一个节点*/
               head=head->next;
               /*(2)将链表最后一个节点的指针指向新的链表头*/
               TailNode->next=head;
               return head;
         } 
         else /*要删除的节点不是链表头部*/
         {
              CurNode=head;
              while(CurNode->next!=del)
                 CurNode=CurNode->next;
              /*(1)找到要删除节点的前一个节点并记录下来*/
              PreNode=CurNode;
              /*要删除的节点*/
              CurNode=CurNode->next;
              /*(2)将要删除节点的前一个指针指向要删除节点的下一个节点*/
              PreNode->next=CurNode->next;
              return head;
         }
     }
}


int main()
{  
	link head,ptr,newnode;
	int new_num, new_score;
	char new_name[10];
	int i,j,position=0,find;
	char namedata[12][10]={{"Allen"},{"Scott"},{"Marry"},{"John"},{"Mark"},{"Ricky"},{"Lisa"},{"Jasica"},{"Hanson"},{"Amy"},{"Bob"},{"Jack"}};
	int data[12][2]={ 1001,32367,1002,24388,1003,27556,1007,31299,
    1012,42660,1014,25676,1018,44145,1043,52182,1031,32769,1037,21100,1041,32196,1046,25776};
	printf("员工编号 薪水 员工编号 薪水 员工编号 薪水 员工编号 薪水\n");
	printf("-------------------------------------------------------\n");
	
	for(i=0;i<3;i++)
	{  
		for (j=0;j<4;j++)
			printf("[%2d] [%3d]  ",data[j*3+i][0],data[j*3+i][1]);
		printf("\n");
	}
	head=(link)malloc(sizeof(node));     /*建立链表头*/
	if(!head)
	{  
		printf("Error!! 内存分配失败!!\n");
		exit(1);
	}
	head->num=data[0][0];
	for (j=0;j<10;j++)
		head->name[j]=namedata[0][j];
	head->score=data[0][1];
	head->num=data[0][0];
	head->next=NULL;
	ptr=head;
	for(i=1;i<12;i++)                   /*建立链表*/
	{  
		newnode=(link)malloc(sizeof(node));
		newnode->num=data[i][0];
		for (j=0;j<10;j++)
			newnode->name[j]=namedata[i][j];
		newnode->score=data[i][1];
		newnode->num=data[i][0];
		newnode->next=NULL;
		ptr->next=newnode;/*将前一个节点指向新建立的节点*/ 
		ptr=newnode; /*新节点成为前一个节点*/ 
	}
	newnode->next=head;/*将最后一个节点指向头节点就成了环状链表*/ 
	while(1)
	{  
		printf("\n请输入要删除的员工编号,要结束插入过程,请输入-1：");
		scanf("%d",&position);
		if(position==-1)    /*循环中断条件*/
			break;
		else
		{  
	
            ptr=findnode(head,position);
            if(ptr==NULL)
             {
              printf("-----------------------\n");
              printf("链表中没这个节点....\n");
              break;
              } 
            else
			 {
             head=deletenode(head,ptr);
			 printf("已删除第 %d 号员工 姓名：%s 薪资:%d\n",ptr->num,ptr->name,ptr->score);
             }
		}
	}
	 ptr=head;/*指向链表的开头*/
     printf("\n\t员工编号    姓名\t薪水\n");         
     printf("\t==============================\n");

	do
	{
	    printf("\t[%2d]\t[ %-10s]\t[%3d]\n",ptr->num,ptr->name,ptr->score);
		ptr=ptr->next;/*指向下一个节点*/
    } while(head!=ptr && head!=head->next);
	system("pause");
	return 0;
}
