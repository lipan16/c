/*
 * 1-6.cpp
 *
 *  Created on: 2018��4��24��
 *      Author: asus
 */

/*
#include <iostream>
using namespace std;

//��Ԫ1��1��1��������һ,������������������ڼ�
void mdays(int year); //��ȡ��ǰ��ݵ�ÿ������

int m_day[12];
int main() {
	int year, month, day, days = 0;
	cout << "��������:";
	cin >> year;
	mdays(year);
	do {
		cout << "��������:";
		cin >> month;
	} while (month <= 0 || month > 12);
	do {
		cout << "��������:";
		cin >> day;
	} while (day <= 0 || day > m_day[month]);

	for (int i = 1; i < year; i++) { //��ȡ1~year-1�������
		mdays(i);
		for (int j = 0; j < 12; j++)
			days += m_day[j];
	}
	for (int i = 1; i < month; i++) //��ȡyear��ǰmonth���µ�����
		days += m_day[i - 1];
	days += day;

	if (days % 7 == 0)
		cout << "������������";
	else
		cout << "����������" << days % 7;
}

void mdays(int year) {
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) { //��ÿ���¶�����
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
