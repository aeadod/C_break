#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<windows.h>
//定位函数 
void gotoxy(int y,int x){
	COORD scrn;
	HANDLE hOuput=GetStdHandle(STD_OUTPUT_HANDLE);
	scrn.X=x;scrn.Y=y;
	SetConsoleCursorPosition(hOuput,scrn);
}
struct Dice{
	int x,y,wid,hei,num;
};
void db(struct Dice dice)
{
	for(int i=0;i<dice.wid;i++)
	{
		gotoxy(dice.y,dice.x+i);
		printf("-\n");
		gotoxy(dice.y+6,dice.x+i);
		printf("-\n");
	}
	for(int j=0;j<dice.hei-2;j++)
	{
		gotoxy(dice.y+j+1,dice.x);
		printf("|\n");
		gotoxy(dice.y+j+1,dice.x+6);
		printf("|\n");
	}	
}
void dn(struct Dice dice){
	switch(dice.num){
		case 1:gotoxy(dice.y+3,dice.x+3);
		printf("o\n");
		break;
		case 2:gotoxy(dice.y+3,dice.x+2);
		printf("o\n");
		gotoxy(dice.y+3,dice.x+4);
		printf("o\n");
		break;
		case 3:gotoxy(dice.y+2,dice.x+2);
		printf("o\n");
		gotoxy(dice.y+3,dice.x+3);
		printf("o\n");
		gotoxy(dice.y+4,dice.x+4);
		printf("o\n");
		break;
		case 4:gotoxy(dice.y+2,dice.x+2);
		printf("o\n");
		gotoxy(dice.y+2,dice.x+4);
		printf("o\n");
		gotoxy(dice.y+4,dice.x+2);
		printf("o\n");
		gotoxy(dice.y+4,dice.x+4);
		printf("o\n");
		break;
		case 5:gotoxy(dice.y+2,dice.x+2);
		printf("o\n");
		gotoxy(dice.y+2,dice.x+4);
		printf("o\n");
		gotoxy(dice.y+4,dice.x+2);
		printf("o\n");
		gotoxy(dice.y+3,dice.x+3);
		printf("o\n");
		gotoxy(dice.y+4,dice.x+4);
		printf("o\n");
		break;
		case 6:gotoxy(dice.y+2,dice.x+2);
		printf("o\n");
		gotoxy(dice.y+2,dice.x+4);
		printf("o\n");
		gotoxy(dice.y+3,dice.x+2);
		printf("o\n");
		gotoxy(dice.y+3,dice.x+4);
		printf("o\n");
		gotoxy(dice.y+4,dice.x+4);
		printf("o\n");
		gotoxy(dice.y+4,dice.x+2);
		printf("o\n");
		break;
		default: break;
	}
}
void cleard(struct Dice dice){
	gotoxy(dice.y+2,dice.x+2);
	printf("   \n");
	gotoxy(dice.y+3,dice.x+2);
	printf("   \n");
	gotoxy(dice.y+4,dice.x+2);
	printf("   \n");
}
void upd(struct Dice *p)
{
	p->num=rand()%6+1;
}
void check(int choose,struct Dice d1,struct Dice d2,struct Dice d3){
	int sum=d1.num+d2.num+d3.num;
	gotoxy(d1.y+9,d1.x);
	if(choose==0){
		printf("总点数：%d.\n",sum);
		if(sum>11)
		printf("赢了");
		else
		printf("输了"); 
	} 
	else if(choose=2){
		printf("总点数：%d.\n",sum);
		if(sum<=11)
		printf("赢了");
		else
		printf("输了"); 
	}
	else{
		printf("3个骰子点数不同，");
		if(d1.num==d2.num&&d2.num==d3.num)
			printf("yingle");
		else printf("shule");
		
	}
}
int main()
{
	int choose =-1;
	do{
	
	srand(time(0));
	int num1=rand()%6+1;
	struct Dice d1={3,2,7,7,num1
	};
	int num2=rand()%6+1;
	struct Dice d2={13,2,7,7,num2
	};
	int num3=rand()%6+1;
	struct Dice d3={23,2,7,7,num3
	};
	db(d1);
	db(d2);
	db(d3);
	dn(d1);
	dn(d2);
	dn(d3);
	gotoxy(d1.y+7,1);
	printf("0买大，1买豹子，2买小\n");
	
	scanf("%d",&choose);
	for(int i=0;i<20;i++){
		Sleep(200);
		cleard(d1);
		cleard(d2);
		cleard(d3);
		upd(&d1);
		upd(&d2);
		upd(&d3);
		dn(d1);
		dn(d2);
		dn(d3);
		
	}
	check(choose,d1,d2,d3);
}while(choose!=-1);
	
	
	
	
	return 0;
}
