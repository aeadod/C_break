//看看女朋友值多少钱
#include<stdio.h>
int main()
{
	int y,temp,w,h,p=1000;
	printf("请输入他的身高和体重。\n");
	scanf("%d,%d",&h,&w);
	if(h>=170)
	p=p+(h-170)*100;
	if(h<=160)
	p=p-(160-h)*100;
	printf("他会唱歌吗,输入1为会，0为不会。\n");
	scanf("%d",&temp);
	if(temp==1)
	p=p+100;
	printf("他会跳舞吗,输入1为会，0为不会。\n");
	scanf("%d",&temp);
	if(temp==1)
	p=p+100;
	printf("他留长发吗,输入1为会，0为不会。\n");
	scanf("%d",&temp);
	if(temp==1)
	p=p+150;
	if(w>=110)
	p=p-(w-110)*10;
	if(w<=100)
	p=p-(100-w)*10;
	printf("近视多少度？\n");
	scanf("%d",&temp);
	if(temp>=300)
	p=p-temp/100*100;
 	printf("谈过几次恋爱？\n");
 	scanf("%d",&temp);
 	if(temp==0)
 	p+=100;
 	else
 	p=p-temp*100;
 	printf("几岁了？\n");
 	scanf("%d",&y);
 	if(y>23)
 	p=p-(y-23)*100;
 	printf("你女朋友价格：%d元。\n",p);
 	if(p<=1000)
 	printf("gun");
 	else if(p>1000&&p<=1500)
	printf("标准");
	else if(p>1500&&p<=2000)
	printf("精品");
	else
	printf ("赶紧娶把"); 
 } 
