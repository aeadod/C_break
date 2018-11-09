#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int enqueue(char*, int);    /* �����ݼ������*/
int dequeue();           /* �Ӷ���ȡ������ */
int show();          	  /* ��ʾ�������� */

struct student
{
    char name[20];
    int score;
    struct student *next;
};
typedef struct student s_data;

s_data *front =NULL;
s_data *rear = NULL;

int main()
{
    int select, score;
    char name[20];

    do
    {
        printf("(1)���� (2)ȡ�� (3)��ʾ (4)�뿪 => ");
        scanf("%d", &select);
        switch (select)
        {
            case 1:
                printf("���� �ɼ���");
                scanf("%s %d", name, &score);
                enqueue(name, score);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                show();
                break;
        }
    } while (select != 4);

    system("pause");
    return 0;
}


int enqueue(char* name, int score)
{
    s_data *new_data;

    new_data = (s_data*) malloc(sizeof(s_data));  /* �����ڴ����Ԫ�� */
    strcpy(new_data->name, name);   /* ������Ԫ�ص����� */
    new_data->score = score;
    if (rear == NULL)      /* ���rearΪNULL����ʾ���ǵ�һ��Ԫ�� */
        front = new_data;
    else
        rear->next = new_data;    /* ����Ԫ�����ӵ�����β�� */

    rear = new_data;    /* ��rearָ����Ԫ�أ������µĶ���β�� */
    new_data->next = NULL;    /* ��Ԫ��֮��������Ԫ�� */
}


int dequeue()
{
    s_data *freeme;
    if (front == NULL)
        puts("�����ѿգ�");
    else
    {
        printf("������%s\t�ɼ���%d ....ȡ��\n", front->name, front->score);
        freeme = front;    /* ���ý�Ҫ�ͷŵ�Ԫ��ָ�� */
        front = front->next;    /* ������ǰ��������һ��Ԫ�� */
        free(freeme);    /* �ͷ���ȡ����Ԫ��֮�ڴ� */
    }
}

int show()
{
    s_data *ptr;
    ptr = front;
    if (ptr == NULL)
        puts("�����ѿգ�");
    else
    {
    puts("front -> rear");
        while (ptr != NULL)    /* ��front��rear�������� */
        {
            printf("������%s\t�ɼ���%d\n", ptr->name, ptr->score);
            ptr = ptr->next;
        }
    }
}
