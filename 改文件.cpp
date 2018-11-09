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
	if((fp=fopen("w:\\demo.txt","r+b"))==NULL){
		printf("BUXing");
		exit(1); 
	}

		struct Stu boy;
		fseek(fp,2*sizeof(struct Stu),SEEK_SET);
		fread(&boy,sizeof(struct Stu),1,fp);
		printf("%s %d %d %f\n",boy.name,boy.num,boy.age,boy.score);
		boy.age=100;
		fseek(fp,2*sizeof(struct Stu),SEEK_SET);//复位到第三个学生，否则自动指向第四个； 
		fwrite(&boy,sizeof(struct Stu),1,fp);
		fclose(fp);
	
	return 0;
}
