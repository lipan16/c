/*
#include <iostream>
#include <cstdio>

using namespace std;

#define maxn 5000

int main(){
	char str[maxn];
	int n=0,len;//¼ÇÂ¼×Ö·û´®³¤¶È
	gets(str);//ÊäÈë×Ö·û´®
	for(len=0;;len++)//Çó×Ö·û´®³¤¶È
		if(str[len]=='\0')
			break;
	for(int i=len-1;i>=0;i--){
		if(str[i]!=' ')
			n++;
		else
			break;
	}
	cout<<n<<endl;
}
*/
