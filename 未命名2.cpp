#include"stdio.h"
#include"windows.h"
int main()
{
	system("cls");
	printf("我送你十七朵玫瑰花：\n");Sleep(1000);
	printf("你开始数。");Sleep(1000); 
	system("cls");
	for(int k=0;k<17;k++)
	{
		for(int i=0;i<k;i++)
			printf("{@}");
			printf("\n");
		for(int i=0;i<k;i++)
			printf(" | ");
			printf("\n");
		for(int i=0;i<k;i++)
			printf("\\|/");
			printf("\n");
		for(int i=0;i<k;i++)
			printf(" | ");
			printf("\n");
		for(int i=0;i<k;i++)
			printf(" | ");
			printf("\n");
		Sleep(1000);
		system("cls");	
	}
	printf("你数来数去，只有十六朵?\n");Sleep(1000);
	printf("还有一朵就是你啊!");Sleep(1000); 
	return 0;
}
