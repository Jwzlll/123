#include"define.h"

int Menu(void)
{
	int posy = 5;
	int option; //�����û�����Ĳ������ŵı��� 
	int i, j;
	SetPosition(POS_X3, posy);
	printf("    ѧ���ɼ�����ϵͳ\n");//���ϵͳ���� 
	//���ϵͳ���ֺ͹���˵��֮������ж̺��� 
	for (i = 0; i < 2; i++)
	{
		SetPosition(POS_X1, ++posy);
		for (j = 0; j < 55; j++)
		{
			printf("-");
		}
	}
	//���ϵͳ֧�ֵĹ��ܺͶ�Ӧ�Ĺ��ܴ��� 
	SetPosition(POS_X1, ++posy);
	printf("1.����ѧ����Ϣ");
	SetPosition(POS_X4, posy);
	printf("2.����ѧ���ɼ�");
	SetPosition(POS_X1, posy += 2);
	printf("3.ɾ��ѧ����Ϣ");
	SetPosition(POS_X4, posy);
	printf("4.��ѧ�Ų��Ҽ�¼");
	SetPosition(POS_X1, posy += 2);
	printf("5.���������Ҽ�¼");
	SetPosition(POS_X4, posy);
	printf("6.�޸�ѧ����Ϣ");
	SetPosition(POS_X1, posy += 2);
	printf("7.����ѧ���ɼ�");
	SetPosition(POS_X4, posy);
	printf("8.����γ̳ɼ�");
	SetPosition(POS_X1, posy += 2);
	printf("9.��ѧ������");
	SetPosition(POS_X4, posy);
	printf("10.����������");
	SetPosition(POS_X1, posy += 2);
	printf("11.���ܳɼ���������");
	SetPosition(POS_X4, posy);
	printf("12.���ܳɼ���������");
	SetPosition(POS_X1, posy += 2);
	printf("13.ѧ���ɼ�ͳ��");
	SetPosition(POS_X4, posy);
	printf("14.��ӡѧ����¼");
	SetPosition(POS_X1, posy += 2);
	printf("15.ѧ����¼����");
	SetPosition(POS_X4, posy);
	printf("16.�Ӵ��̶�ȡѧ����¼");
	SetPosition(POS_X1, posy += 2);
	printf("17.��ǰ��֪");
	SetPosition(POS_X4, posy);
	printf("0.�˳�ϵͳ");
	SetPosition(POS_X1, posy += 2);
	for (i = 0; i < 2; i++)
	{
		SetPosition(POS_X1, ++posy);
		for (j = 0; j < 55; j++)
		{
			printf("-");
		}
	}
	//��ʾ�û�������Ҫִ�еĹ��ܴ��� 
	SetPosition(POS_X1, ++posy);
	printf("��ѡ������Ҫ���еĲ���[0~16]��[  ]\b\b\b");
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
	SetPosition(POS_X2, posy);                    //���ù��λ�ã�����Ҫ��ʾ��λ��
	printf("����ѧ������(n<%d): ", STU_NUM);
	scanf_s("%d", n);
	SetPosition(POS_X2, posy += 2);                 //���ù��λ�ã�����Ҫ��ʾ��λ��
	printf("����γ�����(m<%d): ", COURSE_NUM);
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
	printf("����ѧ����ѧ�š������͸��ſγ̳ɼ���");
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
		printf("�����%d��ѧ����Ϣ��", i + 1);
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
	printf("ÿ��ѧ�����ſγ̵��ֺܷ�ƽ����Ϊ��\n");
	while(p!=NULL)
	{
		p->sum = 0;
		for (j = 0; j < m; j++)
		{
			p->sum += p->score[j];
		}
		p->aver = p->sum / m;
		printf("��%d ��ѧ�����ܷ�=%.2f, ƽ����=%.2f\n", i + 1, p->sum, p->aver);
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
	printf("���ſγ̵��ֺܷ�ƽ���ֵļ�����Ϊ��");
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
		printf("��%d�ſγ̣��ܷ�=%.2f, ƽ����=%.2f\n", j + 1, sum[j], aver[j]);
	}
}

void WritetoFile(int n, int m, STU *stu)
{
	STU* p = stu;
	int j;
	FILE* fp;
	if ((fp = fopen("student.txt", "w")) == NULL)
	{
		printf("�ļ� student.txt �޷������򿪣�");
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
	printf("������ϣ�\n");
}

int ReadfromFile(int* n, int* m, STU *stu, int* first)
{
	//�����ļ�ָ��
	FILE* fp;
	int j;
	int posy = 8;
	STU* p = stu->next, * pold, * pnew;
	SetPosition(POS_X1, posy);
	//���ļ���ָ�����ļ��Ĵ���ʽΪ������������ָ��ָ���ļ�
	if ((fp = fopen("student.txt", "r")) == NULL)
	{
		printf("�����ļ� student.txt �޷���");
		return 1;
	}
	//�����ݰ�ָ����ʽ�Ӵ����ļ�����������ѧ������ n���γ����� m �Լ�ÿλѧ������Ϣ
	while (p != NULL) {
		pold = p;
		p = p->next;
		free(pold);
	}
	//�������
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
	*first = 0;    //�޸ı�־����
	//�ر��ļ�
	fclose(fp);
	printf("���ݴӴ��̶�ȡ��ϣ�");
	return 0;
}

void AppendRecord(int* n, int m, STU *stu)
{
	STU* p = stu, * pnew;
	int i, j;
	int num_record;
	printf("��������Ҫ���ӵ�ѧ����¼������");
	scanf_s("%d", &num_record);
	while (*n + num_record > STU_NUM)  //�ж�������¼��ԭ�м�¼֮���Ƿ�С���趨����
	{
		printf("Ҫ���ӵļ�¼����̫�࣬���������룺");
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
		printf("�����%d��ѧ����Ϣ��\t", i + 1);
		scanf_s("%ld%s", &pnew->num, pnew->name,MAX_S);
		for (j = 0; j < m; j++)
		{
			scanf_s("%f", &pnew->score[j]);
		}
	}
	*n = *n + num_record;
	printf("������!\n");
	return;
}

void SearchByNumber(int n, int m, STU *stu)
{
	STU* p = stu;
	long id;
	int j;
	printf("��������Ҫ���ҵ�ѧ����ѧ�ţ�");
	scanf_s("%ld", &id);
	while (p != NULL)
	{
		if (p->num == id)
		{
			printf("�ҵ��ˣ���ѧ�Ŷ�Ӧ��ѧ����ϢΪ��\n");
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
	printf("δ�ҵ����ѧ�Ŷ�Ӧ��ѧ����¼\n");
	return;
}

void SearchByName(int n, int m, STU *stu)
{
	STU* p = stu;
	int flag = 1;
	int i, j;
	int k = 0;
	char name[NAME_LEN];
	printf("��������Ҫ���ҵ�ѧ����������");
	scanf_s("%s", name,NAME_LEN);
	name[strlen(name)] = '\0';
	for (i = 0; i < n; i++)
	{
		if (strcmp(p->name, name) == 0)
		{
			printf("�ҵ��ˣ���%d��ѧ����ϢΪ��\n", ++k);
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
		printf("δ�ҵ����������Ӧ��ѧ����¼\n");
	}
	return;
}

void DeleteRecord(int* n, int m, STU *stu)
{
	STU* p = stu, * pold = p;
	int i, j;
	long id;
	char ch;
	printf("��������Ҫɾ��ѧ����Ϣ��Ӧ��ѧ�ţ�");
	scanf_s("%ld", &id);
	for (i = 0; i < *n; i++)
	{
		if (p->num == id)
		{
			printf("�ҵ��˸�����¼����ϢΪ��\n");
			printf("%10ld%15s", p->num, p->name);
			for (j = 0; j < m; j++)
			{
				printf("%10.2f", p->score[j]);
			}
			printf("%10.2f%10.2f\n", p->sum, p->aver);
			printf("��ȷ���Ƿ���Ҫɾ��������¼��(Y/y��N/n):");
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
				printf("ɾ�����\n");
				return;
			}
			else if (ch == 'N' || ch == 'n')
			{
				printf("�ҵ��˸�ѧ����¼������ɾ��\n");
				return;
			}
			else
			{
				printf("�������\n");
				return;
			}
		}
		pold = p;
		p = p->next;
	}
	printf("δ�ҵ�������¼��\n");
	return;
}

void ModifyRecord(int n, int m, STU *stu)
{
	STU* p = stu;
	int i, j;
	long id;
	char ch;

	printf("��������Ҫ�޸���Ϣ��Ӧ��ѧ�ţ�");
	scanf_s("%ld", &id);
	for (i = 0; i < n; i++)
	{
		if (p->num == id)
		{
			printf("�ҵ��˸�����¼����ϢΪ��\n");
			printf("%10ld%15s", p->num, p->name);
			for (j = 0; j < m; j++)
			{
				printf("%10.2f", p->score[j]);
			}
			printf("%10.2f%10.2f\n", p->sum, p->aver);
			printf("��ȷ���Ƿ���Ҫ�޸ģ�(Y/N��y/n):");
			char CH=getchar();
			scanf_s("%c", &ch,1);
			if (ch == 'Y' || ch == 'y')
			{
				printf("������Ҫ�޸ĵ�ѧ����Ϣ��");
				scanf_s("%ld%s", &p->num, p->name,MAX_S);
				p->sum = 0;
				for (j = 0; j < m; j++)
				{
					scanf_s("%f", &p->score[j]);
					p->sum += p->score[j];
				}
				p->aver = p->sum / m;
				printf("�޸����\n");
				return;
			}
			else if (ch == 'N' || ch == 'n')
			{
				printf("�ҵ��˸�����¼�������޸�\n");
				return;
			}
			else
			{
				printf("�������\n");
				return;
			}
		}
		p = p->next;
	}
	printf("δ�ҵ�������¼��\n");
	return;
}

void PrintRecord(int n, int m, STU *stu)
{
	STU* p = stu;
	int i, j;
	printf("ѧ��\t\t����\t\t");
	for (j = 0; j < m; j++)
	{
		printf("�γ�%d\t\t", j + 1);
	}
	printf("�ܷ�\t\tƽ����\n");

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
	//�����鸳ֵ
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
	//��������ת��������
	printf("�������ֵ��ѧ����¼�������");
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
	//�����鸳ֵ
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
	//��������ת��������
	printf("��ѧ�Ŵ�С�����ѧ����¼�������");
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
	//�����鸳ֵ
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
	//��������ת��������
	printf("��ѧ���ɼ��ֶܷ�ѧ����¼�������");
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
		printf("\n�γ�%d�ɼ�ͳ�ƽ��Ϊ��\n", j + 1);
		printf("������\t����\tռ��\n");
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
	printf("\nѧ���ɼ�ƽ����ͳ�ƽ��Ϊ��\n");
	printf("������\t����\tռ��\n");
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
	printf("������ѧ���ɼ���Ӧ��������ѧ���ɼ�\n");
	SetPosition(POS_X1, posy+=2);
	printf("������������\n");
	SetPosition(POS_X1, posy += 2);
}