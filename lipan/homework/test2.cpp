/*
 * test2.cpp
 *
 *  Created on: 2018年4月9日
 *      Author: asus
 */

/*作业题⽬⼀：
题⽬描述：计算字符串最后⼀个单词的⻓度，单词以空格隔开。
输⼊描述:⼀⾏字符串，⾮空，⻓度⼩于5000。
输出描述:整数N，最后⼀个单词的⻓度。
示例：
输⼊： hello world
输出： 5

作业题⽬⼆：
题⽬描述:输⼊⼀个int型整数，按照从右向左的阅读顺序，返回⼀个不含重复数字的新的整数。
输⼊描述:输⼊⼀个int型整数
输出描述:按照从右向左的阅读顺序，返回⼀个不含重复数字的新的整数
示例
输⼊：9876673
输出：37689
*/


/*
#include <iostream>
#include <cstdio>

using namespace std;

#define maxn 5000

int main(){
	char str[maxn];
	int n=0,len;//记录字符串长度
	gets(str);//输入字符串
	for(len=0;;len++)//求字符串长度
		if(str[len]=='\0')
			break;
	for(int i=len-1;i>=0;i--){//计算最后一个单词的长度
		if(str[i]!=' ')
			n++;
		else
			break;
	}
	cout<<n<<endl;
}
*/



/*
#include <iostream>

using namespace std;

int main() {
	int i, j, a[10], x; //数组a用来存放不重复的一位数字，一位数最多有10个不重复的数
	cin >> x; //输入整数
	a[0] = x % 10; //a[0]存放最低位
	x /= 10;
	for (i = 1; x > 0 && i < 10; i++) {
		a[i] = x % 10;
		x /= 10;
		for (j = 0; j < i; j++) //检查该位数字是否已重复，已重复的话下标i不往前走，--与++相抵消
			if (a[i] == a[j])
				i--;
	}
	if (a[0] == 0) //如果第一位为零则不输出
		j = 1;
	for (; j < i; j++) //按位输出不含重复数字的新整数
		cout << a[j];
	return 0;
}*/

/*
#include <iostream>
using namespace std;
int main(){
	int num[10] = { 0 }, x;
	cout << "Please input a number:";
	cin >> x;
	while (x) {
		if (num[x % 10] == 0) {
			num[x % 10]++;
			cout << x % 10;
		}
		x /= 10;
	}
}
*/




/*
#include <iostream>

using namespace std;

int main(){
	int x , y, z = 0; //y用来存储x的最后一位，用z的二进制位01来表示对应十进制位是否已经出现过
	cin >> x;
	while (x) {
		y = 1 << (x % 10); //1向右移余数个位，3是1的二进制左移移三位，对应于8，将第三个二进制位置为1。相当于将二进制第余数位置1
		if ((z ^ y) > z) { //如果是已经出现过得数字其对应位上是1，再异或一次不肯能比原数大，如果比原数大则说明该位以前为0，即没出现过。所以将该位置1，输出相应的十进制
			z = z ^ y;	//将十进制数对应的二进制第几位置1
			cout << x % 10;
		}
		x /= 10;
	}
}
*/
