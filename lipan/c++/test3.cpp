/*
 * test3.cpp
 *
 *  Created on: 2018��4��17��
 *      Author: asus
 */


//1.��дһ��������Ҫ���û���������������Ȼ���������գ�Ȼ�����ʹ��һ���ո��պ���������������洢����ʾ����Ͻ����ʾ����
//Enter your first name: Flip
//Enter your last name: Fleming
//Your name: Fleming Flip
//2.ʹ��ѭ�������㲢�洢ǰ 0 �� 16 �Ľ׳ˣ�����ʾ�� PS�� 0 �� 1 �Ľ׳˶�Ϊ 1����



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
	for (int n = 0; n <= max; n++) {//����0~max�Ľ׳�
		int a[200], carry=0, digit = 1;//����a����¼�����ÿһ��λ��carry��¼��λ���λ�Ľ�λ��digit��ʾ������λ��
		a[0] = 1;	//����׳˳�ʼ��ֵΪ1
		for (int i = 2; i <= n; ++i) {	//��ʼ����׳ˣ����������洢�����ÿһλ
			for (int j = 1; j <= digit; ++j) {
				int temp = a[j - 1] * i + carry;	//��λ��i����ټ��ϵ�λ�Ľ�λ
				a[j - 1] = temp % 10;	//д���λ��ֵ
				carry = temp / 10;	//���Ƿ��н�λ
			}
			while (carry) {	//���Ƿ��ܽ�λ���н�λ����ִ��
				a[++digit - 1] = carry % 10;	//����������һλ�������浱ǰλ��Ӧ��ֵ
				carry /= 10;	//�����ܲ��ܽ�λ
			}
		}
		cout << n << "! = ";	//���
		for (int i = digit; i >= 1; --i) {
			cout << a[i - 1];	//��λ�����ʮ������
		}
		cout << endl;
	}
	return 0;
}
*/
