/*
 * cshape.cpp
 *
 *  Created on: 2018��5��17��
 *      Author: asus
 */
/*
#include <iostream>
#include <cmath>
#include "cshape.h"
using namespace std;
const double PI = 3.14159;


Circle::Circle() { //ȱʡ�Ĺ��췽��
	m_x = 0;
	m_y = 0;
	m_r = 1;
}
Circle::Circle(double x, double y, double r) { //���εĹ��췽��
	m_x = x;
	m_y = y;
	while (r < 0) {
		cout << "�뾶r=" << r << "�뾶С����,����һ��Բ������������뾶:";
		cin >> r;
	}
	m_r = r;
}
void Circle::set(double x, double y, double r) {
	m_x = x;
	m_y = y;
	while (r < 0) {
		cout << "�뾶r=" << r << "�뾶С����,����һ��Բ������������뾶:";
		cin >> r;
	}
	m_r = r;
}
double Circle::getarea() {
	return PI * m_r * m_r;
}
void Circle::show() {
	if (m_r == 0)
		cout << "��ʱ��ͼ��Ϊһ���㣬�����ǣ�(" << m_x << "," << m_y << ")" << endl << endl;
	else {
		cout << "Բ��Ϊ��(" << m_x << "," << m_y << ") , �뾶Ϊ��" << m_r << endl;
		cout << "���Ϊ��" << getarea() << endl << endl;
	}
}

Rectangle::Rectangle() { //ȱʡ�Ĺ��췽��
	m_x = 1;
	m_y = 1;
}
Rectangle::Rectangle(double x, double y) { //���εĹ��췽��
	while (x <= 0) {
		cout << "����x=" << x << "���Ȳ���С��0�����������볤��:";
		cin >> x;
	}
	while (x <= 0) {
		cout << "���y=" << y << "��Ȳ���С��0��������������:";
		cin >> x;
	}
	m_x = x;
	m_y = y;
}
void Rectangle::set(double x, double y) {
	while (x <= 0) {
		cout << "����x=" << x << "���Ȳ���С��0�����������볤��:";
		cin >> x;
	}
	while (x <= 0) {
		cout << "���y=" << y << "��Ȳ���С��0��������������:";
		cin >> x;
	}
	m_x = x;
	m_y = y;
}
double Rectangle::getgirth() {
	return 2 * (m_x + m_y);
}
double Rectangle::getarea() {
	return m_x * m_y;
}
void Rectangle::show() {
	cout << "���εĳ�Ϊ��" << m_x << "��Ϊ��" << m_y << endl;
	cout << "�ܳ�Ϊ��" << getgirth() << "���Ϊ��" << getarea() << endl << endl;
}

Triangle::Triangle() {
	m_x1 = 0;
	m_y1 = 0;
	m_x2 = 1;
	m_y2 = 0;
	m_x3 = 0;
	m_y3 = 1;
}
Triangle::Triangle(double x1, double y1, double x2, double y2, double x3,
		double y3) {
	m_x1 = x1;
	m_y1 = y1;
	m_x2 = x2;
	m_y2 = y2;
	m_x3 = x3;
	m_y3 = y3;
	if (f(x1, y1, x2, y2, x3, y3) == false)
		input();
}
void Triangle::input() {
	double x1, x2, x3, y1, y2, y3;
	do {
		cout << "�����������ε���������:";
		cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
		m_x1 = x1;
		m_y1 = y1;
		m_x2 = x2;
		m_y2 = y2;
		m_x3 = x3;
		m_y3 = y3;
		cout << "�������޷�����������" << endl;
	} while (f(x1, y1, x2, y2, x3, y3) == false);
}
bool Triangle::f(double x1, double y1, double x2, double y2, double x3,double y3) {
	double a, b, c;
	a = edge(x1, y1, x2, y2);
	b = edge(x1, y1, x3, y3);
	c = edge(x2, y2, x3, y3);
	if (a == 0 || b == 0 || c == 0)
		return false;
	if (a + b <= c)
		return false;
	if (a + c <= b)
		return false;
	if (b + c <= a)
		return false;
	return true;
}
double Triangle::edge(double x1,double y1,double x2,double y2) {
	return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}
double Triangle::getgirth() {
	return edge(m_x1,m_y1,m_x2,m_y2) + edge(m_x1,m_y1,m_x3,m_y3) + edge(m_x3,m_y3,m_x2,m_y2);
}
double Triangle::getarea(){
	double p, a, b, c;
	a = edge(m_x1, m_y1, m_x2, m_y2);
	b = edge(m_x1, m_y1, m_x3, m_y3);
	c = edge(m_x2, m_y2, m_x3, m_y3);
	p = (a + b + c) / 2;
	return sqrt(p * (p - a) * (p - b) * (p - c));
}
void Triangle::show() {
	cout << "�����ε���������Ϊ��(" << m_x1 << "," << m_y1 << "),(" << m_x2 << "," << m_y2
			<< "),(" << m_x3 << "," << m_y3 << ")" << endl;
	cout << "�ܳ�Ϊ��" << getgirth() << "���Ϊ��" << getarea() << endl << endl;
}
*/
