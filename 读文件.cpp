struct Stu {
	char name[20];
	int num;
	int age;
	float score;
};

#include<stdio.h>
#include<string.h>
#include<windows.h>

int main(){
	FILE*fp;
	if((fp=fopen("w:\\demo.txt","rb"))==NULL){
		printf("buxing");
		exit(1);
	}
	struct Stu boy;
	while(fread(&boy,sizeof(struct Stu),1,fp)==1){
		printf("%s %d %d %f\n",boy.name,boy.num,boy.age,boy.score);
	}
	fclose(fp);
	return 0;
	
} 
