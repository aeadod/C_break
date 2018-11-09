#include <stdio.h>
#include <stdlib.h>
#define MAX 50
char infix_q[MAX]; 
int compare(char stack_o, char infix_o); 
void infix_to_postfix();    
/*运算符优先权的比较，若输入运算符小于堆栈中的运算符*/
/*，则返回值为1，否则为0                          */

/*主函数声明*/
int main () 		
{ 
    int i=0;
    for (i=0; i<MAX; i++)
	infix_q[i]='\0';	
	printf("\t------------------------------------------\n");
	printf("\t中序表达式转成后序表达式\n");
    printf("\t可以使用的运算符包括:^,*,+,-,/,(,)等 \n");
    printf("\t------------------------------------------\n");
    printf("\t请开始输入中序表达式: ");
    infix_to_postfix();
    printf("\n");
    printf("\t--------------------------------------------\n");
    system("pause");      
    return 0; 
}
int compare(char stack_o, char infix_o)
{
/*在中序表示法的队列和暂存堆栈中，运算符的优先级表，*/
/*其优先权值为INDEX/2                               */
    char infix_priority[9] ; 
	char stack_priority[8] ;
	int index_s=0, index_i=0;
	infix_priority[0]='q';infix_priority[1]=')';
	infix_priority[2]='+';infix_priority[3]='-';
	infix_priority[4]='*';infix_priority[5]='/';
	infix_priority[6]='^';infix_priority[7]=' ';
	infix_priority[8]='(';      
	stack_priority[0]='q';stack_priority[1]='(';
	stack_priority[2]='+';stack_priority[3]='-';
	stack_priority[4]='*';stack_priority[5]='/';
	stack_priority[6]='^';stack_priority[7]=' ';
	while (stack_priority[index_s] != stack_o)
		index_s++;
	while (infix_priority[index_i] != infix_o)
		index_i++;
	return ((int)(index_s/2) >= (int)(index_i/2) ? 1 : 0);
}
void infix_to_postfix()
{
	int rear=0, top=0, flag=0,i=0;
	char stack_t[MAX];  
	for (i=0; i<MAX; i++)
			stack_t[i]='\0';
	    gets(infix_q);
	    i=0;
	    while(infix_q[i]!='\0') 
	    {
          i++;
          rear++;
        }
		infix_q[rear] = 'q';  
		printf("\t后序表示法 : ");
		stack_t[top]  = 'q';  
		for (flag = 0; flag <= rear; flag++)\
        {		
			switch (infix_q[flag]) 
            {
				/*输入为)，则输出堆栈内运算符，直到堆栈内为(*/
				case ')':
					while(stack_t[top]!='(') 			      
						printf("%c",stack_t[top--]);				   
					top--;
					break;
				/*输入为q，则将堆栈内还未输出的运算符输出*/
				case 'q':
					while(stack_t[top]!='q')
						printf("%c",stack_t[top--]);
					break;
				/*输入为运算符，若小于TOP在堆栈中所指运算符，*/
                /*则将堆栈所指运算符输出，若大于等于TOP在堆栈*/
                /*中所指运算符，则将输入运算符压入堆栈     */
				case '(':
				case '^':
				case '*':
				case '/':
				case '+':
				case '-': 
					while (compare(stack_t[top], infix_q[flag])==1)                       
						printf("%c",stack_t[top--]);			
					stack_t[++top] = infix_q[flag];
					break;
				/*输入为操作数，则直接输出*/
				default :
					printf("%c",infix_q[flag]);
					break;
			}
		}
}
