/*
 * students.cpp
 *
 *  Created on: 2018��5��4��
 *      Author: asus
 */

#include <iostream>

using namespace std;

#include "stu.h"

students::students(){
	name="����";
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
	cout << "����:" << name << " " << " ѧ��:" << num << " �Ա�:" << sex << " �绰:"
			<< phone << endl;
}


