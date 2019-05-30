/*
 * Shape.cpp
 *
 *  Created on: 2018年5月3日
 *      Author: asus
 */
/*
#include <iostream>
#include <cmath>

using namespace std;

#include "Shape.h"
const double PI = 3.14159;

Circle::Circle() { //缺省的构造方法
	d.x = 0;
	d.y = 0;
	radius = 1;
}
Circle::Circle(double x, double y, double r) { //带参的构造方法
	d.x = x;
	d.y = y;
	while (r < 0) {
		cout << "半径r=" << r << "半径小于零,不是一个圆，请重新输入半径:";
		cin >> r;
	}
	radius = r;
}
void Circle::set(double x, double y, double r) {
	d.x = x;
	d.y = y;
	while (r < 0) {
		cout << "半径r=" << r << "半径小于零,不是一个圆，请重新输入半径:";
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
		cout << "此时，图形为一个点，坐标是：(" << d.x << "," << d.y << ")" << endl << endl;
	else {
		cout << "圆心为：(" << d.x << "," << d.y << ") , 半径为：" << radius << endl;
		cout << "周长为：" << getgirth() << "面积为：" << getarea() << endl << endl;
	}
}

Rectangle::Rectangle() { //缺省的构造方法
	m_x = 1;
	m_y = 1;
}
Rectangle::Rectangle(double x, double y) { //带参的构造方法
	while (x <= 0) {
		cout << "长度x=" << x << "长度不能小于0，请重新输入长度:";
		cin >> x;
	}
	while (x <= 0) {
		cout << "宽度y=" << y << "宽度不能小于0，请重新输入宽度:";
		cin >> x;
	}
	m_x = x;
	m_y = y;
}
void Rectangle::set(double x, double y) {
	while (x <= 0) {
		cout << "长度x=" << x << "长度不能小于0，请重新输入长度:";
		cin >> x;
	}
	while (x <= 0) {
		cout << "宽度y=" << y << "宽度不能小于0，请重新输入宽度:";
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
	cout << "矩形的长为：" << m_x << "宽为：" << m_y << endl;
	cout << "周长为：" << getgirth() << "面积为：" << getarea() << endl << endl;
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
		cout << "该数据无法构成三角形" << endl;
		set();
	}
}
//void set(double x1,double y1,double x2,double y2,double x3,double y3){
void Triangle::set() {
	double x1, x2, x3, y1, y2, y3;
	cout << "请输入三角形的三个顶点:";
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
	a.x = x1;
	a.y = y1;
	b.x = x2;
	b.y = y2;
	c.x = x3;
	c.y = y3;
	if (f(a, b, c) == false) {
		cout << "该数据无法构成三角形" << endl;
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
	cout << "三角形的三个顶点为：(" << a.x << "," << a.y << "),(" << b.x << "," << b.y
			<< "),(" << c.x << "," << c.y << ")" << endl;
	cout << "周长为：" << getgirth() << endl << endl;
}
*/
