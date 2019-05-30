/*
 * caldendar.cpp
 *
 *  Created on: 2018��5��4��
 *      Author: asus
 */

#include <iostream>
#include <iomanip>
using namespace std;

#include "stu.h"

long long Caldendar::t_day = 0;

void Caldendar::setyear(int year) {
	m_year = year;
}

bool Caldendar::isleapyear() {
	if ((m_year % 4 == 0 && m_year % 100 != 0) || (m_year % 400 == 0))
		return true;
	else
		return false;
}

void Caldendar::getmdays(){
	if (isleapyear() == true) { //��ÿ���¶�����
		int day[12] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		for (int i = 0; i < 12; i++)
			m_day[i] = day[i];
	} else {
		int day[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		for (int i = 0; i < 12; i++)
			m_day[i] = day[i];
	}
}

void Caldendar::showyear(int year) {
	setyear(year);
	string t_month[12] = { "һ��(Jan)", "����(Feb)", "����(Mar)", "����(Apr)", "����(May)",
			"����(Jun)", "����(Jul)", "����(Aug)", "����(Sep)", "ʮ��(Oct)", "ʮһ��(Nov)",
			"ʮ����(Dec)" };
	string t_week[7] = { "Sun", "Mon", "Tue", "Wen", "Thru", "Fri", "Sat" };
	getmdays(); //��ȡÿ�µ�����
	long long count = 0; //���ڻ���
	for (int i = 1; i < m_year; i++) {
		if ((i % 4 == 0 && i % 100 != 0) || (i % 400 == 0))
			t_day += 366;
		else
			t_day += 365;
	}
	count = t_day % 7 + 1;

	cout << "��ݣ�" << m_year << endl;
	for (m_month = 0; m_month < 12; m_month++) {
		cout << "---------------------------------" << endl << endl;
		cout << t_month[m_month] << endl;
		for (int m = 0; m < 7; m++) {
			cout << t_week[m] << "  ";
		}
		cout << endl;

		int j = 0;
		for (int k = 0; k < count % 7; k++) {
			cout << setw(3) << "     ";
		}
		for (j = 0; j < m_day[m_month]; j++) {
			count++;
			cout << setw(3) << j + 1 << "  ";
			if (count % 7 == 0) {
				cout << endl;
			}
		}
		cout << endl;
	}
}

void Caldendar::showmonth(int year,int month) {
	setyear(year);
	m_month=month-1;
	string t_month[12] = { "һ��(Jan)", "����(Feb)", "����(Mar)", "����(Apr)",
			"����(May)", "����(Jun)", "����(Jul)", "����(Aug)", "����(Sep)", "ʮ��(Oct)",
			"ʮһ��(Nov)", "ʮ����(Dec)" };
	string t_week[7] = { "Sun", "Mon", "Tue", "Wen", "Thru", "Fri", "Sat" };
	getmdays(); //��ȡÿ�µ�����
	long long count = 0; //���ڻ���
	for (int i = 1; i <= m_year; i++) {
		if ((i % 4 == 0 && i % 100 != 0) || (i % 400 == 0))
			t_day += 366;
		else
			t_day += 365;
	}
	count = t_day % 7 + 1;

	cout << "��ݣ�" << m_year << endl;
	cout << "---------------------------------" << endl << endl;
	cout << t_month[m_month] << endl;
	for (int m = 0; m < 7; m++) {
		cout << t_week[m] << "  ";
	}
	cout << endl;

	int j = 0;
	for (int k = 0; k < count % 7; k++) {
		cout << setw(3) << "     ";
	}
	for (j = 0; j < m_day[m_month]; j++) {
		count++;
		cout << setw(3) << j + 1 << "  ";
		if (count % 7 == 0) {
			cout << endl;
		}
	}
	cout << endl;
}
