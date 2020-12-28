#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void createHomework(FILE *fp)
{
    if (fp == NULL)
    {
        fp = fopen("hwk.txt", "w");
    }
    int a, b;
    char sign, ch;
    while (1)
    {
        printf("输入任意键开始，esc退出：\n");
        ch = _getch();
        if (ch == 27)
        {
            fclose(fp);
            fp = NULL;
            exit(1);
        }
        printf("请输入两个整数已及运算符(格式a,b,+):");
        scanf("%d,%d,%c", &a, &b, &sign);
        char hw[100];
        sprintf(hw, "%d%c%d=\n", a, sign, b);
        fputs(hw, fp);
    }
}

int main(int argc, char const *argv[])
{

    FILE *fp = fopen("hwk.txt", "w");
    printf("====小学生数学作业生成器====\n");
    //printf("输入任意键开始，esc退出：\n");
    createHomework(fp);
}