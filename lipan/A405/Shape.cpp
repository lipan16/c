/*
 * Shape.cpp
 *
 *  Created on: 2018��5��3��
 *      Author: asus
 */
/*
#include <iostream>
#include <cmath>

using namespace std;

#include "Shape.h"
const double PI = 3.14159;

Circle::Circle() { //ȱʡ�Ĺ��췽��
	d.x = 0;
	d.y = 0;
	radius = 1;
}
Circle::Circle(double x, double y, double r) { //���εĹ��췽��
	d.x = x;
	d.y = y;
	while (r < 0) {
		cout << "�뾶r=" << r << "�뾶С����,����һ��Բ������������뾶:";
		cin >> r;
	}
	radius = r;
}
void Circle::set(double x, double y, double r) {
	d.x = x;
	d.y = y;
	while (r < 0) {
		cout << "�뾶r=" << r << "�뾶С����,����һ��Բ������������뾶:";
		cin >> r;
	}
	radius = r;
}
double Circle::getarea() {
	return PI * radius * radius;
}
double Circle::getgirth() {
	return 2 * PI * radius;
}
void Circle::show() {
	if (radius == 0)
		cout << "��ʱ��ͼ��Ϊһ���㣬�����ǣ�(" << d.x << "," << d.y << ")" << endl << endl;
	else {
		cout << "Բ��Ϊ��(" << d.x << "," << d.y << ") , �뾶Ϊ��" << radius << endl;
		cout << "�ܳ�Ϊ��" << getgirth() << "���Ϊ��" << getarea() << endl << endl;
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
	a.x = 0;
	a.y = 1;
	b.x = 0;
	b.y = 0;
	c.x = 1;
	c.y = 0;
}
Triangle::Triangle(double x1, double y1, double x2, double y2, double x3,
		double y3) {
	a.x = x1;
	a.y = y1;
	b.x = x2;
	b.y = y2;
	c.x = x3;
	c.y = y3;
	if (f(a, b, c) == false) {
		cout << "�������޷�����������" << endl;
		set();
	}
}
//void set(double x1,double y1,double x2,double y2,double x3,double y3){
void Triangle::set() {
	double x1, x2, x3, y1, y2, y3;
	cout << "�����������ε���������:";
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
	a.x = x1;
	a.y = y1;
	b.x = x2;
	b.y = y2;
	c.x = x3;
	c.y = y3;
	if (f(a, b, c) == false) {
		cout << "�������޷�����������" << endl;
		set();
	}
}

bool Triangle::f(dot a, dot b, dot c) {
	if (edge(a, b) == 0 || edge(a, c) == 0 || edge(a, c) == 0)
		return false;
	if (edge(a, b) + edge(a, c) <= edge(b, c))
		return false;
	if (edge(a, b) + edge(b, c) <= edge(a, c))
		return false;
	if (edge(c, b) + edge(a, c) <= edge(b, a))
		return false;
	return true;
}

double Triangle::edge(dot a, dot b) {
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

double Triangle::getgirth() {
	return edge(a, b) + edge(a, c) + edge(b, c);
}

void Triangle::show() {
	cout << "�����ε���������Ϊ��(" << a.x << "," << a.y << "),(" << b.x << "," << b.y
			<< "),(" << c.x << "," << c.y << ")" << endl;
	cout << "�ܳ�Ϊ��" << getgirth() << endl << endl;
}
*/
