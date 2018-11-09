/*计算10! 的值*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,sum=1;
    for (i=1;i<=10;i++)  /*定义for循环*/
    {
    sum*=i;     /*sum=sum+i*/
    } 
    printf("i=%d\t sum=%d\n",i-1,sum);   /*打印出i和sum的值*/

    system("pause");
    return 0;
}

