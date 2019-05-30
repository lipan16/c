/*
 * 6-3.cpp
 *
 *  Created on: 2018年6月28日
 *      Author: asus
 */
/*
派生出manager（总经理）、technician（技术人员）、salesmanager（销售经理）、saleman（推销员）。销售经理既是经理又是销售人员，
兼具两类人员的特点，因此同时继承manager 和salesman 两个类。1、类定义
派生类saleman： 新增属性：销售额、所属部门
月薪计算办法：总经理拿固定月薪8000 元，技术人员按每小时25 元领取月薪；推销员
的月薪按当月销售额的4%提成；销售经理固定月薪5000 元加所管辖部门当月销售总额的5‰ 。
*/
/*
#include <iostream>
using namespace std;

enum{
	manager,technician,salesmanager,saleman
};

class date{
private:
	int year, month, day;
public:
	date(int y,int m,int d);
	void setYear(int year);
	void setMonth(int month);
	void setDay(int day);
	int getYear();
	int getMonth();
	int getDay();
};
date::date(int y,int m,int d){
	year=y;
	month=m;
	day=d;
}
void date::setYear(int y){
	year=y;
}
void date::setMonth(int m){
	month=m;
}
void date::setDay(int d){
	day=d;
}
int date::getYear(){
	return year;
}
int date::getMonth(){
	return month;
}
int date::getDay(){
	return day;
}

class Employee {
private:
	int id; //代号
	string name; //姓名
	string sex; //性别
	int age; //年龄
	double salary; //工资
	date dd;//出生日期
public:
	//Employee();
	Employee(int i=1000, string na="zhangsan", string s="m", int a=20, float sa=0,int yy=1998,int mm=1,int dd=1);
	void input();
	void display();
};
//Employee::Employee() {
//	id = 1000;
//	name = "";
//	sex = "";
//	age = 18;
//	salary = 0;
//	dd.setYear(1998);
//	dd.setMonth(1);
//	dd.setDay(1);
//}
Employee::Employee(int i, string na, string s, int a, float sa,int yy,int mm,int dd):dd(yy,mm,dd){
	id = i;
	name = na;
	sex = s;
	age = a;
	salary = sa;
}
void Employee::input() {
	while (true) {
		cout << "请输入ID(1000~9999):";
		cin >> id;
		if (1000 <= id && id <= 9999)
			break;
	}
	cout << "请输入姓名:";
	cin >> name;
	while (true) {
		cout << "请输入性别(f/m):";
		cin >> sex;
		if (sex == "f" || sex == "F" || sex == "m" || sex == "M")
			break;
	}
	int a;
	cout << "请输入出生年份:";
	cin >> a;
	dd.setYear(a);
	cout << "请输入出生月份:";
	cin >> a;
	dd.setMonth(a);
	cout << "请输入出生日期:";
	cin >> a;
	dd.setDay(a);
	while (true) {
		cout << "请输入年龄(18~65):";
		cin >> age;
		if (18 <= age && age <= 65)
			break;
	}
}
void Employee::display() {
	cout << "ID:" << id << "\t姓名:" << name << "出生日期:" << dd.getYear() << "年"
			<< dd.getMonth() << "月" << dd.getDay() << "日    性别:" << sex
			<< "\t年龄:" << age;
}

class Technician:public Employee{
private:
	int time;//工作时间
public:
	Technician(int i=1000, string na="zhangsan", string s="m", int a=20, float sa=0,int hour=0,int yy=1998,int mm=1,int dd=1);
	void input();
	void display();
	void getpay();
};
Technician::Technician(int i, string na, string s, int a, float sa,int hh,int yy,int mm,int dd):dd(yy,mm,dd){
	id = i;
	name = na;
	sex = s;
	age = a;
	salary = sa;
	time=hh;
}
void Technician::input(){
	Employee::input();
	cout<<"请输入工作时间:";
	cin>>time;
	getpay();
}
void Technician::display() {
	Employee::display();
	cout << "工作时间:" << time << endl;
}
void Technician::getpay(){
	salary=time*25;
}

int main(){
	Employee ee;
	ee.display();
}*/
