/*
 * stu.cpp
 *
 *  Created on: 2018��5��4��
 *      Author: asus
 */


/*
#include <iostream>

using namespace std;

#include "stu.h"

void date::setYear(int year) {
	while (year < 0) {
		cout << "�Ƿ���������������:";
		cin >> year;
	}
	this->year = year;
}

void date::setMonth(int month) {
	while (month <= 0 || month > 12) {
		cout << "�Ƿ���������������:";
		cin >> month;
	}
	this->month = month;
}

void date::setDay(int day) {
	while (day <= 0 || day > 31) {
		cout << "�������ݷǷ�����������:";
		cin >> day;
	}
	int flag = 0;
	if (month == 2) {
		if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
			flag = 1; //���꣬2��29��
		else
			flag = 2; //ƽ�꣬2��28��
	}
	else if (month == 1 || month == 4 || month == 6 || month == 9 || month == 11)
		flag = 3;

	switch (flag) {
	case 0:
		break;
	case 1:
		while (day <= 0 || day > 29) {
			cout << year << "��������2�¹���29��  ����������:";
			cin >> day;
		}
		break;
	case 2:
		while (day <= 0 || day > 28) {
			cout << year << "����ƽ��2�¹���28��  ����������:";
			cin >> day;
		}
		break;
	case 3:
		while (day <= 0 || day > 30) {
			cout << month << "��ΪС�¹�30��  ����������:";
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
