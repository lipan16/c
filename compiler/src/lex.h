#pragma once

struct chars {
	char e;
	int id;  //idΪ1ʱΪ��key_s�е��ַ���idΪ0ʱΪkey_s�е��ַ�
};

struct word //��Ϊ�ڴ������ַ�chars str0[500]�������lex result[500]���м��ַ����ṹ�壬��str1��str2��id���ϵ��ں������ý�һ�����֣�������result_build������lex result[500]���ֱ���type
{
	char e[100];
	int row;
	int id;
};

struct selfid  //�Զ����ʶ���ṹ��
{
	char e[100];
	int row;
};

struct selfnum  //�Զ��峣���ṹ��
{
	int e;
	int row;
};

struct lex  //�������ṹ��
{
	int type;   //�ֱ���,4Ϊδʶ��ı�ʶ��
	int row;    //��
	int order;  //���
	int vaule;
	char e[100];  //�ַ�������

};

struct chars str0[1000];  //�ṹ�����飬��Ŵ��ļ������һ�����ַ�
struct word str1[1000];     //��Ž�str0�����ֿ���ķ��ź��ַ���
struct word str2[1000];  //��str1�е��ַ�����Ϊnumber��string��UnknownCharacter��Identifer�洢
struct lex result[1000];   //��str2�еķ��Ž�һ������ɲ�ͬ�ֱ���ķ��ţ��ҽ�number��Identifer�����б�

struct selfnum const_number[100];  //��ų���number���б�
int count_number = 0;     //��¼const_number�ĸ���
struct selfid identifer[100];  //��ű�ʶ�����б�

//�����б������ָ�str0�õ�str1
char key_s[27] = { '(', ')', ';', '{', '}', '+', '-', '*', '\n', ',', '\t', '%',
		'=', '\\', ' ', '/', '\'', '"', '|', '[', ']', '<', '>', '&', '.', '!',
		'#' };

//�����б����ɷ����ֱ���
char *key_c[24] = { "(", ")", "{", "}", "+", "-", "*", "/", "=", ",", ";", "%",
		"\\", "\"", "'", "|", "[", "]", "<", ">", "&", ".", "!", "#" };

//�ؼ����б�
char *key_w[32] = { "auto", "break", "case", "char", "const", "continue",
		"default", "do", "double", "else", "enum", "extern", "float", "for",
		"goto", "if", "int", "long", "register", "return", "short", "signed",
		"sizeof", "static", "struct", "switch", "typedef", "union", "unsigned",
		"void", "volatile", "while" };

void read_file(char *name);
void traversal_keys();
void cut_word();
void traversal_keyw();
int number_check(char *temp);
int id_check(char *temp);
void classify();
void result_build();
void save_file();
void lex_scanner(char *name);
struct WordHead * lexer();



