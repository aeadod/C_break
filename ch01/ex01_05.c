#include <stdio.h>
#include <stdlib.h>

int main()
{
   int i,a,n,sum=1;
   printf("µ×Êýa="); 
   scanf("%d",&a);;
   printf("Ö¸Êýn="); 
   scanf("%d",&n);
   for(i=1;i<=n;i++)
   sum*=a;
   printf("%d\n",sum);
    
   system("pause");
   return 0;
   }
