#include <stdio.h>
#include <stdlib.h>

int main()
{
    struct student
    {
        char name[20];
        int score;
        struct student *next;
    }; /* ���� student �ڵ� */ 
    struct student s[3]; /* �����ṹ���� */ 
    int i;
    struct student *ptr;    /* ���ö�ȡָ�� */

    /* ���ýṹ��Ա���������һ����ַ */
    for(i = 0; i < 3; i++)
    {
        printf("������");
        scanf("%s", s[i].name); /* ����ѧ������ */ 
        printf("�ɼ���");
        scanf("%d", &s[i].score);/* ����ѧ���ɼ� */ 
        if (i != 2)
            s[i].next = &s[i+1];/* ָ����һ���ڵ� */ 
        else
            s[i].next = NULL;/* ���һ���ڵ�ָ�� NULL */ 
    }
    ptr = &s[0];/* ptr ָ������ĵ�һ���ڵ� */ 
    printf("---------------------------------\n");
    while(ptr != NULL)
    {
        printf("������%s\t�ɼ���%d\n", ptr->name, ptr->score);
        ptr = ptr->next;/* ������һ���ڵ� */ 
    }/* ����������ʾ���� */
    system("pause");
    return 0;
}
