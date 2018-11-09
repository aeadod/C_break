#include <stdio.h>
#include <stdlib.h>

int main()
{

    int num[2][3][3]={{{33,45,67},
                       {23,71,56},
                       {55,38,66}},
                       {{21,9,15 },
                        {38,69,18},
                        {90,101,89}}};//声明三维数组 
    int i,j,k,min=num[0][0][0];//设置main为num数组的第一个元素 
    
    for(i=0;i<2;i++)
      for(j=0;j<3;j++)    
        for(k=0;k<3;k++)   
         if(min>=num[i][j][k])
           min=num[i][j][k]; //利用三层循环找出最小值 
    
    printf("最小值= %d\n",min);            
                           
	system("pause");
	return 0;
}
