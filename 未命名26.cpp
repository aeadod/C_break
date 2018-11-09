#include<stdio.h>
#include<stdlib.h>
int main(){
		int size=10;
		int *a=(int*)malloc(size*sizeof(int));
		printf("请输入学生成绩，当输入负数时结束：\n");
		int i=0;
		while(1){
			int b=0;
			scanf("%d",&b);
			if(b<0){
				break;
			}
			a[i]=b;
			i++;
			if(i==size){
				size=2*size;
				int *temp=(int *)realloc(a,size* sizeof(int ));
				if(temp!=NULL){
					a=temp;
				}else{
					printf("内存不够"); 
					break;
				}
			}
		}
for(int j=0;j<i;j++){
	printf("%d ",a[j]);
	if((j+1)%10==0){
		printf("\n");
	}
}
if(a){
	free(a);
}
return 0;


}
