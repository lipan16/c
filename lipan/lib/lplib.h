/*
 * lplib.h
 *
 *  Created on: 2018��4��29��
 *      Author: asus
 */

#ifndef LPLIB_H_
#define LPLIB_H_

unsigned long long fun(int); //
int func();
int gcd(int, int); //���Լ��
void recover();
void BubSort(int[], int); //ð������
void SelSort(int[], int); //ѡ������
void InsSort(int[], int); //��������
void InsWPSort(int[], int); //���ڱ��Ĳ�������
void BInsSort(int[], int); //���ֲ���
void ShellSort(int[], int); //ϣ������
void HeapSort(int[], int); //������
void RadixSort(int[], int); //��������
void QuickSort(int[], int, int); //��������

void filecopy();

template<class T>
int length(T& data);

#endif /* LPLIB_H_ */
