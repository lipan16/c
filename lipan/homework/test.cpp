/*

 * test.cpp
 *
 *  Created on: 2018年4月4日
 *      Author: asus
 *
 */

/*
#include <iostream>
#include<cstdlib>

using namespace std;

double power(double,int);
bool symm(unsigned);

int main() {
	int b = 100;
	cout << hex << b << endl;
	cout << "hello" << endl;
	cout << "welcome to c++" << endl;
	cout << sizeof(float)<<endl;
	int n,r;
	cin>>n;
	do{
		r=n%10;
		cout<<r;
		n/=10;
	}while(n!=0);

//	cout<<power(5.0,2)<<endl;
	for(unsigned m=11;m<1000;m++)
		if(symm(m)&&symm(m*m)&&symm(m*m*m)){
			cout<<"m="<<m<<endl;
			cout<<"m*m="<<m*m<<endl;
			cout<<"m*m*m="<<m*m*m<<endl;
			cout <<endl;
		}
	int x=5,y=10;
	swap(x,y);
	cout <<x<<" "<<y<<endl;
	return 0;
}

double power(double x,int n){
	double d=1.0;
	while(n--)
		d*=x;
	return d;
}

bool symm(unsigned n){
	unsigned i=n,m=0;
	while(i>0){
		m=m*10+i%10;
		i/=10;
	}
	return m==n;
}

void swap(int &a,int &b){
	int t=a;
	a=b;
	b=t;
}*/


/*
#include<iostream>
using namespace std;

typedef unsigned long long ULL;

ULL f[20][172];
ULL ten[20];

void init();
int sumof(ULL);
ULL count(ULL,int);
ULL find(ULL,int,ULL);
ULL calc(ULL,ULL);

int main() {
	init();
	ULL n, k;
	for(int i=0;i<20;i++){
		for(int j=0;j<172;j++)
			cout<<f[i][j]<<" ";
		cout <<endl;
	}
	cout<<count(10,2);
	while (cin >> n >> k) {
		if (!n)
			break;
		cout << find(n, sumof(k), k) << ' ' << calc(n, k) << endl;
	}
	return 0;
}

void init() {
	f[0][0] = 1;
	for (int i = 1; i < 20; ++i)
		for (int j = 0; j <= i * 9; ++j)
			for (int k = 0; k <= 9; ++k)
				if (j >= k)
					f[i][j] += f[i - 1][j - k];	//f[i][j]=第i-1行前j+1个数的和f[i-1][0]+...+f[i-1][j]
	ten[0] = 1;
	for (int i = 1; i < 20; ++i)
		ten[i] = ten[i - 1] * 10;	//1^0,10,100,10^19
}

int sumof(ULL n) {	//对十取余再求和。>>19,<<10
	int sum = 0;
	while (n > 0) {
		sum += n % 10;
		n /= 10;
	}
	return sum;
}

ULL count(ULL n, int sum) {
	ULL ans = 0;
	for (int i = 19; i >= 1; --i) {
		sum -= n / ten[i];
		if (sum < 0)
			break;
		n %= ten[i];
		for (int j = 0; j < n / ten[i - 1]; ++j)
			if (sum - j >= 0)
				ans += f[i - 1][sum - j];
	}
	if (sum == n)
		++ans;
	return ans;
}

ULL find(ULL n, int sum, ULL k) {
	int i;
	ULL k2 = k, ans = 0;
	for (i = 1; i < sum; ++i)
		ans += count(n, i);
	for (i = 0; ten[i + 1] <= n; ++i)
		;
	for (; k < ten[i]; k *= 10)
		;
	for (; k > 0; k /= 10, --i)
		ans += count(min(n, k - (k > k2)), sum) - f[i][sum];
	return ans;
}

ULL calc(ULL n, ULL k) {//统计[0..x]内二进制表示含k个1的个数
	int sum, i;
	ULL ans, k2 = k, tot;//tot记录当前路径上已有的1的数量，ans表示答案
	for (sum = 1;; ++sum) {
		tot = count(n, sum);
		if (k <= tot)
			break;
		k -= tot;
	}
	for (i = 0; ten[i + 1] <= n; ++i)
		;
	for (ans = 1; ans <= 9; ++ans) {
		int j;
		tot = 0;
		for (j = 0; j < i; ++j)
			tot += f[j][sum - ans];
		if (ans < n / ten[i])
			tot += f[i][sum - ans];
		else if (ans == n / ten[i])
			tot += count(n, sum) - count(ans * ten[i] - 1, sum);
		if (k <= tot)
			break;
		k -= tot;
	}
	while (find(n, sumof(ans), ans) != k2) {
		ans *= 10;
		for (i = 0; i <= 9; ++i)
			if (find(n, sum, ans + i) >= k2)
				break;
		ans += i;
		if (find(n, sumof(ans), ans) == k2)
			break;
		--ans;
	}
	return ans;
}
*/
