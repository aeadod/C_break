#include<stdio.h>
#include<string.h>
int main(){
	struct {
		char account[30];
		int password;
		double balance;
		
	}stu;
	FILE *fp;
	//if((fp=fopen("clientInfo.dat","wb"))==NULL)
	if((fp=fopen("clientInfo.dat","rb"))==NULL)
	{
		printf("ʧ�ܡ�"); 
	}else {
		printf("���룺\n"); 
		//while(1)
		while(fread(&stu,sizeof(stu),1,fp)==1)//���ļ��ж���ṹ����Ϣ 
		{
			printf("%s %d %lf",stu.account,stu.password,stu.balance);
		//	scanf("%s %d %lf",&stu.account,&stu.password,&stu.balance);
//		if(strcmp(stu.account,"EOF")==0){
//			break;
//		}
	//	fwrite(&stu,sizeof(stu),1,fp);
		
		
		
		}
		fclose(fp);
	
	
	}
	return 0;
}
