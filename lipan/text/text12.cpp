/*
 * text12.cpp
 *
 *  Created on: 2018Äê6ÔÂ27ÈÕ
 *      Author: asus
 */
/*
#include <iostream>

using namespace std;

template<typename T>
class Array {
public:
	Array(int s);
	virtual ~Array();
	virtual T Entry(int index);
	virtual void Enter(int index, T value);
protected:
	int size;
	T *element;
};

template<typename T> Array<T>::Array(int s) {
	if (s > 1)
		size = s;
	else
		size = 1;
	element = new T[size];
}
template<typename T> Array<T>::~Array() {
	delete[] element;
}
template<typename T> T Array<T>::Entry(int index) {
	return element[index];
}
template<typename T> void Array<T>::Enter(int index, T value) {
	element[index] = value;
}


int main() {
	Array<int> arr(3);
	for (int i = 0; i < 3; i++)
		arr.Enter(i, (int)(i*9));
	cout << "Integer Array:\n";
	for (int i = 0; i < 3; i++)
		cout << arr.Entry(i) << '\t';

	Array<double> arr1(3);
	for (int i = 0; i < 3; i++)
		arr1.Enter(i,i*9.3);
	cout << "\ndouble Array:\n";
	for (int i = 0; i < 3; i++)
		cout << arr1.Entry(i) << '\t';
}
*/
