/*
 * 7-3.cpp
 *
 *  Created on: 2018��5��31��
 *      Author: asus
 */
/*
 ����ĳ����N��5����ѧ��������M��3���ſγ̣�����Ϊ������Ӣ������������༶����ƽ���ɼ���
 ���Student ��
 class student
 {����
 char name[10];
 int deg1,deg2,deg3;

 ��
 ��Ա������name[10]��int deg1,deg2,deg3;
 ���ú�����
 1.	���캯��	student(){deg1=deg2=deg3=0;}
 2.		student(char na[],int d1,int d2,int d3)��
 3.		friend student operator+(student s1,student s2)��
 4.	friend void avg(student &s,int n)��
 Ҫ�����ѧ���ɼ��嵥��ÿ�ſεİ༶ƽ���֡�
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
