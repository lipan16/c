/*
 * test5.cpp
 *
 *  Created on: 2018年5月6日
 *      Author: asus
 *      实现功能：
 *      	输入学生信息
 *      	setinfo方法：默认参数的set方法
 *      	search方法：默认参数的查询方法
 *      	sort方法：可按分数排序默认按平均分排序，参数为1是按第一门课成绩排序，2是按第二门课排序，依此类推
 */


/*
#include <iostream>
using namespace std;
#define max 4 //学生成员的个数
#define n 3 //课程的门数

void search(string na = " ", string = "", double = 0); //查询
void sort(int = 0); //按分数排序,默认按平均分排序，参数为1是按第一门课成绩排序，2是按第二门课排序，依此类推

class student {//student类
private:
	string name; //姓名
	string num; //学号
	double aver; //平均分
public:
	double score[n]; //n门课的成绩
	student(); //不带参的构造方法
	student(string, string, double[]); //带参的构造方法
	void setinfo(string, string, double[]); //set方法，更改信息
	void input();
	string getname(); //get方法返回name
	string getnum(); //get方法返回学号
	double getaver(); //get方法返回平均分aver
	double faver(double[]); //计算平均分
	void display(); //打印输出
} stu[max];

student::student() { //不带参的构造方法
	name = ""; //默认名字为空
	num = "10001"; //默认学号为10001
	for (int i = 0; i < n; i++) {
		score[i] = 80; //每门课默认成绩为80
	}
	aver = faver(score); //计算平均分
}

student::student(string na, string nu, double c[]) { //带参的构造方法
	name = na;//姓名
	num = nu;//学号
	for (int i = 0; i < n; i++) {
		while (c[i] < 0 || c[i] > 100) {
			cout << "成绩数据出错  请重新输入:";
			cin >> c[i];
		}
		score[i] = c[i];
	}
	aver = faver(score);//平均分
}

void student::setinfo(string na, string nu, double c[] = NULL) { //set方法，更改信息
	name = na;
	num = nu;
	if (c == NULL) {//默认参数时，手动输入每门课成绩0~100
		for (int i = 0; i < n; i++) {
			cout << "请输入第" << i + 1 << "门课的成绩(0~100):";
			cin >> score[i];
			if (score[i] < 0 || score[i] > 100) {//检测成绩是否合法
				cout << "第" << i + 1 << "门课的成绩输入错误 请重新输入";
				i--;//往回走一个相当于重新输出人
			}
		}
	} else {//有参数时，用参数赋值
		for (int i = 0; i < n; i++) {
			while (c[i] < 0 || c[i] > 100) {//检测成绩是否合法
				cout << "成绩数据出错  请重新输入:";
				cin >> c[i];
			}
			score[i] = c[i];
		}
	}
	aver = faver(score);
}

void student::input() {
	cout << "输入姓名:";
	cin >> name;
	cout << "输入学号:";
	cin >> num;
	for (int i = 0; i < n; i++) {
		cout << "请输入第" << i + 1 << "门课的成绩(0~100):";
		cin >> score[i];
		if (score[i] < 0 || score[i] > 100) { //检测成绩是否合法
			cout << "第" << i + 1 << "门课的成绩输入错误 请重新输入" << endl;
			i--; //往回走一个相当于重新输出人
		}
	}
	aver = faver(score);
}

string student::getname() { //get方法返回name
	return name;
}
string student::getnum() { //get方法返回学号
	return num;
}
double student::getaver() { //get方法返回平均分aver
	return aver;
}
double student::faver(double a[]) { //求平均分
	double d = 0;
	for (int i = 0; i < n; i++) {
		d += score[i];
	}
	return d / n;
}

void student::display() { //输出
	cout << "姓名:" << name << " 学号:" << num;
	for (int i = 0; i < n; i++) {
		cout << " 第" << i + 1 << "门课成绩:" << score[i];
	}
	cout << " 平均成绩:" << aver << endl;
}

void search(string na, string nu, double a) { //查找函数,按某一类别来查找，非精确查找
	bool flag = true;
	for (int i = 0; i < max; i++) {	//按姓名关键字来匹配
		if (na == stu[i].getname()) {
			cout << "\n按姓名匹配到数据" << endl;
			stu[i].display();
			flag = false;	//如果按照该关键字找到匹配项就不进行其他关键字匹配
		}
	}
	if (flag) {	//按学号关键字来匹配
		for (int i = 0; i < max; i++) {
			if (nu == stu[i].getnum()) {
				cout << "\n按学号匹配到数据" << endl;
				stu[i].display();
				flag = false;	//如果按照该关键字找到匹配项就不进行其他关键字匹配
			}
		}
	}
	if (flag) {	//按平均成绩关键字来匹配
		for (int i = 0; i < max; i++) {
			if (a == stu[i].getaver()) {
				cout << "\n按平均成绩匹配到数据" << endl;
				stu[i].display();
				flag = false;	//如果按照该关键字找到匹配项就不进行其他关键字匹配
			}
		}
	}
	if (!flag)
		return;
	else
		cout << "\n查询失败" << endl;
}

void sort(int a) {
	student s;
	int k;
	switch (a) {
	case 0:
		for (int i = 0; i < max; i++) {	//选择排序
			k = i;
			for (int j = i; j < max; j++)
				if (stu[k].getaver() < stu[j].getaver())
					k = j;
			if (k > i) {	//交换
				s.setinfo(stu[k].getname(), stu[k].getnum(), stu[k].score);
				stu[k].setinfo(stu[i].getname(), stu[i].getnum(), stu[i].score);
				stu[i].setinfo(s.getname(), s.getnum(), s.score);
			}
		}
		cout << "\n按照平均成绩排序结果:" << endl;
		break;
	default:
		for (int i = 0; i < max; i++) {	//选择排序
			k = i;
			for (int j = i; j < max; j++)
				if (stu[k].score[a - 1] < stu[j].score[a - 1])
					k = j;
			if (k > i) {	//交换
				s.setinfo(stu[k].getname(), stu[k].getnum(), stu[k].score);
				stu[k].setinfo(stu[i].getname(), stu[i].getnum(), stu[i].score);
				stu[i].setinfo(s.getname(), s.getnum(), s.score);
			}
		}
		cout << "\n按照第" << a << "门课成绩排序结果:" << endl;
	}
	for (int i = 0; i < max; i++) {
		stu[i].display();
	}
}


int main() {
	double a[n] = { 80, 90, 100 };//三门课的成绩
	stu[1].setinfo("lyton", "10002", a);//修改信息
	stu[2].setinfo("lytons", "10003");//手动输入成绩
	stu[3].input();

	stu[0].display();
	stu[1].display();
	stu[2].display();
	stu[3].display();

	search(" ", "10001"); //搜查学号为1332的成员信息
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
    Date(){};//缺省构造函数
    ~Date();//析构函数
    Date(int , int , int );//带参数的构造函数
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
    Student(){};//默认构造函数
    ~Student();
    Student(long nu, string na, string se, int ye, int mo, int da, int grade);//带参数的构造函数


    void Display(Student *&);//输出学生信息
    Student *next;
private:
    long number;//学号
    string name;//姓名
    string sex;//性别
    Date date;//出生年月日
    int grade;//分数
};

void Set_Student(Student *& f, Student *& r);//学生信息录入
void Find_Name(Student *& f, Student *& r);//姓名查询
void Find_Number(Student *& f, Student *& r);//编号查询
void Modify_Student(Student *& f, Student *& r);//学生信息修改
void Clear_Student(Student *& f, Student *& r);//清空学生信息
void Aver_Grade(Student *& f, Student *& r);//计算平均分
void Sort_Grade(Student *& f, Student *& r);//按照成绩从高到低排序

void menu();//显示菜单
void Test();//测试函数

Date::~Date()
{
    cout << "Date object is end." << endl;
}
Date::Date(int y, int m, int d)//带参数的构造函数
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
    p->date.year  << "年" <<p->date.month << "月" << p->date.day << "日" << setw(22) << p->grade << endl;
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

void Student_Display(Student *& f, Student *& r)//学生信息显示
{
    Student *p = f;

    if(p == NULL)
    {
        cout << "当前无学生信息" << endl;
    }
    else
    {
        cout << "学号"  << setw(18) << "姓名" << setw(20) << "性别" << setw(25) << "出生日期" << setw(25) << "成绩" <<endl;
        while(p != NULL)
        {
            Display(p);
            p = p->next;
        }
    }
}
void Set_Student(Student *& f, Student *& r)//学生信息录入
{

    cout << "请输入学生信息" << endl;
    Student *p = new Student(0);
    cout << "请输入学生学号 : " << endl;
    cin >> p->number;
    while(!cin)
    {
            cout << "输入数据与long型不符，请重新输入！" << endl << "请输入学生学号 : " << endl;
            cin.clear();
            cin.sync();
            cin >> p->number;
    }
    cout << "请输入学生姓名 : " << endl;
    cin >> p->name;
    cout << "请输入学生性别 : " << endl;
    cin >> p->sex;
    cout << "请输入学生出生年 : " << endl;
    cin >> p->date.year;
    while(!cin)
    {
            cout << "输入数据与int型不符，请重新输入！" << endl << "请输入学生出生年 : " << endl;
            cin.clear();
            cin.sync();
            cin >> p->date.year;
    }
    while(p->date.year < 0)
    {
            cout << "年的范围应该大于0，请重新输入！" << endl << "请输入学生出生年 : " << endl;
            cin.clear();
            cin.sync();
            cin >> p->date.year;
    }
    cout << "请输入学生出生月 : " << endl;
    cin >> p->date.month;
    while(!cin)
    {
            cout << "输入数据与int型不符，请重新输入！" << endl << "请输入学生出生月 : " << endl;
            cin.clear();
            cin.sync();
            cin >> p->date.month;
    }
    while(p->date.month > 12 || p->date.month < 1)
    {
            cout << "月份的范围应该在 1~12 之间，请重新输入！" << endl << "请输入学生出生月 : " << endl;
            cin.clear();
            cin.sync();
            cin >> p->date.month;
    }
    cout << "请输入学生出生日 : " << endl;
    cin >> p->date.day;
    while(!cin)
    {
            cout << "输入数据与int型不符，请重新输入！" << endl << "请输入学生出生日 : " << endl;
            cin.clear();
            cin.sync();
            cin >> p->date.day;
    }
    while(p->date.day > 30 || p->date.day < 1)
    {
            cout << "日期的范围应该在 1~30 之间，请重新输入！" << endl << "请输入学生出生日 : " << endl;
            cin.clear();
            cin.sync();
            cin >> p->date.day;
    }
    cout << "请输入学生成绩 : " << endl;
    cin >> p->grade;
    while(!cin)
    {
            cout << "输入数据与int型不符，请重新输入！" << endl << "请输入学生成绩 : " << endl;
            cin.clear();
            cin.sync();
            cin >> p->date.day;
    }
    while(p->grade > 100 || p->grade < 0)
    {
            cout << "成绩的范围应该在 0~100 之间，请重新输入！" << endl << "请输入学生成绩 : " << endl;
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
void Find_Name(Student *& f, Student *& r)//姓名查询
{
    string name;
    Student *p = f;
    cout << "请输入你要查询的学生姓名 :" << endl;
    cin >> name;
    while(p != NULL)
    {
        if(FindName(p, name))
        {
            cout << "你要查找的学生信息为 ：" << endl;
            cout << "学号"  << setw(18) << "姓名" << setw(20) << "性别" << setw(25) << "出生日期" << setw(25) << "成绩" <<endl;
            Display(p);

            return;
        }
        else
            p = p->next;
    }
    cout << "你要查找的学生不存在." << endl;

}
void Find_Number(Student *& f, Student *& r)//编号查询
{
    long number;
    Student *p = f;
    cout << "请输入你要查询的学生编号 :" << endl;
    cin >> number;
    while(p != NULL)
    {
        if(FindNumber(p, number))
        {
            cout << "你要查找的学生信息为 ：" << endl;
            cout << "学号"  << setw(18) << "姓名" << setw(20) << "性别" << setw(25) << "出生日期" << setw(25) << "成绩" <<endl;
            Display(p);

            return;
        }
        else
            p = p->next;
    }
    cout << "你要查找的学生不存在." << endl;
}
void Modify_Student(Student *& f, Student *& r)//学生信息修改
{
    string name;
    int k;
    cout << "请输入你要修改的学生的姓名 :" << endl;
    cin >> name;
    Student *p = f;
    while(p != NULL)
    {
        if(FindName(p, name))
        {
            do
            {
            cout << "1.学号     2.姓名      3.性别     4.出生日期     5.成绩" << endl;
            cout << "请选择要修改的选项(输0结束修改) ：" << endl;
            cin >> k;
            switch(k)
            {
            case 0:
                break;
            case 1:
                {
                    cout << "把学号修改成 ：";
                    cin >> p->number;
                    break;
                }
            case 2:
                {
                    cout << "把姓名修改成 ：";
                    cin >> p->name;
                    break;
                }
            case 3:
                {
                    cout << "把性别修改成 ：";
                    cin >> p->sex;
                    break;
                }
            case 4:
                {
                    cout << "把出生日期修改成 ：";
                    cin >> p->date.year >> p->date.month >> p->date.day;
                    break;
                }
            case 5:
                {
                    cout << "把成绩修改成 ：";
                    cin >> p->grade;
                    break;
                }
            default:
                {
                    cout << "序号输入错误，请重新输入 ：" << endl;
                    break;
                }
            }
        }while(k);
        return;
        }
        else
        p = p->next;
    }
    cout << "你要修改的学生不存在." << endl;
}
void Aver_Grade(Student *& f)//计算平均分
{
    int sum = 0, i = 0;
    Student *p = f;
    while(p != NULL)
    {
        sum += p->grade;
        i++;
        p = p->next;
    }
    cout << "一共有 " << i << " 个学生，他们的平均分为 : " << sum / i << endl;
}
void Sort_Grade(Student *& f, Student *& r)//按照成绩从高到低排序
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
    cout << "按照成绩从大到小排序后的学生信息为 ：" << endl;
    cout << "学号"  << setw(18) << "姓名" << setw(20) << "性别" << setw(25) << "出生日期" << setw(25) << "成绩" <<endl;
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
void menu()//显示菜单
{
    cout << endl << "1.学生信息的录入" << endl;
    cout << "2.学生信息的显示" << endl;
    cout << "3.修改学生的基本信息" << endl;
    cout << "4.通过编号进行学生查询" << endl;
    cout << "5.通过姓名进行学生查询" << endl;
    cout << "6.计算平均分" << endl;
    cout << "7.按照分数从高到低排序" << endl;
    cout << "8.清空学生信息" << endl;
    cout << "输0结束程序" << endl << endl;
}
void Test()//测试函数
{
    Student *front = NULL;
    Student *rear = NULL;
    int choice = 0;
    do
    {
    menu();
    cout << "请输入你要进行的操作 :" << endl;
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
                cout << "序号输入错误，请重新输入" << endl;
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
