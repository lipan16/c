/*
 * 3-2.cpp
 *
 *  Created on: 2018Äê4ÔÂ24ÈÕ
 *      Author: asus
 */

/*
#include <iostream>
using namespace std;

void average(int a[][5],int s[]);
void aversco(int a[][5],int s[]);

int main(){
	int num[5]={0};
	int sco[5][5]={10,20,30,40,50,10,20,30,40,50,10,20,30,40,50,10,20,30,40,50,10,20,30,40,50};
	int asco[5] = { 0 };
	average(sco,asco);
	aversco(sco,num);
	return 0;
}

void average(int a[5][5],int s[5]){
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++)
			s[i]+=a[i][j];
		s[i]/=5;
		cout<<s[i]<<endl;
	}
}

void aversco(int a[5][5],int s[5]){
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++)
			s[i]+=a[j][i];
		s[i]/=5;
		cout<<s[i]<<endl;
	}
}
*/

/*
void average(int a[][7]);
void aversco(int a[][7]);

int main(){
	int stu_info[5][7]={0,10,20,30,40,50,0,0,10,20,30,40,50,0,0,10,20,30,40,50,0,0,10,20,30,40,50,0,0,10,20,30,40,50,0};
	average(stu_info);
	aversco(stu_info);
	return 0;
}

void average(int a[5][7]){
	for(int i=0;i<5;i++){
		for(int j=1;j<6;j++)
			a[i][6]+=a[i][j];
		a[i][6]/=5;
		cout<<a[i][6]<<endl;
	}
}

void aversco(int a[5][7]){
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++)
			a[i][0]+=a[j][i+1];
		a[i][0]/=5;
		cout<<a[i][0]<<endl;
	}
}
*/
