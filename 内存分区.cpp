#include<stdio.h>
#include<stdlib.h>
void fun(){
	int a=0;
	printf("栈区%p\n",&a); 
}
int g=0;
int main(){
	fun(); 
	printf("静态存储区%p\n",&g);
	static int s ;
	printf("静态存储区%p\n",&s);
	 printf("代码区：%p\n",&fun);
	 	 printf("代码区：%p\n",fun);
	 int *b=(int *)malloc(20);
	 printf("堆区%p\n",b);
}
