/*
 * 4-4.cpp
 *
 *  Created on: 2018��4��25��
 *      Author: asus
 *
 *
 *      ��һ��ͨ��¼�����¼���������Ϣ���ɣ�
 *      ������ 	����
 *      ���� 		�ַ���
 *      ��ַ 		�ַ���
 *      �������� 	�ַ���
 *      �绰���� 	�ַ���
 *      �����ʼ� 	�ַ���
 *      ʵ��һ��ͨѶ¼����ʵ�ֹ��ܣ���ȡ����ʾ��ɾ����¼����ѯ��¼�ȹ���
 *
 */


/*
#include <iostream>
using namespace std;

struct contacts{
	char name[20];
	char address[20];
	char phone[20];
	char post[6];
	char email[20];
	contacts *next;
};

int count=0;
contacts *head=NULL,*s=head;

void add();
void display();
void del(int);
void search(contacts &con);

int main(){
	add();
	add();
	display();
	del(1);
	display();
	return 0;
}

void add(){
	count++;
	contacts *con=new contacts;
	con->next=NULL;
	if(head==NULL){
		head=con;
	}
	else{
		s->next=con;
	}
	cout<<"Please input name,address,phone,post,email"<<endl;
	cin>>con->name>>con->address>>con->phone>>con->post>>con->email;
	s=con;
}

void display(){
	s=head;
	cout<<"\noutput name,address,phone,post,email"<<endl;
	while(s){
		cout<<s->name<<" "<<s->address<<" "<<s->phone<<" "<<s->post<<" "<<s->email<<endl;
		s=s->next;
	}
}

void del(int n){
	if(n<=0||n>count){
		cout<<"";
		return;
	}
	s=head;
	contacts *p=s;
	while(n--){
		p=s;
		s=s->next;
	}
	p=s->next;
	//cout<<"\noutput name,address,phone,post,email"<<endl;
	//cout<<s->name<<" "<<s->address<<" "<<s->phone<<" "<<s->post<<" "<<s->email<<endl;
}

void search(contacts &con){

}
*/
