#include<stdio.h>
/*加上取址运算符的函数原型声明*/
void fun(int*, int*);
int main(void)
{	
	int a,b;
 	a=10;
    b=15;
    printf("函数外:\na=%d,\tb=%d\n",a,b);
    printf("a的地址:%d, b的地址:%d\n",&a,&b);
    /*自变量需加上&取址运算符*/	
	fun(&a,&b);
	printf("==========================\n");
	printf("调用函数后: \na=%d,\tb=%d\n",a,b);
	system("pause");
	return 0;	
}
void fun(int *a, int *b)
{
	printf("==========================\n");
 	printf("函数内:\n");
 	/*此时的*a与*b代表的是地址上的数值*/
	printf("接收自变量:a=%d,\tb=%d\n",*a,*b);
	/*输出函数内a与b的地址*/
	printf("a的地址:%d, b的地址:%d\n",a,b);
	*a=20;
	*b=30;	
	printf("变更数值后:a=%d, b=%d\n",*a,*b);
}
