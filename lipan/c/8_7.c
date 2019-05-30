/*
 * 8_7.c
 *
 *  Created on: 2019年4月9日
 *      Author: asus
 */

/*
#include <stdio.h>
#include <stdlib.h>
//10->16进制
char *test(long num) {
	char *buffer = (char *) malloc(sizeof(long) * 2 + 3);
	char *hexstr;
	long temp = 15;
	int i, hexlen = sizeof(long) * 2; //长整型数的字节数 4*2

	buffer[0] = '0';
	buffer[1] = 'x';
	buffer[10] = '\0';
	hexstr = buffer + 2;
	for (i = 0; i < hexlen; i++) {
		//从低位到高位每次取hexlen的四位，可能的数值为0~15，将四位代表的数值转换为字符类型
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
