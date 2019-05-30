#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lex.h"


void read_file(char *name){  //���ļ�д��str0����
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

void traversal_keys() { //��str0�е��ַ����б�������key_s�е�Ԫ�������ַ��Ƿ�Ϊ�ָ���

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

void cut_word()  //��str0���ַ��ָ�ɷָ������ַ������������ַ�������������
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
				str1[j].id = 1;   //�ָ�str0ʱ���Ƿָ���idΪ1
				j++;
				k = 0;
			}
		} else if (str0[i].e == '\n') {
			l++;
		} else {
			str1[j].e[0] = str0[i].e;
			str1[j].row = l;
			str1[j].id = 0;      //�ָ�str0ʱ���ָ���idΪ0
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
				str1[j].id = 4;   //�ָ�str0ʱ������""�ڵ��ַ�����idΪ4
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

void traversal_keyw()  //��str1�е��ַ����б�������key_w�Ƚ������ֳ��ؼ���
{
	int i = 0;
	int j;
	while (strcmp(str1[i].e, "\0") != 0) {
		j = 0;
		while (j < 32) {
			if (strcmp(str1[i].e, key_w[j]) == 0)  //��key_w��,idΪ1
					{
				str1[i].id = 1;
				break;
			}
			j++;
		}
		if (j == 32 && str1[i].id != 0 && str1[i].id != 4) //����key_w�У��Ҳ��Ƿָ�����""�ڵ��ַ������ַ�����idΪ2
				{
			str1[i].id = 2;
		}
		i++;
	}
}

int number_check(char *temp)  //���temp�ַ����Ƿ�Ϊ����
{
	int i = 0;
	while (temp[i] != '\0') {
		if ((temp[i] < '0') || (temp[i] > '9'))
			return 1;
		i++;
	}
	return 0;
}

int id_check(char *temp)  //���temp�ַ����Ƿ��г���0-9��a-z��A-Z���ַ�
{
	int i = 0;
	while (temp[i] != '\0') {
		if (((temp[i] >= '0') && (temp[i] <= '9'))
				|| ((temp[i] >= 'A') && (temp[i] <= 'Z'))
				|| ((temp[i] >= 'a') && (temp[i] <= 'z')) || temp[i] == '_') {
			i++;
			continue;
		} else
			return 1;   //���г���0-9��a-z��A-Z��֮����ַ�������1�����򷵻�0
	}
	return 0;
}

void classify() //����str2,������str1�еķ����еĿո���Ʊ�������Ҷ�str1�е��ַ������г������ิ�ƣ����ֳ�number��string��UnknownCharacter��Identifer
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
			}  //��str1�е��ַ�Ϊstr1�еķ����еĿո��Ʊ�����߻��з�ʱ��ʲô������
			else {
				strcpy(str2[j].e, str1[i].e);
				str2[j].id = 0;
				str2[j].row = str1[j].row;
				j++;
			}
			break;
		}
		case 1: {
			strcpy(str2[j].e, str1[i].e);  //�ؼ���ֱ�Ӹ���
			str2[j].id = 1;
			str2[j].row = str1[j].row;
			j++;
			break;
		}
		case 2: {
			icheck = id_check(str1[i].e);   //����ַ������Ƿ��з���ĸ�������ַ�
			check = number_check(str1[i].e);  //����ַ����Ƿ�Ϊ����
			strcpy(str2[j].e, str1[i].e);
			str2[j].row = str1[j].row;
			if (icheck == 0)  //�����з���ĸ�����ֵ��ַ�
					{
				if (check == 0)
					str2[j].id = 3;  //ȫ�����֣�idΪ3
				else {
					if (((str1[i].e[0] >= 'A') && (str1[i].e[0] <= 'Z'))
							|| ((str1[i].e[0] >= 'a') && (str1[i].e[0] <= 'z')))
						str2[j].id = 2;  //����ĸ��ͷ��idΪ2
					else
						str2[j].id = 5;  //δʶ����ַ���idΪ5
				}
			} else
				str2[j].id = 5;   //δʶ����ַ���idΪ5
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

void result_build() //�õ��ʷ������������str2�еķ��Ű��ַ��ֱ���(����key_c)����,��number����identifer����const_number��identifer�б���
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
		case 0:  //���ŵ��ֱ���ʶ��
		{
			strcpy(result[k].e, str2[i].e);
			result[k].row = str2[i].row;
			while (strcmp(str2[i].e, key_c[j]) != 0) {
				j++;
			}
			result[k].type = 5 + j; //���ɷ��ŵ��ֱ���(���ŵ��ֱ�����ڻ����5����ֱ��������key_c�е�λ�ü�5����)
			j = 0;
			k++;
			break;
		}
		case 1:   //�ؼ���ֱ�Ӹ��ƣ�id��1Ϊtype
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
		case 2:  //��־�����ƣ�id��1Ϊtype
		{
			strcpy(result[k].e, str2[i].e);
			result[k].row = str2[i].row;
			result[k].type = 1;
			if (x == 0)  //�жϱ�ʶ���б��Ƿ�Ϊ�գ��յĻ�ֱ����Ӽ���
					{
				strcpy(identifer[x].e, str2[i].e);
				identifer[x].row = str2[i].row;
				result[k].order = x;
				x++;
			} else  //�ǿգ����жϱ�ʶ���Ƿ��Ѿ������б���
			{
				while (m < x) {
					if (strcmp(identifer[m].e, str2[i].e) == 0) {
						result[k].order = m;    //���ڣ�����ǰ���кŸ�result.order
						break;
					}
					m++;
				}
				if (m == x) {
					strcpy(identifer[x].e, str2[i].e);
					identifer[x].row = str2[i].row;
					result[k].order = x;  //�����ڣ���ӵ��б�����
					x++;
				}
				m = 0;
			}
			k++;
			break;
		}
		case 3:  //���ֳ������ƣ�id��1Ϊtype
		{
			numbers = atoi(str2[i].e);
			//strcpy(result[k].e, str2[i].e);
			result[k].vaule=numbers;
			result[k].row = str2[i].row;
			result[k].type = 2;
			if (y == 0){  //�жϳ����б��Ƿ�Ϊ�գ��յĻ�ֱ����Ӽ���
				const_number[y].e = numbers;
				const_number[y].row = str2[i].row;
				result[k].order = y;
				count_number++;
				y++;
			} else {  //�ǿգ����жϱ�ʶ���Ƿ��Ѿ������б���
				while (n < y) {
					if (const_number[n].e == numbers) {
						result[k].order = n;    //���ڣ�����ǰ���кŸ�result.order
						break;
					}
					n++;
				}
				if (n == y) {
					const_number[y].e = numbers;
					const_number[y].row = str2[i].row;
					result[k].order = y;  //�����ڣ���ӵ��б�����
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
			strcpy(result[k].e, str2[i].e);  //δʶ����ַ�
			result[k].row = str2[i].row;
			result[k].type = 4;
			k++;
			break;
		}
		}
		i++;
	}
}

void save_file()  //���浥���ֱ��룬��ʶ���б������б�����н�����ļ�
{
	int i;

	FILE * fp;

	if ((fp = fopen("�����ֱ���.txt", "w")) == NULL) {
		printf("write fie error\n");
		exit(0);
	}
	fprintf(fp, "---------------�����ֱ���---------------\n");
	fprintf(fp, "0\t�ؼ���\n");
	fprintf(fp, "1\t��ʶ��\n");
	fprintf(fp, "2\t����\n");
	fprintf(fp, "3\t��������\n");
	fprintf(fp, "4\tδʶ��\n");
	i = 0;
	while (i < 23) {
		fprintf(fp, "%d\t%s\n", i + 5, key_c[i]);
		i++;
	}
	fclose(fp);

	if ((fp = fopen("��־���б�.txt", "w")) == NULL) {
		printf("write fie error\n");
		exit(0);
	}
	fprintf(fp, "---------------��־���б�---------------\n");
	fprintf(fp, "���\t��\t��ʶ��\n");
	i = 0;
	while (strcmp(identifer[i].e, "\0") != 0) {
		fprintf(fp, "%d\t%d\t%s\n", i, identifer[i].row, identifer[i].e);
		i++;
	}
	fclose(fp);

	if ((fp = fopen("�����б�.txt", "w")) == NULL) {
		printf("write fie error\n");
		exit(0);
	}
	fprintf(fp, "---------------�����б�---------------\n");
	fprintf(fp, "���\t��\t����\n");
	i = 0;
	while (i < count_number) {
		fprintf(fp, "%d\t%d\t%d\n", i, const_number[i].row, const_number[i].e);
		i++;
	}
	fclose(fp);

	i = 0;
	if ((fp = fopen("���.txt", "w")) == NULL) {
		printf("write fie error\n");
		exit(0);
	}
	fprintf(fp, "---------------���---------------\n");
	fprintf(fp, "�ֱ���\t��\t�ַ���\n");
	while (strcmp(result[i].e, "\0") != 0) {
		fprintf(fp, "%d\t%d\t%s\n", result[i].type, result[i].row, result[i].e);
		i++;
	}
	fclose(fp);
}

void lex_scanner(char *name)  //�ʷ�����ɨ����������
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
//	struct WordHead* Head = malloc(sizeof(struct WordHead)); //�ʴ�����ͷ
	printf("��������Ҫ���дʷ��������ļ�����\n");
	scanf("%s", name);


	lex_scanner(name);

	printf("---------------�����ֱ���---------------\n");
	printf("0\t�ؼ���\n");
	printf("1\t��ʶ��\n");
	printf("2\t����\n");
	printf("3\t��������\n");
	printf("4\tδʶ��\n");
	i = 0;
	while (i < 23) {
		printf("%d\t%s\n", i + 5, key_c[i]);
		i++;
	}
	printf("---------------��ʶ���б�---------------\n");
	printf("���\t��\t��ʶ��\n");
	i = 0;
	while (strcmp(identifer[i].e, "\0") != 0) {
		printf("%d\t%d\t%s\n", i, identifer[i].row, identifer[i].e);
		i++;
	}
	printf("----------------�����б�----------------\n");
	printf("���\t��\t����\n");
	i = 0;
	while (i < count_number) {
		printf("%d\t%d\t%d\n", i, const_number[i].row, const_number[i].e);
		i++;
	}


	i = 0;
	printf("------------------���------------------\n");
	printf("�ֱ���\t��\t�ַ���\n");
	while (strcmp(result[i].e, "\0") != 0) {
		printf("%d\t%d\t%s\n", result[i].type, result[i].row, result[i].e);
		i++;
	}
	printf("----------------�����б�--=-------------\n");
	printf("��\t�ַ���\n");
	i = 0;
	while (strcmp(result[i].e, "\0") != 0) {
		if (result[i].type == 4)
			printf("%d\t%s\n", result[i].row, result[i].e);
		i++;
	}

	return NULL;
}
