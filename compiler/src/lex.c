#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lex.h"


void read_file(char *name){  //读文件写入str0数组
	FILE * fp;
	char e;
	int count = 0;
	//int count_1 = 0;

	if ((fp = fopen(name, "r")) == NULL) {
		printf("open file error\n");
		exit(0);
	}

	while ((e = fgetc(fp)) != EOF) {
		//count_1 = 0;
		str0[count].e = e;
		count++;
	}
	fclose(fp);
}

void traversal_keys() { //对str0中的字符进行遍历，用key_s中的元素区分字符是否为分隔符

	int i = 0;
	int j;
	while (str0[i].e != '\0') {
		j = 0;
		while (j < 27) {
			if (str0[i].e == key_s[j]) {
				str0[i].id = 0;
				break;
			}
			j++;
		}
		if (j == 27) {
			str0[i].id = 1;
		}
		i++;
	}
}

void cut_word()  //将str0的字符分割成分隔符和字符串，并计算字符串的所在行数
{
	int i = 0;
	int j = 0;
	int k = 0;
	int l = 1;
	while (str0[i].e != '\0') {
		if (str0[i].id != 0) {
			str1[j].e[k] = str0[i].e;
			str1[j].row = l;
			k++;
			if (str0[i + 1].id == 0) {
				str1[j].id = 1;   //分割str0时，非分隔符id为1
				j++;
				k = 0;
			}
		} else if (str0[i].e == '\n') {
			l++;
		} else {
			str1[j].e[0] = str0[i].e;
			str1[j].row = l;
			str1[j].id = 0;      //分割str0时，分隔符id为0
			if (str0[i].e == '"') {
				j++;
				k = 0;
				i++;
				while (str0[i].e != '"') {
					str1[j].e[k] = str0[i].e;
					str1[j].row = l;
					k++;
					i++;
				}
				str1[j].id = 4;   //分割str0时，符号""内的字符串的id为4
				j++;
				str1[j].e[0] = str0[i].e;
				str1[j].row = l;
				str1[j].id = 0;
			}
			j++;
			k = 0;
		}
		i++;
	}
}

void traversal_keyw()  //对str1中的字符进行遍历，与key_w比较来区分出关键字
{
	int i = 0;
	int j;
	while (strcmp(str1[i].e, "\0") != 0) {
		j = 0;
		while (j < 32) {
			if (strcmp(str1[i].e, key_w[j]) == 0)  //在key_w中,id为1
					{
				str1[i].id = 1;
				break;
			}
			j++;
		}
		if (j == 32 && str1[i].id != 0 && str1[i].id != 4) //不在key_w中，且不是分隔符和""内的字符串的字符串，id为2
				{
			str1[i].id = 2;
		}
		i++;
	}
}

int number_check(char *temp)  //检查temp字符串是否为数字
{
	int i = 0;
	while (temp[i] != '\0') {
		if ((temp[i] < '0') || (temp[i] > '9'))
			return 1;
		i++;
	}
	return 0;
}

int id_check(char *temp)  //检查temp字符串是否含有除了0-9，a-z，A-Z的字符
{
	int i = 0;
	while (temp[i] != '\0') {
		if (((temp[i] >= '0') && (temp[i] <= '9'))
				|| ((temp[i] >= 'A') && (temp[i] <= 'Z'))
				|| ((temp[i] >= 'a') && (temp[i] <= 'z')) || temp[i] == '_') {
			i++;
			continue;
		} else
			return 1;   //含有除了0-9，a-z，A-Z的之外的字符，返回1，否则返回0
	}
	return 0;
}

void classify() //生成str2,不复制str1中的符号中的空格和制表符，并且对str1中的字符串进行初步分类复制，区分出number，string，UnknownCharacter和Identifer
{
	int i = 0;
	int j = 0;
	int check;
	int icheck;
	int key;
	while (strcmp(str1[i].e, "\0") != 0) {
		key = str1[i].id;
		switch (key) {
		case 0: {
			if ((strcmp(str1[i].e, " ") == 0) || (strcmp(str1[i].e, "\n") == 0)
					|| (strcmp(str1[i].e, "\t") == 0)) {
			}  //当str1中的字符为str1中的符号中的空格、制表符或者换行符时，什么都不做
			else {
				strcpy(str2[j].e, str1[i].e);
				str2[j].id = 0;
				str2[j].row = str1[j].row;
				j++;
			}
			break;
		}
		case 1: {
			strcpy(str2[j].e, str1[i].e);  //关键字直接复制
			str2[j].id = 1;
			str2[j].row = str1[j].row;
			j++;
			break;
		}
		case 2: {
			icheck = id_check(str1[i].e);   //检查字符串中是否有非字母，数字字符
			check = number_check(str1[i].e);  //检测字符串是否为数字
			strcpy(str2[j].e, str1[i].e);
			str2[j].row = str1[j].row;
			if (icheck == 0)  //不含有非字母，数字的字符
					{
				if (check == 0)
					str2[j].id = 3;  //全是数字，id为3
				else {
					if (((str1[i].e[0] >= 'A') && (str1[i].e[0] <= 'Z'))
							|| ((str1[i].e[0] >= 'a') && (str1[i].e[0] <= 'z')))
						str2[j].id = 2;  //以字母开头，id为2
					else
						str2[j].id = 5;  //未识别的字符，id为5
				}
			} else
				str2[j].id = 5;   //未识别的字符，id为5
			j++;
			break;
		}
		case 4: {
			strcpy(str2[j].e, str1[i].e);
			str2[j].row = str1[j].row;
			str2[j].id = 4;
			j++;
		}
		}
		i++;
	}
}

void result_build() //得到词法分析结果，将str2中的符号按字符种别码(借助key_c)分类,将number，和identifer记入const_number和identifer列表中
{
	int i = 0;
	int j = 0;
	int k = 0;
	int x = 0;
	int y = 0;
	int m = 0;
	int n = 0;
	int numbers = 0;
	int key;
	while (strcmp(str2[i].e, "\0") != 0) {
		key = str2[i].id;
		switch (key) {
		case 0:  //符号的种别码识别
		{
			strcpy(result[k].e, str2[i].e);
			result[k].row = str2[i].row;
			while (strcmp(str2[i].e, key_c[j]) != 0) {
				j++;
			}
			result[k].type = 5 + j; //生成符号的种别码(符号的种别码大于或等于5，可直接用其在key_c中的位置加5即可)
			j = 0;
			k++;
			break;
		}
		case 1:   //关键字直接复制，id降1为type
		{
			strcpy(result[k].e, str2[i].e);
			result[k].row = str2[i].row;
			result[i].type = 0;
			while (strcmp(str2[i].e, key_w[j]) != 0) {
				j++;
			}
			result[i].order = j;
			j = 0;
			k++;
			break;
		}
		case 2:  //标志符复制，id降1为type
		{
			strcpy(result[k].e, str2[i].e);
			result[k].row = str2[i].row;
			result[k].type = 1;
			if (x == 0)  //判断标识符列表是否为空，空的话直接添加即可
					{
				strcpy(identifer[x].e, str2[i].e);
				identifer[x].row = str2[i].row;
				result[k].order = x;
				x++;
			} else  //非空，即判断标识符是否已经存在列表中
			{
				while (m < x) {
					if (strcmp(identifer[m].e, str2[i].e) == 0) {
						result[k].order = m;    //存在，将当前序列号给result.order
						break;
					}
					m++;
				}
				if (m == x) {
					strcpy(identifer[x].e, str2[i].e);
					identifer[x].row = str2[i].row;
					result[k].order = x;  //不存在，添加到列表的最后
					x++;
				}
				m = 0;
			}
			k++;
			break;
		}
		case 3:  //数字常量复制，id降1为type
		{
			numbers = atoi(str2[i].e);
			//strcpy(result[k].e, str2[i].e);
			result[k].vaule=numbers;
			result[k].row = str2[i].row;
			result[k].type = 2;
			if (y == 0){  //判断常量列表是否为空，空的话直接添加即可
				const_number[y].e = numbers;
				const_number[y].row = str2[i].row;
				result[k].order = y;
				count_number++;
				y++;
			} else {  //非空，即判断标识符是否已经存在列表中
				while (n < y) {
					if (const_number[n].e == numbers) {
						result[k].order = n;    //存在，将当前序列号给result.order
						break;
					}
					n++;
				}
				if (n == y) {
					const_number[y].e = numbers;
					const_number[y].row = str2[i].row;
					result[k].order = y;  //不存在，添加到列表的最后
					count_number++;
					y++;
					n = 0;
				}
			}
			k++;
			break;
		}
		case 4: {
			strcpy(result[k].e, str2[i].e);
			result[k].row = str2[i].row;
			result[k].type = 3;
			k++;
			break;
		}
		case 5: {
			strcpy(result[k].e, str2[i].e);  //未识别的字符
			result[k].row = str2[i].row;
			result[k].type = 4;
			k++;
			break;
		}
		}
		i++;
	}
}

void save_file()  //保存单词种别码，标识符列表，常量列表和运行结果到文件
{
	int i;

	FILE * fp;

	if ((fp = fopen("单词种别码.txt", "w")) == NULL) {
		printf("write fie error\n");
		exit(0);
	}
	fprintf(fp, "---------------单词种别码---------------\n");
	fprintf(fp, "0\t关键字\n");
	fprintf(fp, "1\t标识符\n");
	fprintf(fp, "2\t常量\n");
	fprintf(fp, "3\t引用内容\n");
	fprintf(fp, "4\t未识别\n");
	i = 0;
	while (i < 23) {
		fprintf(fp, "%d\t%s\n", i + 5, key_c[i]);
		i++;
	}
	fclose(fp);

	if ((fp = fopen("标志符列表.txt", "w")) == NULL) {
		printf("write fie error\n");
		exit(0);
	}
	fprintf(fp, "---------------标志符列表---------------\n");
	fprintf(fp, "编号\t行\t标识符\n");
	i = 0;
	while (strcmp(identifer[i].e, "\0") != 0) {
		fprintf(fp, "%d\t%d\t%s\n", i, identifer[i].row, identifer[i].e);
		i++;
	}
	fclose(fp);

	if ((fp = fopen("常量列表.txt", "w")) == NULL) {
		printf("write fie error\n");
		exit(0);
	}
	fprintf(fp, "---------------常量列表---------------\n");
	fprintf(fp, "编号\t行\t数字\n");
	i = 0;
	while (i < count_number) {
		fprintf(fp, "%d\t%d\t%d\n", i, const_number[i].row, const_number[i].e);
		i++;
	}
	fclose(fp);

	i = 0;
	if ((fp = fopen("结果.txt", "w")) == NULL) {
		printf("write fie error\n");
		exit(0);
	}
	fprintf(fp, "---------------结果---------------\n");
	fprintf(fp, "种别码\t行\t字符串\n");
	while (strcmp(result[i].e, "\0") != 0) {
		fprintf(fp, "%d\t%d\t%s\n", result[i].type, result[i].row, result[i].e);
		i++;
	}
	fclose(fp);
}

void lex_scanner(char *name)  //词法分析扫描器主方法
{
	read_file(name);
	traversal_keys();
	cut_word();
	traversal_keyw();
	classify();
	result_build();
	save_file();
}

struct WordHead * lexer() {
	char name[20];
	int i;
//	struct WordHead* Head = malloc(sizeof(struct WordHead)); //词串链表头
	printf("请输入需要进行词法分析的文件名：\n");
	scanf("%s", name);


	lex_scanner(name);

	printf("---------------单词种别码---------------\n");
	printf("0\t关键字\n");
	printf("1\t标识符\n");
	printf("2\t常量\n");
	printf("3\t引用内容\n");
	printf("4\t未识别\n");
	i = 0;
	while (i < 23) {
		printf("%d\t%s\n", i + 5, key_c[i]);
		i++;
	}
	printf("---------------标识符列表---------------\n");
	printf("编号\t行\t标识符\n");
	i = 0;
	while (strcmp(identifer[i].e, "\0") != 0) {
		printf("%d\t%d\t%s\n", i, identifer[i].row, identifer[i].e);
		i++;
	}
	printf("----------------常量列表----------------\n");
	printf("编号\t行\t数字\n");
	i = 0;
	while (i < count_number) {
		printf("%d\t%d\t%d\n", i, const_number[i].row, const_number[i].e);
		i++;
	}


	i = 0;
	printf("------------------结果------------------\n");
	printf("种别码\t行\t字符串\n");
	while (strcmp(result[i].e, "\0") != 0) {
		printf("%d\t%d\t%s\n", result[i].type, result[i].row, result[i].e);
		i++;
	}
	printf("----------------错误列表--=-------------\n");
	printf("行\t字符串\n");
	i = 0;
	while (strcmp(result[i].e, "\0") != 0) {
		if (result[i].type == 4)
			printf("%d\t%s\n", result[i].row, result[i].e);
		i++;
	}

	return NULL;
}
