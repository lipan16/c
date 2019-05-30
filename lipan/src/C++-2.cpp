/*

 * C++-2.cpp
 *
 *  Created on: 2018年4月8日
 *      Author: asus
 *
 *      输入一个整数，返回最近一个大于该数由该数相同数字组成的整数，如果该数已经是最大返回本身
 *      输入：12345
 *      输出：12354
 *
 *      输入：12345554
 *      输出：12354455
 *
 *      输入：54321
 *      输出：54321
 */




/*
#include <iostream>
#include <string>

using namespace std;

void FindNearestNumber(char (*str), int length);
int FindTransferPoint(char *str, int length);
void ExchangeHead(char *str, int index, int length);
void Reverse(char *str, int index, int length);

int main() {
	string str;
	cin >> str;
	char *str1 = (char *) str.c_str();
	FindNearestNumber(str1, str.length());
	cout << str;
}

void FindNearestNumber(char *str, int length) {
	int index = FindTransferPoint(str, length);
	if (index == 0)
		return;
	ExchangeHead(str, index, length);
	Reverse(str, index, length);
}

int FindTransferPoint(char *str, int length) {
	for (int i = length - 1; i > 0; i--)
		if (str[i] > str[i - 1])
			return i;
	return 0;
}

void ExchangeHead(char *str, int index, int length) {
	int head = str[index - 1];
	for (int i = length - 1; i >= 0; i--) {
		if (head < str[i]) {
			str[index - 1] = str[i];
			str[i] = head;
			break;
		}
	}
}

void Reverse(char *str, int index, int length) {
	for (int i = index, j = length - 1; i < j; i++, j--) {
		int temp = str[i];
		str[i] = str[j];
		str[j] = temp;
	}
}
*/




/*
#include <iostream>
#include <string>

using namespace std;

void FindNearestNumber(char (*str), int length);
int FindTransferPoint(char *str, int length);
void ExchangeHead(char *str, int index, int length);
void Reverse(char *str, int index, int length);

int main() {
	string str;
	cin >> str;
	char *str1 = (char *) str.c_str(); //把string形式的字符串转换成char*形式
	FindNearestNumber(str1, str.length());//找大于它的由这几个数字组成的最小数
	cout<<str;//输出
}

void FindNearestNumber(char *str, int length) {
	int index = FindTransferPoint(str, length);
	if(index==0)
		return;
	ExchangeHead(str, index, length);
	Reverse(str, index, length);
}

int FindTransferPoint(char *str, int length) {//找分段点，顺序时最小，逆序时最大，分段点为两者中间，后面为逆序，前面为顺序
	for (int i = length - 1; i > 0; i--)
		if (str[i] > str[i - 1])
			return i;
	return 0;
}

void ExchangeHead(char *str, int index, int length) {//在后面逆序中找一个刚好大于分段点数的最小数与分段点进行交换
	int head = str[index - 1];
	for (int i = length - 1; i >= 0; i--) {
		if (head < str[i]) {
			str[index - 1] = str[i];
			str[i] = head;
			break;
		}
	}
}

void Reverse(char *str, int index, int length) {//交换分段点数后，后面的逆序变为顺序，刚好最接近于原数
	for (int i = index, j = length - 1; i < j; i++, j--) {
		int temp = str[i];
		str[i] = str[j];
		str[j] = temp;
	}
}*/


