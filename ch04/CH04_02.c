#include <stdio.h>
#include <stdlib.h>

struct Node /*声明堆栈链接节点*/
{
   int data; /*堆栈数据的声明*/
   struct Node *next;/*堆栈中用来指向下一个节点*/
};
typedef struct Node Stack_Node;/*定义堆栈中节点的新类型*/
typedef Stack_Node *Linked_Stack;/*定义链表堆栈的新类型*/
Linked_Stack top=NULL;/*指向堆栈顶端的指针*/
int isEmpty();
int pop();
void push(int data);
/*判断是否为空堆栈*/

/*主程序*/
int main()
{
    int value;
    int i;
    
    do
     {
       printf("要压入堆栈,请输入1,弹出则输入0,停止操作则输入-1: ");
       scanf("%d",&i);
       if(i==-1)
         break;
       else if (i==1)
       { 
        printf("请输入元素值:"); 
        scanf("%d",&value);
        push(value);
       }
       else if(i==0)
        printf("弹出的元素为%d\n",pop());
       } while(i!=-1);

    printf("============================\n");
    while(!isEmpty()) /*将数据陆续从顶端弹出*/
       printf("堆栈弹出的顺序为:%d\n",pop()); 
    printf("==========================\n");
    
    system("pause");      
    return 0; 
}
int isEmpty() 
{
    if(top==NULL) return 1;
    else return 0;
}
/*将指定的数据压入堆栈*/
void push(int data)
{
    Linked_Stack new_add_node; /*新加入节点的指针*/
    /*分配新节点的内存*/
    new_add_node=(Linked_Stack)malloc(sizeof(Stack_Node));
    new_add_node->data=data;/*将传入的值指定为节点的内容*/
    new_add_node->next=top;/*将新节点指向堆栈的顶端*/
    top=new_add_node;/*新节点成为堆栈的顶端*/
}
/*从堆栈弹出数据*/
int pop()
{
    Linked_Stack ptr; /*指向堆栈顶端的指针*/
    int temp;
    if(isEmpty()) /*判断堆栈是否为空,如果是则返回-1*/
    {
       printf("===当前为空堆栈===\n");
       return -1;
    }
    else
    {
        ptr=top;/*指向堆栈的顶端*/
        top=top->next;/*将堆栈顶端的指针指向下一个节点*/
        temp=ptr->data;/*取出堆栈的数据*/
        free(ptr);/*将节点占用的内存释放*/
        return temp;/*将从堆栈弹出的数据返回给主程序*/
    }
}
