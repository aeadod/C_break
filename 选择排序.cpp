#include<stdio.h>
int main(){
	int arr[6]={5,0,6,9,5,4};
	for(int j=0;j<5;j++){
		int k=0;
		int max=arr[0];
		for(int i=1;i<6-j;i++){
			if(max<arr[i]){
				k=i;
				max=arr[i];
			}
			
		}
		if(k!=5-j){
			arr[k]=arr[5-j];
			arr[5-j]=max;
		}
	}
}
