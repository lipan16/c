/*
 * dijkstra.cpp
 *
 *  Created on: 2018年11月18日
 *      Author: asus
 */

#include <iostream>
using namespace std;
/*
const int maxnum = 100;
const int maxint = 999999;

void Dijkstra(int v, int n, int *dist, int *prev, int c[maxnum][maxnum]) {
	bool s[maxnum];    // 判断是否已存入该点到S集合中
	int temp[n] = { 0 };    //记录每一步过程中起始节点 到其余节点的距离

	// 确认起始节点并设置相关参数
	for (int i = 1; i <= n; ++i) {
		dist[i] = c[v][i];     // 将邻接矩阵中数据传入dist[]中
		temp[i] = dist[i];
		s[i] = 0;     // 初始所有点都未纳入S中
		if (dist[i] == maxint || dist[i] == 0)
			prev[i] = 0;     // 该点暂时没找到前驱结点
		else
			prev[i] = v;     // 该点的前驱结点为起始点v
	}
	dist[v] = 0;
	s[v] = 1;

	// 依次将未放入S集合的结点中，取dist[]最小值的结点，放入结合S中
	// 一旦S包含了所有V中顶点，dist就记录了从源点到所有其他顶点之间的最短路径长度
	for (int i = 2; i <= n; ++i) {
		int tmp = maxint;
		int u = v;

		// 找出当前未使用的点j的dist[j]最小值
		for (int j = 1; j <= n; ++j)
			if ((!s[j]) && dist[j] < tmp) {
				u = j;              // u保存当前邻接点中距离最小的点的号码
				tmp = dist[j];
			}
		s[u] = 1;    // 表示u点已存入S集合中
		temp[u] = 0;

		// 更新dist，用更小的值代替原先的值
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
				cout << "第" << temp[j] << "步:\t";
			else if (j != v)
				cout << temp[j] << "\t";
		}
		cout << endl;
	}
}

// 记录下这条最短路径的路线（经过的结点）
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
	// 各数组都从下标1开始
	int dist[maxnum];     // 表示当前点到源点的最短路径长度
	int prev[maxnum];     // 记录当前点的前一个结点
	int c[maxnum][maxnum];   // 记录图的两点间路径长度
	int n, line, s;             // 图的结点数、路径数、起始节点s

	cout << "输入结点数:";
	cin >> n;
	cout << "输入路径数:";
	cin >> line;
	cout << "输入起始节点:";
	cin >> s;
	int p, q, len;          // 输入p, q两点及其路径长度
//	n = 6;
//	line = 7;
//	s = 2;
			// 初始化c[][]为maxint 每个节点之间的距离
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			if (i == j)
				c[i][j] = 0;
			else
				c[i][j] = maxint;
		}
	cout << "输入两个节点及其路径长度:" << endl;
	for (int i = 1; i <= line; ++i) {
		cin >> p >> q >> len;
		if (len < c[p][q])       // 有重边
				{
			c[p][q] = len;      // p指向q
			c[q][p] = len;      // q指向p，这样表示无向图
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
	cout << "初始节点为:" << s << " 到其余节点的dist为:" << endl;

	for (int i = 1; i <= n; i++) {
		if (i != s)
			cout << "\tdist(" << i << ")";
	}
	cout << endl << "第0步:\t";
	for (int j = 1; j <= n; ++j) {
		if (j != s)
			cout << c[s][j] << "\t";
	}
	cout << endl;

	Dijkstra(s, n, dist, prev, c);
	// 最短路径长度
	cout << s << "--->" << n << "的最短路径长度: " << dist[n] << endl;

	//从起始节点到目的节点的最短路径：
	cout << s << "--->" << n << "的最短路径: ";
	searchPath(s, n, prev);
	//暂停
	cout << "按任意键继续...";
	cin.clear();      //清空缓冲区
	cin.sync();
	cin.get();
}
*/
