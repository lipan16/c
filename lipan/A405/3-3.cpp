/*
 * 3-3.cpp
 *
 *  Created on: 2018年4月24日
 *      Author: asus
 */

/*
#include <iostream>
using namespace std;

void sorts(double []);
int fin(double a[],double d);
int main()
{
    int r=0;
    double d=24,a[15]={1,3,2,4,19,24,40,67,89,34,25,46,45,68,87};
//    for(int i=0;i<15;i++){
//        cin>>a[i];
//        if(a[i]>100||a[i]<0){
//            cout<<"输入错误"<<endl;
//            i--;
//        }
//    }
    sorts(a);
    for(int i=0;i<15;i++)
        cout<<a[i]<<" ";
    cout<<endl;
    r=fin(a,d);
    if(r==0)
        cout<<"无此成绩"<<endl;
    else
        cout<<"排名为："<<r<<endl;
}

void sorts(double a[]){
	int k=0;
    for(int i=0;i<15;i++){
        k=i;
        for(int j=i+1;j<15;j++){
            if(a[j]<a[k])
                k=j;
        }
        if(k>i){
        	a[i]=a[k]+a[i];
        	a[k]=a[i]-a[k];
        	a[i]=a[i]-a[k];
        }
    }

}

int fin(double a[],double n){
    int l=0,h=14,m=(l+h)/2;
    while(l<=h){
        if(n==a[m])
            return m+1;
        else if(n>a[m])
            l=m+1;
        else
            h=m-1;
        m=(l+h)/2;
    }
    return -1;
}
*/
