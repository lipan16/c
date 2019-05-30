/*
 * 8_6.c
 *
 *  Created on: 2019年4月9日
 *      Author: asus
 */

/*
#include <stdio.h>
//10->2进制
int main() {
	int Two[sizeof(long) * 8]; //存放二进制表示的数
	int Bit, i;
	long Ten = 10, temp = 1;
	Bit = sizeof(long) * 8;
	if (Ten == 0) {
		for (i = 0; i < Bit; i++)
			printf("0");
	} else {
		for (i = 0; i < Bit; i++, temp = temp << 1) {
			if ((Ten & temp) != 0)  //取Ten第i位(其他位为0)形成的长整型数
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
