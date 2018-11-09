#include<stdio.h>
//带默认参数时只能写在参数表最右边，调用时可省略 。 
int cp(int i,int w=20)
{
	return (i+w)*2;
}
int main()
{
	int p1=cp(10,20);
	int p2=cp(10);
	printf("%d %d",p1,p2);
	
}
