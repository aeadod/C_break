#include <stdio.h> 
#include <stdlib.h>  
                     
int main()
{
     int n;
     
     printf("������һ������:"); 
     scanf("%d",&n);
     while (n!=0)
     {
     printf("%d",n%10);
     n/=10;
      }
   	printf("\n");
	system("pause");
    return 0;                                      
}
