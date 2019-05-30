/*
 * 7-3.cpp
 *
 *  Created on: 2018年5月31日
 *      Author: asus
 */
/*
 假设某班有N（5）名学生，开设M（3）门课程，依次为高数、英语、计算机，计算班级单科平均成绩。
 设计Student 类
 class student
 {……
 char name[10];
 int deg1,deg2,deg3;

 ｝
 成员变量：name[10]、int deg1,deg2,deg3;
 设置函数：
 1.	构造函数	student(){deg1=deg2=deg3=0;}
 2.		student(char na[],int d1,int d2,int d3)；
 3.		friend student operator+(student s1,student s2)；
 4.	friend void avg(student &s,int n)；
 要求输出学生成绩清单、每门课的班级平均分。
 */

/*
#include <iostream>
#include <string.h>
using namespace std;

class student {
protected:
	char name[10];
	int deg1, deg2, deg3;
public:
	student();
	student(char na[], int d1, int d2, int d3);
	friend student operator+(student s1, student s2);
	friend void avg(student &s, int n);
};

student::student() {
	deg1 = 0;
	deg2 = 0;
	deg3 = 0;
}

student::student(char na[], int d1, int d2, int d3) {
	strcpy(name, na);
	deg1 = d1;
	deg2 = d2;
	deg3 = d3;
}

student operator+(student s1, student s2) {
	char na[20];
	strcpy(na, s1.name);
	strcat(na, s2.name);
	int d1 = s1.deg1 + s2.deg1;
	int d2 = s1.deg2 + s2.deg2;
	int d3 = s1.deg3 + s2.deg3;
	return student(na, d1, d2, d3);
}

void avg(student &s, int n) {
	cout << "name:" << s.name << endl;
	cout << "ave:" << (s.deg1 + s.deg2 + s.deg3) / 3.0 << endl;
}

int main() {
	char na[10] = "stu1";
	student s(na, 60, 67, 78);
	avg(s, 3);
}
*/
