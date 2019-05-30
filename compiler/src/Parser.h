#pragma once
#include "Table.h"
//#include "lex.h"

/*
此文件包含
    1.语法分析所用到的文法产生式
    2.语法分析需要的相关函数的定义
    3.语法分析相关数据结构的定义,包括用到的全局变量的定义
    4.语法分析错误时错误信息表
*/
/**
所用文法:
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



struct Syntax_Node{//语法分析基本结点,同时也是语法树的结点
    int type;//单词类型
	int Varnum;//单词在相关表中的编号
	int number;//单词在词串中的编号
	char* Word;//单词
	int value;//变量或常量的值
	struct Syntax_Node* Bro;//语法单元兄弟结点
	struct Syntax_Node* Son;//语法单元儿子结点
	int keeper;//保留
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
//语法分析的错误信息表
static char* Error_Messages[]={
    "未知错误!!!\0",
    "main函数缺少'int'\0",
    "缺少'include'关键字\0",
    "缺少 '<'\0",
    "缺少变量\0",
    "缺少'.'\0",
    "缺少'h'\0",
    "缺少'>'\0",
    "缺少'main'关键字\0",
    "缺少'('\0",
    "缺少')'\0",
    "缺少'{'\0",
    "缺少'}'\0",
    "变量声明缺少变量\0",
    "缺少';'\0",
    "缺少一个语句\0",
    "while或if缺少'('\0",
    "while或if缺少')'\0",
    "赋值语句缺少'='\0",
    "缺少一个Factor元素\0",
    "(Bool)缺少一个')'\0"
};
//语法分析用到的全局变量
static struct WordNode* Now;//指向下一个分析的词法单元结点
static struct WordNode* Last;//指向正在分析的词法单元结点
static struct Syntax_Node * Last_token;//指向上一个分析的语法单元结点
static struct Syntax_Node * token;//指向正在分析的语法单元结点

int Token();
//int Token();//Token 取出下一个待分析的语法单元结点
int UnToken();//UnToken 回退语法单元结点
int SetCurrent(struct WordNode* now);//设置语法分析词法单元链
//具体的递归下降语法分析函数
struct Syntax_Node * Program();//Program 语法单元的分析程序
struct Syntax_Node * Res();//Res 语法单元的分析程序
struct Syntax_Node * Re();//Re 语法单元的分析程序
struct Syntax_Node * Main_Func();//Main_Func 语法单元的分析程序
struct Syntax_Node * Block();//Block 语法单元的分析程序
struct Syntax_Node * Decls();//Decls 语法单元的分析程序
struct Syntax_Node * Decl();//Decl 语法单元的分析程序
struct Syntax_Node * Init();//Init 语法单元的分析程序
struct Syntax_Node * Stmts();//Stmts 语法单元的分析程序
struct Syntax_Node * Stmt();//Stmt 语法单元的分析程序
struct Syntax_Node * Loc();//Loc 语法单元的分析程序
struct Syntax_Node * Bool();//Bool 语法单元的分析程序
struct Syntax_Node * Expr();//Expr 语法单元的分析程序
struct Syntax_Node * Term();//Term 语法单元的分析程序
struct Syntax_Node * Unary();//Unary 语法单元的分析程序
struct Syntax_Node * Factor();//Factor 语法单元的分析程序
int Error(int E_code);//错误处理程序
int PrintSyntaxTree(struct Syntax_Node* Head,int Count,FILE*out);//语法树的打印输出程序

