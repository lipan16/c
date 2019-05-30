/*
 * 10_1.c
 *
 *  Created on: 2019年4月10日
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

typedef struct letter   //初始字符结构体：包含文件中所有字符
{
    char ele;
    int kind;  //是否是无义字符（空格、换行、制表）
} letter;

typedef struct word   //单词结构体：通过判断是否属于五大类型
{
    char e[100];  //单词串
    int row; //位置（行）
    int id;  //单词的类型
} word;

typedef struct output   //输出结构体
{
    int order;  //序号
    char ch[100];  //单词
    int type;  //种类号
    int line;  //行
} output;

letter str0[10000];  //最多容纳10000个字符
word str1[1000];  //最多容纳1000个单词
word str2[1000];  //最多容纳1000个单词
output result[1000];  //输出最多1000个单词
output err[1000];  //输出最多1000个错误单词

int number[500];  //存放常量
int cnum=0;     //记录number的个数
char ident[500][100];  //存放标识符

//分隔符列表
char *key_s[26]= {"(",")",";","{","}","+","-","*","\n",",","\t","%","=","\\"," ","/","'","\"","|","[","]","<",">","&",".","!"};

//运算符列表
char *key_c[23]= {"(",")","{","}","+","-","*","/","=",",",";","%","\\","\"","'","|","[","]","<",">","&",".","!"};

//关键字列表
char *key_w[32]= {"auto", "break","case","char","const","continue","default","do","double","else","enum","extern","float","for","goto","if","int","long","register","return","short","signed","sizeof","static","struct","switch","typedef","union","unsigned","void","volatile","while"};

void read_file(char *name)  //将文件内容全部读入内存
{
    FILE *fp;
    char ele;
    int count0=0;  //str0中元素序号
    int count1=0;  //连续的空格、制表符数量

    if((fp=fopen(name,"r"))==NULL)
    {
        printf("open file error\n");
        exit(0);
    }

    else
        while((ele=fgetc(fp))!=EOF)
        {
            if(ele==' '||ele=='\t')  //重复的空格和制表符只计算一个读入
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

void lexdiv()  //对str0中的字符进行遍历，在key_s中id为1，不在的为2
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

void cut()  //将str0的一个个的字符分割，分成符号和字符串
{
    int i=0;
    int j=0;
    int k=0;
    int l=1;
    while(str0[i].ele!='\0')
    {
        if(str0[i].kind==2)
        {
            str1[j].id=2;  //非分隔符id暂为2
            str1[j].row=l;  //行数
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
                str1[j].id=6;   //分割str0时，符号"后的字符串的id为6
                j++;
                str1[j].e[0]=str0[i].ele;
            }
            j++;
            k=0;
        }
        i++;
    }
}

void matchkey()  //对str1中的字符进行遍历，与key_w比较来区分出关键字
{
    int i=0;
    int j;
    while(strcmp(str1[i].e,"\0")!=0)
    {
        j=0;
        while(j<32)
        {
            if(strcmp(str1[i].e,key_w[j])==0)  //在key_w中,id为2
            {
                str1[i].id=2;break;
            }
            j++;
        }
        if(j==32&&str1[i].id!=1&&str1[i].id!=6)  //不在，且不是符号和""中的字符串的字符串，id为3
        {
            str1[i].id=3;
        }
        i++;
    }
}

int matchnum(char *temp)  //检查temp字符串是否为数字
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

int matchtag(char *temp)  //检查temp字符串是否含有除了0-9，a-z，A-Z的字符
{
    int i=0;
    while(temp[i]!='\0')
    {
        if(((temp[i]>='0')&&(temp[i]<='9'))||((temp[i]>='A')&&(temp[i]<='Z'))||((temp[i]>='a')&&(temp[i]<='z')))
        {i++;continue;}
        else return 1;   //含有除了除了0-9，a-z，A-Z的之外的字符，返回1，否则返回0
    }
    return 0;
}

void classify()  //生成str2,不复制str1中的符号中的空格，制表符，换行符，并且对str1中的字符串进行初步分类复制，区分出number，string，UnknownCharacter和Identifer
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
                {}  //当str中的字符为str中的符号中的空格，制表符，换行符时，什么都不做
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
                strcpy(str2[j].e,str1[i].e);  //关键字直接复制
                str2[j].id=1;
                j++;
                break;
            }
            case 2:
            {
                icheck=matchtag(str1[i].e);   //检查字符串中是否有非字母，数字字符
                check=matchnum(str1[i].e);  //检测字符串是否为数字
                strcpy(str2[j].e,str1[i].e);
                if(icheck==0)  //不含有非字母，数字的字符
                {
                    if(check==0)
                    str2[j].id=5;  //全是数字，id为5
                    else
                    {
                        if(((str1[i].e[0]>='A')&&(str1[i].e[0]<='Z'))||((str1[i].e[0]>='a')&&(str1[i].e[0]<='z')))
                        str2[j].id=4;  //以字母开头，id为4
                        else
                        str2[j].id=0;  //未识别的字符，id为0
                    }
                }
                else
                str2[j].id=0;   //未识别的字符，id为0
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

void beresult()  //得到词法分析结果，将str2中的符号按字符种别码(借助key_c)分类,将number，和identifer记入const_number和identifer列表中
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
            case 1:  //符号的种别码识别
            {
                strcpy(result[k].ch,str2[i].e);
                while(strcmp(str2[i].e,key_c[j])!=0)
                {
                    j++;
                }
                result[k].type=6+j;  //生成符号的种别码(符号的种别码大于或等于5，可直接用其在key_c中的位置加5即可)
                j=0;
                k++;
                break;
            }
            case 2:   //关键字直接复制，id降1为type
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
            case 4:  //标志符复制，id降1为type
            {
                strcpy(result[k].ch,str2[i].e);
                result[k].type=4;
                if(x==0)  //判断标识符列表是否为空，空的话直接添加即可
                {
                    strcpy(ident[x],str2[i].e);
                    result[k].order=x;
                    x++;
                }
                else  //非空，即判断标识符是否已经存在列表中
                {
                    while(m<x)
                    {
                        if(strcmp(ident[m],str2[i].e)==0)
                        {result[k].order=m;break;}  //存在，将当前序列号给result.order
                        m++;
                    }
                    if(m==x)
                    {
                        strcpy(ident[x],str2[i].e);
                        result[k].order=x;  //不存在，添加到列表的最后
                        x++;
                    }
                    m=0;
                }
                k++;
                break;
            }
            case 5:  //数字常量复制，id降1为type
            {
                strcpy(result[k].ch,str2[i].e);
                result[k].type=5;
                numbers=atoi(str2[i].e);
                if(y==0)  //判断常量列表是否为空，空的话直接添加即可
                {
                    number[y]=numbers;
                    result[k].order=y;
                    cnum++;
                    y++;
                }
                else  //非空，即判断标识符是否已经存在列表中
                {
                    while(n<y)
                    {
                        if(number[n]==numbers)
                        {result[k].order=n;break;}  //存在，将当前序列号给result.order
                        n++;
                    }
                    if(n==y)
                    {
                        number[y]=numbers;
                        result[k].order=y;  //不存在，添加到列表的最后
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
                strcpy(result[k].ch,str2[i].e);  //未识别的字符
                result[k].type=0;
                k++;
                break;
            }
        }
        i++;
    }
}

void lex(char *name)  //词法分析扫描器主方法
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
    printf("请输入文件名：\n");
    scanf("%s",name);
    lex(name);

    printf("--------------------Token-----------------------\n");
    printf("***************单词符号种别码***************\n");
    printf("0\t未识别字符\n");
    printf("1\t分隔符\n");
    printf("2\t关键字\n");
    printf("3\t运算符\n");
    printf("4\t标识符\n");
    printf("5\t常量\n");
    printf("6\t引用串\n");
    i=0;
    while(i<23)
    {
        printf("%d\t%s\n",i+5,key_c[i]);
        i++;
    }
    i=0;
    printf("***************结果***************\n");
    printf("种别码\t字符串\n");
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
    printf("请输入文件名：");
    scanf("%s",&name);
    read_file(name);
    while(strcmp(str0[i].ele,'\0')!=0){
        printf("%c",str0[i].ele);
        i++;
    }
}*/




