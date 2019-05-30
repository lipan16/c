#pragma once
#include "Lex_Head.h"

/*
Table.h
���������ļ�
*/

/*
���ļ�������������Ҫ�ı�ṹ
�����ؼ���,�ָ���,�����,��
���������ṹ(ͷ,���)
*/
#define KEY         0
#define SPARATOR    1
#define OPERATOR    2
#define VALUE       3
#define VARIABLE    4
//�ؼ��ֱ�
static char* Key[] ={
    "char", "double", "float", "int", "long", "short", "signed", "unsigned", "void",
    "auto", "break", "case","const", "continue",
    "default", "do", "else", "enum", "extern",
    "for", "goto", "if",
    "register", "return","sizeof", "static",
    "struct", "switch", "typedef", "union",
    "volatile", "while"
};
//�ָ���
static char*  Sparator[] =
{
    "[", "]", "{", "}", ";", "\"", "\'", "#", "(", ")", ".", ":", ",",
    "\\", "\?"
};
//�����
static char* Operator[] ={
    "+", "-", "*", "/", "<", ">", "=", "^", "&", "|", "%", "~","!",
    ">>", "<<", "++", "--", "&&", "||", "!=", "==", "+=", "-=", "<=", ">=", "->"
};
static int TableLength[] = {32, 15, 26};//����
struct VariableNode//��������
{
    int num;//���
    double Value;//ֵ
    char* name;//������
    int Type;//��������
    struct VariableNode* next;//��һ���
    int keeper;//����
};
struct VariableHead//������ͷ���
{
    int Count;//���ȼ���
    struct VariableNode* first;//��һ�����
    struct VariableNode* last;//���һ�����
    int keeper;//����
};

static struct VariableHead VarHead;//ȫ�ֱ�����Ϊ����������̵ı�����ͷ

int SearchVar(struct WordNode*);//�ӱ��������
int Search(struct WordNode*, int);//�ӱ�(�ؼ���,�ָ���,�����)����
int OutPutVar(FILE* out);//�������������

