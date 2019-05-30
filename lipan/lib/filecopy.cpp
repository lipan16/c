/*
 * filecopy.cpp
 *
 *  Created on: 2018Äê5ÔÂ15ÈÕ
 *      Author: asus
 */

/*
#include <iostream>
#include <fstream>

using namespace std;

void filecopy() {
	char src[20], des[20], ch;
	cin >> src >> des;
	ifstream in(src, ios::in);
	ofstream out(des, ios::out);
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
	cout << "copy finish!" << endl;
}

*/
