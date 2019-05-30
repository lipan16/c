/*
 * text13.cpp
 *
 *  Created on: 2018��6��27��
 *      Author: asus
 */


/*
==========================================================
# 001:   ����
==========================================================

#include <vector>
#include <iostream>

int main()
{
    std::vector<double> a;
    a.push_back(1);
    a.push_back(2);
    a.push_back(3);
    a.push_back(4);

    for(int i = 0; i < a.size(); ++i)  {
        std::cout<<a[i]<<std::endl;
    }
    return 0;
}

==========================================================
# 002 ���� ������
==========================================================

#include <iostream>
#include <vector>
using namespace std;

int main() {
   vector<int> vec;    int i;
   cout << "vector size = " << vec.size() << endl;
   for(i = 0; i < 5; i++) { vec.push_back(i);}
   cout << "extended vector size = " << vec.size() << endl;

   for(i = 0; i < 5; i++) {
      cout << "value of vec [" << i << "] = " << vec[i] << endl;
   }

   vector<int>::iterator v = vec.begin();
   while( v != vec.end()) {
      cout << "value of v= " << *v << endl;
      v++;
   }

   return 0;
}

==========================================================
# 002+ ���� ������
==========================================================

#include <iostream>
#include <list>
#include <iterator> //������
using namespace std;

int main(){
	list<int> lI;
	int i;
	for(i=1;i<10;i++)lI.push_back(i);
	for(i=10;i<20;i++)lI.push_front(i);
	list<int>::iterator iPos;
	for(iPos=lI.begin();iPos!=lI.end();iPos++)
		cout << *iPos << " ";
	cout << endl;
	lI.sort();
	for(iPos=lI.begin();iPos!=lI.end();iPos++)
		cout << *iPos << " ";
	cout << endl;
	return 0;
}

==========================================================
# 003 ���� ������
==========================================================

#include <iostream>
#include <map>
using namespace std;

int main()
{
    map<char,int,less<char> > map1;
    map<char,int,less<char> >::iterator mapIter;

    map1['c']=3;    map1['d']=4;
    map1['a']=1;    map1['b']=2;

    for(mapIter=map1.begin();mapIter!=map1.end();++mapIter)
        cout<<(*mapIter).first<<": "<<(*mapIter).second<<" ";

    map<char,int,less<char> >::const_iterator ptr;

    ptr=map1.find('d');
    cout<<'\n'<<(*ptr).first<<" ����Ӧ��ֵ��"<<(*ptr).second<<" ";

    return 0;
}

==========================================================
# 004 ���� ������ // ��ϰ002
==========================================================

#include <cstring>
#include <vector>
#include <iostream>
using namespace std;

int ar[10] = {  12, 45, 234, 64, 12, 35, 63, 23, 12, 55  };
char* str = "Hello World";

int main()
{
    vector <int> vec1(ar, ar+10);
    vector < char > vec2(str,str+strlen(str));

    cout<<"vec1:"<<endl;
    for(vector<int>::const_iterator p=vec1.begin();p!=vec1.end(); ++p)
        cout<<*p;

    cout<<'\n'<<"vec2:"<<endl;
    for(vector< char >::const_iterator p=vec2.begin();p!=vec2.end(); ++p)
        cout<<*p;

    return 0;
}

==========================================================
# 005 ���� �㷨
==========================================================

#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int a[10]={12,0,5,3,6,8,9,34,32,18};
    int b[5]={5,3,6,18,9};
    int d[14];

    sort(a,a+10);
    for(int i=0;i<10;i++)
      cout<<a[i]<<" ";

    sort(b,b+5);
    if(includes(a,a+10,b,b+5))
       cout<<"\nsorted b members are included in a.\n"<<endl;
    else
       cout<<"\nsorted a dosn`t contain sorted b!\n";

    merge(a,a+10,b,b+5,d);
    for(int j=0;j<15;j++)
       cout<<d[j]<<" ";

    return 0;
}

==========================================================
# 006 ���� �㷨
==========================================================

#include <iostream>
#include <algorithm>
#include <iterator>
using namespace std;

int main()
{
    int arr[6]={1,12,3,2,1215,90};
    int arr1[7];
    int arr2[6]={2,5,6,9,0,-56};

    copy(arr,(arr+6),arr1);// ������aar ���Ƶ�arr1
    for(int i=0;i<7;i++)
        cout<<" "<<arr1[i];
    cout << endl;

    reverse(arr,arr+6);// ���ź����arr ��ת
    copy(arr,arr+6,ostream_iterator<int>(cout, " "));// ���Ƶ����������
    cout << endl;

    swap_ranges(arr,arr+6,arr2);// ����arr ��arr2 ����
    copy(arr,arr+6,ostream_iterator<int>(cout, " "));
    cout << endl;
    copy(arr2,arr2+6,ostream_iterator<int>(cout, " "));

    return 0;
}


==========================================================
# 007 ����  �㷨
==========================================================

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int sum=0;
void f(int x) { sum+=x;}

int main()
{
    vector<int> v;
    for(int i=0;i<100;i++)  {
        v.push_back(i);
    }
    for_each(v.begin(),v.end(),f);
    cout<<sum;
    return 0;
}

==========================================================
# 008 �º�������������
==========================================================
�º�����functor������һ��������"()"�������struct��class��
���ö���֧��operator()�����ԣ����ﵽģ�⺯������Ч���ļ�����

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct myprint02 {
    void operator()(int v1) const{
        cout << v1 << ' ';    }
};

int main()
{
    vector<int> v;
    v.push_back(2);  v.push_back(1);
    v.push_back(5);  v.push_back(4);

    for_each(v.begin(), v.end(), myprint02());
};

==========================================================
# 009 for each ģʽ��չ
==========================================================

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;

bool greaterthan10(int value){return value > 10;}
int main(){
	vector<int> vctI;
	vector<int>::iterator iPos;
	vctI.push_back(1); vctI.push_back(100);
    vctI.push_back(25);vctI.push_back(18);
    vctI.push_back(56); vctI.push_back(87);

	iPos=find(vctI.begin(),vctI.end(),25);
	cout << *iPos << endl;
	iPos=find_if(vctI.begin(),vctI.end(),greaterthan10);
	cout << *iPos << endl;
	return 0;
}

==========================================================
# 010 ������� - vector �Ķ�����ʽʹ��
==========================================================

#include <iostream>
#include <vector>

using namespace std;
int main()
{
    //�������顪����̬���飺�䳤�ȿɵ�
	vector<int> vI;  int i;
	vI.reserve(10);//�����鳤����Ϊ10
	for(i=0;i<8;i++)  vI[i]=i;
	for(i=0;i<8;i++)  cout << vI[i] << " " ;
	cout << endl;
	cout << vI.capacity() << endl;

	//����ջ
	vector<double> vD;
	for(i=1;i<=20;i++) vD.push_back(i);
	for(;!vD.empty();){
	     cout << vD.back() << " ";
	     vD.pop_back();
	}

	return 0;
}

==========================================================
# 011 ���� �㷨  ---- ��ǿ������
==========================================================

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool Descending(int a,int b){	return a>b;}

int main(){
	vector<int> vctI;
	int i;
	for(i=1;i<=10;i++)vctI.push_back(i);
	for(i=11;i<=20;i++)vctI.insert(vctI.begin(),i);

	cout << "ԭʼ����: ";
	vector<int>::iterator iPos;
	for(iPos=vctI.begin();iPos!=vctI.end();iPos++)
		cout << *iPos << " ";
	cout << endl;

	cout << "����: ";
	sort(vctI.begin(),vctI.end());
	for(iPos=vctI.begin();iPos!=vctI.end();iPos++)
		cout << *iPos << " ";
	cout << endl;

	cout << "������: ";
	sort(vctI.begin(),vctI.end(),Descending);
	for(iPos=vctI.begin();iPos!=vctI.end();iPos++)
		cout << *iPos << " ";
	cout << endl;
	return 0;
}
*/




