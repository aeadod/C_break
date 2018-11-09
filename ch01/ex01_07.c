#include <stdio.h> 
#include <stdlib.h> 

int main()
{
	 int Num1, Num2, TmpNum; 

	 printf("求解两个数的最大公约数:\n");
	 printf("请输入两个正整数:");
	 scanf("%d %d",&Num1,&Num2);

	 if (Num1 < Num2) 
	 {
		 TmpNum=Num1;
		 Num1=Num2;
		 Num2=TmpNum; /*大小数字对调*/ 
	 }

	 while (Num2 != 0)
	 { 
	 	TmpNum=Num1 % Num2;
		Num1=Num2; 
		Num2=TmpNum; /*辗转相除*/ 
	 }
	  
	  printf("最大公约数(GCD)是:%d\n",Num1); 
       
   system("pause");
   return 0;
}
