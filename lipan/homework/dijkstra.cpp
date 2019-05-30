/*
 * dijkstra.cpp
 *
 *  Created on: 2018��11��18��
 *      Author: asus
 */

#include <iostream>
using namespace std;
/*
const int maxnum = 100;
const int maxint = 999999;

void Dijkstra(int v, int n, int *dist, int *prev, int c[maxnum][maxnum]) {
	bool s[maxnum];    // �ж��Ƿ��Ѵ���õ㵽S������
	int temp[n] = { 0 };    //��¼ÿһ����������ʼ�ڵ� ������ڵ�ľ���

	// ȷ����ʼ�ڵ㲢������ز���
	for (int i = 1; i <= n; ++i) {
		dist[i] = c[v][i];     // ���ڽӾ��������ݴ���dist[]��
		temp[i] = dist[i];
		s[i] = 0;     // ��ʼ���е㶼δ����S��
		if (dist[i] == maxint || dist[i] == 0)
			prev[i] = 0;     // �õ���ʱû�ҵ�ǰ�����
		else
			prev[i] = v;     // �õ��ǰ�����Ϊ��ʼ��v
	}
	dist[v] = 0;
	s[v] = 1;

	// ���ν�δ����S���ϵĽ���У�ȡdist[]��Сֵ�Ľ�㣬������S��
	// һ��S����������V�ж��㣬dist�ͼ�¼�˴�Դ�㵽������������֮������·������
	for (int i = 2; i <= n; ++i) {
		int tmp = maxint;
		int u = v;

		// �ҳ���ǰδʹ�õĵ�j��dist[j]��Сֵ
		for (int j = 1; j <= n; ++j)
			if ((!s[j]) && dist[j] < tmp) {
				u = j;              // u���浱ǰ�ڽӵ��о�����С�ĵ�ĺ���
				tmp = dist[j];
			}
		s[u] = 1;    // ��ʾu���Ѵ���S������
		temp[u] = 0;

		// ����dist���ø�С��ֵ����ԭ�ȵ�ֵ
		for (int j = 1; j <= n; ++j) {
			if ((!s[j]) && c[u][j] < maxint) {
				int newdist = dist[u] + c[u][j];
				if (newdist < dist[j]) {
					dist[j] = newdist;
					temp[j] = dist[j];
					prev[j] = u;
				}
			}
		}
		temp[0]++;
		for (int j = 0; j <= n; j++) {
			if (j == 0)
				cout << "��" << temp[j] << "��:\t";
			else if (j != v)
				cout << temp[j] << "\t";
		}
		cout << endl;
	}
}

// ��¼���������·����·�ߣ������Ľ�㣩
void searchPath(int v, int u, int *prev) {
	int que[maxnum];
	int tot = 1;
	que[tot] = u;
	tot++;
	int tmp = prev[u];
	while (tmp != v) {
		que[tot] = tmp;
		tot++;
		tmp = prev[tmp];
	}
	que[tot] = v;
	for (int i = tot; i >= 1; --i)
		if (i != 1)
			cout << que[i] << " -> ";
		else
			cout << que[i] << endl;
}

int main() {
	// �����鶼���±�1��ʼ
	int dist[maxnum];     // ��ʾ��ǰ�㵽Դ������·������
	int prev[maxnum];     // ��¼��ǰ���ǰһ�����
	int c[maxnum][maxnum];   // ��¼ͼ�������·������
	int n, line, s;             // ͼ�Ľ������·��������ʼ�ڵ�s

	cout << "��������:";
	cin >> n;
	cout << "����·����:";
	cin >> line;
	cout << "������ʼ�ڵ�:";
	cin >> s;
	int p, q, len;          // ����p, q���㼰��·������
//	n = 6;
//	line = 7;
//	s = 2;
			// ��ʼ��c[][]Ϊmaxint ÿ���ڵ�֮��ľ���
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			if (i == j)
				c[i][j] = 0;
			else
				c[i][j] = maxint;
		}
	cout << "���������ڵ㼰��·������:" << endl;
	for (int i = 1; i <= line; ++i) {
		cin >> p >> q >> len;
		if (len < c[p][q])       // ���ر�
				{
			c[p][q] = len;      // pָ��q
			c[q][p] = len;      // qָ��p��������ʾ����ͼ
		}
	}

//	c[1][2] = 1;
//	c[2][1] = 1;
//	c[1][3] = 3;
//	c[3][1] = 3;
//	c[2][3] = 1;
//	c[3][2] = 1;
//	c[2][4] = 3;
//	c[4][2] = 3;
//	c[3][4] = 1;
//	c[4][3] = 1;
//	c[1][6] = 7;
//	c[6][1] = 7;
//	c[4][5] = 4;
//	c[5][4] = 4;

	for (int i = 1; i <= n; ++i)
		dist[i] = maxint;
	cout << "��ʼ�ڵ�Ϊ:" << s << " ������ڵ��distΪ:" << endl;

	for (int i = 1; i <= n; i++) {
		if (i != s)
			cout << "\tdist(" << i << ")";
	}
	cout << endl << "��0��:\t";
	for (int j = 1; j <= n; ++j) {
		if (j != s)
			cout << c[s][j] << "\t";
	}
	cout << endl;

	Dijkstra(s, n, dist, prev, c);
	// ���·������
	cout << s << "--->" << n << "�����·������: " << dist[n] << endl;

	//����ʼ�ڵ㵽Ŀ�Ľڵ�����·����
	cout << s << "--->" << n << "�����·��: ";
	searchPath(s, n, prev);
	//��ͣ
	cout << "�����������...";
	cin.clear();      //��ջ�����
	cin.sync();
	cin.get();
}
*/
