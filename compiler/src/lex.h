#pragma once

struct chars {
	char e;
	int id;  //id为1时为非key_s中的字符，id为0时为key_s中的字符
};

struct word //作为在从输入字符chars str0[500]，到结果lex result[500]的中间字符串结构体，在str1和str2中id不断的在函数调用进一步划分，最终在result_build中生成lex result[500]的种别码type
{
	char e[100];
	int row;
	int id;
};

struct selfid  //自定义标识符结构体
{
	char e[100];
	int row;
};

struct selfnum  //自定义常量结构体
{
	int e;
	int row;
};

struct lex  //输出结果结构体
{
	int type;   //种别码,4为未识别的标识符
	int row;    //行
	int order;  //序号
	int vaule;
	char e[100];  //字符串本身

};

struct chars str0[1000];  //结构体数组，存放从文件读入的一个个字符
struct word str1[1000];     //存放将str0初步分开后的符号和字符串
struct word str2[1000];  //将str1中的字符串分为number，string，UnknownCharacter和Identifer存储
struct lex result[1000];   //将str2中的符号进一步分类成不同种别码的符号，且将number，Identifer放入列表

struct selfnum const_number[100];  //存放常量number的列表
int count_number = 0;     //记录const_number的个数
struct selfid identifer[100];  //存放标识符的列表

//符号列表，用来分割str0得到str1
char key_s[27] = { '(', ')', ';', '{', '}', '+', '-', '*', '\n', ',', '\t', '%',
		'=', '\\', ' ', '/', '\'', '"', '|', '[', ']', '<', '>', '&', '.', '!',
		'#' };

//符号列表，生成符号种别码
char *key_c[24] = { "(", ")", "{", "}", "+", "-", "*", "/", "=", ",", ";", "%",
		"\\", "\"", "'", "|", "[", "]", "<", ">", "&", ".", "!", "#" };

//关键字列表
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



