#include<stdio.h>
#include<windows.h>
//定位函数 
void gotoxy(int y,int x){
	COORD scrn;
	HANDLE hOuput=GetStdHandle(STD_OUTPUT_HANDLE);
	scrn.X=x;scrn.Y=y;
	SetConsoleCursorPosition(hOuput,scrn);
}
void ds(char ch,int n)
{
	for(int i=0;i<n;i++)
	{
		printf("%c",ch);
	 } 
}
	int wid=70;
	int hei=22;

void Dr()
{
	
	ds('*',wid);
	printf("\n");
	for(int i=0;i<hei-2;i++)
	{
		printf("*");
		ds(' ',wid-2);
		printf("*\n");
	}
	ds('*',wid);
	printf("\n");
}
struct balls{
	int x,y,xs,ys;
}bas[100]; 
void db(int x,int y){
		gotoxy(y,x);
		printf("o\n");
}
void cb(int x,int y){
		gotoxy(y,x);
		printf(" \n");
		
}
void balllocation(struct balls *bas){
		bas->x+=bas->xs;
		bas->y+=bas->ys;
		//防止越界 
		if(bas->x>wid-2)
		{
			bas->x=wid-2;
		}
		if(bas->y>hei-2)
		{
			bas->y=hei-2;
		}
		if(bas->x<1)
		bas->x=1;
		if(bas->y<1)
		bas->y=1;
}
void balldirection(struct balls *bas){
	//反向运动 
		if(bas->x>=wid-2||bas->x<=1){
			bas->xs=-bas->xs; 
		}
		if(bas->y>=hei-2||bas->y<=1){
			bas->ys=-bas->ys;
		}
} 

int main()
{
	Dr();
//	int x=20;
//	int y=10;
//	int xs=2;
//	int ys=2;
//	int x1=30;
//	int y1=15;
//	int y1s=1;
//	int x1s=1;
//	int x2=20,y2=40,x2s=2,y2s=1;
	for(int i=0;i<100;i++)
	{
		bas[i].x=rand()%50+5;
		bas[i].y=rand()%17+3;
		bas[i].xs=rand()%5+1;
		bas[i].ys=rand()%5+1;
	}
	while(1)
	{
//		db(x,y);
//		db(x1,y1);
//		db(x2,y2);
	for(int i=0;i<100;i++){
		db(bas[i].x,bas[i].y);
	}
		Sleep(200);
		
//		cb(x,y);
//		cb(x1,y1);
//		cb(x2,y2);
	for(int i=0;i<100;i++){
		cb(bas[i].x,bas[i].y);
	}
	for(int i=0;i<100;i++){
		balllocation(&bas[i]);
	}
//		balllocation(&x,&y,xs,ys);
//		balllocation(&x1,&y1,x1s,y1s);
//		balllocation(&x2,&y2,x2s,y2s);
	for(int i=0;i<100;i++)
	{
		balldirection(&bas[i]);
	}
		//balldirection(x,y,&xs,&ys);
//		balldirection(x1,y1,&x1s,&y1s);
//		balldirection(x2,y2,&x2s,&y2s);
	}
	return 0;
 } 
