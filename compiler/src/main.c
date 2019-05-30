#include <stdio.h>
#include <stdlib.h>

/*
 main函数
 输入文件名
 打印输出:
 1,词法分析词串
 2,变量表
 3,语法分析的语法树
 */
int main() {
	printf("词法分析...\n");
	//struct WordHead*Head=Lexical_Analyzer(argc,argv);
	//struct WordHead * head =;
	lexer();

//	OutPutNode(Head, fopen("LEX_List.txt", "w")); //输出词串
//	OutPutVar(fopen("VAR_Table.txt", "w")); //输出变量表
	printf("词法分析完成!!!\n");
	printf("准备语法分析...\n");

//	SetCurrent(head->first);
//	printf("开始语法分析...\n");
//	struct Syntax_Node * Syntax_Head = Program();
	printf("语法分析完成!!!\n");
	printf("开始输出语法树...\n");
//	PrintSyntaxTree(Syntax_Head, 0, fopen("SyntaxTree.txt", "w"));
//	PrintSyntaxTree(Syntax_Head, 0, stdout);
	printf("\n输出语法树完成!!!\n");
	printf("分析结束!!!\n");
	return 0; //程序结束
}

