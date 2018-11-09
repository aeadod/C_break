#include <stdio.h>
#include <stdlib.h>

struct tree
{  int data;
   struct tree *left,*right;
};

typedef struct tree node;
typedef node *btree;

btree creat_tree(btree root,int val)
{  
	btree newnode,current,backup;
	newnode=(btree)malloc(sizeof(node));
	newnode->data=val;
	newnode->left=NULL;
	newnode->right=NULL;
	if(root==NULL)
	{  
		root=newnode;
		return root;
	}
	else
	{  
		for(current=root;current!=NULL;)
		{  
			backup=current;
			if(current->data > val)
				current=current->left;
			else
				current=current->right;
		}
		if(backup->data >val)
			backup->left=newnode;
		else
			backup->right=newnode;
	}
	return root;
}
btree search(btree ptr,int val)     /*���Ҷ������ӳ���*/
{  
	int i=1;                     /*�ж�ִ�д����ı���*/
	while(1)
	{  
		if(ptr==NULL)            /*û�ҵ��ͷ���NULL*/
			return NULL;
		if(ptr->data==val)       /*�ڵ�ֵ���ڲ���ֵ*/
		{  
			printf("������ %3d ��\n",i);
			return ptr;
		}
		else if(ptr->data > val)  /*�ڵ�ֵ���ڲ���ֵ*/
			ptr=ptr->left;
		else
			ptr=ptr->right;
		i++;
	}   
}

int main()
{  
	int i,data,arr[]={7,1,4,2,8,13,12,11,15,9,5};
	btree ptr=NULL;
	printf("[ԭʼ��������]\n");
	for (i=0;i<11;i++)              
	{  
		ptr=creat_tree(ptr,arr[i]);  /*����������*/
		printf("[%2d] ",arr[i]);
	}
	printf("\n");
	printf("���������ֵ��\n");
	scanf("%d",&data);
	if((search(ptr,data)) !=NULL)        /*���Ҷ�����*/
		printf("��Ҫ�ҵ�ֵ [%3d] �ҵ���!!\n",data);
	else
		printf("��Ҫ�ҵ�ֵû�ҵ�!!\n");
	
    system("pause");
	return 0;
}
