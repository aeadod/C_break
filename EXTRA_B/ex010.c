#include<stdio.h>
/*函数原型声明*/
void fun(int, int);
int main(void)
{	
	int a,b;
 	a=10;
    b=15;
    /*输出主程序中的a,b值与地址*/
    printf("函数外:\na=%d,\tb=%d\n",a,b);
    printf("a的地址:%d, b的地址:%d\n",&a,&b);	
	/*调用函数*/
    fun(a,b);
    /*分隔用*/
	printf("==========================\n");
 	/*输出调用函数后的a,b值*/
  	printf("调用函数后: \na=%d,\tb=%d\n",a,b);
  	system("pause");
 	return 0;	
}
void fun(int a, int b)
{
	printf("==========================\n");
 	printf("函数内:\n");
 	printf("接收自变量:a=%d, b=%d\n",a,b);
 	printf("a的地址:%d, b的地址:%d\n",&a,&b);
 	/*重设函数内的a,b值*/
	a=20;
	b=30;
	printf("变更数值后:a=%d, b=%d\n",a,b);
}
