/*
 * C++-1.cpp
 *
 *  Created on: 2018��4��8��
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

	int chess[max][max] = { 0 }; //��ʼ��Ϊȫ��
	Queen(0, 0, chess); //Ѱ��λ�ò����
	cout << "���п��ܵ�������" << g_count << endl; //������еĿ�������
	return 0;
}

void Queen(int row, int col, int (*chess)[max]) {

	int chess2[max][max];
	//put last scene to temp 2Darray,���һ�ݵ�ǰ�Ļʺ�λ��
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
		g_count++; //��������һ
	} else {
		for (int j = 0; j < max; j++) {
			if (CanPlace(row, j, chess2)) { //����������λ��
				chess2[row][j] = 1; //put chess
				Queen(row + 1, j, chess2); //move to next row��һ��
				chess2[row][j] = 0; //remove chess to use for next by same chess 2Darray
			}
		}
	}
}

bool CanPlace(int row, int col, int (*chess)[max]) {

	for (int i = 0; i < max; i++) {
		if (chess[i][col] == 1) { //�����
			return false; //��������Ѿ���һ��Ϊ1(����һ���ʺ�)�ˣ�����в����ٷ���һ����
		}
		if (chess[row][i] == 1) { //�����
			return false; //��������Ѿ���һ��Ϊ1(����һ���ʺ�)�ˣ�����в����ٷ���һ����
		}
	}

	for (int i = 0; i < max; i++) { //�����б�Ϸ�
		if (row - i < 0 || col - i < 0) {
			break; //������б��
		}
		if (chess[row - i][col - i] == 1) {
			return false; //�����б���Ѿ���һ��Ϊ1(����һ���ʺ�)�ˣ�����в����ٷ���һ����
		}
	}

	for (int i = 0; i < max; i++) { //�����б�Ϸ�
		if (row - i < 0 || col + i > max - 1) {
			break; //������б��
		}
		if (chess[row - i][col + i] == 1) {
			return false; //�����б���Ѿ���һ��Ϊ1(����һ���ʺ�)�ˣ�����в����ٷ���һ����
		}
	}

	for (int i = 0; i < max; i++) { //�����б�·�
		if (row + i > max - 1 || col - i < 0) {
			break; //������б�·�
		}
		if (chess[row + i][col - i] == 1) {
			return false; //�����б�·��Ѿ���һ��Ϊ1(����һ���ʺ�)�ˣ�����в����ٷ���һ����
		}
	}

	for (int i = 0; i < max; i++) { //�����б�·�
		if (row + i > max - 1 || col + i > max - 1) {
			break; //������б�·�
		}
		if (chess[row + i][col + i] == 1) {
			return false; //�����б�·��Ѿ���һ��Ϊ1(����һ���ʺ�)�ˣ�����в����ٷ���һ����
		}
	}
	return true;
}*/

