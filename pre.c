#include"define.h"

int Menu(void)
{
	int posy = 5;
	int option; //保存用户输入的操作代号的变量 
	int i, j;
	SetPosition(POS_X3, posy);
	printf("    学生成绩管理系统\n");//输出系统名字 
	//输出系统名字和功能说明之间的两行短横线 
	for (i = 0; i < 2; i++)
	{
		SetPosition(POS_X1, ++posy);
		for (j = 0; j < 55; j++)
		{
			printf("-");
		}
	}
	//输出系统支持的功能和对应的功能代号 
	SetPosition(POS_X1, ++posy);
	printf("1.输入学生信息");
	SetPosition(POS_X4, posy);
	printf("2.增加学生成绩");
	SetPosition(POS_X1, posy += 2);
	printf("3.删除学生信息");
	SetPosition(POS_X4, posy);
	printf("4.按学号查找记录");
	SetPosition(POS_X1, posy += 2);
	printf("5.按姓名查找记录");
	SetPosition(POS_X4, posy);
	printf("6.修改学生信息");
	SetPosition(POS_X1, posy += 2);
	printf("7.计算学生成绩");
	SetPosition(POS_X4, posy);
	printf("8.计算课程成绩");
	SetPosition(POS_X1, posy += 2);
	printf("9.按学号排序");
	SetPosition(POS_X4, posy);
	printf("10.按姓名排序");
	SetPosition(POS_X1, posy += 2);
	printf("11.按总成绩降序排序");
	SetPosition(POS_X4, posy);
	printf("12.按总成绩升序排序");
	SetPosition(POS_X1, posy += 2);
	printf("13.学生成绩统计");
	SetPosition(POS_X4, posy);
	printf("14.打印学生记录");
	SetPosition(POS_X1, posy += 2);
	printf("15.学生记录存盘");
	SetPosition(POS_X4, posy);
	printf("16.从磁盘读取学生记录");
	SetPosition(POS_X1, posy += 2);
	printf("17.用前需知");
	SetPosition(POS_X4, posy);
	printf("0.退出系统");
	SetPosition(POS_X1, posy += 2);
	for (i = 0; i < 2; i++)
	{
		SetPosition(POS_X1, ++posy);
		for (j = 0; j < 55; j++)
		{
			printf("-");
		}
	}
	//提示用户输入所要执行的功能代号 
	SetPosition(POS_X1, ++posy);
	printf("请选择你想要进行的操作[0~16]：[  ]\b\b\b");
	scanf_s("%d", &option);
	return option;
}

void SetPosition(int x, int y)
{
	HANDLE hOut;
	COORD pos;

	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(hOut, pos);
}

void InputRecord(int* n, int* m, STU *stu)
{
	STU* p, * pnew, * pold;
	p = stu->next;
	int i, j;
	int posy = 6;
	while (p != NULL) {
		pold = p;
		p = p->next;
		free(pold);
	}
	p = stu;
	pnew = stu;
	SetPosition(POS_X2, posy);                    //设置光标位置，即需要显示的位置
	printf("输入学生人数(n<%d): ", STU_NUM);
	scanf_s("%d", n);
	SetPosition(POS_X2, posy += 2);                 //设置光标位置，即需要显示的位置
	printf("输入课程门数(m<%d): ", COURSE_NUM);
	scanf_s("%d", m);
	for (i = 0; i < 2; i++)
	{
		SetPosition(POS_X1, ++posy);
		for (j = 0; j < 55; j++)
		{
			printf("-");
		}
	}
	SetPosition(POS_X2, ++posy);
	printf("输入学生的学号、姓名和各门课程成绩：");
	for (i = 0; i < *n; i++)
	{
		if (i != 0) {
			pnew = (STU*)malloc(sizeof(STU));
			memset(pnew->score, 0, sizeof(pnew->score));
			pnew->next = NULL;
			p->next = pnew;
			p = p->next;
		}
		SetPosition(POS_X2, ++posy);
		printf("输入第%d个学生信息：", i + 1);
		scanf_s("%ld%s", &pnew->num, pnew->name, MAX_S);
		for (j = 0; j < *m; j++)
		{
			scanf_s("%f", &pnew->score[j]);
		}
	}
}

void CalculateScoreOfStudent(int n, int m, STU *stu)
{
	STU* p = stu;
	int i = 0, j;
	printf("每个学生各门课程的总分和平均分为：\n");
	while(p!=NULL)
	{
		p->sum = 0;
		for (j = 0; j < m; j++)
		{
			p->sum += p->score[j];
		}
		p->aver = p->sum / m;
		printf("第%d 个学生：总分=%.2f, 平均分=%.2f\n", i + 1, p->sum, p->aver);
		i++;
		p = p->next;
	}
}

void CalculateScoreOfCourse(int n, int m, STU *stu)
{
	STU* p;
	int j;
	float sum[COURSE_NUM], aver[COURSE_NUM];
	int posy = 7;
	SetPosition(POS_X1, posy);
	printf("各门课程的总分和平均分的计算结果为：");
	for (j = 0; j < m; j++)
	{
		p = stu;
		sum[j] = 0;
		while(p!=NULL)
		{
			sum[j] += p->score[j];
			p = p->next;
		}
		aver[j] = sum[j] / n;
		SetPosition(POS_X1, ++posy);
		printf("第%d门课程：总分=%.2f, 平均分=%.2f\n", j + 1, sum[j], aver[j]);
	}
}

void WritetoFile(int n, int m, STU *stu)
{
	STU* p = stu;
	int j;
	FILE* fp;
	if ((fp = fopen("student.txt", "w")) == NULL)
	{
		printf("文件 student.txt 无法正常打开！");
		exit(0);
	}
	fprintf(fp, "%10d%10d\n", n, m);
	while(p!=NULL)
	{
		fprintf(fp, "%10ld%10s\n", p->num, p->name);
		for (j = 0; j < m; j++)
		{
			fprintf(fp, "%10.1f", p->score[j]);
		}
		fprintf(fp, "%10.1f%10.1f\n", p->sum, p->aver);
		p = p->next;
	}
	fclose(fp);
	printf("存盘完毕！\n");
}

int ReadfromFile(int* n, int* m, STU *stu, int* first)
{
	//定义文件指针
	FILE* fp;
	int j;
	int posy = 8;
	STU* p = stu->next, * pold, * pnew;
	SetPosition(POS_X1, posy);
	//打开文件，指定对文件的处理方式为读操作，并让指针指向文件
	if ((fp = fopen("student.txt", "r")) == NULL)
	{
		printf("磁盘文件 student.txt 无法打开");
		return 1;
	}
	//将数据按指定格式从磁盘文件读出，包括学生人数 n、课程门数 m 以及每位学生的信息
	while (p != NULL) {
		pold = p;
		p = p->next;
		free(pold);
	}
	//清空链表
	fscanf(fp, "%10d%10d", n, m);
	p = stu;
	int i = 0;
	while(!feof(fp))
	{
		if (i != 0) {
			pnew = (STU*)malloc(sizeof(STU));
			pnew->next = NULL;
			p->next = pnew;
			p = p->next;
		}
		fscanf(fp, "%10ld", &p->num);
		fscanf(fp, "%10s", p->name);
		for (j = 0; j < *m; j++)
		{
			fscanf(fp, "%10f", &p->score[j]);
		}
		fscanf(fp, "%10f%10f", &p->sum, &p->aver);
		i++;
	}
	*first = 0;    //修改标志变量
	//关闭文件
	fclose(fp);
	printf("数据从磁盘读取完毕！");
	return 0;
}

void AppendRecord(int* n, int m, STU *stu)
{
	STU* p = stu, * pnew;
	int i, j;
	int num_record;
	printf("请输入需要增加的学生记录条数：");
	scanf_s("%d", &num_record);
	while (*n + num_record > STU_NUM)  //判断新增记录与原有记录之和是否小于设定上限
	{
		printf("要增加的记录条数太多，请重新输入：");
		scanf_s("%d", &num_record);
	}
	while (p->next != NULL)
		p = p->next;
	for (i = *n; i < *n + num_record; i++)
	{
		pnew = (STU*)malloc(sizeof(STU));
		pnew->next = NULL;
		p->next = pnew;
		p = p->next;
		printf("输入第%d个学生信息：\t", i + 1);
		scanf_s("%ld%s", &pnew->num, pnew->name,MAX_S);
		for (j = 0; j < m; j++)
		{
			scanf_s("%f", &pnew->score[j]);
		}
	}
	*n = *n + num_record;
	printf("添加完毕!\n");
	return;
}

void SearchByNumber(int n, int m, STU *stu)
{
	STU* p = stu;
	long id;
	int j;
	printf("请输入你要查找的学生的学号：");
	scanf_s("%ld", &id);
	while (p != NULL)
	{
		if (p->num == id)
		{
			printf("找到了，该学号对应的学生信息为：\n");
			printf("%10ld%15s", p->num, p->name);
			for (j = 0; j < m; j++)
			{
				printf("%10.2f", p->score[j]);
			}
			printf("%10.2f%10.2f", p->sum, p->aver);
			return;
		}
		p = p->next;
	}
	printf("未找到这个学号对应的学生记录\n");
	return;
}

void SearchByName(int n, int m, STU *stu)
{
	STU* p = stu;
	int flag = 1;
	int i, j;
	int k = 0;
	char name[NAME_LEN];
	printf("请输入你要查找的学生的姓名：");
	scanf_s("%s", name,NAME_LEN);
	name[strlen(name)] = '\0';
	for (i = 0; i < n; i++)
	{
		if (strcmp(p->name, name) == 0)
		{
			printf("找到了，第%d个学生信息为：\n", ++k);
			printf("%10ld%15s", p->num, p->name);
			for (j = 0; j < m; j++)
			{
				printf("%10.2f", p->score[j]);
			}
			printf("%10.2f%10.2f\n", p->sum, p->aver);
			flag = 0;
		}
		p = p->next;
	}
	if (flag)
	{
		printf("未找到这个姓名对应的学生记录\n");
	}
	return;
}

void DeleteRecord(int* n, int m, STU *stu)
{
	STU* p = stu, * pold = p;
	int i, j;
	long id;
	char ch;
	printf("请输入你要删除学生信息对应的学号：");
	scanf_s("%ld", &id);
	for (i = 0; i < *n; i++)
	{
		if (p->num == id)
		{
			printf("找到了该生记录，信息为：\n");
			printf("%10ld%15s", p->num, p->name);
			for (j = 0; j < m; j++)
			{
				printf("%10.2f", p->score[j]);
			}
			printf("%10.2f%10.2f\n", p->sum, p->aver);
			printf("请确认是否需要删除这条记录？(Y/y或N/n):");
			char CH = getchar();
			scanf_s("%c", &ch, 1);
			if (ch == 'Y' || ch == 'y')
			{
				if (p == stu) {
					stu = p->next;
					free(p);
				}
				else {
					pold->next = p->next;
					free(p);
				}
				(*n)--;
				printf("删除完毕\n");
				return;
			}
			else if (ch == 'N' || ch == 'n')
			{
				printf("找到了该学生记录，但不删除\n");
				return;
			}
			else
			{
				printf("输入出错！\n");
				return;
			}
		}
		pold = p;
		p = p->next;
	}
	printf("未找到该生记录！\n");
	return;
}

void ModifyRecord(int n, int m, STU *stu)
{
	STU* p = stu;
	int i, j;
	long id;
	char ch;

	printf("请输入需要修改信息对应的学号：");
	scanf_s("%ld", &id);
	for (i = 0; i < n; i++)
	{
		if (p->num == id)
		{
			printf("找到了该生记录，信息为：\n");
			printf("%10ld%15s", p->num, p->name);
			for (j = 0; j < m; j++)
			{
				printf("%10.2f", p->score[j]);
			}
			printf("%10.2f%10.2f\n", p->sum, p->aver);
			printf("请确认是否需要修改？(Y/N或y/n):");
			char CH=getchar();
			scanf_s("%c", &ch,1);
			if (ch == 'Y' || ch == 'y')
			{
				printf("请输入要修改的学生信息：");
				scanf_s("%ld%s", &p->num, p->name,MAX_S);
				p->sum = 0;
				for (j = 0; j < m; j++)
				{
					scanf_s("%f", &p->score[j]);
					p->sum += p->score[j];
				}
				p->aver = p->sum / m;
				printf("修改完毕\n");
				return;
			}
			else if (ch == 'N' || ch == 'n')
			{
				printf("找到了该生记录，但不修改\n");
				return;
			}
			else
			{
				printf("输入出错！\n");
				return;
			}
		}
		p = p->next;
	}
	printf("未找到该生记录！\n");
	return;
}

void PrintRecord(int n, int m, STU *stu)
{
	STU* p = stu;
	int i, j;
	printf("学号\t\t姓名\t\t");
	for (j = 0; j < m; j++)
	{
		printf("课程%d\t\t", j + 1);
	}
	printf("总分\t\t平均分\n");

	for (i = 0; i < n; i++)
	{
		printf("%-16ld%-16s", p->num, p->name);
		for (j = 0; j < m; j++)
		{
			printf("%-16.1lf", p->score[j]);
		}
		printf("%-16.1lf%-16.1lf\n", p->sum, p->aver);
		p = p->next;
	}
	return;
}

void SortbyName(int n, int m, STu Stu[], STU* stu)
{
	STU* p = stu;
	int i, j;
	STu temp;
	for (i = 0; i < n; i++)
	{
		Stu[i].num = p->num;
		strcpy(Stu[i].name, p->name);
		for (j = 0; j < m; j++)
		{
			Stu[i].score[j] = p->score[j];
		}
		Stu[i].sum = p->sum;
		Stu[i].aver = p->aver;
		p = p->next;
	}
	//给数组赋值
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n - 1 - i; j++)
		{
			if (strcmp(Stu[j].name, Stu[j + 1].name) > 0)
			{
				temp = Stu[j];
				Stu[j] = Stu[j + 1];
				Stu[j + 1] = temp;
			}
		}
	}
	p = stu;
	for (i = 0; i < n; i++)
	{
		p->num = Stu[i].num;
		strcpy(p->name, Stu[i].name);
		for (j = 0; j < m; j++)
		{
			p->score[j] = Stu[i].score[j];
		}
		p->sum = Stu[i].sum;
		p->aver = Stu[i].aver;
		p = p->next;
	}
	//将排序结果转到链表里
	printf("按姓名字典对学生记录排序完毕");
	return;
}

void SortbyNum(int n, int m, STu Stu[], STU* stu)
{
	STU* p = stu;
	int i, j;
	STu temp;
	for (i = 0; i < n; i++)
	{
		Stu[i].num = p->num;
		strcpy(Stu[i].name, p->name);
		for (j = 0; j < m; j++)
		{
			Stu[i].score[j] = p->score[j];
		}
		Stu[i].sum = p->sum;
		Stu[i].aver = p->aver;
		p = p->next;
	}
	//给数组赋值
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n - 1 - i; j++)
		{
			if (Stu[j].num > Stu[j + 1].num)
			{
				temp = Stu[j];
				Stu[j] = Stu[j + 1];
				Stu[j + 1] = temp;
			}
		}
	}
	p = stu;
	for (i = 0; i < n; i++)
	{
		p->num = Stu[i].num;
		strcpy(p->name, Stu[i].name);
		for (j = 0; j < m; j++)
		{
			p->score[j] = Stu[i].score[j];
		}
		p->sum = Stu[i].sum;
		p->aver = Stu[i].aver;
		p = p->next;
	}
	//将排序结果转到链表里
	printf("按学号从小到大对学生记录排序完毕");
	return;
}

void SortbyScore(int n, int m, STu Stu[], STU* stu, int(*compare)(float a, float b))
{
	STU* p = stu;
	int i, j;
	STu temp;
	for (i = 0; i < n; i++)
	{
		Stu[i].num = p->num;
		strcpy(Stu[i].name, p->name);
		for (j = 0; j < m; j++)
		{
			Stu[i].score[j] = p->score[j];
		}
		Stu[i].sum = p->sum;
		Stu[i].aver = p->aver;
		p = p->next;
	}
	//给数组赋值
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n - 1 - i; j++)
		{
			if (!(*compare)(Stu[j].sum, Stu[j + 1].sum))
			{
				temp = Stu[j];
				Stu[j] = Stu[j + 1];
				Stu[j + 1] = temp;
			}
		}
	}
	p = stu;
	for (i = 0; i < n; i++)
	{
		p->num = Stu[i].num;
		strcpy(p->name, Stu[i].name);
		for (j = 0; j < m; j++)
		{
			p->score[j] = Stu[i].score[j];
		}
		p->sum = Stu[i].sum;
		p->aver = Stu[i].aver;
		p = p->next;
	}
	//将排序结果转到链表里
	printf("按学生成绩总分对学生记录排序完毕");
}

int Descending(float a, float b)
{
	return a > b;
}

int Ascending(float a, float b)
{
	return a < b;
}

void StatisticAnalysis(int n, int m, STU *stu)
{
	STU* p = stu;
	int i, j, t[6];

	for (j = 0; j < m; j++)
	{
		printf("\n课程%d成绩统计结果为：\n", j + 1);
		printf("分数段\t人数\t占比\n");
		memset(t, 0, sizeof(t));
		for (i = 0; i < n; i++)
		{
			if (p->score[j] >= 0 && p->score[j] < 60)
				t[0]++;
			else if (p->score[j] < 70)
				t[1]++;
			else if (p->score[j] < 80)
				t[2]++;
			else if (p->score[j] < 90)
				t[3]++;
			else if (p->score[j] < 100)
				t[4]++;
			else if (p->score[j] == 100)
				t[5]++;
			p = p->next;
		}

		for (i = 0; i < 6; i++)
		{
			if (i == 0)
				printf("<60\t%d\t%.2f%%\n", t[i], (float)t[i] / n * 100);
			else if (i == 5)
				printf("100\t%d\t%.2f%%\n", t[i], (float)t[i] / n * 100);
			else
				printf("%d-%d\t%d\t%.2f%%\n", (i + 5) * 10, (i + 5) * 10 + 9, t[i], (float)t[i] / n * 100);
		}
	}
	p = stu;
	printf("\n学生成绩平均分统计结果为：\n");
	printf("分数段\t人数\t占比\n");
	memset(t, 0, sizeof(t));
	for (i = 0; i < n; i++)
	{
		if (p->aver >= 0 && p->aver < 60)
			t[0]++;
		else if (p->aver < 70)
			t[1]++;
		else if (p->aver < 80)
			t[2]++;
		else if (p->aver < 90)
			t[3]++;
		else if (p->aver < 100)
			t[4]++;
		else if (p->aver == 100)
			t[5]++;
		p = p->next;;
	}
	for (i = 0; i < 6; i++)
	{
		if (i == 0)
			printf("<60\t%d\t%.2f%%\n", t[i], (float)t[i] / n * 100);
		else if (i == 5)
			printf("100\t%d\t%.2f%%\n", t[i], (float)t[i] / n * 100);
		else
			printf("%d-%d\t%d\t%.2f%%\n", (i + 5) * 10, (i + 5) * 10 + 9, t[i], (float)t[i] / n * 100);
	}
}

void Explain()
{
	int posy = 5;
	SetPosition(POS_X1, posy);
	printf("输入完学生成绩后应立即计算学生成绩\n");
	SetPosition(POS_X1, posy+=2);
	printf("否则会出现问题\n");
	SetPosition(POS_X1, posy += 2);
}