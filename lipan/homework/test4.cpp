/*
 * test4.cpp
 *
 *  Created on: 2018��4��27��
 *      Author: asus
 *
 *      1. ��д���� ����һ�� Employee �࣬ ���������ַ����飬 ��ʾ������ �Ա� ���䡣 ��
 *      �캯����ʼ��ÿ����Ա�� display()�����������Ķ������ݴ�ӡ������ ���е����ݳ�Ա
 *      �Ǳ����ģ� �����ǹ����ġ�
 *      2. ��д���� ���һ���࣬ ������� 3 ��˽�����ݣ����� a �۸� 20 Ԫ/�������� b ��
 *      �� 15 Ԫ/�����Լ����������� total�� ���Թ��캯����ʽ����ֵ�� �������ӵ���������
 *      �����Ӧ�������롣
 */


/*
#include <iostream>
#include <cstring>
using namespace std;

class Employee{
public:
	Employee(){
		name="lipan";
		sex='m';
		year=21;
	}
	Employee(string n,string s,int y){
		name=n;
		sex=s;
		while(y<=0){
			cout<<"�������������⣬���������룺";
			cin>>y;
		}
		year=y;
	}
	void setname(string n){
		name=n;
	}
	void setsex(string s){
		sex=s;
	}
	void setyear(int y){
		while(y<=0){
			cout<<"�������������⣬���������룺";
			cin>>y;
		}
		year=y;
	}
	void display(){
		cout<<"name  sex  year"<<endl;
		cout<<name<<"  "<<sex<<"  "<<year;
	}
private:
	string name;
	string sex;
	int year;
};

int main(){
	Employee e;
	e.display();
}
*/





/*
#include <iostream>
using namespace std;

class gas{
public:
	gas(double x,double y){
		while(x<0){
			cout<<"�������Ͳ���Ϊ�������������룺";
				cin>>x;
		}
		a=x;
		while(y<0){
			cout<<"�������Ͳ���Ϊ�������������룺";
				cin>>y;
		}
		b=y;
	}
	double gettotal(double x,double y){
		while(x<0){
			cout<<"�������Ͳ���Ϊ�������������룺";
				cin>>x;
		}
		a=x;
		while(y<0){
			cout<<"�������Ͳ���Ϊ�������������룺";
				cin>>y;
		}
		b=y;
		return total=a*pa+b*pb;
	}

private:
	double a,b;
	double const pa=20,pb=15;
	double total=0;
};
int main(){
	gas g(10,10);
	cout<<g.gettotal(10,10)<<endl;
}
*/
