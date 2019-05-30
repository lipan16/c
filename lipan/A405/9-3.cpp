/*
 * 9-3.cpp
 *
 *  Created on: 2018年6月23日
 *      Author: asus
 */

/*
#include <iostream>
#include <fstream>

using namespace std;
void filecopy(char src[], char des[]);

int main(int argc, char *argv[]) {
	if (argc != 4) {
		cout << "输入格式错误！" << endl;
		return 0;
	}
	filecopy(argv[1], argv[3]);
	filecopy(argv[2], argv[3]);
}

void filecopy(char src[], char des[]) {
	char ch;
	ifstream in(src, ios::in);
	ofstream out(des, ios::app);
	if (!in) {
		cerr << src << " : File could not be open!" << endl;
		return;
	}
	if (!out) {
		cerr << des << " : File could not be open!" << endl;
		return;
	}
	while (in.get(ch))
		out.put(ch);
	in.close();
	out.close();
}
*/
