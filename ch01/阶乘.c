/*�õݹ麯���� n�׳˵�ֵ*/
#include <stdio.h>
#include <stdlib.h>

int factorial(int);  /*����ԭ��*/
int main()
{  
    int i,n;
    
    printf("������׳���:"); 
    scanf("%d",&n);
    
    for (i=0;i<=n;i++)
     printf("%d !ֵΪ %3d\n", i,factorial(i));
    
    system("pause");
    return 0;
}

int factorial(int i)
{  
    int sum;
     if(i == 0)/* �ݹ���ֹ������ */
      return(1);
     else
     sum = i * factorial(i-1); /* sum=n*(n-1)!����ֱ�Ӻ��б��� */
     return sum;
}
