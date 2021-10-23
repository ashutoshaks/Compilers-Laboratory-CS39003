%{
    /**
    * Vanshita Garg | 19CS10064
    * Ashutosh Kumar Singh | 19CS30008
    * Compilers Laboratory
    * Assignment 5
    *
    * Bison specifications
    */

    #include <iostream>
    #include <sstream>
    #include "ass5_19CS10064_19CS30008_translator.h"
    using namespace std;

    extern int yylex();
    void yyerror(string s);
    extern char* yytext;
    extern int yylineno;
    extern string varType;
%}

%union {
    int intval;
    char* charval;
    int instr;
    char unaryOp;
    int numParams;
    expression* expr;
    statement* stmt;
    symbol* symp;
    symbolType* symType;
    Array* arr;
}

%token AUTO BREAK CASE CHAR CONST CONTINUE DEFAULT DO DOUBLE ELSE ENUM EXTERN FLOAT FOR GOTO IF INLINE INT LONG REGISTER RESTRICT RETURN SHORT SIGNED SIZEOF STATIC STRUCT SWITCH TYPEDEF UNION UNSIGNED VOID VOLATILE WHILE BOOL COMPLEX IMAGINARY

%token SQUARE_BRACE_OPEN SQUARE_BRACE_CLOSE PARENTHESIS_OPEN PARENTHESIS_CLOSE CURLY_BRACE_OPEN CURLY_BRACE_CLOSE 
%token DOT ARROW INCREMENT DECREMENT BITWISE_AND MULTIPLY ADD SUBTRACT BITWISE_NOR NOT DIVIDE MODULO 
%token LSHIFT RSHIFT LESS_THAN GREATER_THAN LESS_THAN_EQUAL GREATER_THAN_EQUAL EQUAL NOT_EQUAL BITWISE_XOR BITWISE_OR 
%token LOGICAL_AND LOGICAL_OR QUESTION_MARK COLON SEMICOLON ELLIPSIS 
%token ASSIGN MULTIPLY_ASSIGN DIVIDE_ASSIGN MODULO_ASSIGN ADD_ASSIGN SUBTRACT_ASSIGN LSHIFT_ASSIGN RSHIFT_ASSIGN AND_ASSIGN XOR_ASSIGN OR_ASSIGN COMMA HASH

%token <symp> IDENTIFIER
%token <intval> INTEGER_CONSTANT
%token <charval> FLOATING_CONSTANT
%token <charval> CHAR_CONSTANT
%token <charval> STRING_LITERAL

%start translation_unit

// to remove dangling else problem
%right THEN ELSE

%type <unaryOp> unary_operator

%type <numParams> argument_expression_list argument_expression_list_opt

%type <expr> 
        expression
        primary_expression 
        multiplicative_expression
        additive_expression
        shift_expression
        relational_expression
        equality_expression
        and_expression
        exclusive_or_expression
        inclusive_or_expression
        logical_and_expression
        logical_or_expression
        conditional_expression
        assignment_expression
        expression_statement

%type <stmt>
        statement
        compound_statement
        loop_statement
        selection_statement
        iteration_statement
        labeled_statement 
        jump_statement
        block_item
        block_item_list
        block_item_list_opt

%type <symType> pointer

%type <symp> constant initializer
%type <symp> direct_declarator init_declarator declarator

%type <arr> postfix_expression unary_expression cast_expression

%type <instr> M
%type <stmt> N

%%

M: %empty
        {
            $$ = nextinstr();
        }
        ;

N: %empty
        {
            $$ = new statement();
            $$->nextlist = makelist(nextinstr());
            emit("goto", "");
        }
        ;

X: %empty
        {
            string newST = currentST->name + "." + blockName + "$" + to_string(STCount++);
            symbol* sym = currentST->lookup(newST);
            sym->nestedTable = new symbolTable(newST);
            sym->name = newST;
            sym->nestedTable->parent = currentST;
            sym->type = new symbolType("block");
            currentSymbol = sym;
        }
        ;

F: %empty
        {
            blockName = "FOR";
        }
        ;

W: %empty
        {
            blockName = "WHILE";
        }
        ;

D: %empty
        {
            blockName = "DO_WHILE";
        }
        ;

change_table: %empty
        {
            if(currentSymbol->nestedTable != NULL) {
                switchTable(currentSymbol->nestedTable);
                emit("label", currentST->name);
            }
            else {
                switchTable(new symbolTable(""));
            }
        }
        ;

primary_expression: 
        IDENTIFIER
        {
            $$ = new expression();
            $$->loc = $1;
            $$->type = "non_bool";
        }
        | constant
        {
            $$ = new expression();
            $$->loc = $1;
        }
        | STRING_LITERAL
        {
            $$ = new expression();
            $$->loc = symbolTable::gentemp(new symbolType("ptr"), $1);
            $$->loc->type->arrType = new symbolType("char");
        }
        | PARENTHESIS_OPEN expression PARENTHESIS_CLOSE
        {
            $$ = $2;
        }
        ;

constant: 
        INTEGER_CONSTANT
        {
            $$ = symbolTable::gentemp(new symbolType("int"), convertIntToString($1));
            emit("=", $$->name, $1);
        }
        | FLOATING_CONSTANT
        {
            $$ = symbolTable::gentemp(new symbolType("float"), string($1));
            emit("=", $$->name, string($1));
        }
        | CHAR_CONSTANT
        {
            $$ = symbolTable::gentemp(new symbolType("float"), string($1));
            emit("=", $$->name, string($1));
        }
        ;

postfix_expression: 
        primary_expression
        {
            $$ = new Array();
            $$->Array = $1->loc;
            $$->type = $1->loc->type;
            $$->loc = $$->Array;
        }
        | postfix_expression SQUARE_BRACE_OPEN expression SQUARE_BRACE_CLOSE
        {
            $$ = new Array();
            $$->type = $1->type->arrType;
            $$->Array = $1->Array;
            $$->loc = symbolTable::gentemp(new symbolType("int"));
            $$->atype = "arr";

            if($1->atype == "arr") {
                symbol* sym = symbolTable::gentemp(new symbolType("int"));
                int sz = sizeOfType($$->type);
                emit("*", sym->name, $3->loc->name, convertIntToString(sz));
                emit("+", $$->loc->name, $1->loc->name, sym->name);
            }
            else {
                int sz = sizeOfType($$->type);
                emit("*", $$->loc->name, $3->loc->name, convertIntToString(sz));
            }
        }
        | postfix_expression PARENTHESIS_OPEN argument_expression_list_opt PARENTHESIS_CLOSE
        {
            $$ = new Array();
            $$->Array = symbolTable::gentemp($1->type);
            emit("call", $$->Array->name, $1->Array->name, convertIntToString($3));
        }
        | postfix_expression DOT IDENTIFIER
        { /* Ignored */ }
        | postfix_expression ARROW IDENTIFIER
        { /* Ignored */ }
        | postfix_expression INCREMENT
        {
            $$ = new Array();
            $$->Array = symbolTable::gentemp($1->Array->type);
            emit("=", $$->Array->name, $1->Array->name);
            emit("+", $1->Array->name, $1->Array->name, "1");
        }
        | postfix_expression DECREMENT
        {
            $$ = new Array();
            $$->Array = symbolTable::gentemp($1->Array->type);
            emit("=", $$->Array->name, $1->Array->name);
            emit("-", $1->Array->name, $1->Array->name, "1");
        }
        | PARENTHESIS_OPEN type_name PARENTHESIS_CLOSE CURLY_BRACE_OPEN initializer_list CURLY_BRACE_CLOSE
        { /* Ignored */ }
        | PARENTHESIS_OPEN type_name PARENTHESIS_CLOSE CURLY_BRACE_OPEN initializer_list COMMA CURLY_BRACE_CLOSE
        { /* Ignored */ }
        ;

argument_expression_list_opt: 
        argument_expression_list
        {
            $$ = $1;
        }
        | %empty
        {
            $$ = 0;
        }
        ;

argument_expression_list: 
        assignment_expression
        {
            $$ = 1;
            emit("param", $1->loc->name);
        }
        | argument_expression_list COMMA assignment_expression
        {
            $$ = $1 + 1;
            emit("param", $3->loc->name);
        }
        ;

unary_expression: 
        postfix_expression
        {
            $$ = $1;
        }
        | INCREMENT unary_expression
        {
            emit("+", $2->Array->name, $2->Array->name, "1");
            $$ = $2;
        }
        | DECREMENT unary_expression
        {
            emit("-", $2->Array->name, $2->Array->name, "1");
            $$ = $2;
        }
        | unary_operator cast_expression
        {
            $$ = new Array();
            switch($1) {
                case '&':
                    $$->Array = symbolTable::gentemp(new symbolType("ptr"));
                    $$->Array->type->arrType = $2->Array->type;
                    emit("= &", $$->Array->name, $2->Array->name);
                    break;
                case '*':
                    $$->atype = "ptr";
                    $$->loc = symbolTable::gentemp($2->Array->type->arrType);
                    $$->Array = $2->Array;
                    emit("= *", $$->loc->name, $2->Array->name);
                    break;
                case '+':
                    $$ = $2;
                    break;
                case '-':
                    $$->Array = symbolTable::gentemp(new symbolType($2->Array->type->type));
                    emit("= -", $$->Array->name, $2->Array->name);
                    break;
                case '~':
                    $$->Array = symbolTable::gentemp(new symbolType($2->Array->type->type));
                    emit("= ~", $$->Array->name, $2->Array->name);
                    break;
                case '!':
                    $$->Array = symbolTable::gentemp(new symbolType($2->Array->type->type));
                    emit("= !", $$->Array->name, $2->Array->name);
                    break;
            }
        }
        | SIZEOF unary_expression
        { /* Ignored */ }
        | SIZEOF PARENTHESIS_OPEN type_name PARENTHESIS_CLOSE
        { /* Ignored */ }
        ;

unary_operator: 
        BITWISE_AND
        {
            $$ = '&';
        }
        | MULTIPLY
        {
            $$ = '*';
        }
        | ADD
        {
            $$ = '+';
        }
        | SUBTRACT
        {
            $$ = '-';
        }
        | BITWISE_NOR
        {
            $$ = '~';
        }
        | NOT
        {
            $$ = '!';
        }
        ;

cast_expression: 
        unary_expression
        {
            $$ = $1;
        }
        | PARENTHESIS_OPEN type_name PARENTHESIS_CLOSE cast_expression
        {
            $$ = new Array();
            $$->Array = convertType($4->Array, varType);
        }
        ;

multiplicative_expression: 
        cast_expression
        {
            $$ = new expression();
            if($1->atype == "arr") {
                $$->loc = symbolTable::gentemp($1->loc->type);
                emit("=[]", $$->loc->name, $1->Array->name, $1->loc->name);
            }
            else if($1->atype == "ptr") {
                $$->loc = $1->loc;
            }
            else {
                $$->loc = $1->Array;
            }
        }
        | multiplicative_expression MULTIPLY cast_expression
        {
            if(typecheck($1->loc, $3->Array)) {
                $$ = new expression();
                $$->loc = symbolTable::gentemp(new symbolType($1->loc->type->type));
                emit("*", $$->loc->name, $1->loc->name, $3->Array->name);
            }
            else {
                yyerror("Type Error");
            }
        }
        | multiplicative_expression DIVIDE cast_expression
        {
            if(typecheck($1->loc, $3->Array)) {
                $$ = new expression();
                $$->loc = symbolTable::gentemp(new symbolType($1->loc->type->type));
                emit("/", $$->loc->name, $1->loc->name, $3->Array->name);
            }
            else {
                yyerror("Type Error");
            }
        }
        | multiplicative_expression MODULO cast_expression
        {
            if(typecheck($1->loc, $3->Array)) {
                $$ = new expression();
                $$->loc = symbolTable::gentemp(new symbolType($1->loc->type->type));
                emit("%", $$->loc->name, $1->loc->name, $3->Array->name);
            }
            else {
                yyerror("Type Error");
            }
        }
        ;

additive_expression: 
        multiplicative_expression
        {
            $$ = $1;
        }
        | additive_expression ADD multiplicative_expression
        {
            if(typecheck($1->loc, $3->loc)) {
                $$ = new expression();
                $$->loc = symbolTable::gentemp(new symbolType($1->loc->type->type));
                emit("+", $$->loc->name, $1->loc->name, $3->loc->name);
            }
            else {
                yyerror("Type Error");
            }
        }
        | additive_expression SUBTRACT multiplicative_expression
        {
            if(typecheck($1->loc, $3->loc)) {
                $$ = new expression();
                $$->loc = symbolTable::gentemp(new symbolType($1->loc->type->type));
                emit("-", $$->loc->name, $1->loc->name, $3->loc->name);
            }
            else {
                yyerror("Type Error");
            }
        }
        ;

shift_expression: 
        additive_expression
        {
            $$ = $1;
        }
        | shift_expression LSHIFT additive_expression
        {
            if($3->loc->type->type == "int") {
                $$ = new expression();
                $$->loc = symbolTable::gentemp(new symbolType("int"));
                emit("<<", $$->loc->name, $1->loc->name, $3->loc->name);
            }
            else {
                yyerror("Type Error");
            }
        }
        | shift_expression RSHIFT additive_expression
        {
            if($3->loc->type->type == "int") {
                $$ = new expression();
                $$->loc = symbolTable::gentemp(new symbolType("int"));
                emit(">>", $$->loc->name, $1->loc->name, $3->loc->name);
            }
            else {
                yyerror("Type Error");
            }
        }
        ;

relational_expression: 
        shift_expression
        {
            $$ = $1;
        }
        | relational_expression LESS_THAN shift_expression
        {
            if(typecheck($1->loc, $3->loc)) {
                $$ = new expression();
                $$->type = "bool";
                $$->truelist = makelist(nextinstr());
                $$->falselist = makelist(nextinstr() + 1);
                emit("<", "", $1->loc->name, $3->loc->name);
                emit("goto", "");
            }
            else {
                yyerror("Type Error");
            }
        }
        | relational_expression GREATER_THAN shift_expression
        {
            if(typecheck($1->loc, $3->loc)) {
                $$ = new expression();
                $$->type = "bool";
                $$->truelist = makelist(nextinstr());
                $$->falselist = makelist(nextinstr() + 1);
                emit(">", "", $1->loc->name, $3->loc->name);
                emit("goto", "");
            }
            else {
                yyerror("Type Error");
            }
        }
        | relational_expression LESS_THAN_EQUAL shift_expression
        {
            if(typecheck($1->loc, $3->loc)) {
                $$ = new expression();
                $$->type = "bool";
                $$->truelist = makelist(nextinstr());
                $$->falselist = makelist(nextinstr() + 1);
                emit("<=", "", $1->loc->name, $3->loc->name);
                emit("goto", "");
            }
            else {
                yyerror("Type Error");
            }
        }
        | relational_expression GREATER_THAN_EQUAL shift_expression
        {
            if(typecheck($1->loc, $3->loc)) {
                $$ = new expression();
                $$->type = "bool";
                $$->truelist = makelist(nextinstr());
                $$->falselist = makelist(nextinstr() + 1);
                emit(">=", "", $1->loc->name, $3->loc->name);
                emit("goto", "");
            }
            else {
                yyerror("Type Error");
            }
        }
        ;

equality_expression: 
        relational_expression
        {
            $$ = $1;
        }
        | equality_expression EQUAL relational_expression
        {
            if(typecheck($1->loc, $3->loc)) {
                convertBoolToInt($1);
                convertBoolToInt($3);
                $$ = new expression();
                $$->type = "bool";
                $$->truelist = makelist(nextinstr());
                $$->falselist = makelist(nextinstr() + 1);
                emit("==", "", $1->loc->name, $3->loc->name);
                emit("goto", "");
            }
            else {
                yyerror("Type Error");
            }
        }
        | equality_expression NOT_EQUAL relational_expression
        {
            if(typecheck($1->loc, $3->loc)) {
                convertBoolToInt($1);
                convertBoolToInt($3);
                $$ = new expression();
                $$->type = "bool";
                $$->truelist = makelist(nextinstr());
                $$->falselist = makelist(nextinstr() + 1);
                emit("!=", "", $1->loc->name, $3->loc->name);
                emit("goto", "");
            }
            else {
                yyerror("Type Error");
            }
        }
        ;

and_expression: 
        equality_expression
        {
            $$ = $1;
        }
        | and_expression BITWISE_AND equality_expression
        {
            if(typecheck($1->loc, $3->loc)) {
                convertBoolToInt($1);
                convertBoolToInt($3);
                $$ = new expression();
                $$->type = "not_bool";
                $$->loc = symbolTable::gentemp(new symbolType("int"));
                emit("&", $$->loc->name, $1->loc->name, $3->loc->name);
            }
            else {
                yyerror("Type Error");
            }
        }
        ;

exclusive_or_expression: 
        and_expression
        {
            $$ = $1;
        }
        | exclusive_or_expression BITWISE_XOR and_expression
        {
            if(typecheck($1->loc, $3->loc)) {
                convertBoolToInt($1);
                convertBoolToInt($3);
                $$ = new expression();
                $$->type = "not_bool";
                $$->loc = symbolTable::gentemp(new symbolType("int"));
                emit("^", $$->loc->name, $1->loc->name, $3->loc->name);
            }
            else {
                yyerror("Type Error");
            }
        }
        ;

inclusive_or_expression: 
        exclusive_or_expression
        {
            $$ = $1;
        }
        | inclusive_or_expression BITWISE_OR exclusive_or_expression
        {
            if(typecheck($1->loc, $3->loc)) {
                convertBoolToInt($1);
                convertBoolToInt($3);
                $$ = new expression();
                $$->type = "not_bool";
                $$->loc = symbolTable::gentemp(new symbolType("int"));
                emit("|", $$->loc->name, $1->loc->name, $3->loc->name);
            }
            else {
                yyerror("Type Error");
            }
        }
        ;

logical_and_expression: 
        inclusive_or_expression
        {
            $$ = $1;
        }
        | logical_and_expression LOGICAL_AND M inclusive_or_expression
        {
            convertIntToBool($1);
            convertIntToBool($4);
            $$ = new expression();
            $$->type = "bool";
            backpatch($1->truelist, $3);
            $$->truelist = $4->truelist;
            $$->falselist = merge($1->falselist, $4->falselist);
        }
        ;

logical_or_expression: 
        logical_and_expression
        {
            $$ = $1;
        }
        | logical_or_expression LOGICAL_OR M logical_and_expression
        {
            convertIntToBool($1);
            convertIntToBool($4);
            $$ = new expression();
            $$->type = "bool";
            backpatch($1->falselist, $3);
            $$->falselist = $4->falselist;
            $$->truelist = merge($1->truelist, $4->truelist);
        }
        ;

conditional_expression: 
        logical_or_expression
        {
            $$ = $1;
        }
        | logical_or_expression N QUESTION_MARK M expression N COLON M conditional_expression
        {
            $$->loc = symbolTable::gentemp($5->loc->type);
            $$->loc->update($5->loc->type);
            emit("=", $$->loc->name, $9->loc->name);
            list<int> l1 = makelist(nextinstr());
            emit("goto", "");
            backpatch($6->nextlist, nextinstr());
            emit("=", $$->loc->name, $5->loc->name);
            list<int> l2 = makelist(nextinstr());
            l1 = merge(l1, l2);
            emit("goto", "");
            backpatch($2->nextlist, nextinstr());
            convertIntToBool($1);
            backpatch($1->truelist, $4);
            backpatch($1->falselist, $8);
            backpatch(l1, nextinstr());
        }
        ;

assignment_expression: 
        conditional_expression
        {
            $$ = $1;
        }
        | unary_expression assignment_operator assignment_expression
        {
            if($1->atype == "arr") {
                $3->loc = convertType($3->loc, $1->type->type);
                emit("[]=", $1->Array->name, $1->loc->name, $3->loc->name);
            }
            else if($1->atype == "ptr") {
                emit("*=", $1->Array->name, $3->loc->name);
            }
            else {
                $3->loc = convertType($3->loc, $1->Array->type->type);
                emit("=", $1->Array->name, $3->loc->name);
            }
            $$ = $3;
        }
        ;

assignment_operator: 
        ASSIGN
        { /* Ignored */ }
        | MULTIPLY_ASSIGN
        { /* Ignored */ }
        | DIVIDE_ASSIGN
        { /* Ignored */ }
        | MODULO_ASSIGN
        { /* Ignored */ }
        | ADD_ASSIGN
        { /* Ignored */ }
        | SUBTRACT_ASSIGN
        { /* Ignored */ }
        | LSHIFT_ASSIGN
        { /* Ignored */ }
        | RSHIFT_ASSIGN
        { /* Ignored */ }
        | AND_ASSIGN
        { /* Ignored */ }
        | XOR_ASSIGN
        { /* Ignored */ }
        | OR_ASSIGN
        { /* Ignored */ }
        ;

expression: 
        assignment_expression
        {
            $$ = $1;
        }
        | expression COMMA assignment_expression
        { /* Ignored */ }
        ;

constant_expression: 
        conditional_expression
        { /* Ignored */ }
        ;

declaration: 
        declaration_specifiers init_declarator_list SEMICOLON
        { /* Ignored */ }
        | declaration_specifiers SEMICOLON
        { /* Ignored */ }
        ;

declaration_specifiers: 
        storage_class_specifier declaration_specifiers
        { /* Ignored */ }
        |storage_class_specifier
        { /* Ignored */ }
        | type_specifier declaration_specifiers
        { /* Ignored */ }
        | type_specifier
        { /* Ignored */ }
        | type_qualifier declaration_specifiers
        { /* Ignored */ }
        | type_qualifier
        { /* Ignored */ }
        | function_specifier declaration_specifiers
        { /* Ignored */ }
        | function_specifier
        { /* Ignored */ }
        ;

init_declarator_list: 
        init_declarator
        { /* Ignored */ }
        | init_declarator_list COMMA init_declarator
        { /* Ignored */ }
        ;

init_declarator: 
        declarator
        {
            $$ = $1;
        }
        | declarator ASSIGN initializer
        {
            if($3->value != "") {
                $1->value = $3->value;
            }
            emit("=", $1->name, $3->name);
        }
        ;

storage_class_specifier: 
        EXTERN
        { /* Ignored */ }
        | STATIC
        { /* Ignored */ }
        | AUTO
        { /* Ignored */ }
        | REGISTER
        { /* Ignored */ }
        ;

type_specifier: 
        VOID
        {
            varType = "void";
        }
        | CHAR
        {
            varType = "char";
        }
        | SHORT
        { /* Ignored */ }
        | INT
        {
            varType = "int";
        }
        | LONG
        { /* Ignored */ }
        | FLOAT
        {
            varType = "float";
        }
        | DOUBLE
        { /* Ignored */ }
        | SIGNED
        { /* Ignored */ }
        | UNSIGNED
        { /* Ignored */ }
        | BOOL
        { /* Ignored */ }
        | COMPLEX
        { /* Ignored */ }
        | IMAGINARY
        { /* Ignored */ }
        | enum_specifier
        { /* Ignored */ }
        ;

specifier_qualifier_list: 
        type_specifier specifier_qualifier_list_opt
        { /* Ignored */ }
        | type_qualifier specifier_qualifier_list_opt
        { /* Ignored */ }
        ;

specifier_qualifier_list_opt: 
        specifier_qualifier_list
        { /* Ignored */ }
        | %empty
        { /* Ignored */ }
        ;

enum_specifier: 
        ENUM identifier_opt CURLY_BRACE_OPEN enumerator_list CURLY_BRACE_CLOSE
        { /* Ignored */ }
        | ENUM identifier_opt CURLY_BRACE_OPEN enumerator_list COMMA CURLY_BRACE_CLOSE
        { /* Ignored */ }
        | ENUM IDENTIFIER
        { /* Ignored */ }
        ;

identifier_opt: 
        IDENTIFIER
        {/* Ignored */}
        | %empty
        {/* Ignored */}
        ;

enumerator_list: 
        enumerator
        {/* Ignored */}
        | enumerator_list COMMA enumerator
        {/* Ignored */}
        ;

enumerator: 
        IDENTIFIER
        {/* Ignored */}
        | IDENTIFIER ASSIGN constant_expression
        {/* Ignored */}
        ;

type_qualifier: 
        CONST
        {/* Ignored */}
        | RESTRICT
        {/* Ignored */}
        | VOLATILE
        {/* Ignored */}
        ;

function_specifier: 
        INLINE
        {/* Ignored */}
        ;

declarator: 
        pointer direct_declarator
        {
            symbolType* t = $1;
            while(t->arrType != NULL) {
                t = t->arrType;
            }
            t->arrType = $2->type;
            $$ = $2->update($1);
        }
        | direct_declarator
        {/* Ignored */}
        ;

direct_declarator: 
        IDENTIFIER
        {
            $$ = $1->update(new symbolType(varType));
            currentSymbol = $$;
        }
        | PARENTHESIS_OPEN declarator PARENTHESIS_CLOSE
        {
            $$ = $2;
        }
        | direct_declarator SQUARE_BRACE_OPEN type_qualifier_list assignment_expression SQUARE_BRACE_CLOSE
        { /* Ignored */ }
        | direct_declarator SQUARE_BRACE_OPEN type_qualifier_list SQUARE_BRACE_CLOSE
        { /* Ignored */ }
        | direct_declarator SQUARE_BRACE_OPEN assignment_expression SQUARE_BRACE_CLOSE
        {
            symbolType* t = $1->type;
            symbolType* prev = NULL;
            while(t->type == "arr") {
                prev = t;
                t = t->arrType;
            }
            if(prev == NULL) {
                int temp = atoi($3->loc->value.c_str());
                symbolType* tp = new symbolType("arr", $1->type, temp);
                $$ = $1->update(tp);
            }
            else {
                int temp = atoi($3->loc->value.c_str());
                prev->arrType = new symbolType("arr", t, temp);
                $$ = $1->update($1->type);
            }
        }
        | direct_declarator SQUARE_BRACE_OPEN SQUARE_BRACE_CLOSE
        {
            symbolType* t = $1->type;
            symbolType* prev = NULL;
            while(t->type == "arr") {
                prev = t;
                t = t->arrType;
            }
            if(prev == NULL) {
                symbolType* tp = new symbolType("arr", $1->type, 0);
                $$ = $1->update(tp);
            }
            else {
                prev->arrType = new symbolType("arr", t, 0);
                $$ = $1->update($1->type);
            }
        }
        | direct_declarator SQUARE_BRACE_OPEN STATIC type_qualifier_list assignment_expression SQUARE_BRACE_CLOSE
        { /* Ignored */ }
        | direct_declarator SQUARE_BRACE_OPEN STATIC assignment_expression SQUARE_BRACE_CLOSE
        { /* Ignored */ }
        | direct_declarator SQUARE_BRACE_OPEN type_qualifier_list STATIC assignment_expression SQUARE_BRACE_CLOSE
        { /* Ignored */ }
        | direct_declarator SQUARE_BRACE_OPEN type_qualifier_list MULTIPLY SQUARE_BRACE_CLOSE
        { /* Ignored */ }
        | direct_declarator SQUARE_BRACE_OPEN MULTIPLY SQUARE_BRACE_CLOSE
        { /* Ignored */ }
        | direct_declarator PARENTHESIS_OPEN change_table parameter_type_list PARENTHESIS_CLOSE
        {
            currentST->name = $1->name;
            if($1->type->type != "void") {
                symbol* s = currentST->lookup("return");
                s->update($1->type);
            }
            $1->nestedTable = currentST;
            currentST->parent = globalST;
            switchTable(globalST);
            currentSymbol = $$;
        }
        | direct_declarator PARENTHESIS_OPEN identifier_list PARENTHESIS_CLOSE
        { /* Ignored */ }
        | direct_declarator PARENTHESIS_OPEN change_table PARENTHESIS_CLOSE
        {
            currentST->name = $1->name;
            if($1->type->type != "void") {
                symbol* s = currentST->lookup("return");
                s->update($1->type);
            }
            $1->nestedTable = currentST;
            currentST->parent = globalST;
            switchTable(globalST);
            currentSymbol = $$;
        }
        ;

type_qualifier_list_opt: 
        type_qualifier_list
        { /* Ignored */ }
        | %empty
        { /* Ignored */ }
        ;

pointer: 
        MULTIPLY type_qualifier_list_opt
        {
            $$ = new symbolType("ptr");
        }
        | MULTIPLY type_qualifier_list_opt pointer
        {
            $$ = new symbolType("ptr", $3);
        }
        ;

type_qualifier_list: 
        type_qualifier
        { /* Ignored */ }
        | type_qualifier_list type_qualifier
        { /* Ignored */ }
        ;

parameter_type_list: 
        parameter_list
        { /* Ignored */ }
        | parameter_list COMMA ELLIPSIS
        { /* Ignored */ }
        ;

parameter_list: 
        parameter_declaration
        { /* Ignored */ }
        | parameter_list COMMA parameter_declaration
        { /* Ignored */ }
        ;

parameter_declaration: 
        declaration_specifiers declarator
        { /* Ignored */ }
        | declaration_specifiers
        { /* Ignored */ }
        ;

identifier_list: 
        IDENTIFIER
        { /* Ignored */ }
        | identifier_list COMMA IDENTIFIER
        { /* Ignored */ }
        ;

type_name: 
        specifier_qualifier_list
        { /* Ignored */ }
        ;

initializer: 
        assignment_expression
        {
            $$ = $1->loc;
        }
        | CURLY_BRACE_OPEN initializer_list CURLY_BRACE_CLOSE
        { /* Ignored */ }
        | CURLY_BRACE_OPEN initializer_list COMMA CURLY_BRACE_CLOSE
        { /* Ignored */ }
        ;

initializer_list: 
        designation_opt initializer
        { /* Ignored */ }
        | initializer_list COMMA designation_opt initializer
        { /* Ignored */ }
        ;

designation_opt: 
        designation
        { /* Ignored */ }
        | %empty
        { /* Ignored */ }
        ;

designation: 
        designator_list ASSIGN
        { /* Ignored */ }
        ;

designator_list: 
        designator
        { /* Ignored */ }
        | designator_list designator
        { /* Ignored */ }
        ;

designator: 
        SQUARE_BRACE_OPEN constant_expression SQUARE_BRACE_CLOSE
        { /* Ignored */ }
        | DOT IDENTIFIER
        { /* Ignored */ }
        ;

statement: 
        labeled_statement
        { /* Ignored */ }
        | compound_statement
        {
            $$ = $1;
        }
        | expression_statement
        {
            $$ = new statement();
            $$->nextlist = $1->nextlist;
        }
        | selection_statement
        {
            $$ = $1;
        }
        | iteration_statement
        {
            $$ = $1;
        }
        | jump_statement
        {
            $$ = $1;
        }
        ;

loop_statement: 
        labeled_statement
        { /* Ignored */ }
        | expression_statement
        {
            $$ = new statement();
            $$->nextlist = $1->nextlist;
        }
        | selection_statement
        {
            $$ = $1;
        }
        | iteration_statement
        {
            $$ = $1;
        }
        | jump_statement
        {
            $$ = $1;
        }
        ;

labeled_statement: 
        IDENTIFIER COLON statement
        { /* Ignored */ }
        | CASE constant_expression COLON statement
        { /* Ignored */ }
        | DEFAULT COLON statement
        { /* Ignored */ }
        ;

compound_statement: 
        CURLY_BRACE_OPEN X change_table block_item_list_opt CURLY_BRACE_CLOSE
        {
            $$ = $4;
            switchTable(currentST->parent);
        }
        ;

block_item_list_opt: 
        block_item_list
        {
            $$ = $1;
        }
        | %empty
        {
            $$ = new statement();
        }
        ;

block_item_list: 
        block_item
        {
            $$ = $1;
        }
        | block_item_list M block_item
        {
            $$ = $3;
            backpatch($1->nextlist, $2);
        }
        ;

block_item: 
        declaration
        {
            $$ = new statement();
        }
        | statement
        {
            $$ = $1;
        }
        ;

expression_statement: 
        expression SEMICOLON
        {
            $$ = $1;
        }
        | SEMICOLON
        {
            $$ = new expression();
        }
        ;

selection_statement: 
        IF PARENTHESIS_OPEN expression N PARENTHESIS_CLOSE M statement N %prec THEN
        {
            backpatch($4->nextlist, nextinstr());
            convertIntToBool($3);
            $$ = new statement();
            backpatch($3->truelist, $6);
            list<int> temp = merge($3->falselist, $7->nextlist);
            $$->nextlist = merge($8->nextlist, temp);
        }
        | IF PARENTHESIS_OPEN expression N PARENTHESIS_CLOSE M statement N ELSE M statement
        {
            backpatch($4->nextlist, nextinstr());
            convertIntToBool($3);
            $$ = new statement();
            backpatch($3->truelist, $6);
            backpatch($3->falselist, $10);
            list<int> temp = merge($7->nextlist, $8->nextlist);
            $$->nextlist = merge($11->nextlist, temp);
        }
        | SWITCH PARENTHESIS_OPEN expression PARENTHESIS_CLOSE statement
        { /* Ignored */ }
        ;

iteration_statement: 
        WHILE W PARENTHESIS_OPEN X change_table M expression PARENTHESIS_CLOSE M loop_statement
        {
            $$ = new statement();
            convertIntToBool($7);
            backpatch($10->nextlist, $6);
            backpatch($7->truelist, $9);
            $$->nextlist = $7->falselist;
            emit("goto", convertIntToString($6));
            blockName = "";
            switchTable(currentST->parent);
        }
        | WHILE W PARENTHESIS_OPEN X change_table M expression PARENTHESIS_CLOSE CURLY_BRACE_OPEN M block_item_list_opt CURLY_BRACE_CLOSE
        {
            $$ = new statement();
            convertIntToBool($7);
            backpatch($11->nextlist, $6);
            backpatch($7->truelist, $10);
            $$->nextlist = $7->falselist;
            emit("goto", convertIntToString($6));
            blockName = "";
            switchTable(currentST->parent);
        }
        | DO D M loop_statement M WHILE PARENTHESIS_OPEN expression PARENTHESIS_CLOSE SEMICOLON
        {
            $$ = new statement();
            convertIntToBool($8);
            backpatch($8->truelist, $3);
            backpatch($4->nextlist, $5);
            $$->nextlist = $8->falselist;
            blockName = "";
        }
        | DO D CURLY_BRACE_OPEN M block_item_list_opt CURLY_BRACE_CLOSE M WHILE PARENTHESIS_OPEN expression PARENTHESIS_CLOSE SEMICOLON
        {
            $$ = new statement();
            convertIntToBool($10);
            backpatch($10->truelist, $4);
            backpatch($5->nextlist, $7);
            $$->nextlist = $10->falselist;
            blockName = "";
        }
        | FOR F PARENTHESIS_OPEN X change_table declaration M expression_statement M expression N PARENTHESIS_CLOSE M loop_statement
        {
            $$ = new statement();
            convertIntToBool($8);
            backpatch($8->truelist, $13);
            backpatch($11->nextlist, $7);
            backpatch($14->nextlist, $9);
            emit("goto", convertIntToString($9));
            $$->nextlist = $8->falselist;
            blockName = "";
            switchTable(currentST->parent);
        }
        | FOR F PARENTHESIS_OPEN X change_table expression_statement M expression_statement M expression N PARENTHESIS_CLOSE M loop_statement
        {
            $$ = new statement();
            convertIntToBool($8);
            backpatch($8->truelist, $13);
            backpatch($11->nextlist, $7);
            backpatch($14->nextlist, $9);
            emit("goto", convertIntToString($9));
            $$->nextlist = $8->falselist;
            blockName = "";
            switchTable(currentST->parent);
        }
        | FOR F PARENTHESIS_OPEN X change_table declaration M expression_statement M expression N PARENTHESIS_CLOSE M CURLY_BRACE_OPEN block_item_list_opt CURLY_BRACE_CLOSE
        {
            $$ = new statement();
            convertIntToBool($8);
            backpatch($8->truelist, $13);
            backpatch($11->nextlist, $7);
            backpatch($15->nextlist, $9);
            emit("goto", convertIntToString($9));
            $$->nextlist = $8->falselist;
            blockName = "";
            switchTable(currentST->parent);
        }
        | FOR F PARENTHESIS_OPEN X change_table expression_statement M expression_statement M expression N PARENTHESIS_CLOSE M CURLY_BRACE_OPEN block_item_list_opt CURLY_BRACE_CLOSE
        {
            $$ = new statement();
            convertIntToBool($8);
            backpatch($8->truelist, $13);
            backpatch($11->nextlist, $7);
            backpatch($15->nextlist, $9);
            emit("goto", convertIntToString($9));
            $$->nextlist = $8->falselist;
            blockName = "";
            switchTable(currentST->parent);
        }
        ;

jump_statement: 
        GOTO IDENTIFIER SEMICOLON
        { /* Ignored */ }
        | CONTINUE SEMICOLON
        {
            $$ = new statement();
        }
        | BREAK SEMICOLON
        {
            $$ = new statement();
        }
        | RETURN expression SEMICOLON
        {
            $$ = new statement();
            emit("return", $2->loc->name);
        }
        | RETURN SEMICOLON
        {
            $$ = new statement();
            emit("return", "");
        }
        ;

translation_unit: 
        external_declaration
        { /* Ignored */ }
        | translation_unit external_declaration
        { /* Ignored */ }
        ;

external_declaration: 
        function_definition
        { /* Ignored */ }
        | declaration
        { /* Ignored */ }
        ;

function_definition: 
        declaration_specifiers declarator declaration_list_opt change_table CURLY_BRACE_OPEN block_item_list_opt CURLY_BRACE_CLOSE
        {   
            currentST->parent = globalST;
            STCount = 0;
            switchTable(globalST);
        }
        ;

declaration_list_opt: 
        declaration_list
        { /* Ignored */ }
        | %empty
        { /* Ignored */ }
        ;

declaration_list: 
        declaration
        { /* Ignored */ }
        | declaration_list declaration
        { /* Ignored */ }
        ;

%%

void yyerror(string s) {
    cout << "Error occurred: " << s << endl;
    cout << "Line no.: " << yylineno << endl;
    cout << "Unable to parse: " << yytext << endl; 
}
