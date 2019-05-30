/*
 * gcd.cpp
 *
 *  Created on: 2018Äê4ÔÂ29ÈÕ
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

