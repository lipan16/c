/*
 * 7-1.cpp
 *
 *  Created on: 2018��5��24��
 *      Author: asus
 */

/*����ַ�����String��������Ų��������ַ����������������= =������>������<�������������ַ����Ĵ��ڡ�С�ں͵��ڵıȽ����㡣

 1��= = ��> ��< ����˫Ŀ�������������˫Ŀ�����ʱ��������Ӧ��������������
 2��String ���Ա����ӦΪ�ַ���ָ�룻
 3��������캯���Ķ��壻
 [��������]
 1�� China china
 2�� National Computer
 3�� Examination Rank
 4�� swust swust
 *
 */

/*
#include <iostream>
#include <string.h>
using namespace std;

class String {
public:
	String();
	String(const char *);
	friend void operator==(String, String);
	friend void operator>(String, String);
	friend void operator<(String, String);
protected:
	const char *p;
};
String::String() {
	p = NULL;
}
String::String(const char *a) {
	p = a;
}

void operator==(String a, String b) {
	if (strcmp(a.p, b.p) == 0)
		cout << "\"" << a.p << "\"" << " == " << "\"" << b.p << "\"" << endl;
	else
		cout << "\"" << a.p << "\"" << " != " << "\"" << b.p << "\"" << endl;
}

void operator<(String a, String b) {
	if (strcmp(a.p, b.p) < 0)
		cout << "\"" << a.p << "\"" << " < " << "\"" << b.p << "\"" << endl;
	else
		cout << "\"" << a.p << "\"" << " >= " << "\"" << b.p << "\"" << endl;
}

void operator>(String a, String b) {
	if (strcmp(a.p, b.p) > 0)
		cout << "\"" << a.p << "\"" << " > " << "\"" << b.p << "\"" << endl;
	else
		cout << "\"" << a.p << "\"" << " =< " << "\"" << b.p << "\"" << endl;
}

int main() {
	char const a[] = "China", b[] = "china";
	String s(a), s1(b);
	s == s1;
	s > s1;
	s < s1;
}
*/
