/*
 * 7-2.cpp
 *
 *  Created on: 2018年5月24日
 *      Author: asus
 */

/*设计 CTime 类
 1、成员变量：hour、minute、second；
 2、多个构造函数；
 显示函数：Display()；
 设置函数：SetHour(int hour)、SetMinute(int min)、 SetSecond(int sec)；
 3、重载++运算符，模拟钟表走动，每次走一秒，每60 秒进一分钟，秒又从0 开始计算；每60 分进一小时，分钟从0 开始计算。
 [实验提示]
 1、++运算符为单目运算符，运算符重载函数只有一个参数，如果运算符重载函数作为成员函数，还可省略此参数；
 2、++有两种使用方式：前置自增运算符和后置自增运算符，为了区别二者，在自增运算符重载函数中，增加一个int 型形参，即为后置运算符函数；
 *
 */
/*
#include <iostream>

using namespace std;

class CTime {
private:
	int hour, minute, second;
public:
	CTime();
	CTime(int, int, int);
	CTime operator++();
	CTime operator++(int);
	void settime();
	void display();
	void sethour(int hour);
	void setmin(int min);
	void setsec(int sec);
};

CTime::CTime() {
	hour = 0;
	minute = 0;
	second = 0;
}
CTime::CTime(int h, int m, int s) {
	hour = h;
	minute = m;
	second = s;
}

CTime CTime::operator++() {
	++second;
	if (second == 60) {
		second = 0;
		++minute;
		if (minute == 60) {
			second = 0;
			minute = 0;
			++hour;
			if (hour == 24) {
				second = 0;
				minute = 0;
				hour = 0;
			}
		}
	}
	return CTime(hour, minute, second);
}
CTime CTime::operator++(int a) {
	second++;
	if (second == 60) {
		second = 0;
		minute++;
		if (minute == 60) {
			second = 0;
			minute = 0;
			hour++;
			if (hour == 24) {
				second = 0;
				minute = 0;
				hour = 0;
			}
		}
	}
	return CTime(hour, minute, second);
}

void CTime::display() {
	cout << hour << ":" << minute << ":" << second << endl;
}
void CTime::settime(){
	cout<<"please input hour:";
	cin>>hour;
	sethour(hour);

	cout<<"please input minute:";
	cin>>minute;
	setmin(minute);

	cout<<"please input second:";
	cin>>second;
	setsec(second);
}
void CTime::sethour(int hh) {
	while (hh < 0 || hh >= 24) {
		cout << "hour error please reset hour:";
		cin >> hh;
	}
	hour = hh;
}
void CTime::setmin(int mm) {
	while (mm < 0 || mm >= 60) {
		cout << "minute error please reset minute:";
		cin >> mm;
	}
	minute = mm;
}
void CTime::setsec(int ss) {
	while (ss < 0 || ss >= 24) {
		cout << "second error please reset second:";
		cin >> ss;
	}
	second = ss;
}

int main() {
	CTime c;
	c.settime();
	c++;
	++c;
	c.display();
}
*/
