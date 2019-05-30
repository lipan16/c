/*
 * C++-1.cpp
 *
 *  Created on: 2018年4月8日
 *      Author: asus
 */


/*
#include<iostream>

using namespace std;

#define max 4

void Queen(int row, int col, int (*chess)[max]);
bool CanPlace(int, int col, int (*chess)[max]);

int g_count = 0;

int main() {

	int chess[max][max] = { 0 };
	Queen(0, 0, chess);
	cout << g_count << endl;
	return 0;
}

void Queen(int row, int col, int (*chess)[max]) {

	int chess2[max][max];
	for (int i = 0; i < max; i++) {
		for (int j = 0; j < max; j++) {
			chess2[i][j] = chess[i][j];
		}
	}

	if (row == max) {
		for (int i = 0; i < max; i++) {
			for (int j = 0; j < max; j++) {
				cout << chess2[i][j] << ' ';
			}
			cout << endl;
		}
		cout << endl;
		g_count++;
	} else {
		for (int j = 0; j < max; j++) {
			if (CanPlace(row, j, chess2)) {
				chess2[row][j] = 1;
				Queen(row + 1, j, chess2);
				chess2[row][j] = 0;
			}
		}
	}
}

bool CanPlace(int row, int col, int (*chess)[max]) {

	for (int i = 0; i < max; i++) {
		if (chess[i][col] == 1) {
			return false;
		}
		if (chess[row][i] == 1) {
			return false;
		}
	}

	for (int i = 0; i < max; i++) {
		if (row - i < 0 || col - i < 0) {
			break;
		}
		if (chess[row - i][col - i] == 1) {
			return false;
		}
	}

	for (int i = 0; i < max; i++) {
		if (row - i < 0 || col + i > max - 1) {
			break;
		}
		if (chess[row - i][col + i] == 1) {
			return false;
		}
	}

	for (int i = 0; i < max; i++) {
		if (row + i > max - 1 || col - i < 0) {
			break;
		}
		if (chess[row + i][col - i] == 1) {
			return false;
		}
	}

	for (int i = 0; i < max; i++) {
		if (row + i > max - 1 || col + i > max - 1) {
			break;
		}
		if (chess[row + i][col + i] == 1) {
			return false;
		}
	}
	return true;
}*/






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
}*/

