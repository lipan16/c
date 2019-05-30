#include "Table.h"
#include<string.h>
#include<malloc.h>

/*
Table.c
表操作函数定义文件

*/
/*
本文件包含编译过程相关表操作函数的定义
*/

/*
查找变量表
输入 单词结点
输出 单词在变量表中的位置
        1,输出序号 int 类型
        2,不在表中时,添加到表中再返回序号
*/
int SearchVar(struct WordNode* node)
{
    struct VariableNode* varnode = VarHead.first;

    if (varnode == NULL)
    {
        struct VariableNode* NewNode = malloc(sizeof(struct VariableNode));
        VarHead.last = VarHead.first = NewNode;
        VarHead.Count = 1;
        NewNode->num = 0;
        NewNode->next = NULL;
        NewNode->Type = node->type;
        NewNode->name = node->Word;
        NewNode->Value = node->value;
        return NewNode->num;
    }

    while (varnode != NULL)
    {
        if (node->type == varnode->Type && !strcmp(node->Word, varnode->name))
        {
            return varnode->num;
        }

        else
        {
            varnode = varnode->next;
            continue;
        }
    }

    struct VariableNode* NewNode = malloc(sizeof(struct VariableNode));

    varnode = VarHead.last;

    VarHead.last = varnode->next = NewNode;

    VarHead.Count++;

    NewNode->num = varnode->num + 1;

    NewNode->next = NULL;

    NewNode->Type = node->type;

    NewNode->name = node->Word;

    NewNode->Value = node->value;

    return NewNode->num;
}
/*
查找表(关键字,分隔符,运算符)
输入 单词结点 查找表
输出 单词在表中的序号
        1,输出序号 int 类型
        2,不在表中时,返回-1
*/
int Search(struct WordNode* node, int Type)
{
    char** Table;
    int length = TableLength[Type];
    int i = 0;

    if (Type == KEY)
    {
        Table = Key;
    }

    else if (Type == SPARATOR)
    {
        Table = Sparator;
    }

    else if (Type == OPERATOR)
    {
        Table = Operator;
    }

    else
    {
        return -1;
    }

    for (i = 0; i < length; i++)
    {
        if (strcmp(Table[i], node->Word))
        {
            continue;
        }

        else
        {
            return i;
        }
    }

    return -1;
}
/*
打印输出变量表
输入 无
输出 打印的变量数
*/
int OutPutVar(FILE* out)
{
    struct VariableNode * node = VarHead.first;
    int i=0;
    while (node != NULL)
    {
        fprintf(out,"%d %d %f %s\n", node->Type, node->num, node->Value, node->name);
        node = node->next;
        i++;
    }

    return i;
}

