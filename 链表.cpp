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
//	//ͷ��
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
	//β��
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
	//�в��� 
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
//	//ɾͷ��
//	head =head->next; 
//	p=head;
//	while(p!=NULL){
//		printf("%d ",p->data);
//		p=p->next;
//	}
//	printf("\n");
	//ɾβ��
//	p=head;
//	struct Node *cur=NULL;//��¼β����ǰһ���ڵ� 
//	while(p!=NULL&p->next!=NULL){//�ڵ�ǿ�����һ���ǿ������ 
//		cur=p;
//		p=p->next;
//		
//	} 
//	//���cur=NULL����֤��������û�нڵ��ֻ��һ���ڵ�
//	//��ʱֻҪ��headָ��NULL 
//	if(cur==NULL){
//		head=NULL;
//		//cur����NULL����ôpΪ�����β����curΪǰһ�� 
//	}else cur->next=NULL;
//	p=head;
//	while(p!=NULL){
//		printf("%d ",p->data);
//		p=p->next;
//	}
//printf("\n");
	//ɾ�м�
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
	}//ѭ��������p����ǿգ�p��ָ��������ڵ㣬curΪǰһ���� 
	if(p!=NULL){
		cur->next=p->next;//p��ǰһ��ָ�����һ����ָ��p����һ���� 
	}else 
	printf("û�е������ڵ�.");
	p=head;
	while(p!=NULL){
		printf("%d ",p->data);
		p=p->next;
	}
	printf("\n");


}
