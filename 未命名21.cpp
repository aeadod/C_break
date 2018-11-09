#include<stdio.h>
#include<string.h>
int main()
{
	char str[10]="abcdefg";
	int len=strlen(str);
	int i=0;
	int j=len-1;
	while(i<len/2){
		char temp=str[i];
		str[i]=str[j];
		str[j]=temp;
		i++;j--;
		
	}
	for(int i=0;i<9;i++)
	printf("%c",str[i]);
 } 
