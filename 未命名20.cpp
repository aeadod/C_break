#include<stdio.h>
int main(){
	int arr[5][5];
	int count =1;
	int left=0,right=4,up=0,down=4;
	while(1){
		for(int i=up;i<=down;i++){
			arr[i][left]=count++;
			if(count>25)
			goto TE;
		}
		left++;
		for(int i=left;i<=right;i++){
			arr[down][i]=count++;
			if(count>25)
			goto TE;
			
		}
		down--;
		for(int i=down;i>=up;i--){
			arr[i][right]=count++;
			if(count>25)
			goto TE;
			
		}
		right--;
		for(int i=right;i>=left;i--){
			arr[up][i]=count++;
			if(count>25)
			goto TE;
			
		}
		up++;
		
	}
	TE:
		for(int i=0;i<5;i++){
			for(int j=0;j<5;j++){
				if(i==4) printf("%d  ",arr[i][j]);
				else printf("%d ",arr[i][j]);
			}
			printf("\n");
		}
} 
