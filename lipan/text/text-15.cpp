/*
 * text-15.cpp
 *
 *  Created on: 2018��7��2��
 *      Author: asus
 */

/*
 * Ҫ��ʵ�ֺ�����
char* stringZip(const char *pInputStr, long inputLen );
����˵����
����һ��Сд��ĸ(a~z) ��ɵ��ַ��� �� ���������ֵ��ظ���ĸ����ѹ���� �����ѹ������ַ��� ��
ѹ������
- ��ѹ�������ظ����ֵ��ַ��� �����ַ��� "abcbc"�����������ظ��ַ��� ѹ����
���ַ�������"abcbc"��
- ѹ���ֶεĸ�ʽΪ"�ַ��ظ��Ĵ���+�ַ�"�� ���磺 �ַ��� "xxxyyyyyyz"ѹ����ͳ�Ϊ"3x6yz"��
��������˵����
 pInputStr��  �����ַ��� ��
 inputLen�� �����ַ����ĳ��ȣ�
���ԣ�
���룺 ��cccddecc�� ����� ��3c2de2c��
���룺 ��adef�� ����� ��adef��
���룺 ��pppppppp�� ����� ��8p��
 */

/*
#include <iostream>
#include <cstring>
using namespace std;

char * stringzip(const char *pInputstr,long inputlen);

int main(){
	char *p[3];
	p[0]=stringzip("cccddecc",8);
	p[1]=stringzip("adef",4);
	p[2]=stringzip("pppppppp",8);
	for(int i=0;i<3;i++)
		cout<<*p<<endl;
}
char * stringzip(const char *pInputstr,long inputlen){
	char ch=pInputstr[0];
	char * des = &ch;
	for (int i = 1; i < inputlen; i++) {
		int count = 1;//��¼�ظ�����
		for (int j = i; j < inputlen; j++) {
			if (ch == pInputstr[j])
				count++;
			else {
				count = 1;
				ch = pInputstr[i];
				strcat(des, &ch);
				break;
			}
			if (count != 1) {
				strcat(des, (char *) count);
				strcat(des, &ch);
			}
		}
	}
	return des;
}
*/
