/*

 * C++-2.cpp
 *
 *  Created on: 2018��4��8��
 *      Author: asus
 *
 *      ����һ���������������һ�����ڸ����ɸ�����ͬ������ɵ���������������Ѿ�����󷵻ر���
 *      ���룺12345
 *      �����12354
 *
 *      ���룺12345554
 *      �����12354455
 *
 *      ���룺54321
 *      �����54321
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
	char *str1 = (char *) str.c_str(); //��string��ʽ���ַ���ת����char*��ʽ
	FindNearestNumber(str1, str.length());//�Ҵ����������⼸��������ɵ���С��
	cout<<str;//���
}

void FindNearestNumber(char *str, int length) {
	int index = FindTransferPoint(str, length);
	if(index==0)
		return;
	ExchangeHead(str, index, length);
	Reverse(str, index, length);
}

int FindTransferPoint(char *str, int length) {//�ҷֶε㣬˳��ʱ��С������ʱ��󣬷ֶε�Ϊ�����м䣬����Ϊ����ǰ��Ϊ˳��
	for (int i = length - 1; i > 0; i--)
		if (str[i] > str[i - 1])
			return i;
	return 0;
}

void ExchangeHead(char *str, int index, int length) {//�ں�����������һ���պô��ڷֶε�������С����ֶε���н���
	int head = str[index - 1];
	for (int i = length - 1; i >= 0; i--) {
		if (head < str[i]) {
			str[index - 1] = str[i];
			str[i] = head;
			break;
		}
	}
}

void Reverse(char *str, int index, int length) {//�����ֶε����󣬺���������Ϊ˳�򣬸պ���ӽ���ԭ��
	for (int i = index, j = length - 1; i < j; i++, j--) {
		int temp = str[i];
		str[i] = str[j];
		str[j] = temp;
	}
}*/


