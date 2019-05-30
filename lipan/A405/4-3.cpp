/*
 * 4-3.cpp
 *
 *  Created on: 2018Äê4ÔÂ25ÈÕ
 *      Author: asus
 */

/*
#include <iostream>
using namespace std;

struct node{
	int elem;
	node *next;
};

int main(){
	int i;
	cout<<"Please input integers to build the link(0 TO END):";
	cin>>i;
	if(i==0)
		return 0;
	else{
		node *head=new node;
		node *s=head;
		s->elem=i;
		s->next=NULL;
		do{
			cin>>i;
			if(i==0)
				break;
			else{
				node *p=new node;
				p->elem=i;
				p->next=NULL;
				s->next=p;
				s=p;
			}
		}while(i);

		s=head;
		cout<<"output:";
		while(s){
			cout<<s->elem<<" ";
			s=s->next;
		}
	}
}
*/

/*
int main(){
	node *head=new node;
	node *s=head;
	cout<<"Please input integers to build the link(0 TO END):";
	cin>>s->elem;
	if(s->elem==0){
		delete head;
		return 0;
	}
	else{
		while (s->elem != 0) {
			node *p = new node;
			cin >> p->elem;
			p->next = NULL;
			s->next = p;
			s = p;
		}
		s = head;
		cout<<"output:";
		while (s->next) {
			cout << s->elem << " ";
			s = s->next;
		}
	}
}
*/
