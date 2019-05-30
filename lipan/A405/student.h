/*
 * student.h
 *
 *  Created on: 2018年5月3日
 *      Author: asus
 */

#ifndef A405_STUDENT_H_
#define A405_STUDENT_H_

struct information{
	string num;//学号
	string name;//姓名
	string sex;//性别
	string college;
	string grade;//年级
	string mclass;//班级
	string major;//专业
};

struct birthday{
	int year,month,day;
};

class student{
public:
	student();
	student(information sinfo,birthday sdate);

	void SetInfo(information sinfo,birthday sdate);
	void Show();
private:
	struct information info;
	struct birthday date;
};



#endif /* A405_STUDENT_H_ */
