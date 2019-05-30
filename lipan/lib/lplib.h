/*
 * lplib.h
 *
 *  Created on: 2018年4月29日
 *      Author: asus
 */

#ifndef LPLIB_H_
#define LPLIB_H_

unsigned long long fun(int); //
int func();
int gcd(int, int); //最大公约数
void recover();
void BubSort(int[], int); //冒泡排序
void SelSort(int[], int); //选择排序
void InsSort(int[], int); //插入排序
void InsWPSort(int[], int); //带哨兵的插入排序
void BInsSort(int[], int); //二分插入
void ShellSort(int[], int); //希尔排序
void HeapSort(int[], int); //堆排序
void RadixSort(int[], int); //基数排序
void QuickSort(int[], int, int); //快速排序

void filecopy();

template<class T>
int length(T& data);

#endif /* LPLIB_H_ */
