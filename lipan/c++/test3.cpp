/*
 * test3.cpp
 *
 *  Created on: 2018年4月17日
 *      Author: asus
 */


//1.编写一个程序，它要求用户首先输入其名，然后输入其姓；然后程序使用一个空格将姓和名组合起来，并存储和显示其组合结果。示例：
//Enter your first name: Flip
//Enter your last name: Fleming
//Your name: Fleming Flip
//2.使用循环来计算并存储前 0 到 16 的阶乘，并显示（ PS： 0 和 1 的阶乘都为 1）。



/*

#include <iostream>
#include <string>

using namespace std;

int main() {
	string s1, s2, s3;
	cout << "Enter your first name:";
	cin >> s1;
	cout << "Enter your last name:";
	cin >> s2;
	s3 = s1 + " " + s2;
	cout << "Your name :" << s3 << endl;
}
*/



/*

#include <iostream>

using namespace std;

int main(){
	static unsigned long long n=1;
	for(int i=0;i<=20;i++){
		if(i==0)
			cout<<i<<"! = "<<1<<endl;
		else{
			n=i*n;
			cout<<i<<"! = "<<n<<endl;
		}
	}
}
*/



/*

#include <iostream>

using namespace std;

#define max 50

int main() {
	for (int n = 0; n <= max; n++) {//计算0~max的阶乘
		int a[200], carry=0, digit = 1;//数组a来记录结果的每一个位，carry记录低位向高位的进位，digit表示该数的位数
		a[0] = 1;	//计算阶乘初始化值为1
		for (int i = 2; i <= n; ++i) {	//开始计算阶乘，用数组来存储结果的每一位
			for (int j = 1; j <= digit; ++j) {
				int temp = a[j - 1] * i + carry;	//该位与i相乘再加上低位的进位
				a[j - 1] = temp % 10;	//写入该位的值
				carry = temp / 10;	//看是否有进位
			}
			while (carry) {	//看是否还能进位，有进位向下执行
				a[++digit - 1] = carry % 10;	//数组往后走一位，并保存当前位对应的值
				carry /= 10;	//看还能不能进位
			}
		}
		cout << n << "! = ";	//输出
		for (int i = digit; i >= 1; --i) {
			cout << a[i - 1];	//按位来输出十进制数
		}
		cout << endl;
	}
	return 0;
}
*/
