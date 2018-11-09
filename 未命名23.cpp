#include<stdio.h>
void swap1(int *x,int *y){
	int *temp;
	*temp=*x;
	*x=*y;
	*y=*temp;
}
void swap2(int *p,int *q){
	int *temp;
	temp=p;
	p=q;
	q=temp;
}

int main()
	{
		int a=2,b=3;
		swap1(&a,&b);
		printf("%d %d",a,b);
	}
