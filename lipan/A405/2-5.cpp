/*
 * 2-5.cpp
 *
 *  Created on: 2018��4��24��
 *      Author: asus
 */
/*
#include <iostream>
#include <cstring>
#include <string>
using namespace std;
#define max 100

void f1();
void f2();
void f3();

int main() {
	f1();
	f2();
	f3();
}

void f1() { //�����鴮����
	char str[max], dst[max];
	cin >> str >> dst;
	int i = 0, j = 0;
	while (str[i] != '\0') {
		i++;
	}
	while (dst[j] != '\0') {
		str[i++] = dst[j++];
	}
	cout << str << endl;
}

void f2() { //strcat����������
	char str[max], dst[max];
	cin >> str >> dst;
	strcat(str, dst);
	cout << str << endl;
}

void f3() { //��string����ֱ����'+'����
	string str, dst;
	cin >> str >> dst;
	str = str + dst; //str.append(dst);
	cout << str << endl;
}

*/
