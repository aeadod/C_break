#include"stdio.h"
#include"windows.h"

int main()
{
	printf("送给你六朵花：");Sleep(1000); 
	system("cls"); 
	for(int i=0;i<5;i++)
	{
		printf("{@}  \n");
		printf(" |\n");
		printf("\\|/\n");
		printf(" |\n");
		printf(" |\n");
		printf("%i\n",i+1);
		Sleep(1000);
		system("cls");
	}
	printf("你数来数去，\n");Sleep(1000);
	printf("只有五朵花，\n");Sleep(1000);
	printf("还有一朵就是你啊！\n");
	return 0;
 } 
