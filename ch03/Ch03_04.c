#include <stdio.h>
#include <stdlib.h>

int main()
{
    int select,student_no=0,num=0;
    float Msum=0,Esum=0;
    
    struct student
    {
        char name[20];
        int Math;
        int Eng;
        char no[10];
        struct student *next;
    };
    typedef struct student s_data;
    s_data *ptr;        /* ��ȡָ�� */
    s_data *head;       /* ����ͷָ�� */
    s_data *new_data;   /* ����Ԫ������λ�õ�ָ�� */
    
    head = (s_data*) malloc(sizeof(s_data)); /* ��������ͷ */ 
    head->next=NULL;
    ptr = head;  
    do
    {
        printf("(1)���� (2)�뿪 =>");
        scanf("%d", &select);
        if (select != 2)
        {
            printf("���� ѧ�� ��ѧ�ɼ� Ӣ��ɼ�:");
            new_data = (s_data*) malloc(sizeof(s_data));    /* ������һ��Ԫ�� */
            scanf("%s %s %d %d",new_data->name,new_data->no,&new_data->Math,&new_data->Eng);
            ptr->next=new_data; /*��ȡָ������Ϊ��Ԫ������λ�� */
            new_data->next =NULL;   /* ��һ��Ԫ�ص�next������Ϊnull */
            ptr=ptr->next;
            num++;
            
        }
    } while (select != 2);
    ptr = head->next;    /* ���ô�ȡָ���ͷ��ʼ */
    putchar('\n');
    while (ptr!= NULL)
    {
        printf("������%s\tѧ��:%s\t��ѧ�ɼ�:%d\tӢ��ɼ�:%d\n", 
         ptr->name,ptr->no,ptr->Math,ptr->Eng);
        Msum+=ptr->Math;
        Esum+=ptr->Eng;
        student_no++;
        ptr= ptr ->next;    /* ��ptr������һ��Ԫ�� */
    }
    printf("---------------------------------------------------------\n");
    printf("������ѧ����ѧƽ���ɼ�:%.2f Ӣ��ƽ���ɼ�:%.2f\n",Msum/student_no,Esum/student_no); 
    system("pause");
    return 0;
}
