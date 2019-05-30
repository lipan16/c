/*
 * 4-1.cpp
 *
 *  Created on: 2018年4月24日
 *      Author: asus
 */

/*
#include <iostream>
using namespace std;


struct date{
	int year, month, day;
}date;
int m_day[12];//每月天数

//公元1年1月1日是星期一,求输入的年月日是星期几
void mdays(int year); //获取当前年份的每月天数

int main() {
	int days = 0;
	cout << "请输入年:";
	cin >> date.year;
	mdays(date.year);
	do {
		cout << "请输入月:";
		cin >> date.month;
	} while (date.month <= 0 || date.month > 12);
	do {
		cout << "请输入日:";
		cin >> date.day;
	} while (date.day <= 0 || date.day > m_day[date.month]);

	for (int i = 1; i < date.year; i++) { //获取1~year-1年的天数
		mdays(i);
		for (int j = 0; j < 12; j++)
			days += m_day[j];
	}
	for (int i = 1; i < date.month; i++) //获取year年前month个月的天数
		days += m_day[i - 1];
	days += date.day;

	if (days % 7 == 0)
		cout << "今天是星期日";
	else
		cout << "今天是星期" << days % 7;
}

void mdays(int year) {
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) { //算每个月多少天
		int day[12] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		for (int i = 0; i < 12; i++)
			m_day[i] = day[i];
	} else {
		int day[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		for (int i = 0; i < 12; i++)
			m_day[i] = day[i];
	}
}
*/
