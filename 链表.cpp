#include<stdio.h>
int main(){
	struct Node{
		int data;
		struct Node *next;
	};
	struct Node node1={34,NULL
	};
	struct Node node2={98,NULL
	};
	struct Node node3={63,NULL
	};
	struct Node node4={72,NULL
	};
	node1.next=&node2;
	node2.next=&node3;
	node3.next=&node4;
	node4.next=NULL;
	struct Node *head=&node1;
	struct Node *p=head;
	while(p!=NULL){
		printf("%d ",p->data);
		p=p->next;
	}
	printf("\n");
//	//头插
//	struct Node node0={79,NULL
//	}; 
//	node0.next=&node1;
//	head=&node0;
//	p=head;
//	while(p!=NULL){
//		printf("%d ",p->data);
//		p=p->next;
//	}
//	printf("\n");
	//尾插
	p=head;
	while(p!=NULL&&p->next!=NULL) 
	{
		p=p->next;
	}
	struct Node n1={666,NULL
	};
	p->next=&n1;
	p=head;
	while(p!=NULL){
		printf("%d ",p->data);
		p=p->next;
	}
	printf("\n");
	//中插入 
//	p=head;
//	int count=0;
//	
//	struct Node *cur=head;
//	while(p!=NULL){
//		count++;
//		if(count ==3){
//			break;
//		}
//		cur=p;
//		p=p->next;
//	} 
//	struct Node n2={233,NULL
//	};
//	if(p!=NULL){
//		struct Node *temp=p->next;
//		p->next=&n2;
//		n2.next=temp;
//		
//	}
//	else 
//		cur->next=&n2;
//	p=head;
//	while(p!=NULL){
//		printf("%d ",p->data);
//		p=p->next;}
//	printf("\n");	
//	//删头部
//	head =head->next; 
//	p=head;
//	while(p!=NULL){
//		printf("%d ",p->data);
//		p=p->next;
//	}
//	printf("\n");
	//删尾部
//	p=head;
//	struct Node *cur=NULL;//记录尾部的前一个节点 
//	while(p!=NULL&p->next!=NULL){//节点非空且下一个非空则继续 
//		cur=p;
//		p=p->next;
//		
//	} 
//	//如果cur=NULL，那证明此链表没有节点或只有一个节点
//	//此时只要让head指向NULL 
//	if(cur==NULL){
//		head=NULL;
//		//cur不是NULL，那么p为链表的尾部，cur为前一个 
//	}else cur->next=NULL;
//	p=head;
//	while(p!=NULL){
//		printf("%d ",p->data);
//		p=p->next;
//	}
//printf("\n");
	//删中间
	int count =0;
	p=head;
	struct Node *cur=head;
	while(p!=NULL){
		count++;
		if(count==3){
			break;			
		}
		cur=p;
		p=p->next;
	}//循环结束后，p如果非空，p就指向第三个节点，cur为前一个。 
	if(p!=NULL){
		cur->next=p->next;//p的前一个指向的下一个，指向p的下一个。 
	}else 
	printf("没有第三个节点.");
	p=head;
	while(p!=NULL){
		printf("%d ",p->data);
		p=p->next;
	}
	printf("\n");


}
