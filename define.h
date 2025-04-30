#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<Windows.h>

#define STU_NUM 50			//教学班学生人数上限
#define COURSE_NUM 10		//一学期的课程门数上限
#define NAME_LEN 10			//学生姓名（字符串）最大长度
#define POS_X1 35			//菜单页，第一列所有功能输出起始位置的坐标值；排序之后输出提示起点的x坐标值
#define POS_X2 40			//输入模块的提示语句起点的x坐标值
#define POS_X3 50			//第一次调用输入模块或磁盘数据读入模块功能以外的其他功能，提示“系统中尚无学生成绩信息，请先输入！”的起始位置的x坐标值
#define POS_X4 65			//菜单页，第二列所有功能输出起始位置的x坐标值
#define POS_Y 3				//排序之后输出提示起点的y坐标值
#define MAX_S 5				//最大成绩位数

typedef struct student
{
	long num;					//学号
	char name[NAME_LEN];		//学生姓名
	float score[COURSE_NUM];	//各门课程成绩
	float sum;					//各门课程总分
	float aver;					//各门课程平均分
	struct student* next;       //指向下一位置的指针
}STU;

typedef struct stud
{
	long num;					//学号
	char name[NAME_LEN];		//学生姓名
	float score[COURSE_NUM];	//各门课程成绩
	float sum;					//各门课程总分
	float aver;					//各门课程平均分
}STu;

//自定义函数声明
int Menu(void);
//操作菜单

void SetPosition(int x, int y);
//设置输出内容在控制台窗口中的起始位置

void InputRecord(int* n, int* m, STU *stu);

//输入学生信息
void AppendRecord(int* n, int m, STU *stu);
//增加学生信息

void DeleteRecord(int* n, int m, STU *stu);
//删除学生信息(指删除整条记录)

void SearchByNumber(int n, int m, STU *stu);
//按学号查询学生信息

void SearchByName(int n, int m, STU *stu);
//按姓名查询学生信息

void ModifyRecord(int n, int m, STU *stu);
//修改学生信息

void CalculateScoreOfStudent(int n, int m, STU *stu);
//计算学生的总分和平均分

void CalculateScoreOfCourse(int n, int m, STU *stu);
//计算某门课程的总分和平均分

void SortbyNum(int n, int m, STu Stu[], STU* stu);
//按学号排序

void SortbyName(int n, int m, STu Stu[], STU* stu);
//按姓名排序

void SortbyScore(int n, int m, STu Stu[], STU* stu, int(*compare)(float a, float b));
//按每个学生平均分进行排序

int Ascending(float a, float b);//升序排序

int Descending(float a, float b); //降序排序

//统计并输出各个分数段学生人数及占比
void StatisticAnalysis(int n, int m, STU *stu);

//打印学生成绩
void PrintRecord(int n, int m, STU *stu);

//将学生信息保存至文件中
void WritetoFile(int n, int m, STU *stu);

//将学生信息从文件中读出，存入内存，方便对学生信息进行处理
int ReadfromFile(int* n, int* m, STU *stu, int* first);

//说明
void Explain();