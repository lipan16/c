/*
 * queen.cpp
 *
 *  Created on: 201max年4月11日
 *      Author: asus
 */

/*

 #include <iostream>

 using namespace std;

 #define  max 4

 int chessBoard[max][max];

 bool check(int , int );
 bool setqueen(int );
 void printchessBoard();

 bool check(int x, int y) {//传入新皇后的落点，通过纵向和斜向是否存在其他皇后来判断是否合规
 for (int i = 0; i < y; i++) {
 if (chessBoard[x][i] == 1)//检查纵向
 return false;
 if (x - i - 1 >= 0 && chessBoard[x - i - 1][y - i - 1] == 1)//检查左侧斜向
 return false;
 if (x + i + 1 < max && chessBoard[x + i + 1][y - i - 1] == 1)//检查右侧斜向
 return false;
 }
 return true;
 }

 bool setqueen(int y) {//递归回溯
 if (y == max)//超过最大行数说明已经找到答案
 return true;
 //遍历当前行，逐一格子验证
 for (int i = 0; i < max; i++) {
 for (int x = 0; x < max; x++)//为当前行清零，避免回溯时候出现干扰数据
 chessBoard[x][y] = 0;
 //检查是否符合规则，如果符合，更改元素值并进一步递归
 if (check(i, y)) {
 chessBoard[i][y] = 1;
 //如果递归返回true，说明下层已找到解决，无需继续循环
 if (setqueen(y + 1))
 return true;
 }
 }
 return false;
 }

 void printchessBoard() {//输出棋盘当前值
 for (int i = 0; i < max; i++) {
 for (int j = 0; j < max; j++)
 cout << chessBoard[i][j] << " ";
 cout << endl;
 }
 }

 int main() {
 setqueen(0);
 printchessBoard();
 }
 */

/*
#include<iostream>

using namespace std;

#define max 8

void Queen(int row, int col, int (*chess)[max]);
bool CanPlace(int , int col, int (*chess)[max]);

int g_count = 0;

int main() {

	int chess[max][max] = { 0 }; //初始化为全零
	Queen(0, 0, chess); //寻找位置并输出
	cout << "所有可能的总数：" << g_count << endl; //输出所有的可能总数
	return 0;
}

void Queen(int row, int col, int (*chess)[max]) {

	int chess2[max][max];
	//put last scene to temp 2Darray,另存一份当前的皇后位置
	for (int i = 0; i < max; i++) {
		for (int j = 0; j < max; j++) {
			chess2[i][j] = chess[i][j];
		}
	}

	if (row == max) { //show result
		for (int i = 0; i < max; i++) {
			for (int j = 0; j < max; j++) {
				cout << chess2[i][j] << ' ';
			}
			cout << endl;
		}
		cout << endl;
		g_count++; //计数器加一
	} else {
		for (int j = 0; j < max; j++) {
			if (CanPlace(row, j, chess2)) { //按列来测试位置
				chess2[row][j] = 1; //put chess
				Queen(row + 1, j, chess2); //move to next row下一行
				chess2[row][j] = 0; //remove chess to use for next by same chess 2Darray
			}
		}
	}
}

bool CanPlace(int row, int col, int (*chess)[max]) {

	for (int i = 0; i < max; i++) {
		if (chess[i][col] == 1) { //检查列
			return false; //如果该列已经有一个为1(即有一个皇后)了，则该列不能再放另一个了
		}
		if (chess[row][i] == 1) { //检查行
			return false; //如果该行已经有一个为1(即有一个皇后)了，则该列不能再放另一个了
		}
	}

	for (int i = 0; i < max; i++) { //检查左斜上方
		if (row - i < 0 || col - i < 0) {
			break; //不在左斜向
		}
		if (chess[row - i][col - i] == 1) {
			return false; //如果左斜向已经有一个为1(即有一个皇后)了，则该列不能再放另一个了
		}
	}

	for (int i = 0; i < max; i++) { //检查右斜上方
		if (row - i < 0 || col + i > max - 1) {
			break; //不在右斜向
		}
		if (chess[row - i][col + i] == 1) {
			return false; //如果右斜向已经有一个为1(即有一个皇后)了，则该列不能再放另一个了
		}
	}

	for (int i = 0; i < max; i++) { //检查左斜下方
		if (row + i > max - 1 || col - i < 0) {
			break; //不在左斜下方
		}
		if (chess[row + i][col - i] == 1) {
			return false; //如果左斜下方已经有一个为1(即有一个皇后)了，则该列不能再放另一个了
		}
	}

	for (int i = 0; i < max; i++) { //检查右斜下方
		if (row + i > max - 1 || col + i > max - 1) {
			break; //不在右斜下方
		}
		if (chess[row + i][col + i] == 1) {
			return false; //如果右斜下方已经有一个为1(即有一个皇后)了，则该列不能再放另一个了
		}
	}
	return true;
}

*/
