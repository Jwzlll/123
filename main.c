#include"define.h"

char CH;

int main()
{
    int n = 0;//学生人数
    int m = 0;//课程门数
    int end = 1;
    char ch;
    int first = 1;
    STU *stu;
    stu = (STU*)malloc(sizeof(STU));
    stu->next = NULL;
    STu Stu[STU_NUM];

    system("mode con cols=130 lines=60");
    system("color 0E");
    while (end)
    {
        system("cls");
        ch = Menu();
        switch (ch)
        {
        case 1:
            system("cls");
            InputRecord(&n, &m, stu);
            first = 0;
            system("pause");
            break;
        case 2:
            system("cls");
            if (first)
            {
                printf("系统中尚无学生成绩信息，请先输入！\n");
                system("pause");
                break;
            }
            AppendRecord(&n, m, stu);
            system("pause");
            break;
        case 3:
            system("cls");
            if (first)
            {
                printf("系统中尚无学生成绩信息，请先输入！\n");
                system("pause");
                break;
            }
            DeleteRecord(&n, m, stu);
            system("pause");
            break;
        case 4:
            system("cls");
            if (first)
            {
                printf("系统中尚无学生成绩信息，请先输入！\n");
                system("pause");
                break;
            }
            SearchByNumber(n, m, stu);
            system("pause");
            break;
        case 5:
            system("cls");
            if (first)
            {
                printf("系统中尚无学生成绩信息，请先输入！\n");
                system("pause");
                break;
            }
            SearchByName(n, m, stu);
            system("pause");
            break;
        case 6:
            system("cls");
            if (first)
            {
                printf("系统中尚无学生成绩信息，请先输入！\n");
                system("pause");
                break;
            }
            ModifyRecord(n, m, stu);
            system("pause");
            break;
        case 7:
            system("cls");
            if (first)
            {
                printf("系统中尚无学生成绩信息，请先输入！\n");
                system("pause");
                break;
            }
            CalculateScoreOfStudent(n, m, stu);
            system("pause");
            break;
        case 8:
            system("cls");
            if (first)
            {
                SetPosition(POS_X3, POS_Y);
                printf("系统中尚无学生成绩信息，请先输入！\n");
                system("pause");
                CH=getchar();
                break;
            }
            CalculateScoreOfCourse(n, m, stu);
            CH=getchar();
            system("pause");
            break;
        case 9:
            system("cls");
            if (first)
            {
                SetPosition(POS_X3, POS_Y);
                printf("系统中尚无学生成绩信息，请先输入！\n");
                CH=getchar();
                system("pause");
                break;
            }
            SortbyNum(n, m, Stu,stu);
            CH = getchar();
            system("pause");
            break;
        case 10:
            system("cls");
            if (first)
            {
                SetPosition(POS_X3, POS_Y);
                printf("系统中尚无学生成绩信息，请先输入！\n");
                CH = getchar();
                system("pause");
                break;
            }
            SortbyName(n, m, Stu,stu);
            CH = getchar();
            system("pause");
            break;
        case 11:
            system("cls");
            if (first)
            {
                SetPosition(POS_X3, POS_Y);
                printf("系统中尚无学生成绩信息，请先输入！\n");
                CH = getchar();
                system("pause");
                break;
            }
            SortbyScore(n, m, Stu, stu, Descending);
            CH = getchar();
            system("pause");
            break;
        case 12:
            system("cls");
            if (first)
            {
                SetPosition(POS_X3, POS_Y);
                printf("系统中尚无学生成绩信息，请先输入！\n");
                CH = getchar();
                system("pause");
                break;
            }
            SortbyScore(n, m, Stu, stu, Ascending);
            CH = getchar();
            system("pause");
            break;
        case 13:
            system("cls");
            if (first)
            {
                SetPosition(POS_X3, POS_Y);
                printf("系统中尚无学生成绩信息，请先输入！\n");
                CH = getchar();
                system("pause");
                break;
            }
            StatisticAnalysis(n, m, stu);
            CH = getchar();
            system("pause");
            break;
        case 14:
            system("cls");
            if (first)
            {
                SetPosition(POS_X3, POS_Y);
                printf("系统中尚无学生成绩信息，请先输入！\n");
                CH = getchar();
                system("pause");
                break;
            }
            PrintRecord(n, m, stu);
            CH = getchar();
            system("pause");
            break;
        case 15:
            system("cls");
            if (first)
            {
                SetPosition(POS_X3, POS_Y);
                printf("系统中尚无学生成绩信息，请先输入！\n");
                CH = getchar();
                system("pause");
                break;
            }
            WritetoFile(n, m, stu);
            CH = getchar();
            system("pause");
            break;
        case 16:
            system("cls");
            if (ReadfromFile(&n,&m,stu,&first)||first)
            {
                SetPosition(POS_X1, 10);
                printf("系统中尚无学生成绩信息，请先输入！\n");
                CH = getchar();
                system("pause");
                break;
            }
            CH = getchar();
            system("pause");
            break;
        case 17:
            system("cls");
            Explain();
            system("pause");
            break;
        case 0:
            system("cls");
            printf("退出系统！\n");
            system("pause");
            end = 0;
            break;
        default:
            system("cls");
            printf("输入出错，请重新选择操作！\n");
            system("pause");
        }
    }
    return 0;
}
