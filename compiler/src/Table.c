#include "Table.h"
#include<string.h>
#include<malloc.h>

/*
Table.c
��������������ļ�

*/
/*
���ļ��������������ر���������Ķ���
*/

/*
���ұ�����
���� ���ʽ��
��� �����ڱ������е�λ��
        1,������ int ����
        2,���ڱ���ʱ,��ӵ������ٷ������
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
���ұ�(�ؼ���,�ָ���,�����)
���� ���ʽ�� ���ұ�
��� �����ڱ��е����
        1,������ int ����
        2,���ڱ���ʱ,����-1
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
��ӡ���������
���� ��
��� ��ӡ�ı�����
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

