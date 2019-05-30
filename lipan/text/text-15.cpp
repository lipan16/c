/*
 * text-15.cpp
 *
 *  Created on: 2018年7月2日
 *      Author: asus
 */

/*
 * 要求实现函数：
char* stringZip(const char *pInputStr, long inputLen );
功能说明：
输入一串小写字母(a~z) 组成的字符串 。 将连续出现的重复字母进行压缩， 并输出压缩后的字符串 。
压缩规则：
- 仅压缩连续重复出现的字符。 比如字符串 "abcbc"由于无连续重复字符， 压缩后
的字符串还是"abcbc"。
- 压缩字段的格式为"字符重复的次数+字符"。 例如： 字符串 "xxxyyyyyyz"压缩后就成为"3x6yz"。
函数参数说明：
 pInputStr：  输入字符串 ；
 inputLen： 输入字符串的长度；
测试：
输入： “cccddecc” 输出： “3c2de2c”
输入： “adef” 输出： “adef”
输入： “pppppppp” 输出： “8p”
 */

/*
#include <iostream>
#include <cstring>
using namespace std;

char * stringzip(const char *pInputstr,long inputlen);

int main(){
	char *p[3];
	p[0]=stringzip("cccddecc",8);
	p[1]=stringzip("adef",4);
	p[2]=stringzip("pppppppp",8);
	for(int i=0;i<3;i++)
		cout<<*p<<endl;
}
char * stringzip(const char *pInputstr,long inputlen){
	char ch=pInputstr[0];
	char * des = &ch;
	for (int i = 1; i < inputlen; i++) {
		int count = 1;//记录重复次数
		for (int j = i; j < inputlen; j++) {
			if (ch == pInputstr[j])
				count++;
			else {
				count = 1;
				ch = pInputstr[i];
				strcat(des, &ch);
				break;
			}
			if (count != 1) {
				strcat(des, (char *) count);
				strcat(des, &ch);
			}
		}
	}
	return des;
}
*/
