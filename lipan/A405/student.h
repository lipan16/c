/*
 * student.h
 *
 *  Created on: 2018��5��3��
 *      Author: asus
 */

#ifndef A405_STUDENT_H_
#define A405_STUDENT_H_

struct information{
	string num;//ѧ��
	string name;//����
	string sex;//�Ա�
	string college;
	string grade;//�꼶
	string mclass;//�༶
	string major;//רҵ
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
