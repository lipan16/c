/*
 * 7_5.c
 *
 *  Created on: 2019Äê4ÔÂ4ÈÕ
 *      Author: asus
 */

/*#include <stdio.h>

int main() {
	int n = 3, i, j, k = 1;
	int a[n][n];
	i = 0;
	j = (n - 1) / 2;
	a[i][j] = 1;
	for (k = 2; k <= n * n; k++) {
		if ((k - 1) % n == 0)
			i++;
		else {
			i = (i - 1 + n) % n;
			j = (j + 1) % n;
		}
		a[i][j] = k;
	}
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
	return 0;
}*/

