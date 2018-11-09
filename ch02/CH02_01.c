#include <stdio.h>
#include <stdlib.h>

int main()
{
     int Score[5]={ 87,66,90,65,70 };    
      /* 定义整数数组Score[5], 并设置5项成绩 */
     int count, Total_Score=0;
     for (count=0; count < 5; count++)   /* 执行 for 循环读取学生的成绩 */
     {
       printf("第 %d 位学生的分数:%d\n", count+1,Score[count]);  
       Total_Score+=Score[count];  /* 从数组中读取分数计算总合 */
      }
      printf("-------------------------\n");
      printf("5位学生的总分:%d\n", Total_Score);  
     /* 输出成绩总分 */
     
     system("pause");
     return 0;
}
