/*
 * 7-2.cpp
 *
 *  Created on: 2018��5��24��
 *      Author: asus
 */

/*��� CTime ��
 1����Ա������hour��minute��second��
 2��������캯����
 ��ʾ������Display()��
 ���ú�����SetHour(int hour)��SetMinute(int min)�� SetSecond(int sec)��
 3������++�������ģ���ӱ��߶���ÿ����һ�룬ÿ60 ���һ���ӣ����ִ�0 ��ʼ���㣻ÿ60 �ֽ�һСʱ�����Ӵ�0 ��ʼ���㡣
 [ʵ����ʾ]
 1��++�����Ϊ��Ŀ���������������غ���ֻ��һ�������������������غ�����Ϊ��Ա����������ʡ�Դ˲�����
 2��++������ʹ�÷�ʽ��ǰ������������ͺ��������������Ϊ��������ߣ���������������غ����У�����һ��int ���βΣ���Ϊ���������������
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
