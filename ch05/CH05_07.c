#include <stdio.h>
#include <stdlib.h>
struct Node/*�������ڵ������*/
{
    int value;/*�ڵ�����*/
    struct Node *left_Node;/*ָ����������ָ��*/
    struct Node *right_Node;/*ָ������������ָ��*/
};
typedef struct Node TreeNode;/*�����µĶ������ڵ���������*/
typedef TreeNode *BinaryTree;/*�����µĶ�����������������*/
BinaryTree rootNode;//*���������ڵ��ָ�� */
BinaryTree rootNode2;
/*��ָ����ֵ���뵽���������ʵ��Ľڵ�*/
void Add_Node_To_Tree(int value)
{
    BinaryTree currentNode;
    BinaryTree newnode;
    int flag=0;/*������¼�Ƿ�����µĽڵ�*/
    newnode=(BinaryTree) malloc(sizeof(TreeNode));
    /*�����ڵ�����*/
    newnode->value=value;
    newnode->left_Node=NULL;
    newnode->right_Node=NULL;
    /*���Ϊ�յĶ�����,�㽫�µĽڵ��趨Ϊ���ڵ�*/
    if(rootNode==NULL)
        rootNode=newnode;
    else 
    {
        currentNode=rootNode;/*ָ��һ��ָ��ָ����ڵ�*/
        while(!flag)
          if (value<currentNode->value) 
          { /*��������*/
             if(currentNode->left_Node==NULL)
             {
                currentNode->left_Node=newnode;
                flag=1;
             }
             else
                currentNode=currentNode->left_Node;
          }
          else
          { /*��������*/
             if(currentNode->right_Node==NULL) 
             {
                currentNode->right_Node=newnode;
                flag=1;
             }
             else
                currentNode=currentNode->right_Node;
          }
     }
}
BinaryTree create(char sequence[100],int index,int ArraySize)
{
      BinaryTree tempNode;            
      if ( sequence[index]==0 ||index >= ArraySize )/*��Ϊ��������*/
         return NULL;
      else  { 
         tempNode=(BinaryTree)malloc(sizeof(TreeNode));
         tempNode->value=(int)sequence[index];
         tempNode->left_Node=NULL;
         tempNode->right_Node=NULL;
         /*����������*/
         tempNode->left_Node = create(sequence, 2*index,ArraySize);
         /*����������*/
         tempNode->right_Node = create(sequence, 2*index+1,ArraySize);
         return tempNode;
      }
}
/*preOrder(ǰ�����)�������ӳ���*/
void preOrder(BinaryTree node) 
{
      if ( node != NULL ) {
         printf("%c",(char)node->value);
         preOrder(node->left_Node);  
         preOrder(node->right_Node); 
      }
}
/*inOrder(�������)�������ӳ���*/
void inOrder(BinaryTree node) 
{
      if ( node != NULL ) {
         inOrder(node->left_Node);  
         printf("%c",(char)node->value);
         inOrder(node->right_Node); 
      }
}
/*postOrder(�������)�������ӳ���*/
void postOrder(BinaryTree node) 
{
      if ( node != NULL ) {
         postOrder(node->left_Node);  
         postOrder(node->right_Node); 
         printf("%c",(char)node->value);
      }
}
/*�жϱ��ʽ�������ķ�����������*/
int condition(char oprator, int num1, int num2)
{
      switch ( oprator ) {
         case '*': return ( num1 * num2 ); /*�˷��뷵��num1 * num2*/
         case '/': return ( num1 / num2 ); /*�����뷵��num1 / num2*/
         case '+': return ( num1 + num2 ); /*�ӷ��뷵��num1 + num2*/
         case '-': return ( num1 - num2 ); /*�����뷵��num1 - num2*/
         case '%': return ( num1 % num2 ); /*ȡ�������뷵��num1 % num2*/
      }
      return -1;
}
/*������ڵ�,��������˶�����������ֵ*/
int answer(BinaryTree node) 
{
      int firstnumber = 0;       
      int secondnumber = 0;      
      /*�ݹ���õĳ�������*/
      if ( node->left_Node == NULL && node->right_Node == NULL )
        /*���ڵ��ֵת������ֵ�󷵻�*/
        return node->value-48;
      else {
        firstnumber = answer(node->left_Node);/*�������������ʽ��ֵ*/
        secondnumber = answer(node->right_Node); /*�������������ʽ��ֵ*/
        return condition((char)node->value, firstnumber, secondnumber);
      }
   }
int main(void)
{
    /* ��һ�����ʽ */
    char information1[] = {' ','+','*','%','6','3','9','5' };
    /* �ڶ������ʽ */
    char information2[] = {' ','+','+','+','*','%','/','*',
                          '1','2','3','2','6','3','2','2' }; 
    rootNode=(BinaryTree) malloc(sizeof(TreeNode));
    rootNode2=(BinaryTree) malloc(sizeof(TreeNode));                      
    // create�������Խ��������������ʾ��ת�������ӱ�ʾ��
    rootNode = create(information1,1,8);
    printf("====������������ֵ���㷶�� 1: ====\n");
    printf("=================================\n");
    printf("===ת����������ʽ===:  ");
    inOrder(rootNode);     
    printf("\n===ת����ǰ����ʽ===:  ");
    preOrder(rootNode);    
    printf("\n===ת���ɺ�����ʽ===:  ");
    postOrder(rootNode);   
    // ������������ʽ��������
    printf("\n�˶���������,������������õ��Ľ��ֵ: ");
    printf("%d",answer(rootNode));
    //�����ڶ��ö�������������
    rootNode2 = create(information2,1,16);
    printf("\n\n");
    printf("====������������ֵ���㷶�� 2: ====\n");
    printf("=================================\n");
    printf("===ת����������ʽ===:  ");
    inOrder(rootNode2);     
    printf("\n===ת����ǰ����ʽ===:  ");
    preOrder(rootNode2);    
    printf("\n===ת���ɺ�����ʽ===:  ");
    postOrder(rootNode2);   
    // ������������ʽ��������
    printf("\n�˶���������,������������õ��Ľ��ֵ: ");
    printf("%d",answer(rootNode2)); 
    printf("\n");
	system("pause");
	return 0;
}
