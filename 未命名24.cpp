#include<stdio.h>
#include<string.h>
char *get1(){
	char str[20]="china";
	printf("%p\n",str);
	return str;
}
char *get2(){
	static char str[20]="china";
	printf("%p\n",str);
	return str;
}
char *get3(){
	char *str="china";
	printf("%p\n",str);
	return str;
}
int main(){
	char *s1=get1();
	char*s2=get2();
	char *s3=get3();
	printf("s1=%s\n",s1);
		printf("s2=%s\n",s2);
			printf("s3=%s\n",s3);
} 
