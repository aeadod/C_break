#include<stdio.h> 
void mystrcpy(char *des,const char *src){
	if(des==NULL||src==NULL){
		return;
	}
	while(*src!='\0'){
		*des=*src;
		des++;
		src++;
	}
	*des='\0';
} 
