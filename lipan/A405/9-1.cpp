/*
 * 9-1.cpp
 *
 *  Created on: 2018��6��14��
 *      Author: asus
 */

/*�Ӽ��������ַ�����������ļ���
 Ҫ��
 1�������ַ����а�������Сд��ĸ���ո����ֵ��ַ����ԡ�#����Ϊ�ַ�������Ľ�
 ��������
 2����������ַ����м��ܲ����棬�Զ������ļ���ʽ���棬�û��������뱣��·����
 �磺C��\file.txt ��
 3�����ļ�ʱ���Լ����ļ����н��ܲ���ʾ����Ļ�ϡ�
 [ʵ����ʾ]
 1��ʹ��cin ��ȡ�����ַ�ʱ�������ո�ʱ��ֹ��ȡ�ַ���Ϊ�˱���������������ܼ�ʹ��cin ����ȡ�����ַ���
 2�����ܷ�ʽ��
 ����ĸ A ���E��a ���e��������ĸ������ĵ�4 ����ĸ��W ��A��X ���B��Y
 ���C��Z ���D��w ��a��x ���b��y ���c��z ���d��
 ���ܷ�ʽ�������ܷ�ʽ������̡�
 [��������]
 �Լ���Ʋ������ݣ����в��ԣ�
 ��ʵ�鱨���У��г��Լ���ƵĲ������ݡ�
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
