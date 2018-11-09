#include<stdio.h>
#include<windows.h>
//¶¨Î»º¯Êý 
void gotoxy(int y,int x){
	COORD scrn;
	HANDLE hOuput=GetStdHandle(STD_OUTPUT_HANDLE);
	scrn.X=x;scrn.Y=y;
	SetConsoleCursorPosition(hOuput,scrn);
}
int main()
{
	gotoxy(30,10);
	printf("Hello");
}
