/*
 * test4.cpp
 *
 *  Created on: 2018年4月27日
 *      Author: asus
 *
 *      1. 编写程序， 创建一个 Employee 类， 该类中有字符数组， 表示姓名， 性别， 年龄。 构
 *      造函数初始化每个成员， display()函数把完整的对象数据打印出来。 其中的数据成员
 *      是保护的， 函数是公共的。
 *      2. 编写程序， 设计一个类， 此类包含 3 个私有数据：汽油 a 价格 20 元/升，汽油 b 价
 *      格 15 元/升，以及当天总收入 total。 请以构造函数方式建立值， 输入所加的汽油量，
 *      输出对应的总收入。
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
			cout<<"年龄输入有问题，请重新输入：";
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
			cout<<"年龄输入有问题，请重新输入：";
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
			cout<<"所加汽油不能为负，请重新输入：";
				cin>>x;
		}
		a=x;
		while(y<0){
			cout<<"所加汽油不能为负，请重新输入：";
				cin>>y;
		}
		b=y;
	}
	double gettotal(double x,double y){
		while(x<0){
			cout<<"所加汽油不能为负，请重新输入：";
				cin>>x;
		}
		a=x;
		while(y<0){
			cout<<"所加汽油不能为负，请重新输入：";
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
