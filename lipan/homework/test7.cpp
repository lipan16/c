/*
 * test7.cpp
 *
 *  Created on: 2018年5月23日
 *      Author: asus
 */

/*
 给复数运算重载复数的四则运算符。 复数由实部和虚部构造， 可以定义一个复数类， 然后再在类中重载复数四则运算的运算符。
 例： c1=2+3i， c2=4-2i。 得出如下结果：
 c1+c2=6+1i
 c1-c2=-2+5i
 c1*c2=14+8i
 c1/c2=0.1+0.8i
 (c1+c2)*(c1-c2)*c2/c1=31.8462+25.2308i
 */


/*

#include <iostream>
#include <stdlib.h>

using namespace std;

class fushu {
public:
	fushu();
	fushu(double);
	fushu(double, double);
	void setXY(double, double);
	double getreal();
	double getimage();
	friend fushu operator+(const fushu &c1, const fushu &c2); //友元函数重载+运算符
	friend fushu operator-(const fushu &c1, const fushu &c2); //友元函数重载-运算符
	friend fushu operator*(const fushu &c1, const fushu &c2); //友元函数重载*运算符
	friend fushu operator/(const fushu &c1, const fushu &c2); //友元函数重载/运算符
	friend fushu operator-(const fushu &c1); //友元函数重载-运算符(负号
	void display();
private:
	double real, image;
};

fushu::fushu() {
	real = 0;
	image = 0;
}

fushu::fushu(double r) {
	real = r;
	image = 0;
}

fushu::fushu(double r, double i) {
	real = r;
	image = i;
}

void fushu::setXY(double r, double i) {
	real = r;
	image = i;
}

double fushu::getreal() {
	return real;
}

double fushu::getimage() {
	return image;
}

fushu operator+(const fushu &c1, const fushu &c2) { //友元函数重载+运算符
	double r = c1.real + c2.real;
	double i = c1.image + c2.image;
	return fushu(r, i);
}

fushu operator-(const fushu &c1, const fushu &c2) { //友元函数重载-运算符
	double r = c1.real - c2.real;
	double i = c1.image - c2.image;
	return fushu(r, i);
}

fushu operator*(const fushu &c1, const fushu &c2) { //友元函数重载*运算符
	double r = c1.real * c2.real - c1.image * c2.image;
	double i = c1.real * c2.image + c1.image * c2.real;
	return fushu(r, i);
}

fushu operator/(const fushu &c1, const fushu &c2) { //友元函数重载/运算符
	if ((c2.real * c2.real + c2.image * c2.image) == 0) {
		cout << "除数不能为零";
		exit(0);
	}
	else {
		double r = (c1.real * c2.real + c1.image * c2.image)
				/ (c2.real * c2.real + c2.image * c2.image);
		double i = (c2.real * c1.image - c1.real * c2.image)
				/ (c2.real * c2.real + c2.image * c2.image);
		return fushu(r, i);
	}
}

fushu operator-(const fushu &c1) { //友元函数重载-运算符(负号
	double r = -c1.real;
	double i = -c1.image;
	return fushu(r, i);
}

void fushu::display() {
	if (real == 0 && image != 0) //实部为0、虚部不为0时，只输出虚部
	{
		if (image == 1) //虚部系数为1，输出i
			cout << "i" << endl;
		else if (image == -1) //虚部系数为-1，输出-i
			cout << "-i" << endl;
		else //虚部系数为其他
			cout << image << "i" << endl;
	}
	else if (image == 0) //虚部为0时，虚部不显示
		cout << real << endl;
	else if (image > 0)
		cout << real << "+" << image << "i" << endl;
	else
		cout << real << image << "i" << endl;
}

int main() {
	fushu c1(0,-1), c2(0,1), c;

	cout << "c1 + c2 =";
	c = c1 + c2;
	c.display();

	cout << "c1 - c2 =";
	c = c1 - c2;
	c.display();

	cout << "c1 * c2 =";
	c = c1 * c2;
	c.display();

	cout << "c1 / c2 =";
	c = c1 / c2;
	c.display();

	cout<<"(c1+c2)*(c1-c2)*c2/c1=";
	c = (c1 + c2) * (c1 - c2) * c2 / c1;
	c.display();
}
*/



/*
class A{
public:
	A(int x):a(x){}
	int a;
};
class B{
public:
	B(int x,int y):aa(x){b=y;}
	void out(){cout<<"aa="<<aa.a<<endl<<"b="<<b<<endl;}
private:
	int b;
	A aa;
};
int main(){
	B b(3,5);
	b.out();
}
*/
