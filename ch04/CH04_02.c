#include <stdio.h>
#include <stdlib.h>

struct Node /*������ջ���ӽڵ�*/
{
   int data; /*��ջ���ݵ�����*/
   struct Node *next;/*��ջ������ָ����һ���ڵ�*/
};
typedef struct Node Stack_Node;/*�����ջ�нڵ��������*/
typedef Stack_Node *Linked_Stack;/*���������ջ��������*/
Linked_Stack top=NULL;/*ָ���ջ���˵�ָ��*/
int isEmpty();
int pop();
void push(int data);
/*�ж��Ƿ�Ϊ�ն�ջ*/

/*������*/
int main()
{
    int value;
    int i;
    
    do
     {
       printf("Ҫѹ���ջ,������1,����������0,ֹͣ����������-1: ");
       scanf("%d",&i);
       if(i==-1)
         break;
       else if (i==1)
       { 
        printf("������Ԫ��ֵ:"); 
        scanf("%d",&value);
        push(value);
       }
       else if(i==0)
        printf("������Ԫ��Ϊ%d\n",pop());
       } while(i!=-1);

    printf("============================\n");
    while(!isEmpty()) /*������½���Ӷ��˵���*/
       printf("��ջ������˳��Ϊ:%d\n",pop()); 
    printf("==========================\n");
    
    system("pause");      
    return 0; 
}
int isEmpty() 
{
    if(top==NULL) return 1;
    else return 0;
}
/*��ָ��������ѹ���ջ*/
void push(int data)
{
    Linked_Stack new_add_node; /*�¼���ڵ��ָ��*/
    /*�����½ڵ���ڴ�*/
    new_add_node=(Linked_Stack)malloc(sizeof(Stack_Node));
    new_add_node->data=data;/*�������ֵָ��Ϊ�ڵ������*/
    new_add_node->next=top;/*���½ڵ�ָ���ջ�Ķ���*/
    top=new_add_node;/*�½ڵ��Ϊ��ջ�Ķ���*/
}
/*�Ӷ�ջ��������*/
int pop()
{
    Linked_Stack ptr; /*ָ���ջ���˵�ָ��*/
    int temp;
    if(isEmpty()) /*�ж϶�ջ�Ƿ�Ϊ��,������򷵻�-1*/
    {
       printf("===��ǰΪ�ն�ջ===\n");
       return -1;
    }
    else
    {
        ptr=top;/*ָ���ջ�Ķ���*/
        top=top->next;/*����ջ���˵�ָ��ָ����һ���ڵ�*/
        temp=ptr->data;/*ȡ����ջ������*/
        free(ptr);/*���ڵ�ռ�õ��ڴ��ͷ�*/
        return temp;/*���Ӷ�ջ���������ݷ��ظ�������*/
    }
}
