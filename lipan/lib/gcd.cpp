/*
 * gcd.cpp
 *
 *  Created on: 2018��4��29��
 *      Author: asus
 */


int gcd(int a,int b){
	int g;
	if(b==0)
		g=a;
	else
		g=gcd(b,a%b);
	return g;
}

