/*
 * 4-1.cpp
 *
 *  Created on: 2018��4��24��
 *      Author: asus
 */

/*
#include <iostream>
using namespace std;


struct date{
	int year, month, day;
}date;
int m_day[12];//ÿ������

//��Ԫ1��1��1��������һ,������������������ڼ�
void mdays(int year); //��ȡ��ǰ��ݵ�ÿ������

int main() {
	int days = 0;
	cout << "��������:";
	cin >> date.year;
	mdays(date.year);
	do {
		cout << "��������:";
		cin >> date.month;
	} while (date.month <= 0 || date.month > 12);
	do {
		cout << "��������:";
		cin >> date.day;
	} while (date.day <= 0 || date.day > m_day[date.month]);

	for (int i = 1; i < date.year; i++) { //��ȡ1~year-1�������
		mdays(i);
		for (int j = 0; j < 12; j++)
			days += m_day[j];
	}
	for (int i = 1; i < date.month; i++) //��ȡyear��ǰmonth���µ�����
		days += m_day[i - 1];
	days += date.day;

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
