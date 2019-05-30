/*
 * 10_2.c
 *
 *  Created on: 2019年4月10日
 *      Author: asus
 */

/*
#include <stdio.h>

int main() {
	int * p[4]; //指针数组，每个数组元素可指向一个int变量 * p[i]
	int i, a = 1, b = 2, c = 3, d = 4;
	p[0] = &a;
	p[1] = &b;
	p[2] = &c;
	p[3] = &d;
	for (i = 0; i < 4; i++) {
		printf("%d ", *p[i]);
	}

	int (*t)[4]; //数组指针，t是一个指针变量，指向（只能指向）包含四个int元素的一维数组，(*t)[i]
	int x[4] = { 1, 2, 3, 4 };
	t = &x;
	for (i = 0; i < 4; i++) {
		printf("%d ", (*t)[i]);
	}
	return 0;
}
*/

