#include <stdio.h>
#include <stdlib.h>

int main()
{
  int value;
    
    printf("������һ��������");
    scanf("%d", &value);/* ����һ������ */ 

  if(value%2==0 || value%3==0)/* �ж��Ƿ�Ϊ2��3�ı��� */ 
   if(value%6!=0)
   printf("������Ҫ������\n");
   else
   printf("��������Ҫ������\n");  
  else
   printf("��������Ҫ������\n");  

   system("pause");
   return 0;
}
