/*
int cmp(int *r, int a, int b, int l) {
	return r[a] == r[b] && r[a + l] == r[b + l];
}

 * ��������ַ�������r�����У���n������r����Ԫ�ص����ֵС��m��Ϊ�˺����������㣬Լ����r[n-1]�����е�r[i]������0,r[n-1]=0
 * �����㷨�����󣬽������sa�����У���sa[0]��sa[n-1]

void da(int *r, int *sa, int n, int m) {
	int wa[maxn], wb[maxn], wv[maxn], ws[maxn];
	int i, j, p, *x = wa, *y = wb, *t;
	for (i = 0; i < m; i++)	//ws�����ʼ��Ϊ0
		ws[i] = 0;
	for (i = 0; i < n; i++)//r���鸴��һ�ݸ�wa���飬ws[r[i]]�Լ�1���൱��ͳ��r�����е�Ԫ�ظ�����ws�����±�Ϊr�����е�ֵ��ws�����ֵΪ��r�����г��ֵĴ���
		ws[x[i] = r[i]]++;
	for (i = 1; i < m; i++)//ws����ӵڶ��ʼÿһ��Ϊ�����ǰһ��֮��
		ws[i] += ws[i - 1];
	for (i = n - 1; i >= 0; i--)//
		sa[--ws[x[i]]] = i;
	for (j = 1, p = 1; p < n; j *= 2, m = p) {
		for (p = 0, i = n - j; i < n; i++)
			y[p++] = i;
		for (i = 0; i < n; i++)
			if (sa[i] >= j)
				y[p++] = sa[i] - j;

		//�Ե�һ�ؼ���(��λ)��������
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
