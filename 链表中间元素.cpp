#include<stdio.h>
int main(){
	struct Node {
		int data ;
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
	struct Node node4={55,NULL
	}; 
	struct Node *head=&node0;
	struct Node *p=head;
	node0.next=&node1;
	node1.next=&node2;
	node2.next=&node3;
	node3.next=&node4;
	node4.next=NULL;
	
	struct Node *slow=head;//���ģ������head
	struct Node *fast =head;
	if(head->next==NULL){
		printf("ֻ��һ���ڵ�\n");
		return NULL;
		 
	}
	else 
	fast=head->next->next;
	while(fast!=NULL){
		slow=slow->next;
		if(fast->next==NULL){
			break;//�쵽��β�������� 
			
		}
		fast=fast->next->next;//��ָ��ÿ�������� 
	} 
	//ѭ��������slowΪ�м�ڵ㡣
	printf("�м�ڵ���%d\n",slow->data);
}
