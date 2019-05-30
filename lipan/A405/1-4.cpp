/*
 * 1-4.cpp
 *
 *  Created on: 2018年6月22日
 *      Author: asus
 */
/*
#include <iostream>
using namespace std;

int main() {
	double time, wage_per_hour, wage;
	int flag;
	cout << "Please input employee's work time and wage_per_hour:";
	cin >> time >> wage_per_hour;
	while (time < 0 || time > 168) {
		cout << "输入时间非法，请重新输入:";
		cin >> time;
	}
	if (time < 40)
		flag = 0;
	else if (time <= 60)
		flag = 1;
	else if (time > 60)
		flag = 2;
	switch (flag) {
	case 0:
		wage = time * wage_per_hour;
		break;
	case 1:
		wage = ((time - 40) * 1.5 + 40) * wage_per_hour;
		break;
	case 2:
		wage = ((time - 60) * 3 + (60 - 20) * 1.5 + 40) * wage_per_hour;
		break;
	}
	cout << "The employee's wage :" << wage << endl;
}
*/


