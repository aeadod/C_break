#include <stdio.h>
#include <stdlib.h>

int main()
{    
   int i,j,sum,max=0,no=1;
   int sale[3][6]={{112,76,95,120,98,68},
                   {90,120,88,112,108,120},
                   {108,99,126,90,76,98}};
   

   for(i=0;i<3;i++)
   {
      sum=0;
      for(j=0;j<6;j++)
       sum+=sale[i][j];/* 加上每月的业绩金额 */ 
      printf("销售员%d的前半年销售总金额为 %d\n",i+1,sum); 
      printf("------------------------------------\n");  
   }
    
     for(i=0;i<6;i++)
   {
      sum=0;
      for(j=0;j<3;j++)
       sum+=sale[j][i];/* 加上每月的业绩金额 */ 
      printf("所有销售员%d月的销售总金额为 %d\n",i+1,sum); 
      printf("=====================================\n");  
   }  
   
   system("pause");
   return 0;
}
