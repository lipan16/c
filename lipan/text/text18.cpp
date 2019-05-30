/*
 * text18.cpp
 *
 *  Created on: 2018Äê7ÔÂ2ÈÕ
 *      Author: asus
 */

/*
#include<iostream>
#include<cstdlib>
using namespace std;
struct node {
	int info;
	struct node *link;
}*top;

class stack_list {
public:
	node *push(node *, int);
	node *pop(node *);
	void traverse(node *);
	stack_list() {
		top = NULL;
	}
};
node *stack_list::push(node *no,int i){
	top=no;
	top->info=i;
	return top;
}
node *stack_list::pop(node *no){
	node *p=top;
	while(p->link!=no)
		p=p->link;
	p->link=NULL;
	return top;
}
void stack_list::traverse(node *no){
	while(no!=NULL){
		cout<<no->info;
		no=no->link;
	}
}
int main() {
	stack_list sl;
	int num = 5;
	for (int i = 1; i <= num; i++) {
		top = sl.push(top, i);
	}
	sl.traverse(top);
	while (top != NULL) {
		top = sl.pop(top);
	}
	sl.traverse(top);
	return 0;
}
*/
