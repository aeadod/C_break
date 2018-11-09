#include<stdio.h>
int main(){
	struct Node {
		int data;
		struct Node *next;
	};
	struct Node node0={11,NULL
	};
	struct Node node1={22,NULL
	};
	struct Node node2={33,NULL
	};
	struct Node node3={44,NULL
	};
	struct Node*head=&node0;
	struct Node*p=head;
	node0.next=&node1;
	node1.next=&node2;
	node2.next=&node3;
	node3.next=NULL;
	while(p!=NULL){
		printf("%d ",p->data);
		p=p->next;
	}
	printf("\n");
	struct Node *cur=head;//记录当前处理的节点最初是head 
	struct Node *next=cur->next;//记录当前节点的下一个 
	struct Node *pre=head;//记录当前节点的前一个，最初是head 
	head->next=NULL;//原来的头变成尾，设置成NULL
	while(next!=NULL){
		cur=next;//下一个节点变成当前； 
		next=cur->next;//事先记录当前节点的下一个 
		cur->next=pre;//当前节点的下一个反向，指向前一个 
		pre=cur;// 当前节点就是下一个循环中当前节点的下一个 
	}
	head=cur;//循环结束后，cur就是新的head； 
	p=head;
	while(p!=NULL) {
		printf("%d ",p->data);
		p=p->next;
	}
} 
