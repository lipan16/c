/*
 * 8-1.cpp
 *
 *  Created on: 2018年6月7日
 *      Author: asus
 */

/*
#include <iostream>
#include <cmath>
using namespace std;
#define PI 3.1415926

class shape {
protected:
	double m_x, m_y;
public:
	shape() {
		m_x = 0;
		m_y = 0;
	}
	shape(double x, double y) {
		m_x = x;
		m_y = y;
	}
	virtual double area()=0;
};

class circle: public shape {
protected:
	double m_r;
public:
	circle() {
		m_r = 1;
	}
	circle(double x, double y, double r) {
		m_x = x;
		m_y = y;
		m_r = r;
	}
	double area() {
		return PI * m_r * m_r;
	}
};

class rectangle: public shape {
public:
	rectangle() {
		m_x = 1;
		m_y = 1;
	}
	rectangle(double x, double y) {
		m_x = x;
		m_y = y;
	}
	double area() {
		return m_x * m_y;
	}
};

class triangle: public shape {
protected:
	int m_x2, m_y2, m_x3, m_y3;
public:
	triangle() {
		m_x = 0;
		m_y = 1;
		m_x2 = 0;
		m_y2 = 0;
		m_x3 = 1;
		m_y3 = 0;
	}
	triangle(double x1, double y1, double x2, double y2, double x3, double y3) {
		m_x = x1;
		m_y = y1;
		m_x2 = x2;
		m_y2 = y2;
		m_x3 = x3;
		m_y3 = y3;
		while (f(m_x, m_y, m_x2, m_y2, m_x3, m_y3) == false) {
			cout << "该数据无法构成三角形" << endl;
			cout << "请输入三角形的三个顶点:";
			cin >> m_x >> m_y >> m_x2 >> m_y2 >> m_x3 >> m_y3;
		}
	}
	bool f(double x1, double y1, double x2, double y2, double x3, double y3) {
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
	double edge(double x1, double y1, double x2, double y2) {
		return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
	}
	double area() {
		double a, b, c, p;
		a = edge(m_x, m_y, m_x2, m_y2);
		b = edge(m_x, m_y, m_x3, m_y3);
		c = edge(m_x2, m_y2, m_x3, m_y3);
		p = (a + b + c) / 2.0;
		return sqrt(p * (p - a) * (p - b) * (p - c));
	}
};
int main() {
	shape *p;
	circle c(30,45,35);
	rectangle r(14,45);
	triangle t(34, 45, 89, 45, 54, 67);

	p=&c;
	cout << "circle area:" << p->area() << endl;
	p=&r;
	cout << "rectangle area:" << p->area() << endl;
	p=&t;
	cout << "triangle area:" << p->area() << endl;
}

*/
