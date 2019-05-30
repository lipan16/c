/*
 * 7_4.c
 *
 *  Created on: 2019Äê4ÔÂ4ÈÕ
 *      Author: asus
 */

/*#include <stdio.h>

int main() {
	int n = 10, i, j;
	int a[n][2 * n];
	for (i = 0; i < n; i++) {
		for (j = 0; j <= i; j++) {
			if (j == 0 || i == j)
				a[i][j] = 1;
			else
				a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
		}
	}
	for (i = 0; i < n; i++) {
		for (j = 0; j < n - i - 1; j++)
			printf(" ");
		for (j = 0; j <= i; j++)
			printf("%3d ", a[i][j]);
		printf("\n");
	}
	return 0;
}*/

