#include <stdio.h>
#include <stdlib.h>

int main()
{
   int i,a,n,sum=1;
   printf("����a="); 
   scanf("%d",&a);;
   printf("ָ��n="); 
   scanf("%d",&n);
   for(i=1;i<=n;i++)
   sum*=a;
   printf("%d\n",sum);
    
   system("pause");
   return 0;
   }
