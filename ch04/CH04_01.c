#include <stdio.h>
#include <stdlib.h>
#define MAXSTACK 100 /*��������ջ����*/

int stack[MAXSTACK];/*�������ڶ�ջ������*/
int top=-1;/*��ջ�Ķ���*/
/*�ж��Ƿ�Ϊ�ն�ջ*/
int isEmpty() 
{
    if(top==-1) return 1;
    else return 0;
}
/*��ָ��������ѹ���ջ*/
int push(int data)
{
    if(top>=MAXSTACK)
    {
       printf("��ջ����,�޷��ټ���\n");
       return 0; 
    }
    else
    {
       stack[++top]=data; /*������ѹ���ջ*/
       return 1;
        
    }
}
/*�Ӷ�ջȡ������*/
int pop()
{
    if(isEmpty()) /*�ж϶�ջ�Ƿ�Ϊ��,������򷵻�-1*/
       return -1;
    else
       return stack[top--]; /*�����ݴӶ�ջ����ȡ����,�ٽ���ջָ��������*/
}
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
    while(!isEmpty()) /*������½���Ӷ�ջ���˵���*/
       printf("��ջ������˳��Ϊ:%d\n",pop()); 
    printf("==========================\n");
    system("pause");      
    return 0; 
}
