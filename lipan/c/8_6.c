/*
 * 8_6.c
 *
 *  Created on: 2019��4��9��
 *      Author: asus
 */

/*
#include <stdio.h>
//10->2����
int main() {
	int Two[sizeof(long) * 8]; //��Ŷ����Ʊ�ʾ����
	int Bit, i;
	long Ten = 10, temp = 1;
	Bit = sizeof(long) * 8;
	if (Ten == 0) {
		for (i = 0; i < Bit; i++)
			printf("0");
	} else {
		for (i = 0; i < Bit; i++, temp = temp << 1) {
			if ((Ten & temp) != 0)  //ȡTen��iλ(����λΪ0)�γɵĳ�������
				Two[Bit - i - 1] = 1;
			else
				Two[Bit - i - 1] = 0;
		}
		for (i = 0; i < Bit; i++)
			printf("%d", Two[i]);
	}
	printf("\n");
}
*/
