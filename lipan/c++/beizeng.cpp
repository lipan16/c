/*
int cmp(int *r, int a, int b, int l) {
	return r[a] == r[b] && r[a + l] == r[b + l];
}

 * 待排序的字符串放在r数组中，共n个，且r数组元素的最大值小于m，为了函数操作方便，约定除r[n-1]外所有的r[i]都大于0,r[n-1]=0
 * 倍增算法结束后，结果放在sa数组中，从sa[0]到sa[n-1]

void da(int *r, int *sa, int n, int m) {
	int wa[maxn], wb[maxn], wv[maxn], ws[maxn];
	int i, j, p, *x = wa, *y = wb, *t;
	for (i = 0; i < m; i++)	//ws数组初始化为0
		ws[i] = 0;
	for (i = 0; i < n; i++)//r数组复制一份给wa数组，ws[r[i]]自加1，相当于统计r数组中的元素个数，ws数组下标为r数组中的值，ws数组的值为在r数组中出现的次数
		ws[x[i] = r[i]]++;
	for (i = 1; i < m; i++)//ws数组从第二项开始每一项为该项和前一项之和
		ws[i] += ws[i - 1];
	for (i = n - 1; i >= 0; i--)//
		sa[--ws[x[i]]] = i;
	for (j = 1, p = 1; p < n; j *= 2, m = p) {
		for (p = 0, i = n - j; i < n; i++)
			y[p++] = i;
		for (i = 0; i < n; i++)
			if (sa[i] >= j)
				y[p++] = sa[i] - j;

		//对第一关键字(高位)进行排序
		for (i = 0; i < n; i++)
			wv[i] = x[y[i]];
		for (i = 0; i < m; i++)
			ws[i] = 0;
		for (i = 0; i < n; i++)
			ws[wv[i]]++;
		for (i = 1; i < m; i++)
			ws[i] += ws[i - 1];
		for (i = n - 1; i >= 0; i--)
			sa[--ws[wv[i]]] = y[i];

		for (t = x, x = y, y = t, p = 1, x[sa[0]] = 0, i = 1; i < n; i++)
			x[sa[i]] = cmp(y, sa[i - 1], sa[i], j) ? p - 1 : p++;
	}
	return;
}
*/
