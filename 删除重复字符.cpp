#include<stdio.h>
int main(){
	char str[]="aabbcaedddd";
	for(int i=0;str[i]!='\0';i++){
		for(int j=i+1;str[j]!='\0';j++){
			if(str[i]==str[j]){
				int k=j+1;
				for(;str[k]!='\0';k++){
					str[k-1]=str[k];
			
				}
				str[k-1]='\0';
				j--;
			}
			
		}		
	}
	printf("%s",str);
}
