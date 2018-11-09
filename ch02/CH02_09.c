#include <stdio.h>
#include <stdlib.h>

int main()
{
   char Name[5][10]={"John",  
 					"Mary",    
 					"Wilson",
 					"Candy",
  				"Allen"};/* 字符串数组的声明 */ 
   int i;
   
   for(i=0;i<5;i++)		
      printf("Name[%d]=%s\n",i,Name[i]);    /* 输出字符串数组内容 */
   
   printf("\n");
   
   system("pause");
   return 0;
}
