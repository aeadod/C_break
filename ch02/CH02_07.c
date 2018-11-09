#include <stdio.h>
#include <stdlib.h>

int main()
{   
   int i=0;
   char str[50];
   
   printf("请输入一个字符串:");
   gets(str); 
   
   while(str[i]!='\0')
   {
      if(str[i]>=65 && str[i]<=90)
         str[i]+=32;/* 大写换小写 */ 
       else if (str[i]>=97 && str[i]<=122)
         str[i]-=32;/* 小写换大写 */ 
      i++;      
   }
   printf("大小写转换后的新字符串=%s\n",str); 
	
   system("pause");
   return 0;
}


