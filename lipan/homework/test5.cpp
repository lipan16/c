/*
 * test5.cpp
 *
 *  Created on: 2018��5��6��
 *      Author: asus
 *      ʵ�ֹ��ܣ�
 *      	����ѧ����Ϣ
 *      	setinfo������Ĭ�ϲ�����set����
 *      	search������Ĭ�ϲ����Ĳ�ѯ����
 *      	sort�������ɰ���������Ĭ�ϰ�ƽ�������򣬲���Ϊ1�ǰ���һ�ſγɼ�����2�ǰ��ڶ��ſ�������������
 */


/*
#include <iostream>
using namespace std;
#define max 4 //ѧ����Ա�ĸ���
#define n 3 //�γ̵�����

void search(string na = " ", string = "", double = 0); //��ѯ
void sort(int = 0); //����������,Ĭ�ϰ�ƽ�������򣬲���Ϊ1�ǰ���һ�ſγɼ�����2�ǰ��ڶ��ſ�������������

class student {//student��
private:
	string name; //����
	string num; //ѧ��
	double aver; //ƽ����
public:
	double score[n]; //n�ſεĳɼ�
	student(); //�����εĹ��췽��
	student(string, string, double[]); //���εĹ��췽��
	void setinfo(string, string, double[]); //set������������Ϣ
	void input();
	string getname(); //get��������name
	string getnum(); //get��������ѧ��
	double getaver(); //get��������ƽ����aver
	double faver(double[]); //����ƽ����
	void display(); //��ӡ���
} stu[max];

student::student() { //�����εĹ��췽��
	name = ""; //Ĭ������Ϊ��
	num = "10001"; //Ĭ��ѧ��Ϊ10001
	for (int i = 0; i < n; i++) {
		score[i] = 80; //ÿ�ſ�Ĭ�ϳɼ�Ϊ80
	}
	aver = faver(score); //����ƽ����
}

student::student(string na, string nu, double c[]) { //���εĹ��췽��
	name = na;//����
	num = nu;//ѧ��
	for (int i = 0; i < n; i++) {
		while (c[i] < 0 || c[i] > 100) {
			cout << "�ɼ����ݳ���  ����������:";
			cin >> c[i];
		}
		score[i] = c[i];
	}
	aver = faver(score);//ƽ����
}

void student::setinfo(string na, string nu, double c[] = NULL) { //set������������Ϣ
	name = na;
	num = nu;
	if (c == NULL) {//Ĭ�ϲ���ʱ���ֶ�����ÿ�ſγɼ�0~100
		for (int i = 0; i < n; i++) {
			cout << "�������" << i + 1 << "�ſεĳɼ�(0~100):";
			cin >> score[i];
			if (score[i] < 0 || score[i] > 100) {//���ɼ��Ƿ�Ϸ�
				cout << "��" << i + 1 << "�ſεĳɼ�������� ����������";
				i--;//������һ���൱�����������
			}
		}
	} else {//�в���ʱ���ò�����ֵ
		for (int i = 0; i < n; i++) {
			while (c[i] < 0 || c[i] > 100) {//���ɼ��Ƿ�Ϸ�
				cout << "�ɼ����ݳ���  ����������:";
				cin >> c[i];
			}
			score[i] = c[i];
		}
	}
	aver = faver(score);
}

void student::input() {
	cout << "��������:";
	cin >> name;
	cout << "����ѧ��:";
	cin >> num;
	for (int i = 0; i < n; i++) {
		cout << "�������" << i + 1 << "�ſεĳɼ�(0~100):";
		cin >> score[i];
		if (score[i] < 0 || score[i] > 100) { //���ɼ��Ƿ�Ϸ�
			cout << "��" << i + 1 << "�ſεĳɼ�������� ����������" << endl;
			i--; //������һ���൱�����������
		}
	}
	aver = faver(score);
}

string student::getname() { //get��������name
	return name;
}
string student::getnum() { //get��������ѧ��
	return num;
}
double student::getaver() { //get��������ƽ����aver
	return aver;
}
double student::faver(double a[]) { //��ƽ����
	double d = 0;
	for (int i = 0; i < n; i++) {
		d += score[i];
	}
	return d / n;
}

void student::display() { //���
	cout << "����:" << name << " ѧ��:" << num;
	for (int i = 0; i < n; i++) {
		cout << " ��" << i + 1 << "�ſγɼ�:" << score[i];
	}
	cout << " ƽ���ɼ�:" << aver << endl;
}

void search(string na, string nu, double a) { //���Һ���,��ĳһ��������ң��Ǿ�ȷ����
	bool flag = true;
	for (int i = 0; i < max; i++) {	//�������ؼ�����ƥ��
		if (na == stu[i].getname()) {
			cout << "\n������ƥ�䵽����" << endl;
			stu[i].display();
			flag = false;	//������ոùؼ����ҵ�ƥ����Ͳ����������ؼ���ƥ��
		}
	}
	if (flag) {	//��ѧ�Źؼ�����ƥ��
		for (int i = 0; i < max; i++) {
			if (nu == stu[i].getnum()) {
				cout << "\n��ѧ��ƥ�䵽����" << endl;
				stu[i].display();
				flag = false;	//������ոùؼ����ҵ�ƥ����Ͳ����������ؼ���ƥ��
			}
		}
	}
	if (flag) {	//��ƽ���ɼ��ؼ�����ƥ��
		for (int i = 0; i < max; i++) {
			if (a == stu[i].getaver()) {
				cout << "\n��ƽ���ɼ�ƥ�䵽����" << endl;
				stu[i].display();
				flag = false;	//������ոùؼ����ҵ�ƥ����Ͳ����������ؼ���ƥ��
			}
		}
	}
	if (!flag)
		return;
	else
		cout << "\n��ѯʧ��" << endl;
}

void sort(int a) {
	student s;
	int k;
	switch (a) {
	case 0:
		for (int i = 0; i < max; i++) {	//ѡ������
			k = i;
			for (int j = i; j < max; j++)
				if (stu[k].getaver() < stu[j].getaver())
					k = j;
			if (k > i) {	//����
				s.setinfo(stu[k].getname(), stu[k].getnum(), stu[k].score);
				stu[k].setinfo(stu[i].getname(), stu[i].getnum(), stu[i].score);
				stu[i].setinfo(s.getname(), s.getnum(), s.score);
			}
		}
		cout << "\n����ƽ���ɼ�������:" << endl;
		break;
	default:
		for (int i = 0; i < max; i++) {	//ѡ������
			k = i;
			for (int j = i; j < max; j++)
				if (stu[k].score[a - 1] < stu[j].score[a - 1])
					k = j;
			if (k > i) {	//����
				s.setinfo(stu[k].getname(), stu[k].getnum(), stu[k].score);
				stu[k].setinfo(stu[i].getname(), stu[i].getnum(), stu[i].score);
				stu[i].setinfo(s.getname(), s.getnum(), s.score);
			}
		}
		cout << "\n���յ�" << a << "�ſγɼ�������:" << endl;
	}
	for (int i = 0; i < max; i++) {
		stu[i].display();
	}
}


int main() {
	double a[n] = { 80, 90, 100 };//���ſεĳɼ�
	stu[1].setinfo("lyton", "10002", a);//�޸���Ϣ
	stu[2].setinfo("lytons", "10003");//�ֶ�����ɼ�
	stu[3].input();

	stu[0].display();
	stu[1].display();
	stu[2].display();
	stu[3].display();

	search(" ", "10001"); //�Ѳ�ѧ��Ϊ1332�ĳ�Ա��Ϣ
	search("lyton");
	sort(1);
}
*/




/*
#include <iostream>
#include <cstring>
#include <iomanip>

using namespace std;

class Date
{
public:
    Date(){};//ȱʡ���캯��
    ~Date();//��������
    Date(int , int , int );//�������Ĺ��캯��
    void SetYear(int year);
    void SetMonth(int month);
    void SetDay(int day);
    int GetYear();
    int GetMonth();
    int GetDay();
    int year;
    int month;
    int day;
};

class Student
{
public:
    Student(){};//Ĭ�Ϲ��캯��
    ~Student();
    Student(long nu, string na, string se, int ye, int mo, int da, int grade);//�������Ĺ��캯��


    void Display(Student *&);//���ѧ����Ϣ
    Student *next;
private:
    long number;//ѧ��
    string name;//����
    string sex;//�Ա�
    Date date;//����������
    int grade;//����
};

void Set_Student(Student *& f, Student *& r);//ѧ����Ϣ¼��
void Find_Name(Student *& f, Student *& r);//������ѯ
void Find_Number(Student *& f, Student *& r);//��Ų�ѯ
void Modify_Student(Student *& f, Student *& r);//ѧ����Ϣ�޸�
void Clear_Student(Student *& f, Student *& r);//���ѧ����Ϣ
void Aver_Grade(Student *& f, Student *& r);//����ƽ����
void Sort_Grade(Student *& f, Student *& r);//���ճɼ��Ӹߵ�������

void menu();//��ʾ�˵�
void Test();//���Ժ���

Date::~Date()
{
    cout << "Date object is end." << endl;
}
Date::Date(int y, int m, int d)//�������Ĺ��캯��
{
    year = y;
    month = m;
    day = d;
}
void Date::SetYear(int year)
{
    year = year;
}
void Date::SetMonth(int month)
{
    month = month;
}
void Date::SetDay(int day)
{
    day = day;
}
int Date::GetYear()
{
    return year;
}
int Date::GetMonth()
{
    return month;
}
int Date::GetDay()
{
    return day;
}
Student::~Student()
{
    cout << "Student object is end." << endl;
}

Student::Student(long nu = 3208007, string na = "James", string se = "Man", int ye = 1980, int mo = 11, int da = 1, int gr = 97):date(ye, mo, da)
{
    number = nu;
    name = na;
    sex = se;
    grade = gr;
}

void Display(Student *& p)
{
     cout << p->number << setw(18) << p->name << setw(20) << p->sex << setw(20) <<
    p->date.year  << "��" <<p->date.month << "��" << p->date.day << "��" << setw(22) << p->grade << endl;
}
int FindGrade(Student *&p, int grade)
{
    if(p->grade == grade)
        return 1;
    else
        return 0;
}
int FindNumber(Student *&p, long number)
{
    if(p->number == number)
        return 1;
    else
        return 0;
}
int FindName(Student *&p, string name)
{
    if(p->name == name)
        return 1;
    else
        return 0;
}

void Student_Display(Student *& f, Student *& r)//ѧ����Ϣ��ʾ
{
    Student *p = f;

    if(p == NULL)
    {
        cout << "��ǰ��ѧ����Ϣ" << endl;
    }
    else
    {
        cout << "ѧ��"  << setw(18) << "����" << setw(20) << "�Ա�" << setw(25) << "��������" << setw(25) << "�ɼ�" <<endl;
        while(p != NULL)
        {
            Display(p);
            p = p->next;
        }
    }
}
void Set_Student(Student *& f, Student *& r)//ѧ����Ϣ¼��
{

    cout << "������ѧ����Ϣ" << endl;
    Student *p = new Student(0);
    cout << "������ѧ��ѧ�� : " << endl;
    cin >> p->number;
    while(!cin)
    {
            cout << "����������long�Ͳ��������������룡" << endl << "������ѧ��ѧ�� : " << endl;
            cin.clear();
            cin.sync();
            cin >> p->number;
    }
    cout << "������ѧ������ : " << endl;
    cin >> p->name;
    cout << "������ѧ���Ա� : " << endl;
    cin >> p->sex;
    cout << "������ѧ�������� : " << endl;
    cin >> p->date.year;
    while(!cin)
    {
            cout << "����������int�Ͳ��������������룡" << endl << "������ѧ�������� : " << endl;
            cin.clear();
            cin.sync();
            cin >> p->date.year;
    }
    while(p->date.year < 0)
    {
            cout << "��ķ�ΧӦ�ô���0�����������룡" << endl << "������ѧ�������� : " << endl;
            cin.clear();
            cin.sync();
            cin >> p->date.year;
    }
    cout << "������ѧ�������� : " << endl;
    cin >> p->date.month;
    while(!cin)
    {
            cout << "����������int�Ͳ��������������룡" << endl << "������ѧ�������� : " << endl;
            cin.clear();
            cin.sync();
            cin >> p->date.month;
    }
    while(p->date.month > 12 || p->date.month < 1)
    {
            cout << "�·ݵķ�ΧӦ���� 1~12 ֮�䣬���������룡" << endl << "������ѧ�������� : " << endl;
            cin.clear();
            cin.sync();
            cin >> p->date.month;
    }
    cout << "������ѧ�������� : " << endl;
    cin >> p->date.day;
    while(!cin)
    {
            cout << "����������int�Ͳ��������������룡" << endl << "������ѧ�������� : " << endl;
            cin.clear();
            cin.sync();
            cin >> p->date.day;
    }
    while(p->date.day > 30 || p->date.day < 1)
    {
            cout << "���ڵķ�ΧӦ���� 1~30 ֮�䣬���������룡" << endl << "������ѧ�������� : " << endl;
            cin.clear();
            cin.sync();
            cin >> p->date.day;
    }
    cout << "������ѧ���ɼ� : " << endl;
    cin >> p->grade;
    while(!cin)
    {
            cout << "����������int�Ͳ��������������룡" << endl << "������ѧ���ɼ� : " << endl;
            cin.clear();
            cin.sync();
            cin >> p->date.day;
    }
    while(p->grade > 100 || p->grade < 0)
    {
            cout << "�ɼ��ķ�ΧӦ���� 0~100 ֮�䣬���������룡" << endl << "������ѧ���ɼ� : " << endl;
            cin.clear();
            cin.sync();
            cin >> p->grade;
    }
    p->next = NULL;
    if(f == NULL)
        f = r = p;
    else
    {
        r->next = p;
        r = r->next;
    }
}
void Find_Name(Student *& f, Student *& r)//������ѯ
{
    string name;
    Student *p = f;
    cout << "��������Ҫ��ѯ��ѧ������ :" << endl;
    cin >> name;
    while(p != NULL)
    {
        if(FindName(p, name))
        {
            cout << "��Ҫ���ҵ�ѧ����ϢΪ ��" << endl;
            cout << "ѧ��"  << setw(18) << "����" << setw(20) << "�Ա�" << setw(25) << "��������" << setw(25) << "�ɼ�" <<endl;
            Display(p);

            return;
        }
        else
            p = p->next;
    }
    cout << "��Ҫ���ҵ�ѧ��������." << endl;

}
void Find_Number(Student *& f, Student *& r)//��Ų�ѯ
{
    long number;
    Student *p = f;
    cout << "��������Ҫ��ѯ��ѧ����� :" << endl;
    cin >> number;
    while(p != NULL)
    {
        if(FindNumber(p, number))
        {
            cout << "��Ҫ���ҵ�ѧ����ϢΪ ��" << endl;
            cout << "ѧ��"  << setw(18) << "����" << setw(20) << "�Ա�" << setw(25) << "��������" << setw(25) << "�ɼ�" <<endl;
            Display(p);

            return;
        }
        else
            p = p->next;
    }
    cout << "��Ҫ���ҵ�ѧ��������." << endl;
}
void Modify_Student(Student *& f, Student *& r)//ѧ����Ϣ�޸�
{
    string name;
    int k;
    cout << "��������Ҫ�޸ĵ�ѧ�������� :" << endl;
    cin >> name;
    Student *p = f;
    while(p != NULL)
    {
        if(FindName(p, name))
        {
            do
            {
            cout << "1.ѧ��     2.����      3.�Ա�     4.��������     5.�ɼ�" << endl;
            cout << "��ѡ��Ҫ�޸ĵ�ѡ��(��0�����޸�) ��" << endl;
            cin >> k;
            switch(k)
            {
            case 0:
                break;
            case 1:
                {
                    cout << "��ѧ���޸ĳ� ��";
                    cin >> p->number;
                    break;
                }
            case 2:
                {
                    cout << "�������޸ĳ� ��";
                    cin >> p->name;
                    break;
                }
            case 3:
                {
                    cout << "���Ա��޸ĳ� ��";
                    cin >> p->sex;
                    break;
                }
            case 4:
                {
                    cout << "�ѳ��������޸ĳ� ��";
                    cin >> p->date.year >> p->date.month >> p->date.day;
                    break;
                }
            case 5:
                {
                    cout << "�ѳɼ��޸ĳ� ��";
                    cin >> p->grade;
                    break;
                }
            default:
                {
                    cout << "�������������������� ��" << endl;
                    break;
                }
            }
        }while(k);
        return;
        }
        else
        p = p->next;
    }
    cout << "��Ҫ�޸ĵ�ѧ��������." << endl;
}
void Aver_Grade(Student *& f)//����ƽ����
{
    int sum = 0, i = 0;
    Student *p = f;
    while(p != NULL)
    {
        sum += p->grade;
        i++;
        p = p->next;
    }
    cout << "һ���� " << i << " ��ѧ�������ǵ�ƽ����Ϊ : " << sum / i << endl;
}
void Sort_Grade(Student *& f, Student *& r)//���ճɼ��Ӹߵ�������
{
    int k = 0, temp;
    Student *p = f;
    while(p != NULL)
    {
        k++;
        p = p->next;
    }
    int Array[k];
    p = f;
    for(int i = 0; i < k; i++)
    {
        Array[i] = p->grade;
        p = p->next;
    }
    for(int i = 0; i < k -1; i++)
    {
        for(int j = 0; j < k-i-1; j++)
        {

            if(Array[j] < Array[j+1])
            {
                temp = Array[j];
                Array[j] = Array[j+1];
                Array[j+1] = temp;
            }
        }
    }
    p = f;
    cout << "���ճɼ��Ӵ�С������ѧ����ϢΪ ��" << endl;
    cout << "ѧ��"  << setw(18) << "����" << setw(20) << "�Ա�" << setw(25) << "��������" << setw(25) << "�ɼ�" <<endl;
    for(int i = 0; i < k; i++)
    {
        while(p != NULL)
        {
            if(FindGrade(p, Array[i]))
            {
                Display(p);
                p = f;
                break;
            }
            else
                p = p->next;
        }
    }
}
void Clear_Student(Student *& f, Student *& r)
{
    f = r =NULL;
}
void menu()//��ʾ�˵�
{
    cout << endl << "1.ѧ����Ϣ��¼��" << endl;
    cout << "2.ѧ����Ϣ����ʾ" << endl;
    cout << "3.�޸�ѧ���Ļ�����Ϣ" << endl;
    cout << "4.ͨ����Ž���ѧ����ѯ" << endl;
    cout << "5.ͨ����������ѧ����ѯ" << endl;
    cout << "6.����ƽ����" << endl;
    cout << "7.���շ����Ӹߵ�������" << endl;
    cout << "8.���ѧ����Ϣ" << endl;
    cout << "��0��������" << endl << endl;
}
void Test()//���Ժ���
{
    Student *front = NULL;
    Student *rear = NULL;
    int choice = 0;
    do
    {
    menu();
    cout << "��������Ҫ���еĲ��� :" << endl;
    cin >> choice;
        switch(choice)
        {
        case 0:
            {
                break;
            }
        case 1:
            {
                Set_Student(front, rear);
                break;
            }
        case 2:
            {
                Student_Display(front, rear);
                break;
            }
        case 3:
            {
                Modify_Student(front, rear);
                break;
            }
        case 4:
            {
                Find_Number(front, rear);
                break;
            }
        case 5:
            {
                Find_Name(front, rear);
                break;
            }
        case 6:
            {
                Aver_Grade(front);
                break;
            }
        case 7:
            {
                Sort_Grade(front, rear);
                break;
            }
        case 8:
            {
                Clear_Student(front, rear);
                break;
            }

        default:
            {
                cout << "��������������������" << endl;
                break;
            }
        }
    }while(choice);
    cout << "End." << endl;
}
int main()
{
    Test();
    return 0;
}

 */
