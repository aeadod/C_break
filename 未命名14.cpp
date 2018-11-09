#include<stdio.h>
#include<windows.h>
void ps(char *s,int n)
{
	for(int i=0;i<n;i++)
	{
		printf("%s",s);
	}
	printf("\n");
}
void pr(int num)
{
	ps("{@}",num);
	ps(" | ",num);
	ps("\\|/",num);
	ps(" | ",num);
	ps(" | ",num);
}
int main()
{
	for(int i=0;i<17;i++)
	{
		pr(i);
		Sleep(1000);
		system("cls");
	}
}
