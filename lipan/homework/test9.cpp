/*
 * test9.cpp
 *
 *  Created on: 2018年6月10日
 *      Author: asus
 */

/*
#include <iostream>

using namespace std;

class Pet {
protected:
	string color;
	double weight;
	int age;
public:
	Pet(string c = "", double w = 0, int a = 0) :
			color(c), weight(w), age(a) {
	}
	string GetColor() const {
		return color;
	}
	virtual void speak() const= 0;
};

class Cat: public Pet {
public:
	Cat(string c, double w, int a) :
			Pet(c, w, a) {
	}
	void speak()  const{
		cout << GetColor() << "猫说：喵喵~" << endl;
	}
};

class Dog: public Pet {
public:
	Dog(string c, double w, int a) :
			Pet(c, w, a) {
	}
	void speak() const {
		cout << GetColor() << "狗说：汪汪~" << endl;
	}
};

int main() {
	Pet *p;
	Dog d("黄", 5.5, 1);
	Cat c("花", 1, 1);
	p = &d;
	p->speak();
	p = &c;
	p->speak();
	return 0;
}
*/


/*

#include<iostream>
#include<vector>
#include<cctype>
#include<cstdlib>
#include<string>
#include<iomanip>
using namespace std;
//毛色
const string Color[] = { "Black","White","Yellow","Gray","Colorful",""};//以长度为0的字符串表示达到数组结尾
//将字符串的第一个字符转成大写，其余转成小写(同毛色数组中的格式相同)
//这样输入时就不用区分大小写了
string regulation(string str) {
	str[0] = toupper(str[0]);
	for (int i = 1; i < str.length(); i++)
		str[i] = tolower(str[i]);
	return str;
}
//基类：宠物类
class Pet {
protected:
	double age, weight;
	string name, color;
	char sex;
public:
	Pet();
	Pet(string name, string color, char sex='M',double age = 1, double weight = 1);
	void setName(string s) { name = s; }
	void setColor(string);
	void setSex(char);
	void setAge(double);
	void setWeight(double);
	virtual void printInfo()const{}//打印宠物信息
	virtual void speak()const{}    //让宠物说话
};
Pet::Pet() {
	name = "NoName";
	color = Color[0];
	sex = 'M';
	age = 1;
	weight = 1;
}
Pet::Pet(string name, string color,char sex, double age, double weight) {
	this->name = name;
	int i;
	color = regulation(color);
	for (i = 0; Color[i].length() && color != Color[i]; i++);
	this->color = Color[i].length() ? color : Color[0];
	this->sex = (sex == 'F'|| sex == 'f') ? 'F' : 'M';//性别输入不区分大小写
	this->age = age > 0 ? age : 1;
	this->weight = weight > 0 ? weight : 1;
}
void Pet::setColor(string s) {
	s = regulation(s);
	int i;
	for (i = 0; Color[i].length() && s != Color[i]; i++);
	color= Color[i].length()?s: Color[0];
}
void Pet::setSex(char s) {
	sex = (s == 'F'|| sex == 'f') ? 'F' : 'M';
}
void Pet::setAge(double a) {
	age = a > 0 ? a : 1;
}
void Pet::setWeight(double w) {
	weight = w > 0 ? w : 1;
}
//狗类
class Dog :public Pet {
public:
	Dog():Pet(){}
	Dog(string name, string color, char sex='M',double age = 1, double weight = 1):
		Pet(name,color,sex,age,weight){}
	void printInfo()const;
	void speak()const;
};
void Dog::printInfo() const{
	cout << fixed << setprecision(1);
	cout << "The infomation of this dog:\n";
	cout << "Sex:\t" << sex << endl;
	cout << "Name:\t" << name << endl;
	cout << "Color:\t" << color << endl;
	cout << "Age:\t" << age << endl;
	cout << "Weight:\t" << weight << endl;
}
void Dog::speak() const{
	cout << color<<" dog says :Woof!" << endl;
}
//猫类
class Cat :public Pet {
public:
	Cat() :Pet() {}
	Cat(string name, string color, char sex = 'M', double age = 1, double weight = 1) :
		Pet(name, color, sex, age, weight) {}
	void printInfo()const;
	void speak()const;
};
void Cat::printInfo() const {
	cout << fixed << setprecision(1);
	cout << "The infomation of this cat:\n";
	cout << "Name:\t" << name << endl;
	cout << "Sex:\t" << sex << endl;
	cout << "Color:\t" << color << endl;
	cout << "Age:\t" << age << endl;
	cout << "Weight:\t" << weight << endl;
}
void Cat::speak() const {
	cout << color << " cat says :Meow!" << endl;
}
int main() {
	Pet *p;//用基类指针指向猫和狗类的对象
	vector<Dog> dog; vector<Cat> cat;
	char sex;
	string name, color;
	double age, weight;
	int choice;
	do{
		cout << "(1)Creat a dog (2)Creat a cat (3)View dogs (4)View cats (0)Quit\nPlease input your choice :";
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "Please input the name of your dog:";
			cin >> name;
			cout << "color ( black|white|yellow|gray|colorful):";
			cin >> color;
			cout << "sex(M|F):";
			cin >> sex;
			cout << "age and weight:";
			cin >> age >> weight;
			dog.push_back(Dog(name, color, sex, age, weight));
			p = &dog.back();
			p->printInfo();
			p->speak();
			cout << endl << endl << endl;
			break;
		case 2:
			cout << "Please input the name of your cat:";
			cin >> name;
			cout << "color ( black|white|yellow|gray|colorful):";
			cin >> color;
			cout << "sex(M|F):";
			cin >> sex;
			cout << "age and weight:";
			cin >> age >> weight;
			cat.push_back(Cat(name, color, sex, age, weight));
			p = &cat.back();
			p->printInfo();
			p->speak();
			cout << endl << endl << endl;
			break;
		case 3:
			if (dog.size() == 0) {
				cout << "You don't have any dogs!\n\n\n";
				break;
			}
			system("cls");
			cout << "You have " << dog.size() << " dog(s)!" << endl;
			for (vector<Dog>::iterator it = dog.begin(); it != dog.end(); it++)
				it->printInfo();
			cout << endl << endl << endl;
			break;
		case 4:
			if (cat.size() == 0) {
				cout << "You don't have any cats!\n\n\n";
				break;
			}
			system("cls");
			cout << "You have " << cat.size() << " cat(s)!" << endl;
			for (vector<Cat>::iterator it = cat.begin(); it != cat.end(); it++)
				it->printInfo();
			cout << endl << endl << endl;
			break;
		default:
			break;
		}
	} while (choice);
	return 0;
}
*/
