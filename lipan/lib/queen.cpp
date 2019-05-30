/*
 * queen.cpp
 *
 *  Created on: 201max��4��11��
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

 bool check(int x, int y) {//�����»ʺ����㣬ͨ�������б���Ƿ���������ʺ����ж��Ƿ�Ϲ�
 for (int i = 0; i < y; i++) {
 if (chessBoard[x][i] == 1)//�������
 return false;
 if (x - i - 1 >= 0 && chessBoard[x - i - 1][y - i - 1] == 1)//������б��
 return false;
 if (x + i + 1 < max && chessBoard[x + i + 1][y - i - 1] == 1)//����Ҳ�б��
 return false;
 }
 return true;
 }

 bool setqueen(int y) {//�ݹ����
 if (y == max)//�����������˵���Ѿ��ҵ���
 return true;
 //������ǰ�У���һ������֤
 for (int i = 0; i < max; i++) {
 for (int x = 0; x < max; x++)//Ϊ��ǰ�����㣬�������ʱ����ָ�������
 chessBoard[x][y] = 0;
 //����Ƿ���Ϲ���������ϣ�����Ԫ��ֵ����һ���ݹ�
 if (check(i, y)) {
 chessBoard[i][y] = 1;
 //����ݹ鷵��true��˵���²����ҵ�������������ѭ��
 if (setqueen(y + 1))
 return true;
 }
 }
 return false;
 }

 void printchessBoard() {//������̵�ǰֵ
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
}

*/
