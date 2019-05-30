/*
 * 7-1.cpp
 *
 *  Created on: 2018年5月24日
 *      Author: asus
 */

/*设计字符串类String，用来存放不定长的字符串，重载运算符“= =”，“>”，“<”，用于两个字符串的大于、小于和等于的比较运算。

 1、= = 、> 、< 属于双目运算符，在重载双目运算符时，函数中应该有两个参数。
 2、String 类成员变量应为字符型指针；
 3、多个构造函数的定义；
 [测试数据]
 1、 China china
 2、 National Computer
 3、 Examination Rank
 4、 swust swust
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
