#include <stdio.h>
#include <stdlib.h>

int main()
{
   char Name[5][10]={"John",  
 					"Mary",    
 					"Wilson",
 					"Candy",
  				"Allen"};/* �ַ������������ */ 
   int i;
   
   for(i=0;i<5;i++)		
      printf("Name[%d]=%s\n",i,Name[i]);    /* ����ַ����������� */
   
   printf("\n");
   
   system("pause");
   return 0;
}
