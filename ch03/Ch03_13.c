#include <stdio.h>
#include <stdlib.h>

int main()
{
    int select;
    
    struct student
    {
        char name[20];
        int Math;
        int Eng;
        char no[10];
        struct student *rlink;
        struct student *llink;
    };
    typedef struct student s_data;
    s_data *ptr;        /* ��ȡָ�� */
    s_data *head;       /* ����ͷָ�� */
    s_data *new_data;   /* ����Ԫ������λ�õ�ָ�� */

    head = (s_data*) malloc(sizeof(s_data)); 
    head->llink=NULL;
    head->rlink=NULL;
    ptr = head;   /* ���ô�ȡָ�뿪ʼ��λ��  */
    do
    {
        printf("(1)���� (2)�뿪 =>");
        scanf("%d", &select);
        if (select != 2)
        {
            printf("���� ѧ�� ��ѧ�ɼ� Ӣ��ɼ�:");
            new_data = (s_data*) malloc(sizeof(s_data));    /* ������һ��Ԫ�� */
            scanf("%s %s %d %d",new_data->name,new_data->no,&new_data->Math,&new_data->Eng); 
            /*����ڵ�ṹ�е����� */
            ptr->rlink=new_data;
            new_data->rlink = NULL;   /* ��һ��Ԫ�ص�next������Ϊnull */
            new_data->llink=ptr;   /* ��ȡָ������Ϊ��Ԫ�����ڵ�λ�� */
            ptr=new_data;
        }
    } while (select != 2);

    ptr = head->rlink;    /* ���ô�ȡָ�������ͷ����ָ����ָ�ڵ㿪ʼ */
    putchar('\n');
    
    while (ptr!= NULL)
    {
     printf("������%s\tѧ��:%s\t��ѧ�ɼ�:%d\tӢ��ɼ�:%d\n", ptr->name,ptr->no,ptr->Math,ptr->Eng);    
     ptr = ptr ->rlink;    /* ��ptr�����ұ���һ��Ԫ�� */   
     }
        
    system("pause");
    return 0;
}
