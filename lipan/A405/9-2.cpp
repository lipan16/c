/*
 * 9-2.cpp
 *
 *  Created on: 2018年6月23日
 *      Author: asus
 */
/*
#include <iostream>
#include <fstream>

using namespace std;

class Employee {
protected:
	int id; //代号
	string name; //姓名
	string sex; //性别
	int age; //年龄
	double salary; //工资
public:
	Employee();
	Employee(int i, string na, string s, int a, float sa);
	void input(); //输入信息
	void display(); //输出信息
	void storelog(); //存储记录到文件
	void readlog(); //读文件
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
	while (true) {
		cout << "请输入年龄(18~65):";
		cin >> age;
		if (18 <= age && age <= 65)
			break;
	}
	storelog(); //存储人员信息
}
void Employee::display() {
	cout << id << "\t" << name << "\t" << sex << "\t" << age << endl;
}
void Employee::storelog() {
	ofstream outstuf("log.txt", ios::app);
	if (!outstuf) {
		cerr << "log.txt : File could not be open!" << endl;
		return;
	}
	outstuf << "id\t\tname\tsex\tage" << endl;
	outstuf << id << '\t' << name << "\t\t" << sex << '\t' << age;
	outstuf.close();
}
void Employee::readlog(){
	char ch;
	ifstream in("log.txt", ios::in);
	if (!in) {
		cerr << "log.txt : File could not be open!" << endl;
		return;
	}
	while(in.get(ch)){
		cout<<ch;
	}
	in.close();
}
int main() {
	Employee e;
	e.input();
	e.display();
	cout << endl;
	e.readlog();
}
*/
