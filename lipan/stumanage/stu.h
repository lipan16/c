/*
 * stu.h
 *
 *  Created on: 2018��5��4��
 *      Author: asus
 */

#ifndef STU_H_
#define STU_H_

class date{
private:
	int year, month, day;
public:
	void setYear(int year);
	void setMonth(int month);
	void setDay(int day);
	int getYear();
	int getMonth();
	int getDay();
};


class Caldendar{
protected:
		int m_year;                               //���
		int m_month;                              //�·�
		int m_day[12];                            //һ����ÿ���µ�����
		static long long t_day;                   //������빫ԪԪ�������
public:
		void setyear(int year);                   //�������
		bool isleapyear();                        //�ж��Ƿ�������
		void getmdays();                          //���ÿ������
		void showyear(int year);                  //��ӡ����
		void showmonth(int year,int month);                  //��ӡ����
};


class students{
private:
	string name;
	string num;
	char sex;
	string phone;
public:
	students();
	students(string name,string num,char sex,string phone);
	//employee(string name,string num="10000",string sex="��",string job="����",int year=1998,int month=12,int day=17);

	void setinfo(string name,string num,char sex,string phone);
	void display();
};




#endif /* STU_H_ */
