/*
 * test10.cpp
 *
 *  Created on: 2018年6月19日
 *      Author: asus
 */

/*
#include <iostream>
#include <fstream>

using namespace std;

static int index=0,ID[9000]={0};


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
	virtual ~Employee();
	virtual void input();
	virtual void display();
	virtual void storelog()=0;
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
	while (true) {
		reid: cout << "请输入ID(1000~9999):";
		cin >> id;
		if (1000 <= id && id <= 9999) {
			for (int j = 0; j <= index; j++) {
				if (id == ID[j]) {
					cout << "该ID已被使用..." << endl;
					goto reid;
				}
			}
			ID[index] = id;
			index++;
			break;
		}
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
}
void Employee::display() {
	cout << id << "\t" << name << "\t" << sex << "\t" << age;
}



class Teacher: public Employee {
protected:
	int hour; //工作时长
	float basepay; //基本工资
public:
	Teacher();
	Teacher(int i, string na, string s, int a, float sa, int h, float b);
	~Teacher();
	void input();
	void display();
	void storelog();
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
		cout << "请输入月课时(0~40):";
		cin >> hour;
		if (0 <= hour && hour <= 40)
			break;
	}
	getpay();
	storelog();
}
void Teacher::getpay() {
	salary = basepay + hour * 30;
}
void Teacher::display() {
	Employee::display();
	cout << '\t' << hour << '\t' << basepay << '\t' << salary << endl;
}
void Teacher::storelog() {
	ofstream outstuf("log.txt", ios::app);
	if (!outstuf) {
		cerr << "log.txt : File could not be open!" << endl;
		return;
	}
	outstuf << "\t\t******教师信息******" << endl;
	outstuf << "id\t\tname\tsex\tage\thour\tbasepay\tsalary" << endl;
	outstuf << id << '\t' << name << "\t\t" << sex << '\t' << age << '\t'
			<< hour << "\t\t" << basepay << '\t' << salary << endl;
	outstuf.close();
}



class Labworker: public Employee {
protected:
	int hour; //值班时常
	float basepay; //基本工资
	float allowance; //实验室补助
public:
	Labworker();
	Labworker(int i, string na, string s, int a, float sa, int h, float b, float al);
	~Labworker();
	void input();
	void display();
	void storelog();
	void getpay();
};
Labworker::Labworker() {
	hour = 0;
	basepay = 800;
	allowance = 150;
}
Labworker::Labworker(int i, string na, string s, int a, float sa, int h, float b, float al) {
	id = i;
	name = na;
	sex = s;
	age = a;
	salary = sa;
	hour = h;
	basepay = b;
	allowance = al;
}
Labworker::~Labworker() {
	hour = 0;
	basepay = 0;
	allowance = 0;
}
void Labworker::input() {
	Employee::input();
	while (true) {
		cout << "请输入值班时长(0~40):";
		cin >> hour;
		if (0 <= hour && hour <= 40)
			break;
	}
	getpay();
	storelog();
}
void Labworker::getpay() {
	salary = basepay + allowance + hour * 5;
}
void Labworker::display() {
	Employee::display();
	cout << "\t" << hour << "\t" << basepay << '\t' << allowance << "\t\t" << salary << endl;
}
void Labworker::storelog() {
	ofstream outstuf("log.txt", ios::app);
	if (!outstuf) {
		cerr << "log.txt : File could not be open!" << endl;
		return;
	}
	outstuf << "\t\t******实验员信息******" << endl;
	outstuf << "id\t\tname\tsex\tage\thour\tallowance\tsalary" << endl;
	outstuf << id << '\t' << name << "\t\t" << sex << '\t' << age << '\t'
			<< hour << "\t\t" << allowance << "\t\t\t" << salary << endl;
	outstuf.close();
}



class Admin: public Employee {
protected:
	float basepay; //基本工资
	float allowance; //津贴
public:
	Admin();
	Admin(int i, string na, string s, int a, float sa, float b, float al);
	~Admin();
	void input();
	void display();
	void storelog();
	void getpay();
};
Admin::Admin() {
	basepay = 900;
	allowance = 200;
}
Admin::Admin(int i, string na, string s, int a, float sa, float b, float al) {
	id = i;
	name = na;
	sex = s;
	age = a;
	salary = sa;
	basepay = b;
	allowance = al;
}
Admin::~Admin() {
	basepay = 0;
	allowance = 0;
}
void Admin::input() {
	Employee::input();
	getpay();
	storelog();
}
void Admin::getpay() {
	salary = basepay + allowance;
}
void Admin::display() {
	Employee::display();
	cout << "\t" << basepay << "\t" << allowance << "\t\t" << salary << endl;
}
void Admin::storelog() {
	ofstream outstuf("log.txt", ios::app);
	if (!outstuf) {
		cerr << "log.txt : File could not be open!" << endl;
		return;
	}
	outstuf << "\t\t******行政人员信息******" << endl;
	outstuf << "id\t\tname\tsex\tage\tbasepay\tallowance\tsalary" << endl;
	outstuf << id << '\t' << name << "\t\t" << sex << '\t' << age << '\t'
			<< basepay << "\t\t" << allowance << "\t\t\t" << salary << endl;
	outstuf.close();
}



int main() {
	Teacher *te = NULL;
	Labworker *la = NULL;
	Admin *ad = NULL;
	int N1 = 0, N2 = 0, N3 = 0; //分别表示三类人员的数目
	int option = 0; //定义一个选择变量
	while (true) {
		cout << "******************************" << endl;
		cout << "****继承和派生类的设计及应用*****" << endl;
		cout << "****** 1、输入教师信息 ******" << endl;
		cout << "****** 2、输出教师信息 ******" << endl;
		cout << "****** 3、输入实验员信息 ******" << endl;
		cout << "****** 4、输出实验员信息 ******" << endl;
		cout << "****** 5、输入行政人员信息 ******" << endl;
		cout << "****** 6、输出行政人员信息 ******" << endl;
		cout << "****** 0、退出 ******" << endl;
		cout << "******************************" << endl;
		cout << "\t请选择菜单项:";
		cin >> option;
		switch (option) {
		case 0:
			return 0;
		case 1: {
			cout << "确定要输入教师信息的人数:";
			cin >> N1;
			Teacher *t = new Teacher[N1];
			te = t;
			cout << "***请开始输入教师信息***" << endl;
			for (int i = 0; i < N1; i++)
				te[i].input();
			break;
		}
		case 2: {
			if (te == NULL) {
				cout << "暂无此数据" << endl;
				break;
			}
			cout << "\t******教师信息******" << endl;
			cout << "id\tname\tsex\tage\thour\tbasepay\tsalary" << endl;
			for (int i = 0; i < N1; i++)
				te[i].display();
			cout << endl;
			break;
		}
		case 3: {
			cout << "确定要输入实验员信息的人数:";
			cin >> N2;
			Labworker *l = new Labworker[N2];
			la = l;
			cout << "***请开始输入实验员信息***" << endl;
			for (int i = 0; i < N2; i++)
				la[i].input();
			break;
		}
		case 4: {
			if (la == NULL) {
				cout << "暂无此数据" << endl;
				break;
			}
			cout << "\t******实验员信息******" << endl;
			cout << "id\tname\tsex\tage\ttime\tbasepay\tallowance\tsalary" << endl;
			for (int i = 0; i < N2; i++)
				la[i].display();
			cout << endl;
			break;
		}
		case 5: {
			cout << "确定要输入行政人员信息的人数:";
			cin >> N3;
			Admin *a = new Admin[N3];
			ad = a;
			cout << "***请开始输入行政人员信息***" << endl;
			for (int i = 0; i < N3; i++)
				ad[i].input();
			break;
		}
		case 6: {
			if (ad == NULL) {
				cout << "暂无此数据" << endl;
				break;
			}
			cout << "\t\t******行政人员信息******" << endl;
			cout << "id\tname\tsex\tage\tbasepay\tallowance\tsalary" << endl;
			for (int i = 0; i < N3; i++)
				ad[i].display();
			cout << endl;
			break;
		}
		default: {
			cout << "请重新选择菜单项:";
			cin >> option;
		}
		}
	}
}


*/
