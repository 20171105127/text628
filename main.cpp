
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#define LEN sizeof(struct athlete)
#define FORMAT"%-8d%-15s%-6s%-12s%-10.2f%-10.2f%-10.2f%-10.2f\n"
#define      DATA
member[i].num,member[i].name,member[i].sex,member[i].faculty,member[i].run,member[i].basketball,member[i].football,member[i].total
struct athlete                         //定义运动员信息
{
    int num;                  //编号
    char name[15];            //运动员姓名
    char sex[6];              //运动员性别
    char faculty[12];         //运动员所在院系
    float run;                //跑步分数
    float basketball;         //篮球分数
    float football;           //足球分数
    float total;              //该运动员总分数
};
struct athlete member[50];            //定义结构体数组
void menu();                          //主界面
void in();                            //录入运动员信息
void show();                          //显示运动员信息
void del();                           //删除运动员信息
void modify();                        //修改运动员信息
void total();                         //计算某一运动员的总分
void search();                        //查找运动员信息
