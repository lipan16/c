#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
/*
Lex_Head.h
词法分析头文件
*/
/*
此文件包含
    1.词法分析需要的相关函数的定义
    2.词法分析相关数据结构的定义
*/

//static int WordCount=0;//单词串计数
struct WordNode//词串结点
{
	int type;//单词类型
	int Varnum;//单词在相关表中的编号
	int number;//单词在词串中的编号
	char* Word;//单词
	double value;//变量或常量的值
	struct WordNode* next;//下一结点指针
	int keeper;//保留
};
struct WordHead//词串头
{
	struct WordNode * first;//词串第一个单词结点
	struct WordNode * last;//词串最后一个单词结点
	int nodecount;//词串单词计数
	int keeper;//保留
};
char* input_filename();//输入文件名
FILE* openfile(char* filename);//打开文件
struct WordNode* getWord(FILE* filepointer);//读取一个单词
void AnalyseWord(struct WordNode* node);//分析单词
void addNode(struct WordHead* Head, struct WordNode* node);//单词结点添加到词串中
int OutPutNode(struct WordHead* Head,FILE* out);//输出词串
struct WordHead * Lexical_Analyzer(int argc, char* argv[]);

