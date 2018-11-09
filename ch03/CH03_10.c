#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

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
     return ptr;
}

link insertnode(link head,link after,int num,int score,char name[10])   
{  
    link InsertNode;
    InsertNode=(link)malloc(sizeof(node));
    link CurNode=NULL;
    InsertNode->num=num;
    InsertNode->score=score;
    strcpy(InsertNode->name,name);
    InsertNode->next=NULL;
    if(InsertNode==NULL)
    {
       printf("内存分配失败\n");
       return NULL;
    }
    else
    {
        if(head==NULL)/*链表是空的*/
        {
           head=InsertNode;
           InsertNode->next=head;
           return head;
        }              
        else
        {    
            
            if(after->next==head) /*新增节点在链表头部的位置*/
            {  
               /*(1)将新增节点的指针指向链表头*/
               InsertNode->next=head;
               CurNode=head;
               while(CurNode->next!=head)
                  CurNode=CurNode->next;
               /*(2)找到链表末尾后将它的指针指向新增节点*/
               CurNode->next=InsertNode;
               /*(3)将链表头指向新增节点*/
               head=InsertNode;
               return head;
             }
            else /*新增节点在链表头以外的地方*/
            {
               /*(1)将新增节点的指针指向after的下一个节点*/  
               InsertNode->next=after->next;
               /*(2)将节点after的指针指向新增节点*/ 
               after->next=InsertNode;
               return head; 
            }
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
	head=(link)malloc(sizeof(node));     /*建立串行首*/
	if(!head)
	{  
		printf("Error!! 内存配置失败!!\n");
		exit(1);
	}
	head->num=data[0][0];
	for (j=0;j<10;j++)
		head->name[j]=namedata[0][j];
	head->score=data[0][1];
	head->next=NULL;
	ptr=head;
	for(i=1;i<12;i++)                   /*建立串行*/
	{  
		newnode=(link)malloc(sizeof(node));
		newnode->num=data[i][0];
		for (j=0;j<10;j++)
			newnode->name[j]=namedata[i][j];
		newnode->score=data[i][1];
		newnode->next=NULL;
		ptr->next=newnode;/*将前一个节点指向新建立的节点*/ 
		ptr=newnode; /*新节点成为前一个节点*/ 
	}
	newnode->next=head;/*将最后一个节点指向头节点就成了环状链结*/ 
	while(1)
	{  
		printf("请输入要插入其后的员工编号,如输入的编号不在此串行中,\n");
        printf("新输入的员工节点将视为此串行的第一个节点,要结束插入过程,请输入-1：");
		scanf("%d",&position);
		if(position==-1)    /*循环中断条件*/
			break;
		else
		{  
			ptr=findnode(head,position);
			printf("请输入新插入的员工编号：");
			scanf("%d",&new_num);
			printf("请输入新插入的员工薪水：");
			scanf("%d",&new_score);
			printf("请输入新插入的员工姓名：");
			scanf("%s",new_name);
			head=insertnode(head,ptr,new_num,new_score,new_name);
		}
	}
	ptr=head;/*指向串行的开头*/
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

