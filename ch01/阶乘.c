/*用递归函数求 n阶乘的值*/
#include <stdio.h>
#include <stdlib.h>

int factorial(int);  /*函数原型*/
int main()
{  
    int i,n;
    
    printf("请输入阶乘数:"); 
    scanf("%d",&n);
    
    for (i=0;i<=n;i++)
     printf("%d !值为 %3d\n", i,factorial(i));
    
    system("pause");
    return 0;
}

int factorial(int i)
{  
    int sum;
     if(i == 0)/* 递归终止的条件 */
      return(1);
     else
     sum = i * factorial(i-1); /* sum=n*(n-1)!所以直接呼叫本身 */
     return sum;
}
