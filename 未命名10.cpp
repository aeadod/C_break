#include<stdio.h>
int main()
{
	printf("爱情心理测试\n");
	printf("如果你的五个手指都破了，只能包一个，你要包哪个？\n");
	printf("1:大拇指2:食指3:中指4:无名指5:小指\n");
	
	int c=0;
	while(1)
	{
		printf("请选择：");
		scanf("%d",&c);
		fflush(stdin);//清除scanf的缓冲区，防止输入小数时陷入死循环。 
		if(c==1)
		printf("有人爱你一生");
		else if(c==2)
		printf("你爱别人一生");
		else if(c==3)
		printf("你爱很多人");
		else if(c==4)
		printf("你爱自己");
		else if(c==5)
	
		printf("很多人爱你"); 
		else if(c<=0)
		break;
		else 
		printf("输入错误");	
	
	 } 
}
