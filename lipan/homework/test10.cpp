/*
 * test10.cpp
 *
 *  Created on: 2018��6��19��
 *      Author: asus
 */

/*
#include <iostream>
#include <fstream>

using namespace std;

static int index=0,ID[9000]={0};


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
		reid: cout << "������ID(1000~9999):";
		cin >> id;
		if (1000 <= id && id <= 9999) {
			for (int j = 0; j <= index; j++) {
				if (id == ID[j]) {
					cout << "��ID�ѱ�ʹ��..." << endl;
					goto reid;
				}
			}
			ID[index] = id;
			index++;
			break;
		}
	}
	cout << "����������:";
	cin >> name;
	while (true) {
		cout << "�������Ա�(f/m):";
		cin >> sex;
		if (sex == "f" || sex == "F" || sex == "m" || sex == "M")
			break;
	}
	while (true) {
		cout << "����������(18~65):";
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
	int hour; //����ʱ��
	float basepay; //��������
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
		cout << "�������¿�ʱ(0~40):";
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
	outstuf << "\t\t******��ʦ��Ϣ******" << endl;
	outstuf << "id\t\tname\tsex\tage\thour\tbasepay\tsalary" << endl;
	outstuf << id << '\t' << name << "\t\t" << sex << '\t' << age << '\t'
			<< hour << "\t\t" << basepay << '\t' << salary << endl;
	outstuf.close();
}



class Labworker: public Employee {
protected:
	int hour; //ֵ��ʱ��
	float basepay; //��������
	float allowance; //ʵ���Ҳ���
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
		cout << "������ֵ��ʱ��(0~40):";
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
	outstuf << "\t\t******ʵ��Ա��Ϣ******" << endl;
	outstuf << "id\t\tname\tsex\tage\thour\tallowance\tsalary" << endl;
	outstuf << id << '\t' << name << "\t\t" << sex << '\t' << age << '\t'
			<< hour << "\t\t" << allowance << "\t\t\t" << salary << endl;
	outstuf.close();
}



class Admin: public Employee {
protected:
	float basepay; //��������
	float allowance; //����
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
	outstuf << "\t\t******������Ա��Ϣ******" << endl;
	outstuf << "id\t\tname\tsex\tage\tbasepay\tallowance\tsalary" << endl;
	outstuf << id << '\t' << name << "\t\t" << sex << '\t' << age << '\t'
			<< basepay << "\t\t" << allowance << "\t\t\t" << salary << endl;
	outstuf.close();
}



int main() {
	Teacher *te = NULL;
	Labworker *la = NULL;
	Admin *ad = NULL;
	int N1 = 0, N2 = 0, N3 = 0; //�ֱ��ʾ������Ա����Ŀ
	int option = 0; //����һ��ѡ�����
	while (true) {
		cout << "******************************" << endl;
		cout << "****�̳к����������Ƽ�Ӧ��*****" << endl;
		cout << "****** 1�������ʦ��Ϣ ******" << endl;
		cout << "****** 2�������ʦ��Ϣ ******" << endl;
		cout << "****** 3������ʵ��Ա��Ϣ ******" << endl;
		cout << "****** 4�����ʵ��Ա��Ϣ ******" << endl;
		cout << "****** 5������������Ա��Ϣ ******" << endl;
		cout << "****** 6�����������Ա��Ϣ ******" << endl;
		cout << "****** 0���˳� ******" << endl;
		cout << "******************************" << endl;
		cout << "\t��ѡ��˵���:";
		cin >> option;
		switch (option) {
		case 0:
			return 0;
		case 1: {
			cout << "ȷ��Ҫ�����ʦ��Ϣ������:";
			cin >> N1;
			Teacher *t = new Teacher[N1];
			te = t;
			cout << "***�뿪ʼ�����ʦ��Ϣ***" << endl;
			for (int i = 0; i < N1; i++)
				te[i].input();
			break;
		}
		case 2: {
			if (te == NULL) {
				cout << "���޴�����" << endl;
				break;
			}
			cout << "\t******��ʦ��Ϣ******" << endl;
			cout << "id\tname\tsex\tage\thour\tbasepay\tsalary" << endl;
			for (int i = 0; i < N1; i++)
				te[i].display();
			cout << endl;
			break;
		}
		case 3: {
			cout << "ȷ��Ҫ����ʵ��Ա��Ϣ������:";
			cin >> N2;
			Labworker *l = new Labworker[N2];
			la = l;
			cout << "***�뿪ʼ����ʵ��Ա��Ϣ***" << endl;
			for (int i = 0; i < N2; i++)
				la[i].input();
			break;
		}
		case 4: {
			if (la == NULL) {
				cout << "���޴�����" << endl;
				break;
			}
			cout << "\t******ʵ��Ա��Ϣ******" << endl;
			cout << "id\tname\tsex\tage\ttime\tbasepay\tallowance\tsalary" << endl;
			for (int i = 0; i < N2; i++)
				la[i].display();
			cout << endl;
			break;
		}
		case 5: {
			cout << "ȷ��Ҫ����������Ա��Ϣ������:";
			cin >> N3;
			Admin *a = new Admin[N3];
			ad = a;
			cout << "***�뿪ʼ����������Ա��Ϣ***" << endl;
			for (int i = 0; i < N3; i++)
				ad[i].input();
			break;
		}
		case 6: {
			if (ad == NULL) {
				cout << "���޴�����" << endl;
				break;
			}
			cout << "\t\t******������Ա��Ϣ******" << endl;
			cout << "id\tname\tsex\tage\tbasepay\tallowance\tsalary" << endl;
			for (int i = 0; i < N3; i++)
				ad[i].display();
			cout << endl;
			break;
		}
		default: {
			cout << "������ѡ��˵���:";
			cin >> option;
		}
		}
	}
}


*/
