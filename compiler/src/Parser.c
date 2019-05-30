#include "Parser.h"
#include "lex.h"
/*
 Token ����
 ���� ��
 ��� ִ�гɹ�����0
 ���� ȡ����һ�����������﷨��Ԫ�ڵ�

 �ýڵ��ɴʷ���Ԫ�ڵ�ת������
 ȡ�����ǰ����ǰ��㱣�浽Last��,Ԥ����UnToken���˽��
 */
int index=0;
int Token() {
	if (result[index].e!="\0") //�ʷ�δ����
	{
		Last_token = token; //���浱ǰtoken
		token = malloc(sizeof(struct Syntax_Node)); //�����µ�token,����ֵ
		token->type = result[index].type;
		//token->Varnum = Now->Varnum;
		token->number = result[index].row;
		token->Word = result[index].e;
		token->value = result[index].vaule;
		token->keeper = 0;
		token->Bro = token->Son = NULL;
		//Last = Now; //������һ���ʷ���Ԫ���
		index++; //ǰ��һ��
	}
	return 0; //��������
}

/*
 UnToken ����
 ���� ��
 ��� ִ�гɹ�����0
 ���� ����token
 ��Last_tokenȡ����һ��token,
 free����ǰtoken
 ���˴ʷ���Ԫ���
 */
int UnToken() {
	Now = Last;
	free(token);
	token = Last_token;
	return 0; //��������
}

/*
 �����﷨�����Ĵʷ���Ԫ��
 ���� �ʷ���Ԫ����ͷ
 ��� ִ�гɹ�����0
 ���� �����﷨�����Ĵʷ���Ԫ��
 ���﷨������ʼ֮ǰ����
 */
int SetCurrent(struct WordNode* now) {
	Now = now;
	Last = NULL;
	return 0; //��������
}

/*
 Program ��Ԫ�ķ�������
 ���� ��
 ��� ���ڵ�ΪProgram ������
 ������һ�����Program �﷨��Ԫ
 ����������Ĳ���ʽ��:Program-->Res Main_Func
 */
struct Syntax_Node * Program() {
	struct Syntax_Node* son1 = Res(); //����Res
	struct Syntax_Node* son2 = Main_Func(); //����Main_Func
	if (son1) //ResΪ��ʱ
		son1->Bro = son2;
	struct Syntax_Node* This = malloc(sizeof(struct Syntax_Node)); //�������ڵ�Program
	This->Bro = NULL;
	This->Son = son1 ? son1 : son2;
	This->Varnum = This->keeper = This->number = This->type = This->value = 0;
	This->Word = "Program";
	return This; //��������,��������

}
/*
 Res ��Ԫ�ķ�������
 ���� ��
 ��� ���ڵ�ΪRes ������
 ������һ����� Res �﷨��Ԫ
 ����������Ĳ���ʽ��:Res-->Re Res|null
 */
struct Syntax_Node * Res() {
	Token(); //ȡ���﷨��Ԫ
	if (!strcmp(token->Word, "#")) //�Ƿ���Res��First
			{
		struct Syntax_Node* son1 = Re(); //����Re
		struct Syntax_Node* son2 = Res(); //����Res
		son1->Bro = son2; //�������ӵ������
		struct Syntax_Node* This = malloc(sizeof(struct Syntax_Node)); //�������ڵ�Res
		This->Bro = NULL;
		This->Son = son1;
		This->Varnum = This->keeper = This->number = This->type = This->value =
				0;
		This->Word = "Res";
		return This; //��������,��������
	} else if (!strcmp(token->Word, "int")) //�Ƿ���Res��Follow
			{
		return NULL; //���ؿ���
	} else
		Error(1); //�Ȳ���ResdeFirstҲ����Followʱ,����,������ 1
	return NULL;
}
/*
 Re ��Ԫ�ķ�������
 ���� ��
 ��� ���ڵ�Ϊ Re ������
 ������һ�����Re �﷨��Ԫ
 ����������Ĳ���ʽ��:Re--># include < Vari . h >
 */
struct Syntax_Node * Re() {
	struct Syntax_Node* son1 = token; // # ֱ�ӷŵ�������
	Token();
	if (strcmp(token->Word, "include")) //�Ƿ������Re�� include
		Error(2);
	struct Syntax_Node* son2 = token; //�ŵ�����
	son1->Bro = son2; //������Ϊ�ֵܹ�ϵ
	Token();
	if (strcmp(token->Word, "<")) //�Ƿ������Re�� <
		Error(3);
	son2 = son2->Bro = token;
	Token();
	if (token->type != VARIABLE) //�Ƿ������Re�� Variable Ԫ��
		Error(4);
	son2 = son2->Bro = token;
	Token();
	if (strcmp(token->Word, ".")) //�Ƿ������Re�� .
		Error(5);
	son2 = son2->Bro = token;
	Token();
	if (strcmp(token->Word, "h")) //�Ƿ������Re�� h
		Error(6);
	son2 = son2->Bro = token;
	Token();
	if (strcmp(token->Word, ">")) //�Ƿ������Re�� >
		Error(7);
	son2 = son2->Bro = token;
	struct Syntax_Node* This = malloc(sizeof(struct Syntax_Node)); //�������ڵ� Re
	This->Bro = NULL;
	This->Son = son1;
	This->Varnum = This->keeper = This->number = This->type = This->value = 0;
	This->Word = "Re";
	return This; //��������,��������
}
/*
 Main_Func ��Ԫ�ķ�������
 ���� ��
 ��� ���ڵ�Ϊ ������
 ������һ�����Main_Func �﷨��Ԫ
 ����������Ĳ���ʽ��:Main_Func-->int main ( ) Block
 */
struct Syntax_Node * Main_Func() {
	if (strcmp(token->Word, "int")) //�Ƿ���Main_Func��First
			{
		Error(2); //���� ������ 2
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
 Block ��Ԫ�ķ�������
 ���� ��
 ��� ���ڵ�ΪBlock ������
 ������һ�����Block �﷨��Ԫ
 ����������Ĳ���ʽ��:Block-->{ Decls Stmts }
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
 Decls ��Ԫ�ķ�������
 ���� ��
 ��� ���ڵ�ΪDecls ������
 ������һ�����Decls �﷨��Ԫ
 ����������Ĳ���ʽ��:Decls-->Decl Decls|null
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
 Decl ��Ԫ�ķ�������
 ���� ��
 ��� ���ڵ�ΪDecl ������
 ������һ�����Decl �﷨��Ԫ
 ����������Ĳ���ʽ��:Decl-->Basic Vari Init;
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
 Init ��Ԫ�ķ�������
 ���� ��
 ��� ���ڵ�ΪInit ������
 ������һ�����Init �﷨��Ԫ
 ����������Ĳ���ʽ��:Init--> = Bool
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
 �ж�token�Ƿ�ΪStmt��First
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
 Stmts ��Ԫ�ķ�������
 ���� ��
 ��� ���ڵ�ΪStmts ������
 ������һ�����Stmts �﷨��Ԫ
 ����������Ĳ���ʽ��:Stmts-->Stmt Stmts|null
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
 Stmt ��Ԫ�ķ�������
 ���� ��
 ��� ���ڵ�ΪStmt ������
 ������һ�����Stmt �﷨��Ԫ
 ����������Ĳ���ʽ��:Stmt-->if(Bool)Stmt ELSE
 -->while(Bool)Stmt
 -->Block
 -->Loc=Bool;
 -->Return Bool;
 */
struct Syntax_Node * Stmt() {
	struct Syntax_Node* son1;
	if (!(strcmp(token->Word, "if"))) //if ����First
	{
		son1 = token; //'if' �ŵ�����
		Token();
		if (strcmp(token->Word, "(")) //'('�ŵ�����
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
		if (!strcmp(token->Word, "else")) //�ж��Ƿ���else���
				{
			son2 = son2->Bro = token;
			Token();
			if (!inStmtFirst(token))
				Error(15);
			son2 = son2->Bro = Stmt();
		}
	} else if (!strcmp(token->Word, "while")) //while��First
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
 Loc ��Ԫ�ķ�������
 ���� ��
 ��� ���ڵ�ΪLoc ������
 ������һ�����Loc �﷨��Ԫ
 ����������Ĳ���ʽ��:Loc-->Vari
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
 Bool ��Ԫ�ķ�������
 ���� ��
 ��� ���ڵ�ΪBool ������
 ������һ�����Bool �﷨��Ԫ
 ����������Ĳ���ʽ��:Bool-->Expr==Expr|Expr!=Expr|Expr>Expr|Expr<Expr|Expr
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
 Expr ��Ԫ�ķ�������
 ���� ��
 ��� ���ڵ�ΪExpr ������
 ������һ�����Expr �﷨��Ԫ
 ����������Ĳ���ʽ��:Expr-->Term+Expr|Term-Expr|Term
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
 Term ��Ԫ�ķ�������
 ���� ��
 ��� ���ڵ�ΪTerm ������
 ������һ�����Term �﷨��Ԫ
 ����������Ĳ���ʽ��:Term-->Unary*Term|Unary/Term|Unary
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
 Unary ��Ԫ�ķ�������
 ���� ��
 ��� ���ڵ�ΪUnary ������
 ������һ�����Unary �﷨��Ԫ
 ����������Ĳ���ʽ��:Unary-->!Factor|-Factor|Factor++|Factor--|Factor
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
 Factor ��Ԫ�ķ�������
 ���� ��
 ��� ���ڵ�ΪFactor ������
 ������һ�����Factor �﷨��Ԫ
 ����������Ĳ���ʽ��:Factor--(Bool)|Vari|Value
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
 ���������
 ���� ������
 ��� ����������0
 �޷�����ʱ ִ��exit(0)
 ���� ���ȴ�ӡ������������ش�����Ϣ
 �ٸ��ݴ�����ִ����ش�����
 �޷�����ʱ,�˳��﷨����
 ��ʱֻ��ȱ��ĳЩԪ��ʱ�Ĵ�����,
 ��Щ������������UnToken����һ��,�ٴ���һ����Ҫ�Ľ���������
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
 ��ӡ�ո�,��ӡ�﷨��ʱ����,���﷨������
 */
int PrintSpace(int Count, FILE*out) {
	int i = 0;
	for (i = 0; i < Count; i++)
		fprintf(out, " ");
	return 0;
}
/*
 ��ӡ�﷨��
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
