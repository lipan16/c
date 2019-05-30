/*
 * text11.cpp
 *
 *  Created on: 2018��6��21��
 *      Author: asus
 */
/*

#include <iostream>
#include <fstream>

using namespace std;


class Employee {
protected:
	int id; //����
	string name; //����
	string sex; //�Ա�
	int age; //����
	double salary; //����
public:
	Employee();
	Employee(int i, string na, string s, int a, float sa);
	virtual ~Employee();
	virtual void input();
	virtual void display();
	virtual void storelog();
};
Employee::Employee() {
	id = 1000;
	name = "";
	sex = "";
	age = 18;
	salary = 0;
}
Employee::Employee(int i, string na, string s, int a, float sa) {
	id = i;
	name = na;
	sex = s;
	age = a;
	salary = sa;
}
Employee::~Employee() {
	id = 0;
	name = "";
	sex = "";
	age = 0;
	salary = 0;
}
void Employee::input() {
	cout << "������ID(1000~9999):";
	cin >> id;
	cout << "����������:";
	cin >> name;
	cout << "�������Ա�(f/m):";
	cin >> sex;
	cout << "����������(18~65):";
	cin >> age;
}
void Employee::display() {
	cout << id << "\t" << name << "\t" << sex << "\t" << age;
}
void Employee::storelog() {
	ofstream outstuf("log.txt", ios::app);
	if (!outstuf) {
		cerr << "log.txt : File could not be open!" << endl;
		return;
	}
	outstuf << "\t******��ʦ��Ϣ******" << endl;
	outstuf << "id\t\tname\tsex\tage" << endl;
	outstuf << id << '\t' << name << '\t' << '\t' << sex << '\t' << age << endl;
	outstuf.close();
}

class Teacher: public Employee {
protected:
	int hour; //����ʱ��
	float basepay; //��������
public:
	Teacher();
	Teacher(int i, string na, string s, int a, float sa, int h, float b);
	~Teacher();
	void input();
	void display();
	void getpay();
};
Teacher::Teacher() {
	hour = 0;
	basepay = 1000;
}
Teacher::Teacher(int i, string na, string s, int a, float sa, int h, float b) {
	id = i;
	name = na;
	sex = s;
	age = a;
	salary = sa;
	hour = h;
	basepay = b;
}
Teacher::~Teacher() {
	hour = 0;
	basepay = 0;
}
void Teacher::input() {
	Employee::input();
	while (true) {
		cout << "�������¿�ʱ(0~40):";
		cin >> hour;
		if (0 <= hour && hour <= 40) {
			getpay();
			break;
		}
	}
}
void Teacher::getpay() {
	salary = basepay + hour * 30;
}
void Teacher::display() {
	Employee::display();
	cout << "\t" << salary << endl;
}




int main() {
//	int N = 2;
//	Employee *e;
//	Teacher *t = new Teacher[N];
//	for (int i = 0; i < N; i++)
//		t[i].input();
//	for (int i = 0; i < N; i++)
//		e[i].display();

	Employee *e=new Teacher;
	e->input();
	e->storelog();
}

*/
