#include <stdio.h>
#include <stdlib.h>

int main()
{   
   int i=0;
   char str[50];
   
   printf("������һ���ַ���:");
   gets(str); 
   
   while(str[i]!='\0')
   {
      if(str[i]>=65 && str[i]<=90)
         str[i]+=32;/* ��д��Сд */ 
       else if (str[i]>=97 && str[i]<=122)
         str[i]-=32;/* Сд����д */ 
      i++;      
   }
   printf("��Сдת��������ַ���=%s\n",str); 
	
   system("pause");
   return 0;
}


