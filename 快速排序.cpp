#include<stdio.h>
void quicksort(int a[],int left,int right){
	int i=left;
	int j=right;
	int temp=a[left];
	if(left>right){
		return ;
	}
	while(i!=j){
		while(a[j]>=temp&&j>i)
		j--;
		if(j>i) a[i++]=a[j];
		while(a[i]<=temp&&j>i)
		i++;
		if(j>i) a[j--]=a[i];
	}
	a[i]=temp;
	quicksort(a,left,i-1);
	quicksort(a,i+1,right);
} 
int main(){
	int a[9]={3,6,5,9,7,1,8,2,4};
	quicksort(a,0,8);
	for(int i=0;i<9;i++){
		printf("%4d",a[i]);
			}
	return 0;
} 
