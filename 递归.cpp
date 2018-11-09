#include<windows.h>
#include<stdio.h> 
int func (int a){
	
	if(a==1||a==0)
	return 1;
	return func(a-1)*a;
}
int main()
{
	func(1000000) ;
	//递归很占栈区空间 
}
