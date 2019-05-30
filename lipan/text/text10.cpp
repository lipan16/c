/*
 * text10.cpp
 *
 *  Created on: 2018Äê6ÔÂ11ÈÕ
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
	virtual T& Entry(int index);
	virtual void Enter(int index, T value);
protected:
	int size;
	T * element;
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
template<typename T> T& Array<T>::Entry(int index) {
	return element[index];
}
template<typename T> void Array<T>::Enter(int index, T valute) {
	element[index] = valute;
}

int main() {
	Array<int> As(5);
	for (int i = 0; i < 5; i++)
		As.Enter(i, i);
	for (int i = 0; i < 5; i++)
		cout << As.Entry(i) << "\t";
	cout << endl;

	Array<double> Ass(5);
	for (int i = 0; i < 5; i++)
		Ass.Enter(i, i * 0.3);
	for (int i = 0; i < 5; i++)
		cout << Ass.Entry(i) << "\t";
}
*/
