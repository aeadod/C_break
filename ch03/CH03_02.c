#include <stdio.h>
#include <stdlib.h>

int main()
{
    struct student
    {
        char name[20];
        int score;
    };
    
    typedef struct student s_data;	/* ������������Ϊs_data */
    s_data *new_student;    		/* ����һ���ṹָ�� */

    new_student = (s_data*) malloc(sizeof(s_data));   /* ���ṹ���������ڴ�ռ� */

    
        printf("������");
        scanf("%s", new_student->name);
        printf("�ɼ���");
        scanf("%d", &new_student->score);


    printf("������%s\t�ɼ���%d\n", new_student->name, new_student->score);
    
    free(new_student);/* �ͷŴ˽ṹ�������ڴ� */ 

    system("pause");
    return 0;
}
