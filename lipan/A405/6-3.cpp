/*
 * 6-3.cpp
 *
 *  Created on: 2018��6��28��
 *      Author: asus
 */
/*
������manager���ܾ�����technician��������Ա����salesmanager�����۾�����saleman������Ա�������۾�����Ǿ�������������Ա��
���������Ա���ص㣬���ͬʱ�̳�manager ��salesman �����ࡣ1���ඨ��
������saleman�� �������ԣ����۶��������
��н����취���ܾ����ù̶���н8000 Ԫ��������Ա��ÿСʱ25 Ԫ��ȡ��н������Ա
����н���������۶��4%��ɣ����۾���̶���н5000 Ԫ������Ͻ���ŵ��������ܶ��5�� ��
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
	int id; //����
	string name; //����
	string sex; //�Ա�
	int age; //����
	double salary; //����
	date dd;//��������
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
		cout << "������ID(1000~9999):";
		cin >> id;
		if (1000 <= id && id <= 9999)
			break;
	}
	cout << "����������:";
	cin >> name;
	while (true) {
		cout << "�������Ա�(f/m):";
		cin >> sex;
		if (sex == "f" || sex == "F" || sex == "m" || sex == "M")
			break;
	}
	int a;
	cout << "������������:";
	cin >> a;
	dd.setYear(a);
	cout << "����������·�:";
	cin >> a;
	dd.setMonth(a);
	cout << "�������������:";
	cin >> a;
	dd.setDay(a);
	while (true) {
		cout << "����������(18~65):";
		cin >> age;
		if (18 <= age && age <= 65)
			break;
	}
}
void Employee::display() {
	cout << "ID:" << id << "\t����:" << name << "��������:" << dd.getYear() << "��"
			<< dd.getMonth() << "��" << dd.getDay() << "��    �Ա�:" << sex
			<< "\t����:" << age;
}

class Technician:public Employee{
private:
	int time;//����ʱ��
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
	cout<<"�����빤��ʱ��:";
	cin>>time;
	getpay();
}
void Technician::display() {
	Employee::display();
	cout << "����ʱ��:" << time << endl;
}
void Technician::getpay(){
	salary=time*25;
}

int main(){
	Employee ee;
	ee.display();
}*/
