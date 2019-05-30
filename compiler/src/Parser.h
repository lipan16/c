#pragma once
#include "Table.h"
//#include "lex.h"

/*
���ļ�����
    1.�﷨�������õ����ķ�����ʽ
    2.�﷨������Ҫ����غ����Ķ���
    3.�﷨����������ݽṹ�Ķ���,�����õ���ȫ�ֱ����Ķ���
    4.�﷨��������ʱ������Ϣ��
*/
/**
�����ķ�:
Program --> Res Main_Func
Res     --> Re Res | null
Re      --> # include < Vari . h >
Main_Func --> int main ( ) Block
Block   --> { Decls Stmts }
Decls   --> Decl Decls | null
Decl    --> Basic Vari Init ;
Init    --> = Bool
Stmts   --> Stmt Stmts | null
Stmt    --> if ( Bool ) Stmt ELSE
        --> while ( Bool ) Stmt
        --> Block
        --> Loc = Bool ;
        --> Return Bool ;
ELSE    --> else Stmt | null
Loc     --> Vari
Bool    --> Expr == Expr | Expr != Expr | Expr > Expr | Expr < Expr | Expr
Expr    --> Term + Expr | Term - Expr | Term
Term    --> Unary * Term | Unary / Term | Unary
Unary   --> ! Factor | - Factor | Factor ++ | Factor -- | Factor
Factor  --> ( Bool ) | Vari | Value
*/



struct Syntax_Node{//�﷨�����������,ͬʱҲ���﷨���Ľ��
    int type;//��������
	int Varnum;//��������ر��еı��
	int number;//�����ڴʴ��еı��
	char* Word;//����
	int value;//����������ֵ
	struct Syntax_Node* Bro;//�﷨��Ԫ�ֵܽ��
	struct Syntax_Node* Son;//�﷨��Ԫ���ӽ��
	int keeper;//����
};
/**
1       Main_Func lack of int
2       include
3       <
4       Vari
5       .
6       h
7       >
8       main
9       (
10      )
11      {
12      }
13      Vari
14      ;
15      Stmt
16      (
17      )
18      =
19      Factor
20      )
*/
//�﷨�����Ĵ�����Ϣ��
static char* Error_Messages[]={
    "δ֪����!!!\0",
    "main����ȱ��'int'\0",
    "ȱ��'include'�ؼ���\0",
    "ȱ�� '<'\0",
    "ȱ�ٱ���\0",
    "ȱ��'.'\0",
    "ȱ��'h'\0",
    "ȱ��'>'\0",
    "ȱ��'main'�ؼ���\0",
    "ȱ��'('\0",
    "ȱ��')'\0",
    "ȱ��'{'\0",
    "ȱ��'}'\0",
    "��������ȱ�ٱ���\0",
    "ȱ��';'\0",
    "ȱ��һ�����\0",
    "while��ifȱ��'('\0",
    "while��ifȱ��')'\0",
    "��ֵ���ȱ��'='\0",
    "ȱ��һ��FactorԪ��\0",
    "(Bool)ȱ��һ��')'\0"
};
//�﷨�����õ���ȫ�ֱ���
static struct WordNode* Now;//ָ����һ�������Ĵʷ���Ԫ���
static struct WordNode* Last;//ָ�����ڷ����Ĵʷ���Ԫ���
static struct Syntax_Node * Last_token;//ָ����һ���������﷨��Ԫ���
static struct Syntax_Node * token;//ָ�����ڷ������﷨��Ԫ���

int Token();
//int Token();//Token ȡ����һ�����������﷨��Ԫ���
int UnToken();//UnToken �����﷨��Ԫ���
int SetCurrent(struct WordNode* now);//�����﷨�����ʷ���Ԫ��
//����ĵݹ��½��﷨��������
struct Syntax_Node * Program();//Program �﷨��Ԫ�ķ�������
struct Syntax_Node * Res();//Res �﷨��Ԫ�ķ�������
struct Syntax_Node * Re();//Re �﷨��Ԫ�ķ�������
struct Syntax_Node * Main_Func();//Main_Func �﷨��Ԫ�ķ�������
struct Syntax_Node * Block();//Block �﷨��Ԫ�ķ�������
struct Syntax_Node * Decls();//Decls �﷨��Ԫ�ķ�������
struct Syntax_Node * Decl();//Decl �﷨��Ԫ�ķ�������
struct Syntax_Node * Init();//Init �﷨��Ԫ�ķ�������
struct Syntax_Node * Stmts();//Stmts �﷨��Ԫ�ķ�������
struct Syntax_Node * Stmt();//Stmt �﷨��Ԫ�ķ�������
struct Syntax_Node * Loc();//Loc �﷨��Ԫ�ķ�������
struct Syntax_Node * Bool();//Bool �﷨��Ԫ�ķ�������
struct Syntax_Node * Expr();//Expr �﷨��Ԫ�ķ�������
struct Syntax_Node * Term();//Term �﷨��Ԫ�ķ�������
struct Syntax_Node * Unary();//Unary �﷨��Ԫ�ķ�������
struct Syntax_Node * Factor();//Factor �﷨��Ԫ�ķ�������
int Error(int E_code);//���������
int PrintSyntaxTree(struct Syntax_Node* Head,int Count,FILE*out);//�﷨���Ĵ�ӡ�������

