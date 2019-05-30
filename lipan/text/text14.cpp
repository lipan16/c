/*
 * text14.cpp
 *
 *  Created on: 2018��6��28��
 *      Author: asus
 */

/*
#include <iostream>
#include <stdlib.h>

using namespace std;
class vector {
public:
	vector(int = 1);
	vector(const int *, int);
	vector(const vector&);
	~vector();
	int &operator[](int i) const; //���������[]
	int operator()() const; //���������()
	friend ostream &operator<<(ostream &output, const vector &); //���������<<
	friend istream &operator>>(istream &input, vector &); //���������>>
private:
	int *v;
	int len;
};
vector::vector(int size) {
	if (size <= 0 || size >= 100) {
		cout << "The size of" << size << "is fail!\n";
		exit(0);
	}
	v = new int[size];
	for (int i = 0; i < size; i++)
		v[i] = 0;
	len = size;
}
vector::vector(const int *B, int size) {
	if (size <= 0 || size >= 100) {
		cout << "The size of" << size << "is fail!\n";
		exit(0);
	}
	v = new int[size];
	for (int i = 0; i < size; i++)
		v[i] = B[i];
	len = size;
}
vector::vector(const vector & A) {
	len = A();
	v = new int[len];
	for (int i = 0; i < len; i++)
		v[i] = A[i];
}
vector::~vector() {
	delete[] v;
	len = 0;
}
int & vector::operator [](int i) const {
	if (i >= 0 && i < len)
		return v[i];
	cout << "The subscript " << i << "is outside!\n";
	exit(0);
}
int vector::operator ()() const {
	return len;
}
ostream & operator <<(ostream & output, const vector & A) {
	for (int i = 0; i < A.len; i++)
		output << A.v[i] << "  ";
	return output;
}
istream & operator >>(istream & input, vector & A) {
	for (int i = 0; i < A(); i++)
		input >> A.v[i];
	return input;
}


int main() {
	vector A(3);
	cout << "Iuput three elements of vector A:";
	cin >> A; //�������ص������������>>

	cout << "A's elements:" << A << endl; //�������������<<
	cout << "A's length:" << A() << endl; //�������������()�����س���
	cout << "A[1]=" << A[1] << endl; //�������������[]

}
*/
