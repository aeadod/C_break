#include <stdio.h> 
#include <stdlib.h> 

int main()
{
	 int Num1, Num2, TmpNum; 

	 printf("��������������Լ��:\n");
	 printf("����������������:");
	 scanf("%d %d",&Num1,&Num2);

	 if (Num1 < Num2) 
	 {
		 TmpNum=Num1;
		 Num1=Num2;
		 Num2=TmpNum; /*��С���ֶԵ�*/ 
	 }

	 while (Num2 != 0)
	 { 
	 	TmpNum=Num1 % Num2;
		Num1=Num2; 
		Num2=TmpNum; /*շת���*/ 
	 }
	  
	  printf("���Լ��(GCD)��:%d\n",Num1); 
       
   system("pause");
   return 0;
}
