#include <stdio.h>
#include <stdlib.h>
#include <string.h>/* �]�t�r��B�z��� */ 

int push(char*, int);    /* �m�J���|��� */
int pop();           /* ���X���|��� */
int show();          /* ��ܰ��|��� */

struct student
{
    char name[20];
    int score;
    struct student *next;
};
typedef struct student s_data;
s_data *top = NULL;

int main()
{
    int select, score;
    char name[20];

    do
    {
        printf("(1)�s�J (2)���X (3)���X (4)���} => ");
        scanf("%d", &select);
        switch (select)
        {
            case 1:
                printf("�m�W ���Z�G");
                scanf("%s %d", name, &score);
                push(name, score);
                break;
            case 2:
                pop();
                break;
            case 3:
                show();
                break;
        }
    } while (select != 4);
    
    system("pause");
    return 0;
}

int push(char* name, int score)/* �s�J�s���� */
{
    s_data *new_data;

    new_data = (s_data*) malloc(sizeof(s_data));    /* �t�m�Ŷ����s���� */
    strcpy(new_data->name, name);    /* �]�w�s��������Ƥ��e */
    new_data->score = score;
    new_data->next = top;    /* �N�s������next���V����|���� */
    top = new_data;    /* �]�w�s���������|���� */
}

int pop() /* ���X�s���� */
{
    s_data *freeme;

    if(top != NULL)   /* �p�G���|������ */
    {
        printf("�m�W�G%s\t���Z�G%d......���X\n", top->name, top->score);
        freeme = top;   /* �]�wfreeme���СA�ݷ|�n���񥦩ҫ��V����m */
        top = top->next;    /* �]�w�s���|���� */
        free(freeme);    /* ����freeme���V���O����Ŷ� */
    }
    else
        printf("���|�w�šI\n");
}

int show()/* ���X���|�}�C */
{
    s_data *ptr;
    ptr = top;
    if (ptr == NULL)    /* �p�G���V�Ŧ�}�A��ܰ��|���� */
        printf("���|�w��\n");
    else
    {
        while (ptr != NULL)    /* �ѤW���U���X���| */
        {
            printf("�m�W�G%s\t���Z�G%d\n", ptr->name, ptr->score);
            ptr = ptr->next;
        }
    }
}
