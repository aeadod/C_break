#include<stdio.h>
#include<stdlib.h>
int main(){
	char *p=(char*)malloc(10*sizeof(char));
	int *p1=(int *)malloc(10*sizeof(int ));
	if(p==NULL){
		printf("�ڴ�");
		exit(1); 
	}
	free(p1);
	free(p);
	p=NULL;
	p1=NULL;
	int *a=(int *)malloc(4*5);
//(void *)calloc(size_t n,size_t size);//����n������Ϊsize�Ŀռ䣬��ʼΪ0�� 
	for(int i=0;i<5;i++){
		printf("%d ",a[i]);
	}
	printf("\n");
	int *b=(int *)calloc(5,4);
	for(int i=0;i<5;i++){
		printf("%d ",b[i]);
	}
	int *aa=(int*)realloc(a,1000);
	printf("%p\n",aa);
	return 0;
}
