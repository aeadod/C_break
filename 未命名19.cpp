#include<stdio.h>
int main()
{
	int arr[5]={5,4,9,6,8};
	for(int i=0;i<5;i++){
		int flag=0;
		for(int j=0;j<5-i;j++){
			if(arr[i]>arr[i+1]){
				flag=1;
				int temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
		if(flag==0)
		break;
	}
}
