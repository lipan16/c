/*
 * 2-4.cpp
 *
 *  Created on: 2018��4��24��
 *      Author: asus
 */

/*
#include <iostream>
using namespace std;

int main(){
    int r1,c1,r2,c2;
    do{
        cout<<"���������һ��������������";
        cin>>r1>>c1;
        cout<<"������������������������";
        cin>>r2>>c2;
    }while(c1!=r2);
    int a[r1][c1],b[r2][c2],c[r1][c2]={0};
    for(int i=0;i<r1;i++){//��ʼ������һ
        for(int j=0;j<c1;j++)
            cin>>a[i][j];
    }
    for(int i=0;i<r2;i++){//��ʼ�������
        for(int j=0;j<c2;j++)
            cin>>b[i][j];
    }
    cout<<endl;
    for(int i=0;i<r1;i++){//����
        for(int j=0;j<c2;j++)
            for(int k=0;k<c1;k++)
            c[i][j]+=a[i][k]*b[k][j];
    }
    for(int i=0;i<r1;i++){//���������
        for(int j=0;j<c2;j++)
            cout<<c[i][j]<<" ";
        cout<<endl;
    }
}

*/
