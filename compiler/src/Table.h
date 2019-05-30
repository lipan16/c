#pragma once
#include "Lex_Head.h"

/*
Table.h
编译器表文件
*/

/*
本文件包含编译器需要的表结构
包含关键字,分隔符,运算符,表
定义变量表结构(头,结点)
*/
#define KEY         0
#define SPARATOR    1
#define OPERATOR    2
#define VALUE       3
#define VARIABLE    4
//关键字表
static char* Key[] ={
    "char", "double", "float", "int", "long", "short", "signed", "unsigned", "void",
    "auto", "break", "case","const", "continue",
    "default", "do", "else", "enum", "extern",
    "for", "goto", "if",
    "register", "return","sizeof", "static",
    "struct", "switch", "typedef", "union",
    "volatile", "while"
};
//分隔符
static char*  Sparator[] =
{
    "[", "]", "{", "}", ";", "\"", "\'", "#", "(", ")", ".", ":", ",",
    "\\", "\?"
};
//运算符
static char* Operator[] ={
    "+", "-", "*", "/", "<", ">", "=", "^", "&", "|", "%", "~","!",
    ">>", "<<", "++", "--", "&&", "||", "!=", "==", "+=", "-=", "<=", ">=", "->"
};
static int TableLength[] = {32, 15, 26};//表长度
struct VariableNode//变量表结点
{
    int num;//序号
    double Value;//值
    char* name;//变量名
    int Type;//变量类型
    struct VariableNode* next;//下一结点
    int keeper;//保留
};
struct VariableHead//变量表头结点
{
    int Count;//表长度计数
    struct VariableNode* first;//第一个结点
    struct VariableNode* last;//最后一个结点
    int keeper;//保留
};

static struct VariableHead VarHead;//全局变量作为整个编译过程的变量表头

int SearchVar(struct WordNode*);//从变量表查找
int Search(struct WordNode*, int);//从表(关键字,分隔符,运算符)查找
int OutPutVar(FILE* out);//输出变量表内容

