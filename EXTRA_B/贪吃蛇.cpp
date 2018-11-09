#include<stdio.h>
#include<string.h>
#include<windows.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
int width=60;
int height=22;
void gotoxy(int y,int x){
	COORD scrn;
	HANDLE hOuput=GetStdHandle(STD_OUTPUT_HANDLE);
	scrn.X=x;
	scrn.Y=y;
	SetConsoleCursorPosition(hOuput,scrn);	
}
struct Food{
	int x;
	int y;
	char type;
	int value;
}; 
struct SnakeNode{
	int x,y;
	int row;
	int col;
	struct SnakeNode *next;
};

void drawInterface(){
	for(int i=0;i<height;i+=height-1){
		for(int j=0;j<width;j++){
			gotoxy(i+1,j+1);
			printf("-\n");
		}
	}
	for(int i=0;i<width;i+=width-1){
		for(int j=0;j<height-2;j++){
			gotoxy(j+2,i+1);
			printf("|\n");
		}
	}
}
struct Food food;
void produceFood(){
	char fs[5]={'@','#','$','%','&'};
	srand(time(0));
	int n=rand()%5;
	food.type=fs[n];
	food.value=n+1;
	food.x=rand()%(height-3)+2;
	food.y=rand()%(width-3)+2;
	gotoxy(food.x,food.y);
	printf("%c\n",food.type);

}
struct SnakeNode *head=NULL;
struct SnakeNode *tail=NULL;
void produceSnake(){
	struct SnakeNode *node1=(struct SnakeNode *)malloc(sizeof(struct SnakeNode));
	node1->row=height/2;
	node1->col=20;
	node1->next=NULL;
	struct SnakeNode *node2=(struct SnakeNode *)malloc(sizeof(struct SnakeNode));
	node2->row=height/2;
	node2->col=19;
	node2->next=node1;
	struct SnakeNode *node3=(struct SnakeNode *)malloc(sizeof(struct SnakeNode));
	node3->row=height/2;
	node3->col=18;
	node3->next=node2;
	tail=node3;
	head=node1;
} 
void drawSnake(struct SnakeNode *head){
	while(head!=NULL){
		gotoxy(head->y,head->x);
		printf("*\n");
		head=head->next;
	}
}
enum Direction{
	Left,Right,Up,Down,
};
enum Direction dir=Right;
void checkDirection();

void checkDirection(){
	int res=kbhit();
	if(res>0){
		char ch=getch();
		if(ch=='a')
		dir=Left;
		else if(ch=='d')
		dir=Right;
		else if(ch=='w')
		dir=Up;
		else if(ch=='s')
		dir=Down;
	}
}
void eatFood();
int checkGameOver();
int moveSnake(){
	if(tail==NULL&&head==NULL){
		printf("Game Over!!!\n");
		return -1;
	}
	else {
		int oldRow=tail->y;
		int oldCol=tail->x;
		struct SnakeNode *p=tail;
		tail=tail->next;
		gotoxy(p->y,p->x);
		printf(" \n");
		if(tail==NULL){
			tail=p;
			head->next=p;
			p->next=NULL;
		}
		switch(dir){
			case Right:
				p->x=head->x+1;
				p->y=head->y;
				break;
			case Left:
				p->x=head->x-1;
				p->y=head->y;
				break;
			case Up:
				p->y=head->y-1;
				p->x=head->x;
				break;
			
			case Down:
				p->y=head->y+1;
				p->x=head->x;
				break;
			default :break;
			
		}
		head=p;
		gotoxy(p->y,p->x);
		printf("*\n");
		eatFood();
		return checkGameOver();
		
		
		
	}
	return 0;
}
void eatFood(){
	if(head->y==food.y&&head->x==food.x){
		for(int i=0;i<food.value;i++){
			struct SnakeNode *pNode=(struct SnakeNode*)malloc(sizeof(struct SnakeNode));
			pNode->next=tail;
			pNode->y=tail->y;
			pNode->x=tail->x;
			tail=pNode;
			gotoxy(pNode->y,pNode->x);
			printf("*\n");
	
	
		}
		produceFood();
	}
}
int checkGameOver(){
	if(head->y<=0||head->y>=height-1||head->x<=0||head->x>=width-1){
	
		return -1;
	}
	return 0;
}



int main(){
	drawInterface();
	produceFood();
	drawSnake(tail);
	while(1){
		checkDirection();
		int res=moveSnake();
		if(res<0){
			break;
		}
		Sleep(200);
	}
	return 0;
}
