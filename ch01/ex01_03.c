#include <stdio.h>
#include <stdlib.h>

int main()
{
  int value;
    
    printf("请输入一个整数：");
    scanf("%d", &value);/* 输入一个整数 */ 

  if(value%2==0 || value%3==0)/* 判断是否为2或3的倍数 */ 
   if(value%6!=0)
   printf("符合所要的条件\n");
   else
   printf("不符合所要的条件\n");  
  else
   printf("不符合所要的条件\n");  

   system("pause");
   return 0;
}
