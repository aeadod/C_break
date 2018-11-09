#include <stdio.h>
#include <stdlib.h>
struct Node/*二叉树节点的声明*/
{
    int value;/*节点数据*/
    struct Node *left_Node;/*指向左子树的指针*/
    struct Node *right_Node;/*指向左右子树的指针*/
};
typedef struct Node TreeNode;/*定义新的二叉树节点数据类型*/
typedef TreeNode *BinaryTree;/*定义新的二叉树链接数据类型*/
BinaryTree rootNode;//*二叉树根节点的指针 */
BinaryTree rootNode2;
/*将指定的值加入到二叉树中适当的节点*/
void Add_Node_To_Tree(int value)
{
    BinaryTree currentNode;
    BinaryTree newnode;
    int flag=0;/*用来记录是否插入新的节点*/
    newnode=(BinaryTree) malloc(sizeof(TreeNode));
    /*建立节点内容*/
    newnode->value=value;
    newnode->left_Node=NULL;
    newnode->right_Node=NULL;
    /*如果为空的二叉树,便将新的节点设定为根节点*/
    if(rootNode==NULL)
        rootNode=newnode;
    else 
    {
        currentNode=rootNode;/*指定一个指针指向根节点*/
        while(!flag)
          if (value<currentNode->value) 
          { /*在左子树*/
             if(currentNode->left_Node==NULL)
             {
                currentNode->left_Node=newnode;
                flag=1;
             }
             else
                currentNode=currentNode->left_Node;
          }
          else
          { /*在右子树*/
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
      if ( sequence[index]==0 ||index >= ArraySize )/*作为出口条件*/
         return NULL;
      else  { 
         tempNode=(BinaryTree)malloc(sizeof(TreeNode));
         tempNode->value=(int)sequence[index];
         tempNode->left_Node=NULL;
         tempNode->right_Node=NULL;
         /*建立左子树*/
         tempNode->left_Node = create(sequence, 2*index,ArraySize);
         /*建立右子树*/
         tempNode->right_Node = create(sequence, 2*index+1,ArraySize);
         return tempNode;
      }
}
/*preOrder(前序遍历)方法的子程序*/
void preOrder(BinaryTree node) 
{
      if ( node != NULL ) {
         printf("%c",(char)node->value);
         preOrder(node->left_Node);  
         preOrder(node->right_Node); 
      }
}
/*inOrder(中序遍历)方法的子程序*/
void inOrder(BinaryTree node) 
{
      if ( node != NULL ) {
         inOrder(node->left_Node);  
         printf("%c",(char)node->value);
         inOrder(node->right_Node); 
      }
}
/*postOrder(后序遍历)方法的子程序*/
void postOrder(BinaryTree node) 
{
      if ( node != NULL ) {
         postOrder(node->left_Node);  
         postOrder(node->right_Node); 
         printf("%c",(char)node->value);
      }
}
/*判断表达式如何运算的方法声明内容*/
int condition(char oprator, int num1, int num2)
{
      switch ( oprator ) {
         case '*': return ( num1 * num2 ); /*乘法请返回num1 * num2*/
         case '/': return ( num1 / num2 ); /*除法请返回num1 / num2*/
         case '+': return ( num1 + num2 ); /*加法请返回num1 + num2*/
         case '-': return ( num1 - num2 ); /*减法请返回num1 - num2*/
         case '%': return ( num1 % num2 ); /*取余数法请返回num1 % num2*/
      }
      return -1;
}
/*传入根节点,用来计算此二叉运算树的值*/
int answer(BinaryTree node) 
{
      int firstnumber = 0;       
      int secondnumber = 0;      
      /*递归调用的出口条件*/
      if ( node->left_Node == NULL && node->right_Node == NULL )
        /*将节点的值转换成数值后返回*/
        return node->value-48;
      else {
        firstnumber = answer(node->left_Node);/*计算左子树表达式的值*/
        secondnumber = answer(node->right_Node); /*计算右子树表达式的值*/
        return condition((char)node->value, firstnumber, secondnumber);
      }
   }
int main(void)
{
    /* 第一个表达式 */
    char information1[] = {' ','+','*','%','6','3','9','5' };
    /* 第二个表达式 */
    char information2[] = {' ','+','+','+','*','%','/','*',
                          '1','2','3','2','6','3','2','2' }; 
    rootNode=(BinaryTree) malloc(sizeof(TreeNode));
    rootNode2=(BinaryTree) malloc(sizeof(TreeNode));                      
    // create方法可以将二叉树的数组表示法转换成链接表示法
    rootNode = create(information1,1,8);
    printf("====二叉运算树数值运算范例 1: ====\n");
    printf("=================================\n");
    printf("===转换成中序表达式===:  ");
    inOrder(rootNode);     
    printf("\n===转换成前序表达式===:  ");
    preOrder(rootNode);    
    printf("\n===转换成后序表达式===:  ");
    postOrder(rootNode);   
    // 计算二叉树表达式的运算结果
    printf("\n此二叉运算树,经过计算后所得到的结果值: ");
    printf("%d",answer(rootNode));
    //建立第二棵二叉搜索树对象
    rootNode2 = create(information2,1,16);
    printf("\n\n");
    printf("====二叉运算树数值运算范例 2: ====\n");
    printf("=================================\n");
    printf("===转换成中序表达式===:  ");
    inOrder(rootNode2);     
    printf("\n===转换成前序表达式===:  ");
    preOrder(rootNode2);    
    printf("\n===转换成后序表达式===:  ");
    postOrder(rootNode2);   
    // 计算二叉树表达式的运算结果
    printf("\n此二叉运算树,经过计算后所得到的结果值: ");
    printf("%d",answer(rootNode2)); 
    printf("\n");
	system("pause");
	return 0;
}
