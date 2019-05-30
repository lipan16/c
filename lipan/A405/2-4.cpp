/*
 * 2-4.cpp
 *
 *  Created on: 2018年4月24日
 *      Author: asus
 */

/*
#include <iostream>
using namespace std;

int main(){
    int r1,c1,r2,c2;
    do{
        cout<<"请输入矩阵一的行数和列数：";
        cin>>r1>>c1;
        cout<<"请输入矩阵二的行数和列数：";
        cin>>r2>>c2;
    }while(c1!=r2);
    int a[r1][c1],b[r2][c2],c[r1][c2]={0};
    for(int i=0;i<r1;i++){//初始化矩阵一
        for(int j=0;j<c1;j++)
            cin>>a[i][j];
    }
    for(int i=0;i<r2;i++){//初始化矩阵二
        for(int j=0;j<c2;j++)
            cin>>b[i][j];
    }
    cout<<endl;
    for(int i=0;i<r1;i++){//计算
        for(int j=0;j<c2;j++)
            for(int k=0;k<c1;k++)
            c[i][j]+=a[i][k]*b[k][j];
    }
    for(int i=0;i<r1;i++){//输出计算结果
        for(int j=0;j<c2;j++)
            cout<<c[i][j]<<" ";
        cout<<endl;
    }
}

*/
