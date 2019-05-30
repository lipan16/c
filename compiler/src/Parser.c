#include "Parser.h"
#include "lex.h"
/*
 Token 函数
 输入 无
 输出 执行成功返回0
 功能 取出下一个待分析的语法单元节点

 该节点由词法单元节点转换而来
 取出结点前将当前结点保存到Last中,预留给UnToken回退结点
 */
int index=0;
int Token() {
	if (result[index].e!="\0") //词法未结束
	{
		Last_token = token; //保存当前token
		token = malloc(sizeof(struct Syntax_Node)); //生成新的token,并赋值
		token->type = result[index].type;
		//token->Varnum = Now->Varnum;
		token->number = result[index].row;
		token->Word = result[index].e;
		token->value = result[index].vaule;
		token->keeper = 0;
		token->Bro = token->Son = NULL;
		//Last = Now; //保存上一个词法单元结点
		index++; //前进一步
	}
	return 0; //函数结束
}

/*
 UnToken 函数
 输入 无
 输出 执行成功返回0
 功能 回退token
 从Last_token取出上一个token,
 free掉当前token
 回退词法单元结点
 */
int UnToken() {
	Now = Last;
	free(token);
	token = Last_token;
	return 0; //函数结束
}

/*
 设置语法分析的词法单元链
 输入 词法单元链表头
 输出 执行成功返回0
 功能 设置语法分析的词法单元链
 在语法分析开始之前设置
 */
int SetCurrent(struct WordNode* now) {
	Now = now;
	Last = NULL;
	return 0; //函数结束
}

/*
 Program 单元的分析程序
 输入 无
 输出 根节点为Program 的子树
 该子树一起组成Program 语法单元
 本程序分析的产生式是:Program-->Res Main_Func
 */
struct Syntax_Node * Program() {
	struct Syntax_Node* son1 = Res(); //分析Res
	struct Syntax_Node* son2 = Main_Func(); //分析Main_Func
	if (son1) //Res为空时
		son1->Bro = son2;
	struct Syntax_Node* This = malloc(sizeof(struct Syntax_Node)); //创建根节点Program
	This->Bro = NULL;
	This->Son = son1 ? son1 : son2;
	This->Varnum = This->keeper = This->number = This->type = This->value = 0;
	This->Word = "Program";
	return This; //函数结束,返回子树

}
/*
 Res 单元的分析程序
 输入 无
 输出 根节点为Res 的子树
 该子树一起组成 Res 语法单元
 本程序分析的产生式是:Res-->Re Res|null
 */
struct Syntax_Node * Res() {
	Token(); //取出语法单元
	if (!strcmp(token->Word, "#")) //是否是Res的First
			{
		struct Syntax_Node* son1 = Re(); //分析Re
		struct Syntax_Node* son2 = Res(); //分析Res
		son1->Bro = son2; //子树连接到根结点
		struct Syntax_Node* This = malloc(sizeof(struct Syntax_Node)); //创建根节点Res
		This->Bro = NULL;
		This->Son = son1;
		This->Varnum = This->keeper = This->number = This->type = This->value =
				0;
		This->Word = "Res";
		return This; //分析结束,返回子树
	} else if (!strcmp(token->Word, "int")) //是否是Res的Follow
			{
		return NULL; //返回空树
	} else
		Error(1); //既不是ResdeFirst也不是Follow时,报错,错误码 1
	return NULL;
}
/*
 Re 单元的分析程序
 输入 无
 输出 根节点为 Re 的子树
 该子树一起组成Re 语法单元
 本程序分析的产生式是:Re--># include < Vari . h >
 */
struct Syntax_Node * Re() {
	struct Syntax_Node* son1 = token; // # 直接放到子树中
	Token();
	if (strcmp(token->Word, "include")) //是否是组成Re的 include
		Error(2);
	struct Syntax_Node* son2 = token; //放到子树
	son1->Bro = son2; //子树间为兄弟关系
	Token();
	if (strcmp(token->Word, "<")) //是否是组成Re的 <
		Error(3);
	son2 = son2->Bro = token;
	Token();
	if (token->type != VARIABLE) //是否是组成Re的 Variable 元素
		Error(4);
	son2 = son2->Bro = token;
	Token();
	if (strcmp(token->Word, ".")) //是否是组成Re的 .
		Error(5);
	son2 = son2->Bro = token;
	Token();
	if (strcmp(token->Word, "h")) //是否是组成Re的 h
		Error(6);
	son2 = son2->Bro = token;
	Token();
	if (strcmp(token->Word, ">")) //是否是组成Re的 >
		Error(7);
	son2 = son2->Bro = token;
	struct Syntax_Node* This = malloc(sizeof(struct Syntax_Node)); //创建根节点 Re
	This->Bro = NULL;
	This->Son = son1;
	This->Varnum = This->keeper = This->number = This->type = This->value = 0;
	This->Word = "Re";
	return This; //分析结束,返回子树
}
/*
 Main_Func 单元的分析程序
 输入 无
 输出 根节点为 的子树
 该子树一起组成Main_Func 语法单元
 本程序分析的产生式是:Main_Func-->int main ( ) Block
 */
struct Syntax_Node * Main_Func() {
	if (strcmp(token->Word, "int")) //是否是Main_Func的First
			{
		Error(2); //报错 错误码 2
		return NULL;
	} else {
		struct Syntax_Node* son1 = token;
		Token();
		if (strcmp(token->Word, "main"))
			Error(8);
		struct Syntax_Node* son2 = token;
		son1->Bro = son2;
		Token();
		if (strcmp(token->Word, "("))
			Error(9);
		son2 = son2->Bro = token;
		Token();
		if (strcmp(token->Word, ")"))
			Error(10);
		son2 = son2->Bro = token;
		Token();
		if (strcmp(token->Word, "{"))
			Error(11);
		son2 = son2->Bro = Block();
		struct Syntax_Node* This = malloc(sizeof(struct Syntax_Node));
		This->Bro = NULL;
		This->Son = son1;
		This->Varnum = This->keeper = This->number = This->type = This->value =
				0;
		This->Word = "Main_Func";
		return This;
	}
}
/*
 Block 单元的分析程序
 输入 无
 输出 根节点为Block 的子树
 该子树一起组成Block 语法单元
 本程序分析的产生式是:Block-->{ Decls Stmts }
 */
struct Syntax_Node * Block() {
	struct Syntax_Node* son1 = token;
	struct Syntax_Node* son2 = NULL;
	Token();
	if (token->type == KEY && token->Varnum >= 0 && token->Varnum <= 8) {
		son2 = Decls();
		son1->Bro = son2;
		son2 = son2->Bro = Stmts();
	} else
		son1->Bro = son2 = Stmts();
	if (strcmp(token->Word, "}"))
		Error(12);
	if (son2)
		son2 = son2->Bro = token;
	else
		son2 = token;
	Token();
	struct Syntax_Node* This = malloc(sizeof(struct Syntax_Node));
	This->Bro = NULL;
	This->Son = son1;
	This->Varnum = This->keeper = This->number = This->type = This->value = 0;
	This->Word = "Block";
	return This;
}
/*
 Decls 单元的分析程序
 输入 无
 输出 根节点为Decls 的子树
 该子树一起组成Decls 语法单元
 本程序分析的产生式是:Decls-->Decl Decls|null
 */
struct Syntax_Node * Decls() {
	struct Syntax_Node* son1 = Decl();
	struct Syntax_Node* son2 = NULL;
	if (son1) {
		son2 = Decls();
		son1->Bro = son2;
	}
	struct Syntax_Node* This = malloc(sizeof(struct Syntax_Node));
	This->Bro = NULL;
	This->Son = son1;
	This->Varnum = This->keeper = This->number = This->type = This->value = 0;
	This->Word = "Decls";

	return This;

}
/*
 Decl 单元的分析程序
 输入 无
 输出 根节点为Decl 的子树
 该子树一起组成Decl 语法单元
 本程序分析的产生式是:Decl-->Basic Vari Init;
 */
struct Syntax_Node * Decl() {
	if (token->type == KEY && token->Varnum >= 0 && token->Varnum <= 8) {
		struct Syntax_Node* son1 = token;
		Token();
		if (token->type != VARIABLE)
			Error(13);
		struct Syntax_Node* son2 = token;
		son1->Bro = son2;
		Token();
		if (!strcmp(token->Word, "="))
			son2 = son2->Bro = Init();
		if (strcmp(token->Word, ";"))
			Error(14);
		son2 = son2->Bro = token;
		Token();
		struct Syntax_Node* This = malloc(sizeof(struct Syntax_Node));
		This->Bro = NULL;
		This->Son = son1;
		This->Varnum = This->keeper = This->number = This->type = This->value =
				0;
		This->Word = "Decl";
		return This;
	} else
		return NULL;
}
/*
 Init 单元的分析程序
 输入 无
 输出 根节点为Init 的子树
 该子树一起组成Init 语法单元
 本程序分析的产生式是:Init--> = Bool
 */
struct Syntax_Node * Init() {
	struct Syntax_Node* son1 = token;
	son1->Bro = Bool();
	Token();
	struct Syntax_Node* This = malloc(sizeof(struct Syntax_Node));
	This->Bro = NULL;
	This->Son = son1;
	This->Varnum = This->keeper = This->number = This->type = This->value = 0;
	This->Word = "Init";
	return This;
}
/*
 判断token是否为Stmt的First
 */
int inStmtFirst(struct Syntax_Node *token) {
	char* Word = token->Word;
	if (!(strcmp(Word, "if") && strcmp(Word, "while") && strcmp(Word, "{")
			&& strcmp(Word, "return")))
		return 1;
	else
		return token->type == VARIABLE;
}
/*
 Stmts 单元的分析程序
 输入 无
 输出 根节点为Stmts 的子树
 该子树一起组成Stmts 语法单元
 本程序分析的产生式是:Stmts-->Stmt Stmts|null
 */
struct Syntax_Node * Stmts() {
	if (inStmtFirst(token)) {
		struct Syntax_Node* son1 = Stmt();
		struct Syntax_Node* son2 = Stmts();
		son1->Bro = son2;
		struct Syntax_Node* This = malloc(sizeof(struct Syntax_Node));
		This->Bro = NULL;
		This->Son = son1;
		This->Varnum = This->keeper = This->number = This->type = This->value =
				0;
		This->Word = "Stmts";
		return This;
	} else
		return NULL;
}
/*
 Stmt 单元的分析程序
 输入 无
 输出 根节点为Stmt 的子树
 该子树一起组成Stmt 语法单元
 本程序分析的产生式是:Stmt-->if(Bool)Stmt ELSE
 -->while(Bool)Stmt
 -->Block
 -->Loc=Bool;
 -->Return Bool;
 */
struct Syntax_Node * Stmt() {
	struct Syntax_Node* son1;
	if (!(strcmp(token->Word, "if"))) //if 语句的First
	{
		son1 = token; //'if' 放到子树
		Token();
		if (strcmp(token->Word, "(")) //'('放到子树
			Error(16);
		struct Syntax_Node* son2 = token;
		son1->Bro = son2;
		son2 = son2->Bro = Bool();
		Token();
		if (strcmp(token->Word, ")"))
			Error(17);
		son2 = son2->Bro = token;
		Token();
		if (!inStmtFirst(token))
			Error(15);
		son2 = son2->Bro = Stmt();
		if (!strcmp(token->Word, "else")) //判断是否有else语句
				{
			son2 = son2->Bro = token;
			Token();
			if (!inStmtFirst(token))
				Error(15);
			son2 = son2->Bro = Stmt();
		}
	} else if (!strcmp(token->Word, "while")) //while的First
			{
		son1 = token;
		Token();
		if (strcmp(token->Word, "("))
			Error(16);
		struct Syntax_Node* son2 = token;
		son1->Bro = son2;
		son2 = son2->Bro = Bool();
		Token();
		if (strcmp(token->Word, ")"))
			Error(17);
		son2 = son2->Bro = token;
		Token();
		if (!inStmtFirst(token))
			Error(15);
		son2 = son2->Bro = Stmt();
	} else if (!strcmp(token->Word, "{")) {
		son1 = Block();
	} else if (token->type == VARIABLE) {
		son1 = Loc();
		if (strcmp(token->Word, "="))
			Error(18);
		struct Syntax_Node* son2 = token;
		son1->Bro = son2;

		son2 = son2->Bro = Bool();
		Token();
		if (strcmp(token->Word, ";"))
			Error(14);
		son2 = son2->Bro = token;
		Token();
	} else if (!strcmp(token->Word, "return")) {
		son1 = token;
		struct Syntax_Node* son2 = Bool();
		son1->Bro = son2;
		Token();
		if (strcmp(token->Word, ";"))
			Error(14);
		son2 = son2->Bro = token;
		Token();
	} else
		Error(15);
	struct Syntax_Node* This = malloc(sizeof(struct Syntax_Node));
	This->Bro = NULL;
	This->Son = son1;
	This->Varnum = This->keeper = This->number = This->type = This->value = 0;
	This->Word = "Stmt";
	return This;
}
/*
 Loc 单元的分析程序
 输入 无
 输出 根节点为Loc 的子树
 该子树一起组成Loc 语法单元
 本程序分析的产生式是:Loc-->Vari
 */
struct Syntax_Node * Loc() {
	struct Syntax_Node* son1 = token;
	Token();
	struct Syntax_Node* This = malloc(sizeof(struct Syntax_Node));
	This->Bro = NULL;
	This->Son = son1;
	This->Varnum = This->keeper = This->number = This->type = This->value = 0;
	This->Word = "Loc";
	return This;
}
/*
 Bool 单元的分析程序
 输入 无
 输出 根节点为Bool 的子树
 该子树一起组成Bool 语法单元
 本程序分析的产生式是:Bool-->Expr==Expr|Expr!=Expr|Expr>Expr|Expr<Expr|Expr
 */
struct Syntax_Node * Bool() {
	struct Syntax_Node* son1 = Expr();
	if (!(strcmp(token->Word, "==") && strcmp(token->Word, "!=")
			&& strcmp(token->Word, ">") && strcmp(token->Word, "<"))) {
		struct Syntax_Node* son2 = token;
		son1->Bro = son2;
		son2 = son2->Bro = Expr();
	}
	struct Syntax_Node* This = malloc(sizeof(struct Syntax_Node));
	This->Bro = NULL;
	This->Son = son1;
	This->Varnum = This->keeper = This->number = This->type = This->value = 0;
	This->Word = "Bool";
	return This;
}
/*
 Expr 单元的分析程序
 输入 无
 输出 根节点为Expr 的子树
 该子树一起组成Expr 语法单元
 本程序分析的产生式是:Expr-->Term+Expr|Term-Expr|Term
 */
struct Syntax_Node * Expr() {
	struct Syntax_Node* son1 = Term();
	Token();
	if (!(strcmp(token->Word, "+") && strcmp(token->Word, "-"))) {
		struct Syntax_Node* son2 = token;
		son1->Bro = son2;
		son2 = son2->Bro = Expr();
	} else
		UnToken();
	struct Syntax_Node* This = malloc(sizeof(struct Syntax_Node));
	This->Bro = NULL;
	This->Son = son1;
	This->Varnum = This->keeper = This->number = This->type = This->value = 0;
	This->Word = "Expr";
	return This;
}
/*
 Term 单元的分析程序
 输入 无
 输出 根节点为Term 的子树
 该子树一起组成Term 语法单元
 本程序分析的产生式是:Term-->Unary*Term|Unary/Term|Unary
 */
struct Syntax_Node * Term() {
	struct Syntax_Node* son1 = Unary();
	Token();
	if (!(strcmp(token->Word, "*") && strcmp(token->Word, "/"))) {
		struct Syntax_Node*son2 = token;
		son1->Bro = son2;
		son2 = son2->Bro = Term();
	} else
		UnToken();
	struct Syntax_Node* This = malloc(sizeof(struct Syntax_Node));
	This->Bro = NULL;
	This->Son = son1;
	This->Varnum = This->keeper = This->number = This->type = This->value = 0;
	This->Word = "Term";
	return This;
}
/*
 Unary 单元的分析程序
 输入 无
 输出 根节点为Unary 的子树
 该子树一起组成Unary 语法单元
 本程序分析的产生式是:Unary-->!Factor|-Factor|Factor++|Factor--|Factor
 */
struct Syntax_Node * Unary() {
	Token();
	struct Syntax_Node* son1 = NULL;
	if (!(strcmp(token->Word, "!") && strcmp(token->Word, "-"))) {
		son1 = token;
		Token();
		if (!strcmp(token->Word,
				"(")||token->type==VARIABLE||token->type==VALUE) {
			son1->Bro = Factor();
		} else
			Error(19);
	} else if (!strcmp(token->Word,
			"(")||token->type==VARIABLE||token->type==VALUE) {
		son1 = Factor();
		Token();
		if (!strcmp(token->Word, "++") || !strcmp(token->Word, "--"))
			son1->Bro = token;
		else
			UnToken();
	}
	struct Syntax_Node* This = malloc(sizeof(struct Syntax_Node));
	This->Bro = NULL;
	This->Son = son1;
	This->Varnum = This->keeper = This->number = This->type = This->value = 0;
	This->Word = "Unary";
	return This;
}
/*
 Factor 单元的分析程序
 输入 无
 输出 根节点为Factor 的子树
 该子树一起组成Factor 语法单元
 本程序分析的产生式是:Factor--(Bool)|Vari|Value
 */
struct Syntax_Node * Factor() {
	struct Syntax_Node* son1;
	if (!(strcmp(token->Word, "("))) {
		son1 = token;
		struct Syntax_Node* son2 = Bool();
		son1->Bro = son2;
		Token();
		if (strcmp(token->Word, ")"))
			Error(20);
		son2 = son2->Bro = token;
	} else
		son1 = token;
	struct Syntax_Node* This = malloc(sizeof(struct Syntax_Node));
	This->Bro = NULL;
	This->Son = son1;
	This->Varnum = This->keeper = This->number = This->type = This->value = 0;
	This->Word = "Factor";
	return This;
}
/*
 错误处理程序
 输入 错误码
 输出 处理完成输出0
 无法处理时 执行exit(0)
 功能 首先打印输出错误码和相关错误信息
 再根据错误码执行相关错误处理
 无法处理时,退出语法分析
 暂时只有缺少某些元素时的错误处理,
 这些处理方法都是先UnToken回退一步,再创建一个需要的结点继续分析
 */
int Error(int E_code) {
	printf("ERROR:\tCode:%d %s\n", E_code, Error_Messages[E_code]);
	UnToken();
	token = malloc(sizeof(struct Syntax_Node));

	token->Varnum = -1;
	token->number = -1;
	token->value = 0;
	token->keeper = 0;
	token->Bro = token->Son = NULL;
	switch (E_code) {
	case 0:
		exit(0);
	case 1:
		token->type = KEY;
		token->Word = "int\0";
		break;
	case 2:
		token->type = VARIABLE;
		token->Word = "include\0";
		break;
	case 3:
		token->type = OPERATOR;
		token->Word = "<\0";
		break;
	case 4:
		token->type = VARIABLE;
		token->Word = "Variable\0";
		break;
	case 5:
		token->type = SPARATOR;
		token->Word = ".\0";
		break;
	case 6:
		token->type = VARIABLE;
		token->Word = "h\0";
		break;
	case 7:
		token->type = SPARATOR;
		token->Word = ">\0";
		break;
	case 8:
		token->type = VARIABLE;
		token->Word = "main\0";
		break;
	case 9:
		token->type = SPARATOR;
		token->Word = "(\0";
		break;
	case 10:
		token->type = SPARATOR;
		token->Word = ")\0";
		break;
	case 11:
		token->type = SPARATOR;
		token->Word = "{\0";
		break;
	case 12:
		token->type = SPARATOR;
		token->Word = "}\0";
		break;
	case 13:
		token->type = VARIABLE;
		token->Word = "Vari\0";
		break;
	case 14:
		token->type = SPARATOR;
		token->Word = ";\0";
		break;
	case 15:
		Token();
		Token();
		break;
	case 16:
		token->type = SPARATOR;
		token->Word = "(\0";
		break;
	case 17:
		token->type = SPARATOR;
		token->Word = ")\0";
		break;
	case 18:
		token->type = KEY;
		token->Word = "=\0";
		break;
	case 19:
		token->type = VALUE;
		token->Word = "0\0";
		break;
	case 20:
		token->type = SPARATOR;
		token->Word = ")\0";
		break;
	}
	return 0;
}
/*
 打印空格,打印语法树时调用,让语法树对齐
 */
int PrintSpace(int Count, FILE*out) {
	int i = 0;
	for (i = 0; i < Count; i++)
		fprintf(out, " ");
	return 0;
}
/*
 打印语法树
 */
int PrintSyntaxTree(struct Syntax_Node* Head, int Count, FILE*out) {
	if (Head) {
		int i = 0;
		i = fprintf(out, "<%s>", Head->Word);
		if (Head->Bro)
			fprintf(out, "-");
		PrintSyntaxTree(Head->Bro, Count + i + 2, out);
		if (Head->Son) {
			fprintf(out, "\n");
			PrintSpace(Count + 3, out);
			fprintf(out, "|");
			PrintSyntaxTree(Head->Son, Count, out);
		}
	}
	return 0;
}
