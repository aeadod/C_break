#include<stdio.h>
int main(){
	char str[]="aabbcaedddd";
	int f[27]={0};
	int i=0,j=0;
	while(str[j]!='\0'){
		int k=str[j]-'a';
		if(f[k]==0){
			str[i]=str[j];
			f[k]=1;
			i++;
					}
	else{
		j++;
	}
	}
	str[i]='\0';
	printf("%s",str);
}
