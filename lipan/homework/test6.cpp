/*
 * test6.cpp
 *
 *  Created on: 2018��5��9��
 *      Author: asus
 */

/*
#include <iostream>

using namespace std;

#define MAX 10
class function{
private:
	double d[MAX];//����
	int count;//��¼����Ԫ�ظ���
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
	f.input();//��������Ԫ�أ���0Ϊ������־
	cout << "����Ԫ�ص����ֵ��" << f.max() << endl;
	cout << "����Ԫ�ص���Сֵ��" << f.min() << endl;
	cout << "����Ԫ�صĺͣ�" << f.sum() << endl;
	cout << "����Ԫ�ص�ƽ��ֵ��" << f.avg() << endl;
	f.output();//���
}

void function::input() {
	double a;
	count = 0;
	cout << "����������Ԫ��(0Ϊ������־)��";
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
