#include <stdio.h>
#include <stdlib.h>

/*
 main����
 �����ļ���
 ��ӡ���:
 1,�ʷ������ʴ�
 2,������
 3,�﷨�������﷨��
 */
int main() {
	printf("�ʷ�����...\n");
	//struct WordHead*Head=Lexical_Analyzer(argc,argv);
	//struct WordHead * head =;
	lexer();

//	OutPutNode(Head, fopen("LEX_List.txt", "w")); //����ʴ�
//	OutPutVar(fopen("VAR_Table.txt", "w")); //���������
	printf("�ʷ��������!!!\n");
	printf("׼���﷨����...\n");

//	SetCurrent(head->first);
//	printf("��ʼ�﷨����...\n");
//	struct Syntax_Node * Syntax_Head = Program();
	printf("�﷨�������!!!\n");
	printf("��ʼ����﷨��...\n");
//	PrintSyntaxTree(Syntax_Head, 0, fopen("SyntaxTree.txt", "w"));
//	PrintSyntaxTree(Syntax_Head, 0, stdout);
	printf("\n����﷨�����!!!\n");
	printf("��������!!!\n");
	return 0; //�������
}

