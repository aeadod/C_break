#include<stdio.h>
#include<string.h>
#include<stdlib.h>
	struct Node {
		char* word;
		struct Node *next;
	};
	void splitIntoWords(char *str,struct Node **wordList){
		int count =0;
		char*p=str;
		while(*p!='\0'){
			if(*p!=' '){
				count++;
			}else{
				if(count>0){
					struct Node *pNode=(struct Node *)malloc(sizeof(struct Node));
					pNode->word=(char*)malloc((count+1)*sizeof(char));
					strncpy(pNode->word,p-count,count );
					pNode->word[count]='\0';
					pNode->next=NULL;
					if(*wordList==NULL){
						*wordList=pNode;
						
					}else{
						pNode->next=*wordList;
						*wordList=pNode;
					}
				}
				count=0;
			}
			p++;
		}
		if(count>0){
			struct Node*pNode=(struct Node*)malloc(sizeof(struct Node));
			pNode->word=(char*)malloc((count+1)*sizeof(char));
			strncpy(pNode->word,p-count,count);
		pNode->next=NULL;
		if(*wordList==NULL){
			*wordList=pNode;
			
		}else{
			pNode->next=*wordList;
			*wordList=pNode;
		}
		}
	}
	void printList(struct Node*wordList){
		struct Node*p=wordList;
		while(p!=NULL){
			printf("%s",p->word);
			p=p->next;
		}
		printf("\n");
	}
	void freeMemory(struct Node *wordList){
		struct Node *p=wordList;
		while(p!=NULL){
			struct Node *temp=p;
			p=p->next;
			free(temp->word);
			free(temp);
		}
	}
int main(){
char str[]="She is a cat";
struct Node *wordList=NULL;
splitIntoWords(str,&wordList);
printList(wordList);
freeMemory(wordList);
return 0;
	
}
