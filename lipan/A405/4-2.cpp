/*
 * 4-2.cpp
 *
 *  Created on: 2018年4月24日
 *      Author: asus
 */


/*
#include <iostream>
using namespace std;

struct student{
	int num;//学号
	char name[20];//名字
	char classname[20];//班级
	float score[3];//三门课成绩
	float aver_score;//平均成绩
};


void average(student &stu);
int max(student stu[]);

int main(){
	student stu[5];
	cout<<"请输入num,name,class,score1,score2,score3"<<endl;
	for (int i = 0; i < 5; i++) {
		cin>>stu[i].num>>stu[i].name>>stu[i].classname>>stu[i].score[0]>>stu[i].score[1]>>stu[i].score[2];
	}
	for(int i=0;i<5;i++){
		average(stu[i]);
		cout<<"student"<<i<<"'s average score:"<<stu[i].aver_score<<endl;
	}
	cout<<"平均分最高的学生为："<<max(stu)<<endl;
}


void average(student &stu){
	stu.aver_score=0;
	for(int i=0;i<3;i++){
		stu.aver_score+=stu.score[i];
	}
	stu.aver_score/=3;
}

int max(student stu[]){
	int k=0;
	for(int i=1;i<5;i++){
		if(stu[k].aver_score<stu[i].aver_score)
			k=i;
	}
	return k;
}*/
