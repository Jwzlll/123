#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<Windows.h>

#define STU_NUM 50			//��ѧ��ѧ����������
#define COURSE_NUM 10		//һѧ�ڵĿγ���������
#define NAME_LEN 10			//ѧ���������ַ�������󳤶�
#define POS_X1 35			//�˵�ҳ����һ�����й��������ʼλ�õ�����ֵ������֮�������ʾ����x����ֵ
#define POS_X2 40			//����ģ�����ʾ�������x����ֵ
#define POS_X3 50			//��һ�ε�������ģ���������ݶ���ģ�鹦��������������ܣ���ʾ��ϵͳ������ѧ���ɼ���Ϣ���������룡������ʼλ�õ�x����ֵ
#define POS_X4 65			//�˵�ҳ���ڶ������й��������ʼλ�õ�x����ֵ
#define POS_Y 3				//����֮�������ʾ����y����ֵ
#define MAX_S 5				//���ɼ�λ��

typedef struct student
{
	long num;					//ѧ��
	char name[NAME_LEN];		//ѧ������
	float score[COURSE_NUM];	//���ſγ̳ɼ�
	float sum;					//���ſγ��ܷ�
	float aver;					//���ſγ�ƽ����
	struct student* next;       //ָ����һλ�õ�ָ��
}STU;

typedef struct stud
{
	long num;					//ѧ��
	char name[NAME_LEN];		//ѧ������
	float score[COURSE_NUM];	//���ſγ̳ɼ�
	float sum;					//���ſγ��ܷ�
	float aver;					//���ſγ�ƽ����
}STu;

//�Զ��庯������
int Menu(void);
//�����˵�

void SetPosition(int x, int y);
//������������ڿ���̨�����е���ʼλ��

void InputRecord(int* n, int* m, STU *stu);

//����ѧ����Ϣ
void AppendRecord(int* n, int m, STU *stu);
//����ѧ����Ϣ

void DeleteRecord(int* n, int m, STU *stu);
//ɾ��ѧ����Ϣ(ָɾ��������¼)

void SearchByNumber(int n, int m, STU *stu);
//��ѧ�Ų�ѯѧ����Ϣ

void SearchByName(int n, int m, STU *stu);
//��������ѯѧ����Ϣ

void ModifyRecord(int n, int m, STU *stu);
//�޸�ѧ����Ϣ

void CalculateScoreOfStudent(int n, int m, STU *stu);
//����ѧ�����ֺܷ�ƽ����

void CalculateScoreOfCourse(int n, int m, STU *stu);
//����ĳ�ſγ̵��ֺܷ�ƽ����

void SortbyNum(int n, int m, STu Stu[], STU* stu);
//��ѧ������

void SortbyName(int n, int m, STu Stu[], STU* stu);
//����������

void SortbyScore(int n, int m, STu Stu[], STU* stu, int(*compare)(float a, float b));
//��ÿ��ѧ��ƽ���ֽ�������

int Ascending(float a, float b);//��������

int Descending(float a, float b); //��������

//ͳ�Ʋ��������������ѧ��������ռ��
void StatisticAnalysis(int n, int m, STU *stu);

//��ӡѧ���ɼ�
void PrintRecord(int n, int m, STU *stu);

//��ѧ����Ϣ�������ļ���
void WritetoFile(int n, int m, STU *stu);

//��ѧ����Ϣ���ļ��ж����������ڴ棬�����ѧ����Ϣ���д���
int ReadfromFile(int* n, int* m, STU *stu, int* first);

//˵��
void Explain();