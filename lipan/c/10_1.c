/*
 * 10_1.c
 *
 *  Created on: 2019��4��10��
 *      Author: asus
 */

/*
#include <stdio.h>

int main(){
	int max(int,int);
	int add(int,int);
	int min(int,int);
	int a=1,b=4;
	int (*p)(int,int);
	p=max;
	printf("%d\n",(*p)(a,b));
	return 0;
}
int max(int a,int b){
	return a>b?a:b;
}
int add(int a,int b){
	return a+b;
}
int min(int a,int b){
	return a>b?b:a;
}
*/








#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct letter   //��ʼ�ַ��ṹ�壺�����ļ��������ַ�
{
    char ele;
    int kind;  //�Ƿ��������ַ����ո񡢻��С��Ʊ�
} letter;

typedef struct word   //���ʽṹ�壺ͨ���ж��Ƿ������������
{
    char e[100];  //���ʴ�
    int row; //λ�ã��У�
    int id;  //���ʵ�����
} word;

typedef struct output   //����ṹ��
{
    int order;  //���
    char ch[100];  //����
    int type;  //�����
    int line;  //��
} output;

letter str0[10000];  //�������10000���ַ�
word str1[1000];  //�������1000������
word str2[1000];  //�������1000������
output result[1000];  //������1000������
output err[1000];  //������1000�����󵥴�

int number[500];  //��ų���
int cnum=0;     //��¼number�ĸ���
char ident[500][100];  //��ű�ʶ��

//�ָ����б�
char *key_s[26]= {"(",")",";","{","}","+","-","*","\n",",","\t","%","=","\\"," ","/","'","\"","|","[","]","<",">","&",".","!"};

//������б�
char *key_c[23]= {"(",")","{","}","+","-","*","/","=",",",";","%","\\","\"","'","|","[","]","<",">","&",".","!"};

//�ؼ����б�
char *key_w[32]= {"auto", "break","case","char","const","continue","default","do","double","else","enum","extern","float","for","goto","if","int","long","register","return","short","signed","sizeof","static","struct","switch","typedef","union","unsigned","void","volatile","while"};

void read_file(char *name)  //���ļ�����ȫ�������ڴ�
{
    FILE *fp;
    char ele;
    int count0=0;  //str0��Ԫ�����
    int count1=0;  //�����Ŀո��Ʊ������

    if((fp=fopen(name,"r"))==NULL)
    {
        printf("open file error\n");
        exit(0);
    }

    else
        while((ele=fgetc(fp))!=EOF)
        {
            if(ele==' '||ele=='\t')  //�ظ��Ŀո���Ʊ��ֻ����һ������
            {
                count1++;
                if((count1)>1)
                {
                    continue;
                }
                else
                {
                    str0[count0].ele=ele;
                    count0++;
                }
            }
            else
            {
                count1=0;
                str0[count0].ele=ele;
                count0++;
            }
        }
    fclose(fp);
}

void lexdiv()  //��str0�е��ַ����б�������key_s��idΪ1�����ڵ�Ϊ2
{
    int i=0;
    int j;
    while(str0[i].ele!='\0')
    {
        j=0;
        while(j<26)
        {
            if(str0[i].ele==*key_s[j])
            {
                str0[i].kind=1;
                break;
            }
            j++;
        }
        if(j==26)
        {
            str0[i].kind=2;
        }
        i++;
    }
}

void cut()  //��str0��һ�������ַ��ָ�ֳɷ��ź��ַ���
{
    int i=0;
    int j=0;
    int k=0;
    int l=1;
    while(str0[i].ele!='\0')
    {
        if(str0[i].kind==2)
        {
            str1[j].id=2;  //�Ƿָ���id��Ϊ2
            str1[j].row=l;  //����
            str1[j].e[k]=str0[i].ele;
            k++;
            if(str0[i+1].kind==1)
            {
                j++;
                k=0;
            }
        }
        else
        {
            if(str0[i].ele=='\n'){
                l++;
                i++;
                if(str0[i+1].kind==2){
                    str1[j].id=2;
                }
                else {
                    str1[j].id=1;
                }
            }
            else {
                str1[j].id=1;
            }
            str1[j].row=l;
            str1[j].e[0]=str0[i].ele;
            if(str0[i].ele=='"')
            {
                j++;
                k=0;
                i++;
                while(str0[i].ele!='"')
                {
                    str1[j].e[k]=str0[i].ele;
                    k++;
                    i++;
                }
                str1[j].id=6;   //�ָ�str0ʱ������"����ַ�����idΪ6
                j++;
                str1[j].e[0]=str0[i].ele;
            }
            j++;
            k=0;
        }
        i++;
    }
}

void matchkey()  //��str1�е��ַ����б�������key_w�Ƚ������ֳ��ؼ���
{
    int i=0;
    int j;
    while(strcmp(str1[i].e,"\0")!=0)
    {
        j=0;
        while(j<32)
        {
            if(strcmp(str1[i].e,key_w[j])==0)  //��key_w��,idΪ2
            {
                str1[i].id=2;break;
            }
            j++;
        }
        if(j==32&&str1[i].id!=1&&str1[i].id!=6)  //���ڣ��Ҳ��Ƿ��ź�""�е��ַ������ַ�����idΪ3
        {
            str1[i].id=3;
        }
        i++;
    }
}

int matchnum(char *temp)  //���temp�ַ����Ƿ�Ϊ����
{
    int i=0;
    while(temp[i]!='\0')
    {
        if((temp[i]<'0')||(temp[i]>'9'))
        return 1;
        i++;
    }
    return 0;
}

int matchtag(char *temp)  //���temp�ַ����Ƿ��г���0-9��a-z��A-Z���ַ�
{
    int i=0;
    while(temp[i]!='\0')
    {
        if(((temp[i]>='0')&&(temp[i]<='9'))||((temp[i]>='A')&&(temp[i]<='Z'))||((temp[i]>='a')&&(temp[i]<='z')))
        {i++;continue;}
        else return 1;   //���г��˳���0-9��a-z��A-Z��֮����ַ�������1�����򷵻�0
    }
    return 0;
}

void classify()  //����str2,������str1�еķ����еĿո��Ʊ�������з������Ҷ�str1�е��ַ������г������ิ�ƣ����ֳ�number��string��UnknownCharacter��Identifer
{
    int i=0;
    int j=0;
    int check;
    int icheck;
    int key;
    while(strcmp(str1[i].e,"\0")!=0)
    {
        key=str1[i].id;
        switch(key)
        {
            case 0:
            {
                if((strcmp(str1[i].e," ")==0)||(strcmp(str1[i].e,"\n")==0)||(strcmp(str1[i].e,"\t")==0))
                {}  //��str�е��ַ�Ϊstr�еķ����еĿո��Ʊ�������з�ʱ��ʲô������
                else
                {
                    strcpy(str2[j].e,str1[i].e);
                    str2[j].id=0;
                    j++;
                }
                break;
            }
            case 1:
            {
                strcpy(str2[j].e,str1[i].e);  //�ؼ���ֱ�Ӹ���
                str2[j].id=1;
                j++;
                break;
            }
            case 2:
            {
                icheck=matchtag(str1[i].e);   //����ַ������Ƿ��з���ĸ�������ַ�
                check=matchnum(str1[i].e);  //����ַ����Ƿ�Ϊ����
                strcpy(str2[j].e,str1[i].e);
                if(icheck==0)  //�����з���ĸ�����ֵ��ַ�
                {
                    if(check==0)
                    str2[j].id=5;  //ȫ�����֣�idΪ5
                    else
                    {
                        if(((str1[i].e[0]>='A')&&(str1[i].e[0]<='Z'))||((str1[i].e[0]>='a')&&(str1[i].e[0]<='z')))
                        str2[j].id=4;  //����ĸ��ͷ��idΪ4
                        else
                        str2[j].id=0;  //δʶ����ַ���idΪ0
                    }
                }
                else
                str2[j].id=0;   //δʶ����ַ���idΪ0
                j++;
                break;
            }
            case 4:
            {
                strcpy(str2[j].e,str1[i].e);
                str2[j].id=6;
                j++;
            }
        }
        i++;
    }
}

void beresult()  //�õ��ʷ������������str2�еķ��Ű��ַ��ֱ���(����key_c)����,��number����identifer����const_number��identifer�б���
{
    int i=0;
    int j=0;
    int k=0;
    int x=0;
    int y=0;
    int m=0;
    int n=0;
    int numbers=0;
    int key;
    while(strcmp(str2[i].e,"\0")!=0)
    {
        key=str2[i].id;
        switch(key)
        {
            case 1:  //���ŵ��ֱ���ʶ��
            {
                strcpy(result[k].ch,str2[i].e);
                while(strcmp(str2[i].e,key_c[j])!=0)
                {
                    j++;
                }
                result[k].type=6+j;  //���ɷ��ŵ��ֱ���(���ŵ��ֱ�����ڻ����5����ֱ��������key_c�е�λ�ü�5����)
                j=0;
                k++;
                break;
            }
            case 2:   //�ؼ���ֱ�Ӹ��ƣ�id��1Ϊtype
            {
                strcpy(result[k].ch,str2[i].e);
                result[i].order=2;
                while(strcmp(str2[i].e,key_w[j])!=0)
                {
                    j++;
                }
                result[i].order=j;
                j=0;
                k++;
                break;
            }
            case 4:  //��־�����ƣ�id��1Ϊtype
            {
                strcpy(result[k].ch,str2[i].e);
                result[k].type=4;
                if(x==0)  //�жϱ�ʶ���б��Ƿ�Ϊ�գ��յĻ�ֱ����Ӽ���
                {
                    strcpy(ident[x],str2[i].e);
                    result[k].order=x;
                    x++;
                }
                else  //�ǿգ����жϱ�ʶ���Ƿ��Ѿ������б���
                {
                    while(m<x)
                    {
                        if(strcmp(ident[m],str2[i].e)==0)
                        {result[k].order=m;break;}  //���ڣ�����ǰ���кŸ�result.order
                        m++;
                    }
                    if(m==x)
                    {
                        strcpy(ident[x],str2[i].e);
                        result[k].order=x;  //�����ڣ���ӵ��б�����
                        x++;
                    }
                    m=0;
                }
                k++;
                break;
            }
            case 5:  //���ֳ������ƣ�id��1Ϊtype
            {
                strcpy(result[k].ch,str2[i].e);
                result[k].type=5;
                numbers=atoi(str2[i].e);
                if(y==0)  //�жϳ����б��Ƿ�Ϊ�գ��յĻ�ֱ����Ӽ���
                {
                    number[y]=numbers;
                    result[k].order=y;
                    cnum++;
                    y++;
                }
                else  //�ǿգ����жϱ�ʶ���Ƿ��Ѿ������б���
                {
                    while(n<y)
                    {
                        if(number[n]==numbers)
                        {result[k].order=n;break;}  //���ڣ�����ǰ���кŸ�result.order
                        n++;
                    }
                    if(n==y)
                    {
                        number[y]=numbers;
                        result[k].order=y;  //�����ڣ���ӵ��б�����
                        cnum++;
                        y++;
                        n=0;
                    }
                }
                k++;
                break;
            }
            case 6:
            {
                strcpy(result[k].ch,str2[i].e);
                result[k].type=3;
                k++;
                break;
            }
            case 0:
            {
                strcpy(result[k].ch,str2[i].e);  //δʶ����ַ�
                result[k].type=0;
                k++;
                break;
            }
        }
        i++;
    }
}

void lex(char *name)  //�ʷ�����ɨ����������
{
    read_file(name);
    lexdiv();
    cut();
    matchkey();
    classify();
    beresult();
}

void main()
{
	char name[10];
    int i;
    printf("�������ļ�����\n");
    scanf("%s",name);
    lex(name);

    printf("--------------------Token-----------------------\n");
    printf("***************���ʷ����ֱ���***************\n");
    printf("0\tδʶ���ַ�\n");
    printf("1\t�ָ���\n");
    printf("2\t�ؼ���\n");
    printf("3\t�����\n");
    printf("4\t��ʶ��\n");
    printf("5\t����\n");
    printf("6\t���ô�\n");
    i=0;
    while(i<23)
    {
        printf("%d\t%s\n",i+5,key_c[i]);
        i++;
    }
    i=0;
    printf("***************���***************\n");
    printf("�ֱ���\t�ַ���\n");
    while(strcmp(result[i].ch,"\0")!=0)
    {
    	if(result[i].type!=0){
        printf("%d\t%s\n",result[i].type,result[i].ch);
        i++;}
    }
    printf("--------------------Error-----------------------\n");
    while(strcmp(result[i].ch,"\0")!=0)
    {
    	if(result[i].type==0){
        printf("%d\t%s\n",result[i].type,result[i].ch);
        i++;}
    }
}/*
void main(){
    char name[100];
    int i=0;
    printf("�������ļ�����");
    scanf("%s",&name);
    read_file(name);
    while(strcmp(str0[i].ele,'\0')!=0){
        printf("%c",str0[i].ele);
        i++;
    }
}*/




