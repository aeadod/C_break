#include"stdio.h"
#include"windows.h"
int main()
{
	system("cls");
	printf("������ʮ�߶�õ�廨��\n");Sleep(1000);
	printf("�㿪ʼ����");Sleep(1000); 
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
	printf("��������ȥ��ֻ��ʮ����?\n");Sleep(1000);
	printf("����һ������㰡!");Sleep(1000); 
	return 0;
}
