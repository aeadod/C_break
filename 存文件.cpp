struct Stu{
	char name[20];
	int num;
	int age;
	float score;
};
#include<stdio.h>
#include<string.h>
#include<windows.h> 
int main(){
	FILE *fp;
	int i;
	if((fp=fopen("w:\\demo.txt","wb+"))==NULL){
		printf("BUxing");
		exit(1);
	}
	printf("输入学生信息\n");
	for(i=0;i<4;i++){
		struct Stu stu;
		scanf("%s%d%d%f",stu.name,&stu.num,&stu.age,&stu.score);
		fwrite(&stu,sizeof(struct Stu),1,fp);
	}
	fclose(fp);
	return 0;
}
