//����Ů����ֵ����Ǯ
#include<stdio.h>
int main()
{
	int y,temp,w,h,p=1000;
	printf("������������ߺ����ء�\n");
	scanf("%d,%d",&h,&w);
	if(h>=170)
	p=p+(h-170)*100;
	if(h<=160)
	p=p-(160-h)*100;
	printf("���ᳪ����,����1Ϊ�ᣬ0Ϊ���ᡣ\n");
	scanf("%d",&temp);
	if(temp==1)
	p=p+100;
	printf("����������,����1Ϊ�ᣬ0Ϊ���ᡣ\n");
	scanf("%d",&temp);
	if(temp==1)
	p=p+100;
	printf("����������,����1Ϊ�ᣬ0Ϊ���ᡣ\n");
	scanf("%d",&temp);
	if(temp==1)
	p=p+150;
	if(w>=110)
	p=p-(w-110)*10;
	if(w<=100)
	p=p-(100-w)*10;
	printf("���Ӷ��ٶȣ�\n");
	scanf("%d",&temp);
	if(temp>=300)
	p=p-temp/100*100;
 	printf("̸������������\n");
 	scanf("%d",&temp);
 	if(temp==0)
 	p+=100;
 	else
 	p=p-temp*100;
 	printf("�����ˣ�\n");
 	scanf("%d",&y);
 	if(y>23)
 	p=p-(y-23)*100;
 	printf("��Ů���Ѽ۸�%dԪ��\n",p);
 	if(p<=1000)
 	printf("gun");
 	else if(p>1000&&p<=1500)
	printf("��׼");
	else if(p>1500&&p<=2000)
	printf("��Ʒ");
	else
	printf ("�Ͻ�Ȣ��"); 
 } 
