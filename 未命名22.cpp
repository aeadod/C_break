#include<stdio.h>
#include<string.h>
void convertString(char str[]){
	int i=0;
	int j=(int)strlen(str)-1;
	while(i<j){
		char temp=str[i];
		str[i]=str[j];
		str[j]=temp;
		i++;
		j--;
	}
}
void  intToString(char str[],int n){
	int i=0;while(1){
		int one=n%10;
		str[i]=one+'0';
		n=n/10;
		i++;
		if(n==0){
			break;
		}
		
	}
	str[i]='\0';
	convertString(str);
}
int main()
{
	char str[100]="abbbddcdddeeee";
	int i=0;
	int j=1;
	while(str[i]!='\0'){
		if(str[i]=str[j])
			j++;
		else {
			if(j-i>1){
				char res[10];
				intToString(res,j-i);
				int len=(int)strlen(res);
				strncpy(&str[i+1],res,len);
				int k=0;
				for(k=j;str[k]!='\0';k++){
					str[k-j+i+len+1]=str[k];	
					}
					str[k-j+i+len+1]='\0';
					i=i+len;
					j=i+1; 
				}
				i++;
				j=i+1;
			}
	}
	printf("%s\n",str);
	return 0;
 } 
