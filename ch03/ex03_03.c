#include <stdio.h>
#include <stdlib.h>

int main()
{
    int select,student_no=0,sum=0;
    float Msum=0,Esum=0;
    
    struct student
    {
        char name[20];
        char no[10];
        struct student *next;
    };
    typedef struct student s_data;
    s_data *ptr;        /* ��ȡָ�� */
    s_data *head;       /* ����ͷָ�� */
    s_data *new_data;   /* ����Ԫ������λ�õ�ָ�� */

    head = (s_data*) malloc(sizeof(s_data));   /* ��������ͷԪ�� */
    ptr = head;    /* ���ô�ȡָ���λ�� */
    ptr->next = NULL;    /* ��ǰ����һ��Ԫ�� */
    do
    {
        printf("(1)���� (2)�뿪 =>");
        scanf("%d", &select);
        if (select != 2)
        {
            printf("���� ѧ�� :");
            scanf("%s %s",ptr->name,ptr->no);
            new_data = (s_data*) malloc(sizeof(s_data));    /* ������һ��Ԫ�� */
            ptr->next = new_data;    /* ������һ��Ԫ�� */
            new_data->next = NULL;   /* ��һ��Ԫ�ص�next������Ϊnull */
            ptr = new_data;    /* ��ȡָ������Ϊ��Ԫ�����ڵ�λ�� */
        }
    } while (select != 2);

    ptr = head;    /* ���ô�ȡָ���ͷ��ʼ */

    putchar('\n');

    while (ptr->next != NULL)
    {
        printf("������%s\tѧ��:%s\n", 
              ptr->name,ptr->no);
        head = head ->next;    /* ��head������һ��Ԫ�� */
        sum++; /* �ڵ�������һ */
        ptr = head;   /* ���ô�ȡָ��Ϊ��ǰhead���ڵ�λ�� */
    }
    printf("---------------------------------------------------------\n");
    
    printf("��������%d���ڵ�\n",sum); 
    system("pause");
    return 0;
}
