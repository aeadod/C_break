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
	struct Node *cur=head;//��¼��ǰ����Ľڵ������head 
	struct Node *next=cur->next;//��¼��ǰ�ڵ����һ�� 
	struct Node *pre=head;//��¼��ǰ�ڵ��ǰһ���������head 
	head->next=NULL;//ԭ����ͷ���β�����ó�NULL
	while(next!=NULL){
		cur=next;//��һ���ڵ��ɵ�ǰ�� 
		next=cur->next;//���ȼ�¼��ǰ�ڵ����һ�� 
		cur->next=pre;//��ǰ�ڵ����һ������ָ��ǰһ�� 
		pre=cur;// ��ǰ�ڵ������һ��ѭ���е�ǰ�ڵ����һ�� 
	}
	head=cur;//ѭ��������cur�����µ�head�� 
	p=head;
	while(p!=NULL) {
		printf("%d ",p->data);
		p=p->next;
	}
} 
