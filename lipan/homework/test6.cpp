/*
 * test6.cpp
 *
 *  Created on: 2018年5月9日
 *      Author: asus
 */

/*
#include <iostream>

using namespace std;

#define MAX 10
class function{
private:
	double d[MAX];//数组
	int count;//记录数组元素个数
public:
	void input();
	double max();
	double min();
	double sum();
	double avg();
	void output();
};

int main(){
	function f;
	f.input();//输入数组元素，以0为结束标志
	cout << "数组元素的最大值：" << f.max() << endl;
	cout << "数组元素的最小值：" << f.min() << endl;
	cout << "数组元素的和：" << f.sum() << endl;
	cout << "数组元素的平均值：" << f.avg() << endl;
	f.output();//输出
}

void function::input() {
	double a;
	count = 0;
	cout << "请输入数组元素(0为结束标志)：";
	cin >> a;
	for (int i = 0; a != 0; i++) {
		d[i] = a;
		cin >> a;
		count++;
	}
}

void function::output() {
	for (int i = 0; i < count; i++)
		cout << d[i] << " ";
}

double function::max() {
	double a = d[0];
	for (int i = 0; i < count; i++) {
		if (a < d[i]) {
			a = d[i];
		}
	}
	return a;
}

double function::min() {
	double a = d[0];
	for (int i = 0; i < count; i++) {
		if (a > d[i]) {
			a = d[i];
		}
	}
	return a;
}

double function::sum() {
	double a =0;
	for (int i = 0; i < count; i++) {
		a += d[i];
	}
	return a;
}

double function::avg() {
	return sum() / count;
}
*/
