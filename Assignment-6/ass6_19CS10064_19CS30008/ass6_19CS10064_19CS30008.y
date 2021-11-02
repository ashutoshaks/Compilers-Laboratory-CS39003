%{
    /**
    * Vanshita Garg | 19CS10064
    * Ashutosh Kumar Singh | 19CS30008
    * Compilers Laboratory
    * Assignment 6
    *
    * Bison specifications
    */

    #include <iostream>
    #include "ass6_19CS10064_19CS30008_translator.h"
    using namespace std;

    extern int yylex();         // From lexer
    void yyerror(string s);     // Function to report errors
    extern char* yytext;        // From lexer, gives the text being currently scanned
    extern int yylineno;        // Used for keeping track of the line number

    extern int nextinstr;
    extern quadArray quadList;
    extern symbolTable globalST;
    extern symbolTable* ST;
    extern vector<string> stringConsts;

    int strCount = 0;
%}

%union {
    int intval;             // For an integer value
    char charval;          // For a char value
    float floatval;
    void* ptr;
    string* str;
    symbolType* symType;    // For the type of a symbol
    symbol* symp;           // For a symbol
    DataType types;
    opcode opc;
    expression* expr;       // For an expression
    declaration* dec;
    vector<declaration*> decList;
    param* prm;
    vector<param*> *prmList;
}

/*
    All tokens
*/
%token AUTO BREAK CASE CHAR CONST CONTINUE DEFAULT DO DOUBLE ELSE ENUM EXTERN FLOAT FOR GOTO IF INLINE INT LONG REGISTER RESTRICT RETURN SHORT SIGNED SIZEOF STATIC STRUCT SWITCH TYPEDEF UNION UNSIGNED VOID VOLATILE WHILE BOOL COMPLEX IMAGINARY
%token SQUARE_BRACE_OPEN SQUARE_BRACE_CLOSE PARENTHESIS_OPEN PARENTHESIS_CLOSE CURLY_BRACE_OPEN CURLY_BRACE_CLOSE 
%token DOT ARROW INCREMENT DECREMENT BITWISE_AND MULTIPLY ADD SUBTRACT BITWISE_NOR NOT DIVIDE MODULO 
%token LSHIFT RSHIFT LESS_THAN GREATER_THAN LESS_THAN_EQUAL GREATER_THAN_EQUAL EQUAL NOT_EQUAL BITWISE_XOR BITWISE_OR 
%token LOGICAL_AND LOGICAL_OR QUESTION_MARK COLON SEMICOLON ELLIPSIS 
%token ASSIGN MULTIPLY_ASSIGN DIVIDE_ASSIGN MODULO_ASSIGN ADD_ASSIGN SUBTRACT_ASSIGN LSHIFT_ASSIGN RSHIFT_ASSIGN AND_ASSIGN XOR_ASSIGN OR_ASSIGN COMMA HASH

// Identifiers are treated with type symbol*
%token <str> IDENTIFIER

// Integer constants have a type intval
%token <intval> INTEGER_CONSTANT

// Floating constants have a type charval
%token <floatval> FLOATING_CONSTANT

// Character constants have a type charval
%token <charval> CHAR_CONSTANT

// String literals have a type charval
%token <str> STRING_LITERAL

// Non-terminals of type expr (denoting expressions)
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
        postfix_expression
        unary_expression
        cast_expression
        expression_statement
        statement
        compound_statement
        selection_statement
        iteration_statement
        labeled_statement 
        jump_statement
        block_item
        block_item_list
        initializer
        M
        N

// Non-terminals of type unaryOp (unary operator)
%type <charval> unary_operator

// The pointer non-terminal is treated with type symbolType
%type <intval> pointer

%type <types> type_specifier declaration_specifiers

// Non-terminals of type symp (symbol*)
%type <dec> direct_declarator initializer_list init_declarator declarator function_prototype

%type <decList> init_declarator_list

%type <prm> parameter_declaration

%type <prmList> parameter_list parameter_type_list parameter_type_list_opt argument_expression_list

// Helps in removing the dangling else problem
%expect 1
%nonassoc ELSE

// The start symbol is translation_unit
%start translation_unit

%%

primary_expression: 
        IDENTIFIER
        {
            $$ = new expression();  // Create new expression
            string s = *($1);
            ST->lookup(s);
            $$->loc = s;           // Store pointer to entry in the symbol table
        }
        | INTEGER_CONSTANT
        {
            $$ = new expression();
            $$->loc = ST->gentemp(INT);
            emit($$->loc, $1, ASSIGN);
            symbolValue* val = new symbolValue();
            val->setInitVal($1);
            ST->lookup($$->loc)->initVal = val;
        }
        | FLOATING_CONSTANT
        {
            $$ = new expression();
            $$->loc = ST->gentemp(FLOAT);
            emit($$->loc, $1, ASSIGN);
            symbolValue* val = new symbolValue();
            val->setInitVal($1);
            ST->lookup($$->loc)->initVal = val;
        }
        | CHAR_CONSTANT
        {
            $$ = new expression();
            $$->loc = ST->gentemp(CHAR);
            emit($$->loc, $1, ASSIGN);
            symbolValue* val = new symbolValue();
            val->setInitVal($1);
            ST->lookup($$->loc)->initVal = val;
        }
        | STRING_LITERAL
        {
            $$ = new expression();  // Create new expression
            $$->loc = ".LC" + to_string(strCount++);
            stringConsts.push_back(*($1));
        }
        | PARENTHESIS_OPEN expression PARENTHESIS_CLOSE
        {
            $$ = $2;    // Simple assignment
        }
        ;

postfix_expression: 
        primary_expression
        | postfix_expression SQUARE_BRACE_OPEN expression SQUARE_BRACE_CLOSE
        {
            symbolType to = ST->lookup($1->loc)->type;
            string f = "";
            if(!($1->fold)) {
                f = ST->gentemp(INT);
                emit(f, 0, ASSIGN);
                $1->folder = new string(f);
            }
            string temp = ST->gentemp(INT);
            emit(temp, $3->loc, "", ASSIGN);
            emit(temp, temp, "4", MULT);
            emit(f, temp, "", ASSIGN);
            $$ = $1;
        }
        | postfix_expression PARENTHESIS_OPEN PARENTHESIS_CLOSE
        {   
            // Corresponds to calling a function with the function name and the appropriate number of parameters
            symbolTable* funcTable = ST->lookup($1->loc)->nestedTable;
            emit($1->loc, "0", "", CALL);
        }
        | postfix_expression PARENTHESIS_OPEN argument_expression_list PARENTHESIS_CLOSE
        {   
            // Corresponds to calling a function with the function name and the appropriate number of parameters
            symbolTable* funcTable = ST->lookup($1->loc)->nestedTable;
            vector<param*> parameters = *($3);
            vector<symbol*> paramsList = funcTable->symbols;

            for(int i = 0; i < (int)parameters.size(); i++)
                emit(parameters[i]->name, "", "", PARAM);

            DataType retType = funcTable->lookup("RETVAL")->type.type;
            if(retType == VOID)
                emit($1->loc, (int)parameters.size(), CALL);
            else {
                string retVal = ST->gentemp(retType);
                emit($1->loc, to_string(parameters.size()), retVal, CALL);
                $$ = new expression();
                $$->loc = retVal;
            }
        }
        | postfix_expression DOT IDENTIFIER
        { /* Ignored */ }
        | postfix_expression ARROW IDENTIFIER
        { /* Ignored */ }
        | postfix_expression INCREMENT
        {   
            $$ = new expression();
            symbolType t = ST->lookup($1->loc)->type;
            if(t.type == ARRAY) {
                $$->loc = ST->gentemp(ST->lookup($1->loc)->type.nextType);
                emit($$->loc, $1->loc, *($1->folder), ARR_IDX_ARG);
                string temp = ST->gentemp(t.nextType);
                emit(temp, $1->loc, *($1->folder), ARR_IDX_ARG);
                emit(temp, temp, "1", ADD);
                emit($1->loc, temp, *($1->folder), ARR_IDX_RES);
            }
            else {
                $$->loc = ST->gentemp(ST->lookup($1->loc)->type.type);
                emit($$->loc, $1->loc, "", ASSIGN);
                emit($1->loc, $1->loc, "1", ADD);
            }
        }
        | postfix_expression DECREMENT
        {
            $$ = new expression();
            symbolType t = ST->lookup($1->loc)->type;
            if(t.type == ARRAY) {
                $$->loc = ST->gentemp(ST->lookup($1->loc)->type.nextType);
                emit($$->loc, $1->loc, *($1->folder), ARR_IDX_ARG);
                string temp = ST->gentemp(t.nextType);
                emit(temp, $1->loc, *($1->folder), ARR_IDX_ARG);
                emit(temp, temp, "1", SUB);
                emit($1->loc, temp, *($1->folder), ARR_IDX_RES);
            }
            else {
                $$->loc = ST->gentemp(ST->lookup($1->loc)->type.type);
                emit($$->loc, $1->loc, "", ASSIGN);
                emit($1->loc, $1->loc, "1", SUB);
            }
        }
        | PARENTHESIS_OPEN type_name PARENTHESIS_CLOSE CURLY_BRACE_OPEN initializer_list CURLY_BRACE_CLOSE
        { /* Ignored */ }
        | PARENTHESIS_OPEN type_name PARENTHESIS_CLOSE CURLY_BRACE_OPEN initializer_list COMMA CURLY_BRACE_CLOSE
        { /* Ignored */ }
        ;

argument_expression_list: 
        assignment_expression
        {
            param* first = new param();
            first->name = $1->loc;
            first->type = ST->lookup($1->loc)->type;
            $$ = new vector<param*>();
            $$->push_back(first);
        }
        | argument_expression_list COMMA assignment_expression
        {
            param* next = new param();
            next->name = $3->loc;
            next->type = ST->lookup(next->name)->type;
            $$ = $1;
            $$->push_back(next);
        }
        ;

unary_expression: 
        postfix_expression
        {
            // $$ = $1;    // Assign $1 to $$
        }
        | INCREMENT unary_expression
        {
            $$ = new expression();
            symbolType type = ST->lookup($2->loc)->type;
            if(type.type == ARRAY) {
                string t = ST->gentemp(type.nextType);
                emit(t, $2->loc, *($2->folder), ARR_IDX_ARG);
                emit(t, t, "1", ADD);
                emit($2->loc, t, *($2->folder), ARR_IDX_RES);
                $$->loc = ST->gentemp(ST->lookup($2->loc)->type.nextType);
            }
            else {
                emit($2->loc, $2->loc, "1", ADD);
                $$->loc = ST->gentemp(ST->lookup($2->loc)->type.type);
            }
            $$->loc = ST->gentemp(ST->lookup($2->loc)->type.type);
            emit($$->loc, $2->loc, "", ASSIGN);
        }
        | DECREMENT unary_expression
        {
            $$ = new expression();
            symbolType type = ST->lookup($2->loc)->type;
            if(type.type == ARRAY) {
                string t = ST->gentemp(type.nextType);
                emit(t, $2->loc, *($2->folder), ARR_IDX_ARG);
                emit(t, t, "1", SUB);
                emit($2->loc, t, *($2->folder), ARR_IDX_RES);
                $$->loc = ST->gentemp(ST->lookup($2->loc)->type.nextType);
            }
            else {
                emit($2->loc, $2->loc, "1", SUB);
                $$->loc = ST->gentemp(ST->lookup($2->loc)->type.type);
            }
            // $$->loc = ST->gentemp(ST->lookup($2->loc)->type.type);
            emit($$->loc, $2->loc, "", ASSIGN);
        }
        | unary_operator cast_expression
        {
            // Case of unary operator
            $$ = new expression();
            switch($1) {
                case '&':   // Address
                    $$->loc = ST->gentemp(POINTER);
                    emit($$->loc, $2->loc, "", REFERENCE)            // Emit the quad
                    break;
                case '*':   // De-referencing
                    $$->loc = ST->gentemp(INT);
                    $$->fold = 1;
                    $$->folder = new string($2->loc);
                    emit($$->loc, $2->loc, "", DEREFERENCE)            // Emit the quad
                    break;
                case '-':   // Unary minus
                    $$->loc = ST->gentemp();
                    emit($$->loc, $2->loc, "", U_MINUS)            // Emit the quad
                    break;
                case '!':   // Logical not 
                    $$->loc = ST->gentemp(INT);
                    int temp = nextinstr + 2;
                    emit(to_string(temp), $2->loc, "0", GOTO_EQ);
                    temp = nextinstr + 3;
                    emit(to_string(temp), "", "", GOTO);
                    emit($$->loc, "1", "", ASSIGN);
                    temp = nextinstr + 2;
                    emit(to_string(temp), "", "", GOTO);
                    emit($$->loc, "0", "", ASSIGN);
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
        {}
        | PARENTHESIS_OPEN type_name PARENTHESIS_CLOSE cast_expression
        {}
        ;

multiplicative_expression: 
        cast_expression
        {
            $$ = new expression();          // Generate new expression
            symbolType tp = ST->lookup($1->loc)->type;
            if(tp.type == ARRAY) {
                string t = ST->gentemp(tp.nextType);
                if($1->folder != NULL) {
                    emit(t, $1->loc, *($1->folder), ARR_IDX_ARG);
                    $1->loc = t;
                    $1->type = tp.nextType;
                }
                else
                    $$ = $1;
            }
            else
                $$ = $1;
        }
        | multiplicative_expression MULTIPLY cast_expression
        {   
            // Indicates multiplication
            $$ = new expression();
            symbol* one = ST->lookup($1->loc);
            symbol* two = ST->lookup($3->loc);
            if(two->type.type == ARRAY) {
                string t = ST->gentemp(two->type.nextType);
                emit(t, $3->loc, *($3->folder), ARR_IDX_ARG);
                $3->loc = t;
                $3->type = two->type.nextType;
            }
            if(one->type.type == ARRAY) {
                string t = ST->gentemp(one->type.nextType);
                emit(t, $1->loc, *($1->folder), ARR_IDX_ARG);
                $1->loc = t;
                $1->type = one->type.nextType;
            }
            DataType final = ((one->type.type > two->type.type) ? one->type.type : two->type.type);
            $$->loc = ST->gentemp(final);
            emit($$->loc, $1->loc, $3->loc, MULT);
        }
        | multiplicative_expression DIVIDE cast_expression
        {
            // Indicates division
            $$ = new expression();
            symbol* one = ST->lookup($1->loc);
            symbol* two = ST->lookup($3->loc);
            if(two->type.type == ARRAY) {
                string t = ST->gentemp(two->type.nextType);
                emit(t, $3->loc, *($3->folder), ARR_IDX_ARG);
                $3->loc = t;
                $3->type = two->type.nextType;
            }
            if(one->type.type == ARRAY) {
                string t = ST->gentemp(one->type.nextType);
                emit(t, $1->loc, *($1->folder), ARR_IDX_ARG);
                $1->loc = t;
                $1->type = one->type.nextType;
            }
            DataType final = ((one->type.type > two->type.type) ? one->type.type : two->type.type);
            $$->loc = ST->gentemp(final);
            emit($$->loc, $1->loc, $3->loc, DIV);
        }
        | multiplicative_expression MODULO cast_expression
        {
            // Indicates modulo
            $$ = new expression();
            symbol* one = ST->lookup($1->loc);
            symbol* two = ST->lookup($3->loc);
            if(two->type.type == ARRAY) {
                string t = ST->gentemp(two->type.nextType);
                emit(t, $3->loc, *($3->folder), ARR_IDX_ARG);
                $3->loc = t;
                $3->type = two->type.nextType;
            }
            if(one->type.type == ARRAY) {
                string t = ST->gentemp(one->type.nextType);
                emit(t, $1->loc, *($1->folder), ARR_IDX_ARG);
                $1->loc = t;
                $1->type = one->type.nextType;
            }
            DataType final = ((one->type.type > two->type.type) ? one->type.type : two->type.type);
            $$->loc = ST->gentemp(final);
            emit($$->loc, $1->loc, $3->loc, MOD);
        }
        ;

additive_expression: 
        multiplicative_expression
        | additive_expression ADD multiplicative_expression
        {   
            // Indicates addition
            $$ = new expression();
            symbol* one = ST->lookup($1->loc);
            symbol* two = ST->lookup($3->loc);
            if(two->type.type == ARRAY) {
                string t = ST->gentemp(two->type.nextType);
                emit(t, $3->loc, *($3->folder), ARR_IDX_ARG);
                $3->loc = t;
                $3->type = two->type.nextType;
            }
            if(one->type.type == ARRAY) {
                string t = ST->gentemp(one->type.nextType);
                emit(t, $1->loc, *($1->folder), ARR_IDX_ARG);
                $1->loc = t;
                $1->type = one->type.nextType;
            }
            DataType final = ((one->type.type > two->type.type) ? one->type.type : two->type.type);
            $$->loc = ST->gentemp(final);
            emit($$->loc, $1->loc, $3->loc, ADD);
        }
        | additive_expression SUBTRACT multiplicative_expression
        {
            // Indicates subtraction
            $$ = new expression();
            symbol* one = ST->lookup($1->loc);
            symbol* two = ST->lookup($3->loc);
            if(two->type.type == ARRAY) {
                string t = ST->gentemp(two->type.nextType);
                emit(t, $3->loc, *($3->folder), ARR_IDX_ARG);
                $3->loc = t;
                $3->type = two->type.nextType;
            }
            if(one->type.type == ARRAY) {
                string t = ST->gentemp(one->type.nextType);
                emit(t, $1->loc, *($1->folder), ARR_IDX_ARG);
                $1->loc = t;
                $1->type = one->type.nextType;
            }
            DataType final = ((one->type.type > two->type.type) ? one->type.type : two->type.type);
            $$->loc = ST->gentemp(final);
            emit($$->loc, $1->loc, $3->loc, SUB);
        }
        ;

shift_expression: 
        additive_expression
        | shift_expression LSHIFT additive_expression
        {
            // Indicates left shift
            $$ = new expression();
            symbol* one = ST->lookup($1->loc);
            symbol* two = ST->lookup($3->loc);
            if(two->type.type == ARRAY) {
                string t = ST->gentemp(two->type.nextType);
                emit(t, $3->loc, *($3->folder), ARR_IDX_ARG);
                $3->loc = t;
                $3->type = two->type.nextType;
            }
            if(one->type.type == ARRAY) {
                string t = ST->gentemp(one->type.nextType);
                emit(t, $1->loc, *($1->folder), ARR_IDX_ARG);
                $1->loc = t;
                $1->type = one->type.nextType;
            }
            $$->loc = ST->gentemp(one->type.type);
            emit($$->loc, $1->loc, $3->loc, SL);
        }
        | shift_expression RSHIFT additive_expression
        {
            // Indicates right shift
            $$ = new expression();
            symbol* one = ST->lookup($1->loc);
            symbol* two = ST->lookup($3->loc);
            if(two->type.type == ARRAY) {
                string t = ST->gentemp(two->type.nextType);
                emit(t, $3->loc, *($3->folder), ARR_IDX_ARG);
                $3->loc = t;
                $3->type = two->type.nextType;
            }
            if(one->type.type == ARRAY) {
                string t = ST->gentemp(one->type.nextType);
                emit(t, $1->loc, *($1->folder), ARR_IDX_ARG);
                $1->loc = t;
                $1->type = one->type.nextType;
            }
            $$->loc = ST->gentemp(one->type.type);
            emit($$->loc, $1->loc, $3->loc, SR);
        }
        ;

relational_expression: 
        shift_expression
        | relational_expression LESS_THAN shift_expression
        {
            $$ = new expression();
            symbol* one = ST->lookup($1->loc);
            symbol* two = ST->lookup($3->loc);
            if(two->type.type == ARRAY) {
                string t = ST->gentemp(two->type.nextType);
                emit(t, $3->loc, *($3->folder), ARR_IDX_ARG);
                $3->loc = t;
                $3->type = two->type.nextType;
            }
            if(one->type.type == ARRAY) {
                string t = ST->gentemp(one->type.nextType);
                emit(t, $1->loc, *($1->folder), ARR_IDX_ARG);
                $1->loc = t;
                $1->type = one->type.nextType;
            }
            $$->loc = ST->gentemp();
            $$->type = BOOL;
            emit($$->loc, "1", "", ASSIGN);
            $$->truelist = makelist(nextinstr);
            emit("", $1->loc, $3->loc, GOTO_LT);
            emit($$->loc, "0", "", ASSIGN);
            $$->falselist = makelist(nextinstr);
            emit("", "", "", GOTO);
        }
        | relational_expression GREATER_THAN shift_expression
        {
            $$ = new expression();
            symbol* one = ST->lookup($1->loc);
            symbol* two = ST->lookup($3->loc);
            if(two->type.type == ARRAY) {
                string t = ST->gentemp(two->type.nextType);
                emit(t, $3->loc, *($3->folder), ARR_IDX_ARG);
                $3->loc = t;
                $3->type = two->type.nextType;
            }
            if(one->type.type == ARRAY) {
                string t = ST->gentemp(one->type.nextType);
                emit(t, $1->loc, *($1->folder), ARR_IDX_ARG);
                $1->loc = t;
                $1->type = one->type.nextType;
            }
            $$->loc = ST->gentemp();
            $$->type = BOOL;
            emit($$->loc, "1", "", ASSIGN);
            $$->truelist = makelist(nextinstr);
            emit("", $1->loc, $3->loc, GOTO_GT);
            emit($$->loc, "0", "", ASSIGN);
            $$->falselist = makelist(nextinstr);
            emit("", "", "", GOTO);
        }
        | relational_expression LESS_THAN_EQUAL shift_expression
        {
            $$ = new expression();
            symbol* one = ST->lookup($1->loc);
            symbol* two = ST->lookup($3->loc);
            if(two->type.type == ARRAY) {
                string t = ST->gentemp(two->type.nextType);
                emit(t, $3->loc, *($3->folder), ARR_IDX_ARG);
                $3->loc = t;
                $3->type = two->type.nextType;
            }
            if(one->type.type == ARRAY) {
                string t = ST->gentemp(one->type.nextType);
                emit(t, $1->loc, *($1->folder), ARR_IDX_ARG);
                $1->loc = t;
                $1->type = one->type.nextType;
            }
            $$->loc = ST->gentemp();
            $$->type = BOOL;
            emit($$->loc, "1", "", ASSIGN);
            $$->truelist = makelist(nextinstr);
            emit("", $1->loc, $3->loc, GOTO_LTE);
            emit($$->loc, "0", "", ASSIGN);
            $$->falselist = makelist(nextinstr);
            emit("", "", "", GOTO);
        }
        | relational_expression GREATER_THAN_EQUAL shift_expression
        {
            $$ = new expression();
            symbol* one = ST->lookup($1->loc);
            symbol* two = ST->lookup($3->loc);
            if(two->type.type == ARRAY) {
                string t = ST->gentemp(two->type.nextType);
                emit(t, $3->loc, *($3->folder), ARR_IDX_ARG);
                $3->loc = t;
                $3->type = two->type.nextType;
            }
            if(one->type.type == ARRAY) {
                string t = ST->gentemp(one->type.nextType);
                emit(t, $1->loc, *($1->folder), ARR_IDX_ARG);
                $1->loc = t;
                $1->type = one->type.nextType;
            }
            $$->loc = ST->gentemp();
            $$->type = BOOL;
            emit($$->loc, "1", "", ASSIGN);
            $$->truelist = makelist(nextinstr);
            emit("", $1->loc, $3->loc, GOTO_GTE);
            emit($$->loc, "0", "", ASSIGN);
            $$->falselist = makelist(nextinstr);
            emit("", "", "", GOTO);
        }
        ;

equality_expression: 
        relational_expression
        {
            $$ = new expression();
            $$ = $1;    // Simple assignment
        }
        | equality_expression EQUAL relational_expression
        {
            $$ = new expression();
            symbol* one = ST->lookup($1->loc);
            symbol* two = ST->lookup($3->loc);
            if(two->type.type == ARRAY) {
                string t = ST->gentemp(two->type.nextType);
                emit(t, $3->loc, *($3->folder), ARR_IDX_ARG);
                $3->loc = t;
                $3->type = two->type.nextType;
            }
            if(one->type.type == ARRAY) {
                string t = ST->gentemp(one->type.nextType);
                emit(t, $1->loc, *($1->folder), ARR_IDX_ARG);
                $1->loc = t;
                $1->type = one->type.nextType;
            }
            $$->loc = ST->gentemp();
            $$->type = BOOL;
            emit($$->loc, "1", "", ASSIGN);
            $$->truelist = makelist(nextinstr);
            emit("", $1->loc, $3->loc, GOTO_EQ);
            emit($$->loc, "0", "", ASSIGN);
            $$->falselist = makelist(nextinstr);
            emit("", "", "", GOTO);
        }
        | equality_expression NOT_EQUAL relational_expression
        {
            $$ = new expression();
            symbol* one = ST->lookup($1->loc);
            symbol* two = ST->lookup($3->loc);
            if(two->type.type == ARRAY) {
                string t = ST->gentemp(two->type.nextType);
                emit(t, $3->loc, *($3->folder), ARR_IDX_ARG);
                $3->loc = t;
                $3->type = two->type.nextType;
            }
            if(one->type.type == ARRAY) {
                string t = ST->gentemp(one->type.nextType);
                emit(t, $1->loc, *($1->folder), ARR_IDX_ARG);
                $1->loc = t;
                $1->type = one->type.nextType;
            }
            $$->loc = ST->gentemp();
            $$->type = BOOL;
            emit($$->loc, "1", "", ASSIGN);
            $$->truelist = makelist(nextinstr);
            emit("", $1->loc, $3->loc, GOTO_NEQ);
            emit($$->loc, "0", "", ASSIGN);
            $$->falselist = makelist(nextinstr);
            emit("", "", "", GOTO);
        }
        ;

and_expression: 
        equality_expression
        {
            // $$ = $1;    // Simple assignment
        }
        | and_expression BITWISE_AND equality_expression
        {
            $$ = new expression();
            symbol* one = ST->lookup($1->loc);
            symbol* two = ST->lookup($3->loc);
            if(two->type.type == ARRAY) {
                string t = ST->gentemp(two->type.nextType);
                emit(t, $3->loc, *($3->folder), ARR_IDX_ARG);
                $3->loc = t;
                $3->type = two->type.nextType;
            }
            if(one->type.type == ARRAY) {
                string t = ST->gentemp(one->type.nextType);
                emit(t, $1->loc, *($1->folder), ARR_IDX_ARG);
                $1->loc = t;
                $1->type = one->type.nextType;
            }
            $$->loc = ST->gentemp();
            emit($$->loc, $1->loc, $3->loc, BW_AND);
        }
        ;

exclusive_or_expression: 
        and_expression
        {
            $$ = $1;    // Simple assignment
        }
        | exclusive_or_expression BITWISE_XOR and_expression
        {
            $$ = new expression();
            symbol* one = ST->lookup($1->loc);
            symbol* two = ST->lookup($3->loc);
            if(two->type.type == ARRAY) {
                string t = ST->gentemp(two->type.nextType);
                emit(t, $3->loc, *($3->folder), ARR_IDX_ARG);
                $3->loc = t;
                $3->type = two->type.nextType;
            }
            if(one->type.type == ARRAY) {
                string t = ST->gentemp(one->type.nextType);
                emit(t, $1->loc, *($1->folder), ARR_IDX_ARG);
                $1->loc = t;
                $1->type = one->type.nextType;
            }
            $$->loc = ST->gentemp();
            emit($$->loc, $1->loc, $3->loc, BW_XOR);
        }
        ;

inclusive_or_expression: 
        exclusive_or_expression
        {
            $$ = new expression();
            $$ = $1;    // Simple assignment
        }
        | inclusive_or_expression BITWISE_OR exclusive_or_expression
        {
            $$ = new expression();
            symbol* one = ST->lookup($1->loc);
            symbol* two = ST->lookup($3->loc);
            if(two->type.type == ARRAY) {
                string t = ST->gentemp(two->type.nextType);
                emit(t, $3->loc, *($3->folder), ARR_IDX_ARG);
                $3->loc = t;
                $3->type = two->type.nextType;
            }
            if(one->type.type == ARRAY) {
                string t = ST->gentemp(one->type.nextType);
                emit(t, $1->loc, *($1->folder), ARR_IDX_ARG);
                $1->loc = t;
                $1->type = one->type.nextType;
            }
            $$->loc = ST->gentemp();
            emit($$->loc, $1->loc, $3->loc, BW_OR);
        }
        ;

logical_and_expression: 
        inclusive_or_expression
        {
            // $$ = $1;    // Simple assignment
        }
        | logical_and_expression LOGICAL_AND M inclusive_or_expression
        {
            /*
                Here, we have augmented the grammar with the non-terminal M to facilitate backpatching
            */
            backpatch($1->truelist, $3->instr);                            // Backpatching
            $$->falselist = merge($1->falselist, $4->falselist);    // Generate falselist by merging the falselists of $1 and $4
            $$->truelist = $4->truelist;                            // Generate truelist from truelist of $4
            $$->type = BOOL;
        }
        ;

logical_or_expression: 
        logical_and_expression
        {
            // $$ = $1;    // Simple assignment
        }
        | logical_or_expression LOGICAL_OR M logical_and_expression
        {
            backpatch($1->falselist, $3->instr);                            // Backpatching
            $$->truelist = merge($1->truelist, $4->truelist);    // Generate falselist by merging the falselists of $1 and $4
            $$->falselist = $4->falselist;                            // Generate truelist from truelist of $4
            $$->type = BOOL;
        }
        ;

conditional_expression: 
        logical_or_expression
        {
            $$ = $1;    // Simple assignment
        }
        | logical_or_expression N QUESTION_MARK M expression N COLON M conditional_expression
        {   
            /*
                Note the augmented grammar with the non-terminals M and N
            */
            symbol* one = ST->lookup($5->loc);
            $$->loc = ST->gentemp(one->type.type);
            $$->type = one->type.type;
            emit($$->loc, $9->loc, "", ASSIGN);
            list<int> temp = makelist(nextinstr);
            emit("", "", "", GOTO);
            backpatch($6->nextlist, nextinstr);
            emit($$->loc, $5->loc, "", ASSIGN);
            temp = merge(temp, makelist(nextinstr));
            emit("", "", "", GOTO);
            backpatch($2->nextlist, nextinstr);
            convertIntToBool($1);
            backpatch($1->truelist, $4->instr);
            backpatch($1->falselist, $8->instr);
            backpatch($2->nextlist, nextinstr);
        }
        ;

M: %empty
        {   
            // Stores the next instruction value, and helps in backpatching
            $$ = new expression();
            $$->instr = nextinstr;
        }
        ;

N: %empty
        {
            // Helps in control flow
            $$ = new expression();
            $$->nextlist = makelist(nextinstr);
            emit("", "", "", GOTO);
        }
        ;

assignment_expression: 
        conditional_expression
        {
            // $$ = $1;    // Simple assignment
        }
        | unary_expression assignment_operator assignment_expression
        {
            symbol* sym1 = ST->lookup($1->lookup);
            symbol* sym2 = ST->lookup($3->lookup);
            if($1->fold == 0) {
                if(sym1->type.type != ARRAY)
                    emit($1->loc, $3->loc, "", ASSIGN);
                else
                    emit($1->loc, $3->loc, *($1->folder), ARR_IDX_RES);
            }
            else
                emit(*($1->folder), $3->loc, "", L_DEREF);
            $$ = $1;
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
            // $$ = $1;
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
        {
            DataType currType = $1;
            int currSize = -1;
            if(currType == INT || currType == CHAR || currType == FLOAT)
                currSize = sizeOfType(currType);
            vector<declaration*> decs = *($2);
            for(vector<declaration*>::iterator it = decs.begin(); it != decs.end(); it++) {
                declaration* currDec = *it;
                if(currDec->type == FUNCTION) {
                    ST = &globalST;
                    emit(currDec->name, "", "", FUNC_END);
                    symbol* one = ST->lookup(currDec->name);
                    symbol* two = one->nestedTable->lookup("RETVAL", currType, currDec->pointers);
                    one->size = 0;
                    one->initVal = NULL;
                    continue;
                }

                symbol* three = ST->lookup(currDec->name, currType);
                three->nestedTable = NULL;
                if(currDec->li == vector<int>() && currDec->pointers == 0) {
                    three->type.type = currType;
                    three->size = currSize;
                    if(currDec->initVal != NULL) {
                        string rval = currDec->initVal->loc;
                        emit(three->name, rval, "", ASSIGN);
                        three->initVal = ST->lookup(rval)->initVal;
                    }
                    else
                        three->initVal = NULL;
                }
                else if(currDec->li != vector<int>()) {
                    three->type.type = ARRAY;
                    three->type.nextType = currType;
                    three->type.dims = currDec->li;
                    vector<int> temp = three->type.dims;
                    int sz = currSize;
                    for(int i = 0; i < (int)temp.size(); i++)
                        sz *= temp[i];
                    ST->offset += sz;
                    three->size = sz;
                    ST->offset -= 4;
                }
                else if(currDec->pointers != 0) {
                    three->type.type = POINTER;
                    three->type.nextType = currType;
                    three->type.pointers = currDec->pointers;
                    ST->offset += (__POINTER_SIZE - currSize);
                    three->size = __POINTER_SIZE;
                }
            }
        }
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
        {
            $$ = new vector<declaration*>;
            $$->push_back($1);
        }
        | init_declarator_list COMMA init_declarator
        {
            $1->push_back($3);
            $$ = $1;
        }
        ;

init_declarator: 
        declarator
        {
            $$ = $1;
            $$->initVal = NULL;
        }
        | declarator ASSIGN initializer
        {   
            $$ = $1;
            $$->initVal = $3;
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
            $$ = VOID;
        }
        | CHAR
        {
            $$ = CHAR;
        }
        | SHORT
        { /* Ignored */ }
        | INT
        {
            $$ = INT; 
        }
        | LONG
        { /* Ignored */ }
        | FLOAT
        {
            $$ = FLOAT;
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
            $$ = $2;
            $$->pointers = $1;
        }
        | direct_declarator
        {
            $$ = $1;
            $$->pointers = 0;
        }
        ;

direct_declarator: 
        IDENTIFIER
        {
            $$ = new declaration();
            $$->name = *($1);
        }
        | PARENTHESIS_OPEN declarator PARENTHESIS_CLOSE
        {
            // $$ = $2;    // Simple assignment
        }
        | direct_declarator SQUARE_BRACE_OPEN type_qualifier_list_opt SQUARE_BRACE_CLOSE
        {
            $1->type = ARRAY;
            $1->nextType = INT;
            $$ = $1;
            $$->li.push_back(0);
        }
        | direct_declarator SQUARE_BRACE_OPEN type_qualifier_list_opt assignment_expression SQUARE_BRACE_CLOSE
        {
            $1->type = ARRAY;
            $1->nextType = INT;
            $$ = $1;
            int index = ST->lookup($4->loc)->initVal->a;
            $$->li.push_back(index);
        }
        | direct_declarator SQUARE_BRACE_OPEN STATIC type_qualifier_list assignment_expression SQUARE_BRACE_CLOSE
        { /* Ignored */ }
        | direct_declarator SQUARE_BRACE_OPEN STATIC assignment_expression SQUARE_BRACE_CLOSE
        { /* Ignored */ }
        | direct_declarator SQUARE_BRACE_OPEN type_qualifier_list STATIC assignment_expression SQUARE_BRACE_CLOSE
        { /* Ignored */ }
        | direct_declarator SQUARE_BRACE_OPEN type_qualifier_list_opt MULTIPLY SQUARE_BRACE_CLOSE
        {
            $1->type = POINTER;
            $1->nextType = INT;
            $$ = $1;
        }
        | direct_declarator PARENTHESIS_OPEN parameter_type_list_opt PARENTHESIS_CLOSE
        {
            $$ = $1;
            $$->type = FUNCTION;
            symbol* funcData = ST->lookup($$->name, $$->type);
            symbol* funcTable = new symbolTable();
            funcData->nestedTable = funcTable;
            vector<param*> paramList = *($3);
            for(int i = 0; i < (int)paramList.size(); i++) {
                param* curParam = paramList[i];
                if(curParam->type.type == ARRAY) {
                    funcTable->lookup(curParam->name, curParam->type.type);
                    funcTable->lookup(curParam->name)->type.nextType = INT;
                    funcTable->lookup(curParam->name)->type.dims.push_back(0);
                }
                else if(curParam->type.type == POINTER) {
                    funcTable->lookup(curParam->name, curParam->type.type);
                    funcTable->lookup(curParam->name)->type.nextType = INT;
                    funcTable->lookup(curParam->name)->type.dims.push_back(0);
                }
                else
                    funcTable->lookup(curParam->name, curParam->type.type);
            }
            ST = funcTable;
            emit($$->name, "", "", FUNC_BEG);
        }
        | direct_declarator PARENTHESIS_OPEN identifier_list PARENTHESIS_CLOSE
        { /* Ignored */ }
        ;

parameter_type_list_opt:
        parameter_type_list
        {}
        | %empty
        {}
        ;

type_qualifier_list_opt: 
        type_qualifier_list
        { /* Ignored */ }
        | %empty
        { /* Ignored */ }
        ;

pointer: 
        MULTIPLY type_qualifier_list
        {}
        | MULTIPLY
        {
            $$ = 1;
        }
        | MULTIPLY type_qualifier_list pointer
        {}
        | MULTIPLY pointer
        {
            $$ = 1 + $2;
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
        | parameter_list COMMA ELLIPSIS
        ;

parameter_list: 
        parameter_declaration
        {
            $$ = new vector<param*>;
            $$->push_back($1);
        }
        | parameter_list COMMA parameter_declaration
        {
            $1->push_back($3);
            $$ = $1;
        }
        ;

parameter_declaration: 
        declaration_specifiers declarator
        {
            $$ = new param();
            $$->name = $2->name;
            if($2->type == ARRAY) {
                $$->type.type = ARRAY;
                $$->type.nextType = $1;
            }
            else if($2->pc != 0) {
                $$->type.type = POINTER;
                $$->type.nextType = $1;
            }
            else
                $$->type.type = $1;
        }
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
            $$ = $1;   // Simple assignment
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
        | expression_statement
        | selection_statement
        | iteration_statement
        | jump_statement
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
        CURLY_BRACE_OPEN CURLY_BRACE_CLOSE
        {}
        | CURLY_BRACE_OPEN block_item_list CURLY_BRACE_CLOSE
        {
            $$ = $2;
        }
        ;

block_item_list: 
        block_item
        {
            $$ = $1;    // Simple assignment
            backpatch($1->nextlist, nextinstr);
        }
        | block_item_list M block_item
        {   
            /*
                This production rule has been augmented with the non-terminal M
            */
            $$ = new expression();
            backpatch($1->nextlist, $2->instr);    // After $1, move to block_item via $2
            $$->nextlist = $3->nextlist;
        }
        ;

block_item: 
        declaration
        {
            $$ = new expression();   // Create new expression
        }
        | statement
        ;

expression_statement: 
        expression SEMICOLON
        {
            // $$ = $1;    // Simple assignment
        }
        | SEMICOLON
        {
            $$ = new expression();  // Create new expression
        }
        ;

selection_statement: 
        IF PARENTHESIS_OPEN expression N PARENTHESIS_CLOSE M statement N
        {
            /*
                This production rule has been augmented for control flow
            */
            backpatch($4->nextlist, nextinstr);                   // nextlist of N now has nextinstr
            convertIntToBool($3);                                   // Convert expression to bool
            backpatch($3->truelist, $6->instr);                            // Backpatching - if expression is true, go to M
            $$ = new expression();                                   // Create new statement
            // Merge falselist of expression, nextlist of statement and nextlist of the last N
            $7->nextlist = merge($8->nextlist, $7->nextlist);
            $$->nextlist = merge($3->nextlist, $7->nextlist);
        }
        | IF PARENTHESIS_OPEN expression N PARENTHESIS_CLOSE M statement N ELSE M statement N
        {
            /*
                This production rule has been augmented for control flow
            */
            backpatch($4->nextlist, nextinstr);                   // nextlist of N now has nextinstr
            convertIntToBool($3);                                   // Convert expression to bool
            $$ = new statement();                                   // Create new statement
            backpatch($3->truelist, $6->instr);                            // Backpatching - if expression is true, go to first M, else go to second M
            backpatch($3->falselist, $10->instr);
            // Merge nextlist of statement, nextlist of N and nextlist of the last statement
            $$->nextlist = merge($7->nextlist, $8->nextlist);
            $$->nextlist = merge($$->nextlist, $11->nextlist);
            $$->nextlist = merge($$->nextlist, $12->nextlist);
        }
        | SWITCH PARENTHESIS_OPEN expression PARENTHESIS_CLOSE statement
        { /* Ignored */ }
        ;

iteration_statement: 
        WHILE M PARENTHESIS_OPEN expression N PARENTHESIS_CLOSE M statement
        {   
            /*
                This production rule has been augmented with non-terminals like W, X, change_table and M to handle the control flow, 
                backpatching, detect the kind of loop, create a separate symbol table for the loop block and give it an appropriate name
            */
            $$ = new expression();                   // Create a new expression
            emit("", "", "", GOTO);
            backpatch(makelist(nextinstr - 1), $2->instr);
            backpatch($5->nextlist, nextinstr);
            convertIntToBool($4);                   // Convert expression to bool
            $$->nextlist = $4->falselist;
            backpatch($4->truelist, $7->instr);
            backpatch($8->nextlist, $2->instr);
        }
        | DO M statement M WHILE PARENTHESIS_OPEN expression N PARENTHESIS_CLOSE SEMICOLON
        {
            /*
                This production rule has been augmented with non-terminals like D and M to handle the control flow, backpatching and detect the kind of loop
            */
            $$ = new expression();                   // Create a new expression  
            backpatch($8->nextlist, nextinstr);   
            convertIntToBool($7);                   // Convert expression to bool
            backpatch($7->truelist, $2->instr);
            backpatch($3->nextlist, $4->instr);
            $$->nextlist = $7->falselist;
        }
        | FOR PARENTHESIS_OPEN expression_statement M expression_statement N M expression N PARENTHESIS_CLOSE M statement
        {
            /*
                This production rule has been augmented with non-terminals like F, X, change_table and M to handle the control flow, 
                backpatching, detect the kind of loop, create a separate symbol table for the loop block and give it an appropriate name
            */
            $$ = new expression();                   // Create a new expression
            emit("", "", "", GOTO);
            $12->nextlist = merge($12->nextlist, makelist(nextinstr - 1));
            backpatch($12->nextlist, $7->instr);
            backpatch($9->nextlist, $4->instr);
            backpatch($6->nextlist, nextinstr);
            convertIntToBool($5);                   // Convert expression to bool
            backpatch($5->truelist, $11->instr);
            $$->nextlist = $5->falselist;
        }
        ;

jump_statement: 
        GOTO IDENTIFIER SEMICOLON
        { /* Ignored */ }
        | CONTINUE SEMICOLON
        {}
        | BREAK SEMICOLON
        {}
        | RETURN expression SEMICOLON
        {
            $$ = new expression();
            if(ST->lookup("RETVAL")->type.type == ST->lookup($2->loc)->type.type)
                emit($2->loc, "", "", RETURN);
        }
        | RETURN SEMICOLON
        {
            $$ = new expression();
            if(ST->lookup("RETVAL")->type.type == VOID)
                emit("", "", "", RETURN);
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
        declaration_specifiers declarator declaration_list compound_statement
        {}
        | function_prototype compound_statement
        {
            ST = &globalST;
            emit($1->name, "", "", FUNC_END);
        }
        ;

function_prototype:
        declaration_specifiers declarator
        {
            DataType currType = $1;
            int currSize = -1;
            if(currType == INT || currType == CHAR || currType == FLOAT)
                currSize = sizeOfType(currType);
            declaration* currDec = $2;
            symbol* sym = globalST.lookup(currDec->name);
            if(currDec->type == FUNCTION) {
                symbol* retval = sym->nestedTable->lookup("RETVAL", currType, currDec->pointers);
                sym->size = 0;
                sym->initVal = NULL;
            }
            $$ = $2;
        }
        ;

declaration_list: 
        declaration
        { /* Ignored */ }
        | declaration_list declaration
        { /* Ignored */ }
        ;

%%

void yyerror(string s) {
    /*
        This function prints any error encountered while parsing
    */
    cout << "Error occurred: " << s << endl;
    cout << "Line no.: " << yylineno << endl;
    cout << "Unable to parse: " << yytext << endl; 
}
