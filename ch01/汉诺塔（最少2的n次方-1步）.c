#include <stdio.h>
#include <stdlib.h>

void hanoi(int, int, int, int);	/* 函数原型 */

int main()
{  
    int j;
    printf("请输入盘子数量：");
    scanf("%d", &j);
    hanoi(j,1, 2, 3);
    
    system("pause");
    return 0;
 }
 
 void hanoi(int n, int p1, int p2, int p3)
 {  
   if (n==1) /* 递归出口 */ 
    printf("盘子从 %d 移到 %d\n", p1, p3);
     else
     {  
         hanoi(n-1, p1, p3, p2);
         printf("盘子从 %d 移到 %d\n", p1, p3);
         hanoi(n-1, p2, p1, p3);
   	  }
 }
