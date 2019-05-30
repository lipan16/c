#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
/*
Lex_Head.h
�ʷ�����ͷ�ļ�
*/
/*
���ļ�����
    1.�ʷ�������Ҫ����غ����Ķ���
    2.�ʷ�����������ݽṹ�Ķ���
*/

//static int WordCount=0;//���ʴ�����
struct WordNode//�ʴ����
{
	int type;//��������
	int Varnum;//��������ر��еı��
	int number;//�����ڴʴ��еı��
	char* Word;//����
	double value;//����������ֵ
	struct WordNode* next;//��һ���ָ��
	int keeper;//����
};
struct WordHead//�ʴ�ͷ
{
	struct WordNode * first;//�ʴ���һ�����ʽ��
	struct WordNode * last;//�ʴ����һ�����ʽ��
	int nodecount;//�ʴ����ʼ���
	int keeper;//����
};
char* input_filename();//�����ļ���
FILE* openfile(char* filename);//���ļ�
struct WordNode* getWord(FILE* filepointer);//��ȡһ������
void AnalyseWord(struct WordNode* node);//��������
void addNode(struct WordHead* Head, struct WordNode* node);//���ʽ����ӵ��ʴ���
int OutPutNode(struct WordHead* Head,FILE* out);//����ʴ�
struct WordHead * Lexical_Analyzer(int argc, char* argv[]);

