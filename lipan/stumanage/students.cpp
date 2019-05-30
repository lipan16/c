/*
 * students.cpp
 *
 *  Created on: 2018年5月4日
 *      Author: asus
 */

#include <iostream>

using namespace std;

#include "stu.h"

students::students(){
	name="李攀";
	num="320160939611";
	sex='M';
	phone="13993176525";
}

students::students(string na,string numb,char s,string pphone){
	name=na;
	num=numb;
	sex=s;
	phone=pphone;
}

void students::setinfo(string na,string numb,char s,string pphone){
	name=na;
	num=numb;
	sex=s;
	phone=pphone;
}

void students::display(){
	cout << "姓名:" << name << " " << " 学号:" << num << " 性别:" << sex << " 电话:"
			<< phone << endl;
}


