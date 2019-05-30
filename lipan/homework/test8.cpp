/*
 * test8.cpp
 *
 *  Created on: 2018年5月28日
 *      Author: asus
 */

/*
#include <iostream>

using namespace std;

class circle{
protected:
	double r;
public:
	circle();
	circle(int);
	double area();
	void display();
};

class cylinder:public circle{
protected:
	double h;
public:
	cylinder();
	cylinder(int hh);
	cylinder(int rr,int hh);
	double volume();
	void display();
};


circle::circle() {
	r = 1;
}
circle::circle(int i) {
	while (i < 0) {
		cout << "radius error please reset radius:";
		cin >> i;
	}
	r = i;
}
double circle::area() {
	return r * r * 3.14;
}
void circle::display() {
	cout << "the circle of information:" << endl;
	cout << "该圆半径：" << r << endl;
	cout << "该圆面积：" << area() << endl;
}

cylinder::cylinder() {
	r = 1;
	h = 1;
}
cylinder::cylinder(int hh) {
	while (hh < 0) {
		cout << "height error please reset height:";
		cin >> hh;
	}
	h = hh;
}
cylinder::cylinder(int rr, int hh) {
	while (rr < 0) {
		cout << "radius error please reset radius:";
		cin >> rr;
	}
	r = rr;
	while (hh < 0) {
		cout << "height error please reset height:";
		cin >> hh;
	}
	h = hh;
}
double cylinder::volume(){
	return h*area();
}
void cylinder::display(){
	cout << "the cylinder of information:" << endl;
	cout << "该圆柱体的底面半径：" << r << endl;
	cout << "该圆柱高：" << h << endl;
	cout << "该圆柱体的底面积：" << area() << endl;
	cout << "该圆柱体积：" << volume() << endl;
}

int main(){
	circle(3).display();
	cylinder(3,2).display();
}
*/
