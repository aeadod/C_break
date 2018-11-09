#include <stdio.h>
#include <stdlib.h>

int main()
{
 char arr2[50];
 int i,sum;
 printf("请输入一个字符串:");
   gets(arr2); 

  for (i=0;i<50;i++)
   {
    if (arr2[i]=='\0')
    break; //如果是用户输入字符串的结尾就中断循环
    sum=i;//记录空字符前一个字符的索引
    }
   for (i=sum;i>=0;i--)     //将用户输入的字符串反向输出
   printf("%c",arr2[i]); 
   printf("\n");	
   
   system("pause");
   return 0;
 }
