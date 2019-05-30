/*
 * stu.cpp
 *
 *  Created on: 2018年5月4日
 *      Author: asus
 */


/*
#include <iostream>

using namespace std;

#include "stu.h"

void date::setYear(int year) {
	while (year < 0) {
		cout << "非法数据请重新输入:";
		cin >> year;
	}
	this->year = year;
}

void date::setMonth(int month) {
	while (month <= 0 || month > 12) {
		cout << "非法数据请重新输入:";
		cin >> month;
	}
	this->month = month;
}

void date::setDay(int day) {
	while (day <= 0 || day > 31) {
		cout << "日期数据非法请重新输入:";
		cin >> day;
	}
	int flag = 0;
	if (month == 2) {
		if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
			flag = 1; //闰年，2月29天
		else
			flag = 2; //平年，2月28天
	}
	else if (month == 1 || month == 4 || month == 6 || month == 9 || month == 11)
		flag = 3;

	switch (flag) {
	case 0:
		break;
	case 1:
		while (day <= 0 || day > 29) {
			cout << year << "年是闰年2月共有29天  请重新输入:";
			cin >> day;
		}
		break;
	case 2:
		while (day <= 0 || day > 28) {
			cout << year << "年是平年2月共有28天  请重新输入:";
			cin >> day;
		}
		break;
	case 3:
		while (day <= 0 || day > 30) {
			cout << month << "月为小月共30天  请重新输入:";
			cin >> day;
		}
		break;
	}
	this->day = day;
}

int date::getYear() {
	return year;
}

int date::getMonth() {
	return month;
}

int date::getDay() {
	return day;
}


*/
