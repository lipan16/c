/*
 * 2-1.cpp
 *
 *  Created on: 2018年6月22日
 *      Author: asus
 */

/*
#include <iostream>

using namespace std;

int n = 0;//全局变量
int func(int x = 10);
int a, b;
int main() {
	a = 10;
	b = func(a);
	cout << "\nlocal a=" << a << endl << "local b=" << b << endl << "global n="
			<< n << endl;
	a++;
	b = func(a);
	cout << "\nlocal a=" << a << endl << "local b=" << b << endl << "global n="
			<< n << endl;
	cout << "\nlocal a=" << a << endl << "local b=" << b << endl << "global n="
			<< n << endl;
	func();
}
int func(int x) {
	int a = 1;//局部变量
	static int b = 10;//静态局部变量
	a++;
	b++;
	x++;
	n++;
	cout << "\nlocal a=" << a << endl << "local b=" << b << endl << "parameter x="
			<< x << endl;
	return a + b;
}
*/
