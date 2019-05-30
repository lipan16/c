/*
 * 9-1.cpp
 *
 *  Created on: 2018年6月14日
 *      Author: asus
 */

/*从键盘输入字符串并保存成文件。
 要求：
 1、输入字符串中包括：大小写字母、空格、数字等字符，以“#”作为字符串输入的结
 束条件；
 2、对输入的字符进行加密并保存，以二进制文件方式保存，用户可以输入保存路径，
 如：C：\file.txt ；
 3、打开文件时，对加密文件进行解密并显示在屏幕上。
 [实验提示]
 1、使用cin 获取输入字符时，遇到空格时终止读取字符，为了避免这种情况，不能简单使用cin 来获取输入字符；
 2、加密方式：
 将字母 A 变成E，a 变成e，即将字母变成其后的第4 个字母，W 变A，X 变成B，Y
 变成C，Z 变成D，w 变a，x 变成b，y 变成c，z 变成d。
 解密方式：即加密方式的逆过程。
 [测试数据]
 自己设计测试数据，进行测试；
 在实验报告中，列出自己设计的测试数据。
 */
/*
#include <iostream>
#include <fstream>

using namespace std;

void file(char []);
void decode(char []);

int main() {
	char des[20];
	cout<<"please input file name:";
	cin>>des;
	file(des);
	decode(des);
}

void file(char des[]) {
	char ch;
	ofstream out(des, ios::out);
	if (!out) {
		cerr << des<<" : File could not be open!" << endl;
		return;
	}
	cout << "please input:";
	cin.get(ch);
	while (ch != '#') {
		if (('a' <= ch && ch <= 'z') || ('A' <= ch && ch <= 'Z')) {
			switch (ch) {
			case 'w':
				ch = 'a';break;
			case 'W':
				ch = 'A';break;
			case 'x':
				ch = 'b';break;
			case 'X':
				ch = 'B';break;
			case 'y':
				ch = 'c';break;
			case 'Y':
				ch = 'C';break;
			case 'z':
				ch = 'd';break;
			case 'Z':
				ch = 'D';break;
			default:
				ch += 4;break;
			}
		}
		out.put(ch);
		cin.get(ch);
	}
	out.close();
}

void decode(char des[]) {
	char ch;
	ifstream in(des, ios::in);
	if (!in) {
		cerr << des<<" : File could not be open!" << endl;
		return;
	}
	cout << "\ndecode:";
	while (in.get(ch)) {
		if (('a' <= ch && ch <= 'z') || ('A' <= ch && ch <= 'Z')) {
			switch (ch) {
			case 'a':
				ch = 'w';break;
			case 'A':
				ch = 'W';break;
			case 'b':
				ch = 'x';break;
			case 'B':
				ch = 'X';break;
			case 'c':
				ch = 'y';break;
			case 'C':
				ch = 'Y';break;
			case 'd':
				ch = 'z';break;
			case 'D':
				ch = 'Z';break;
			default:
				ch -= 4;break;
			}
		}
		cout << ch;
	}
	in.close();
}
*/
