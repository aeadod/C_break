/*����10! ��ֵ*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,sum=1;
    for (i=1;i<=10;i++)  /*����forѭ��*/
    {
    sum*=i;     /*sum=sum+i*/
    } 
    printf("i=%d\t sum=%d\n",i-1,sum);   /*��ӡ��i��sum��ֵ*/

    system("pause");
    return 0;
}

