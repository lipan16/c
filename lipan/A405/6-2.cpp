/*
 * 6-2.cpp
 *
 *  Created on: 2018年6月28日
 *      Author: asus
 */
/*设计两个基类：教师类（Teacher）、干部类（Cadre），采用多重继承派生出新类：
Teacher_Cadre
1、两个基类都包含：姓名、年龄、性别、地址、电话等；
在 Teacher 类中包含：title（），在Cadre 类中包含：post（职务），在Teacher_Cadre
中包含：wages（工资）；
2、两个基类都包含：display()函数，分别输出本类中的成员信息；
3、在两个基类中的姓名、年龄、性别、地址、电话等数据成员使用相同名字，在派生
类中引用这些数据成员时，采用指定作用域的方式；
4、在派生类Teacher_Cadre 的成员函数Show（）中调用Teacher 类中的display（）函
数，输出姓名、年龄、性别、地址、电话；
5、使用对象数组保存输入的对象；
[实验提示]
[测试数据]
1、姓名：zhang 年龄：20 性别：male 地址：Build 305-503 电话：6081202
职称：tutor（助教） 职务：普通职工
2、姓名：chen 年龄：38 性别：male 地址：Build 3A-302 电话：6088132
职称：associate professor（副教授） 职务：副院长
3、姓名：fan 年龄：30 性别：female 地址：Build 2A-202 电话：6088099
职称：lectuer（讲师） 职务：教研室主任
[思考与扩展]
 *
 */

/*
#include <iostream>
using namespace std;

class Teacher{
	string name; //姓名
	string sex; //性别
	int age; //年龄
	string address;//地址
	string phone;//电话
	string title;//职称
public:
	Teacher();
	void display();
};
Teacher::Teacher(){
	name
}

class Cadre{
protected:
	string name; //姓名
	string sex; //性别
	int age; //年龄
	string address;//地址
	string phone;//电话
	string post;//职务
public:

};
class Employee {
protected:
public:
	Employee();
	Employee(int i, string na, string s, int a, float sa);
	virtual ~Employee();
	virtual void input();
	virtual void display();
	virtual void storelog()=0;
};

*/
