#include<stdio.h>
#include<stdlib.h>
void fun(){
	int a=0;
	printf("ջ��%p\n",&a); 
}
int g=0;
int main(){
	fun(); 
	printf("��̬�洢��%p\n",&g);
	static int s ;
	printf("��̬�洢��%p\n",&s);
	 printf("��������%p\n",&fun);
	 	 printf("��������%p\n",fun);
	 int *b=(int *)malloc(20);
	 printf("����%p\n",b);
}
