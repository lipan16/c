/*
 * text8.cpp
 *
 *  Created on: 2018Äê6ÔÂ7ÈÕ
 *      Author: asus
 */

/*
#include <iostream>

using namespace std;

class A{
public:
	A(){
		cout<<"call A::A()"<<endl;
	}
	~A(){
		cout<<"A::~A() is called"<<endl;
	}
	int a;
};
class B:public A{
public:
	B(){
		cout<<"call B::B()"<<endl;
	}
	~B(){
		cout<<"B::~B() is called"<<endl;
	}
	int b;
};
class C:public A{
public:
	C(){
		cout<<"call C::C()"<<endl;
	}
	~C(){
		cout<<"C::~C() is called"<<endl;
	}
	int c;
};

class D:public B,public C{
public:
	D(){
		cout<<"call D::D()"<<endl;
	}
	~D(){
		cout<<"D::~D() is called"<<endl;
	}
	int d;
};

int main(){
	D dd;
	dd.B::b=5;
	dd.C::c=5;
	dd.b=25;
	dd.c=100;
	dd.d=130;
	cout<<"dd.B::b="<<dd.B::b<<"\ndd.C::b="<<dd.B::b<<endl;
	cout<<"dd.b="<<dd.b<<"\ndd.c="<<dd.c<<"\ndd.d="<<dd.d<<endl;
}
*/
