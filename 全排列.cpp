#include<stdio.h>
#include<windows.h>
void permutate(char* s,int begin,int end){
	if(begin==end){
		printf("%s\n",s);
	}else{
		for(int i=begin;i<=end;i++){
			char c=s[begin];
			s[begin]=s[i];
			s[i]=c;
			permutate(s,begin+1,end);
			c=s[begin];
			s[begin]=s[i];
			s[i]=c;
		}
	}
}
int main(){
	char s[]="abcde";
	permutate(s,0,4);
	return 0;
}
