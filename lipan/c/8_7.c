/*
 * 8_7.c
 *
 *  Created on: 2019��4��9��
 *      Author: asus
 */

/*
#include <stdio.h>
#include <stdlib.h>
//10->16����
char *test(long num) {
	char *buffer = (char *) malloc(sizeof(long) * 2 + 3);
	char *hexstr;
	long temp = 15;
	int i, hexlen = sizeof(long) * 2; //�����������ֽ��� 4*2

	buffer[0] = '0';
	buffer[1] = 'x';
	buffer[10] = '\0';
	hexstr = buffer + 2;
	for (i = 0; i < hexlen; i++) {
		//�ӵ�λ����λÿ��ȡhexlen����λ�����ܵ���ֵΪ0~15������λ�������ֵת��Ϊ�ַ�����
		hexstr[hexlen - i - 1] = (char) ((num >> 4 * i) & temp);
		hexstr[hexlen - i - 1] =
				hexstr[hexlen - i - 1] < 10 ?
						hexstr[hexlen - i - 1] + 48 :
						hexstr[hexlen - i - 1] + 55;
	}
	return buffer;
}

int main() {
	char *p;
	long number = 15;
	p = test(number);
	printf("%s\n", p);
	return 0;
}
*/
