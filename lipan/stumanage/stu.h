/*
 * stu.h
 *
 *  Created on: 2018年5月4日
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
		int m_year;                               //年份
		int m_month;                              //月份
		int m_day[12];                            //一年中每个月的天数
		static long long t_day;                   //计算距离公元元年的天数
public:
		void setyear(int year);                   //输入年份
		bool isleapyear();                        //判断是否是闰年
		void getmdays();                          //获得每月天数
		void showyear(int year);                  //打印日历
		void showmonth(int year,int month);                  //打印日历
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
	//employee(string name,string num="10000",string sex="男",string job="经理",int year=1998,int month=12,int day=17);

	void setinfo(string name,string num,char sex,string phone);
	void display();
};




#endif /* STU_H_ */
