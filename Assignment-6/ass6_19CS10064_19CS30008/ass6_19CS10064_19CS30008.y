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

    extern int yylex();                     // From lexer
    void yyerror(string s);                 // Function to report errors
    extern char* yytext;                    // From lexer, gives the text being currently scanned
    extern int yylineno;                    // Used for keeping track of the line number

    extern int nextinstr;                   // Used for keeping track of the next instruction
    extern quadArray quadList;              // List of all quads
    extern symbolTable globalST;            // Global symbol table
    extern symbolTable* ST;                 // Pointer to the current symbol table
    extern vector<string> stringConsts;     // List of all string constants

    int strCount = 0;                       // Counter for string constants
%}

%union {
    int intval;                     // For an integer value
    char charval;                   // For a char value
    float floatval;                 // For a float value
    void* ptr;                      // For a pointer
    string* str;                    // For a string
    symbolType* symType;            // For the type of a symbol
    symbol* symp;                   // For a symbol
    DataType types;                 // For the type of an expression
    opcode opc;                     // For an opcode
    expression* expr;               // For an expression
    declaration* dec;               // For a declaration
    vector<declaration*> *decList;  // For a list of declarations
    param* prm;                     // For a parameter
    vector<param*> *prmList;        // For a list of parameters
}

/*
    All tokens
*/
%token AUTO BREAK CASE CHAR_ CONST CONTINUE DEFAULT DO DOUBLE ELSE ENUM EXTERN FLOAT_ FOR GOTO_ IF INLINE INT_ LONG REGISTER RESTRICT RETURN_ SHORT SIGNED SIZEOF STATIC STRUCT SWITCH TYPEDEF UNION UNSIGNED VOID_ VOLATILE WHILE BOOL_ COMPLEX IMAGINARY
%token SQUARE_BRACE_OPEN SQUARE_BRACE_CLOSE PARENTHESIS_OPEN PARENTHESIS_CLOSE CURLY_BRACE_OPEN CURLY_BRACE_CLOSE 
%token DOT ARROW INCREMENT DECREMENT BITWISE_AND MULTIPLY ADD_ SUBTRACT BITWISE_NOR NOT DIVIDE MODULO 
%token LSHIFT RSHIFT LESS_THAN GREATER_THAN LESS_THAN_EQUAL GREATER_THAN_EQUAL EQUAL NOT_EQUAL BITWISE_XOR BITWISE_OR 
%token LOGICAL_AND LOGICAL_OR QUESTION_MARK COLON SEMICOLON ELLIPSIS 
%token ASSIGN_ MULTIPLY_ASSIGN DIVIDE_ASSIGN MODULO_ASSIGN ADD_ASSIGN SUBTRACT_ASSIGN LSHIFT_ASSIGN RSHIFT_ASSIGN AND_ASSIGN XOR_ASSIGN OR_ASSIGN COMMA HASH

// Identifiers are treated with type str
%token <str> IDENTIFIER

// Integer constants have a type intval
%token <intval> INTEGER_CONSTANT

// Floating constants have a type floatval
%token <floatval> FLOATING_CONSTANT

// Character constants have a type charval
%token <charval> CHAR_CONSTANT

// String literals have a type str
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

// Non-terminals of type charval (unary operator)
%type <charval> unary_operator

// The pointer non-terminal is treated with type intval
%type <intval> pointer

// Non-terminals of type DataType (denoting types)
%type <types> type_specifier declaration_specifiers

// Non-terminals of type declaration
%type <dec> direct_declarator initializer_list init_declarator declarator function_prototype

// Non-terminals of type decList
%type <decList> init_declarator_list

// Non-terminals of type param
%type <prm> parameter_declaration

// Non-terminals of type prmList
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
            ST->lookup(s);          // Store entry in the symbol table
            $$->loc = s;            // Store pointer to string identifier name
        }
        | INTEGER_CONSTANT
        {
            $$ = new expression();                  // Create new expression
            $$->loc = ST->gentemp(INT);             // Generate a new temporary variable
            emit($$->loc, $1, ASSIGN);
            symbolValue* val = new symbolValue();
            val->setInitVal($1);                    // Set the initial value
            ST->lookup($$->loc)->initVal = val;     // Store in symbol table
        }
        | FLOATING_CONSTANT
        {
            $$ = new expression();                  // Create new expression
            $$->loc = ST->gentemp(FLOAT);           // Generate a new temporary variable
            emit($$->loc, $1, ASSIGN);
            symbolValue* val = new symbolValue();
            val->setInitVal($1);                    // Set the initial value
            ST->lookup($$->loc)->initVal = val;     // Store in symbol table
        }
        | CHAR_CONSTANT
        {
            $$ = new expression();                  // Create new expression
            $$->loc = ST->gentemp(CHAR);            // Generate a new temporary variable
            emit($$->loc, $1, ASSIGN);
            symbolValue* val = new symbolValue();
            val->setInitVal($1);                    // Set the initial value
            ST->lookup($$->loc)->initVal = val;     // Store in symbol table
        }
        | STRING_LITERAL
        {
            $$ = new expression();                  // Create new expression
            $$->loc = ".LC" + to_string(strCount++);
            stringConsts.push_back(*($1));          // Add to the list of string constants
        }
        | PARENTHESIS_OPEN expression PARENTHESIS_CLOSE
        {
            $$ = $2;                                // Simple assignment
        }
        ;

postfix_expression: 
        primary_expression
        {}
        | postfix_expression SQUARE_BRACE_OPEN expression SQUARE_BRACE_CLOSE
        {
            symbolType to = ST->lookup($1->loc)->type;      // Get the type of the expression
            string f = "";
            if(!($1->fold)) {
                f = ST->gentemp(INT);                       // Generate a new temporary variable
                emit(f, 0, ASSIGN);
                $1->folder = new string(f);
            }
            string temp = ST->gentemp(INT);

            // Emit the necessary quads
            emit(temp, $3->loc, "", ASSIGN);
            emit(temp, temp, "4", MULT);
            emit(f, temp, "", ASSIGN);
            $$ = $1;
        }
        | postfix_expression PARENTHESIS_OPEN PARENTHESIS_CLOSE
        {   
            // Corresponds to calling a function with the function name but without any arguments
            symbolTable* funcTable = globalST.lookup($1->loc)->nestedTable;
            emit($1->loc, "0", "", CALL);
        }
        | postfix_expression PARENTHESIS_OPEN argument_expression_list PARENTHESIS_CLOSE
        {   
            // Corresponds to calling a function with the function name and the appropriate number of arguments
            symbolTable* funcTable = globalST.lookup($1->loc)->nestedTable;
            vector<param*> parameters = *($3);                          // Get the list of parameters
            vector<symbol*> paramsList = funcTable->symbols;

            for(int i = 0; i < (int)parameters.size(); i++) {
                emit(parameters[i]->name, "", "", PARAM);               // Emit the parameters
            }

            DataType retType = funcTable->lookup("RETVAL")->type.type;  // Add an entry in the symbol table for the return value
            if(retType == VOID)                                         // If the function returns void
                emit($1->loc, (int)parameters.size(), CALL);
            else {                                                      // If the function returns a value
                string retVal = ST->gentemp(retType);
                emit($1->loc, to_string(parameters.size()), retVal, CALL);
                $$ = new expression();
                $$->loc = retVal;
            }
        }
        | postfix_expression DOT IDENTIFIER
        {}
        | postfix_expression ARROW IDENTIFIER
        {}
        | postfix_expression INCREMENT
        {   
            $$ = new expression();                                          // Create new expression
            symbolType t = ST->lookup($1->loc)->type;                       // Get the type of the expression and generate a temporary variable
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
                emit($$->loc, $1->loc, "", ASSIGN);                         // Assign the old value 
                emit($1->loc, $1->loc, "1", ADD);                           // Increment the value
            }
        }
        | postfix_expression DECREMENT
        {
            $$ = new expression();                                          // Create new expression
            $$->loc = ST->gentemp(ST->lookup($1->loc)->type.type);          // Generate a new temporary variable
            symbolType t = ST->lookup($1->loc)->type;
            if(t.type == ARRAY) {
                $$->loc = ST->gentemp(ST->lookup($1->loc)->type.nextType);
                string temp = ST->gentemp(t.nextType);
                emit(temp, $1->loc, *($1->folder), ARR_IDX_ARG);
                emit($$->loc, temp, "", ASSIGN);
                emit(temp, temp, "1", SUB);
                emit($1->loc, temp, *($1->folder), ARR_IDX_RES);
            }
            else {
                $$->loc = ST->gentemp(ST->lookup($1->loc)->type.type);
                emit($$->loc, $1->loc, "", ASSIGN);                         // Assign the old value
                emit($1->loc, $1->loc, "1", SUB);                           // Decrement the value
            }
        }
        | PARENTHESIS_OPEN type_name PARENTHESIS_CLOSE CURLY_BRACE_OPEN initializer_list CURLY_BRACE_CLOSE
        {}
        | PARENTHESIS_OPEN type_name PARENTHESIS_CLOSE CURLY_BRACE_OPEN initializer_list COMMA CURLY_BRACE_CLOSE
        {}
        ;

argument_expression_list: 
        assignment_expression
        {
            param* first = new param();                 // Create a new parameter
            first->name = $1->loc;
            first->type = ST->lookup($1->loc)->type;
            $$ = new vector<param*>;
            $$->push_back(first);                       // Add the parameter to the list
        }
        | argument_expression_list COMMA assignment_expression
        {
            param* next = new param();                  // Create a new parameter
            next->name = $3->loc;
            next->type = ST->lookup(next->name)->type;
            $$ = $1;
            $$->push_back(next);                        // Add the parameter to the list
        }
        ;

unary_expression: 
        postfix_expression
        {}
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
                emit($2->loc, $2->loc, "1", ADD);                       // Increment the value
                $$->loc = ST->gentemp(ST->lookup($2->loc)->type.type);
            }
            $$->loc = ST->gentemp(ST->lookup($2->loc)->type.type);
            emit($$->loc, $2->loc, "", ASSIGN);                         // Assign the value
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
                emit($2->loc, $2->loc, "1", SUB);                       // Decrement the value
                $$->loc = ST->gentemp(ST->lookup($2->loc)->type.type);
            }
            emit($$->loc, $2->loc, "", ASSIGN);                         // Assign the value
        }
        | unary_operator cast_expression
        {
            // Case of unary operator
            switch($1) {
                case '&':   // Address
                    $$ = new expression();
                    $$->loc = ST->gentemp(POINTER);                 // Generate temporary of the same base type
                    emit($$->loc, $2->loc, "", REFERENCE);          // Emit the quad
                    break;
                case '*':   // De-referencing
                    $$ = new expression();
                    $$->loc = ST->gentemp(INT);                     // Generate temporary of the same base type
                    $$->fold = 1;
                    $$->folder = new string($2->loc);
                    emit($$->loc, $2->loc, "", DEREFERENCE);        // Emit the quad
                    break;
                case '-':   // Unary minus
                    $$ = new expression();
                    $$->loc = ST->gentemp();                        // Generate temporary of the same base type
                    emit($$->loc, $2->loc, "", U_MINUS);            // Emit the quad
                    break;
                case '!':   // Logical not 
                    $$ = new expression();
                    $$->loc = ST->gentemp(INT);                     // Generate temporary of the same base type
                    int temp = nextinstr + 2;
                    emit(to_string(temp), $2->loc, "0", GOTO_EQ);   // Emit the quads
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
        {}
        | SIZEOF PARENTHESIS_OPEN type_name PARENTHESIS_CLOSE
        {}
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
        | ADD_
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
            $$ = new expression();                                  // Generate new expression
            symbolType tp = ST->lookup($1->loc)->type;
            if(tp.type == ARRAY) {                                  // If the type is an array
                string t = ST->gentemp(tp.nextType);                // Generate a temporary
                if($1->folder != NULL) {
                    emit(t, $1->loc, *($1->folder), ARR_IDX_ARG);   // Emit the necessary quad
                    $1->loc = t;
                    $1->type = tp.nextType;
                    $$ = $1;
                }
                else
                    $$ = $1;        // Simple assignment
            }
            else
                $$ = $1;            // Simple assignment
        }
        | multiplicative_expression MULTIPLY cast_expression
        {   
            // Indicates multiplication
            $$ = new expression();
            symbol* one = ST->lookup($1->loc);                  // Get the first operand from the symbol table
            symbol* two = ST->lookup($3->loc);                  // Get the second operand from the symbol table
            if(two->type.type == ARRAY) {                       // If the second operand is an array, perform necessary operations
                string t = ST->gentemp(two->type.nextType);
                emit(t, $3->loc, *($3->folder), ARR_IDX_ARG);
                $3->loc = t;
                $3->type = two->type.nextType;
            }
            if(one->type.type == ARRAY) {                       // If the first operand is an array, perform necessary operations
                string t = ST->gentemp(one->type.nextType);
                emit(t, $1->loc, *($1->folder), ARR_IDX_ARG);
                $1->loc = t;
                $1->type = one->type.nextType;
            }

            // Assign the result of the multiplication to the higher data type
            DataType final = ((one->type.type > two->type.type) ? (one->type.type) : (two->type.type));
            $$->loc = ST->gentemp(final);                       // Store the final result in a temporary
            emit($$->loc, $1->loc, $3->loc, MULT);
        }
        | multiplicative_expression DIVIDE cast_expression
        {
            // Indicates division
            $$ = new expression();
            symbol* one = ST->lookup($1->loc);                  // Get the first operand from the symbol table
            symbol* two = ST->lookup($3->loc);                  // Get the second operand from the symbol table
            if(two->type.type == ARRAY) {                       // If the second operand is an array, perform necessary operations
                string t = ST->gentemp(two->type.nextType);
                emit(t, $3->loc, *($3->folder), ARR_IDX_ARG);
                $3->loc = t;
                $3->type = two->type.nextType;
            }
            if(one->type.type == ARRAY) {                       // If the first operand is an array, perform necessary operations
                string t = ST->gentemp(one->type.nextType);
                emit(t, $1->loc, *($1->folder), ARR_IDX_ARG);
                $1->loc = t;
                $1->type = one->type.nextType;
            }

            // Assign the result of the division to the higher data type
            DataType final = ((one->type.type > two->type.type) ? (one->type.type) : (two->type.type));
            $$->loc = ST->gentemp(final);                       // Store the final result in a temporary
            emit($$->loc, $1->loc, $3->loc, DIV);
        }
        | multiplicative_expression MODULO cast_expression
        {
            // Indicates modulo
            $$ = new expression();
            symbol* one = ST->lookup($1->loc);                  // Get the first operand from the symbol table
            symbol* two = ST->lookup($3->loc);                  // Get the second operand from the symbol table
            if(two->type.type == ARRAY) {                       // If the second operand is an array, perform necessary operations
                string t = ST->gentemp(two->type.nextType);
                emit(t, $3->loc, *($3->folder), ARR_IDX_ARG);
                $3->loc = t;
                $3->type = two->type.nextType;
            }
            if(one->type.type == ARRAY) {                       // If the first operand is an array, perform necessary operations
                string t = ST->gentemp(one->type.nextType);
                emit(t, $1->loc, *($1->folder), ARR_IDX_ARG);
                $1->loc = t;
                $1->type = one->type.nextType;
            }

            // Assign the result of the modulo to the higher data type
            DataType final = ((one->type.type > two->type.type) ? (one->type.type) : (two->type.type));
            $$->loc = ST->gentemp(final);                       // Store the final result in a temporary
            emit($$->loc, $1->loc, $3->loc, MOD);
        }
        ;

additive_expression: 
        multiplicative_expression
        {}
        | additive_expression ADD_ multiplicative_expression
        {   
            // Indicates addition
            $$ = new expression();
            symbol* one = ST->lookup($1->loc);                  // Get the first operand from the symbol table
            symbol* two = ST->lookup($3->loc);                  // Get the second operand from the symbol table
            if(two->type.type == ARRAY) {                       // If the second operand is an array, perform necessary operations
                string t = ST->gentemp(two->type.nextType);
                emit(t, $3->loc, *($3->folder), ARR_IDX_ARG);
                $3->loc = t;
                $3->type = two->type.nextType;
            }
            if(one->type.type == ARRAY) {                       // If the first operand is an array, perform necessary operations
                string t = ST->gentemp(one->type.nextType);
                emit(t, $1->loc, *($1->folder), ARR_IDX_ARG);
                $1->loc = t;
                $1->type = one->type.nextType;
            }

            // Assign the result of the addition to the higher data type
            DataType final = ((one->type.type > two->type.type) ? (one->type.type) : (two->type.type));
            $$->loc = ST->gentemp(final);                       // Store the final result in a temporary
            emit($$->loc, $1->loc, $3->loc, ADD);
        }
        | additive_expression SUBTRACT multiplicative_expression
        {
            // Indicates subtraction
            $$ = new expression();
            symbol* one = ST->lookup($1->loc);                  // Get the first operand from the symbol table
            symbol* two = ST->lookup($3->loc);                  // Get the second operand from the symbol table
            if(two->type.type == ARRAY) {                       // If the second operand is an array, perform necessary operations
                string t = ST->gentemp(two->type.nextType);
                emit(t, $3->loc, *($3->folder), ARR_IDX_ARG);
                $3->loc = t;
                $3->type = two->type.nextType;
            }
            if(one->type.type == ARRAY) {                       // If the first operand is an array, perform necessary operations
                string t = ST->gentemp(one->type.nextType);
                emit(t, $1->loc, *($1->folder), ARR_IDX_ARG);
                $1->loc = t;
                $1->type = one->type.nextType;
            }

            // Assign the result of the subtraction to the higher data type
            DataType final = ((one->type.type > two->type.type) ? (one->type.type) : (two->type.type));
            $$->loc = ST->gentemp(final);                       // Store the final result in a temporary
            emit($$->loc, $1->loc, $3->loc, SUB);
        }
        ;

shift_expression: 
        additive_expression
        {}
        | shift_expression LSHIFT additive_expression
        {
            // Indicates left shift
            $$ = new expression();
            symbol* one = ST->lookup($1->loc);                  // Get the first operand from the symbol table
            symbol* two = ST->lookup($3->loc);                  // Get the second operand from the symbol table
            if(two->type.type == ARRAY) {                       // If the second operand is an array, perform necessary operations
                string t = ST->gentemp(two->type.nextType);
                emit(t, $3->loc, *($3->folder), ARR_IDX_ARG);
                $3->loc = t;
                $3->type = two->type.nextType;
            }
            if(one->type.type == ARRAY) {                       // If the first operand is an array, perform necessary operations
                string t = ST->gentemp(one->type.nextType);
                emit(t, $1->loc, *($1->folder), ARR_IDX_ARG);
                $1->loc = t;
                $1->type = one->type.nextType;
            }
            $$->loc = ST->gentemp(one->type.type);              // Assign the result of the left shift to the data type of the left operand
            emit($$->loc, $1->loc, $3->loc, SL);
        }
        | shift_expression RSHIFT additive_expression
        {
            // Indicates right shift
            $$ = new expression();
            symbol* one = ST->lookup($1->loc);                  // Get the first operand from the symbol table
            symbol* two = ST->lookup($3->loc);                  // Get the second operand from the symbol table
            if(two->type.type == ARRAY) {                       // If the second operand is an array, perform necessary operations
                string t = ST->gentemp(two->type.nextType);
                emit(t, $3->loc, *($3->folder), ARR_IDX_ARG);
                $3->loc = t;
                $3->type = two->type.nextType;
            }
            if(one->type.type == ARRAY) {                       // If the first operand is an array, perform necessary operations
                string t = ST->gentemp(one->type.nextType);
                emit(t, $1->loc, *($1->folder), ARR_IDX_ARG);
                $1->loc = t;
                $1->type = one->type.nextType;
            }
            $$->loc = ST->gentemp(one->type.type);              // Assign the result of the right shift to the data type of the left operand
            emit($$->loc, $1->loc, $3->loc, SR);
        }
        ;

relational_expression: 
        shift_expression
        {}
        | relational_expression LESS_THAN shift_expression
        {
            $$ = new expression();
            symbol* one = ST->lookup($1->loc);                  // Get the first operand from the symbol table
            symbol* two = ST->lookup($3->loc);                  // Get the second operand from the symbol table
            if(two->type.type == ARRAY) {                       // If the second operand is an array, perform necessary operations
                string t = ST->gentemp(two->type.nextType);
                emit(t, $3->loc, *($3->folder), ARR_IDX_ARG);
                $3->loc = t;
                $3->type = two->type.nextType;
            }
            if(one->type.type == ARRAY) {                       // If the first operand is an array, perform necessary operations
                string t = ST->gentemp(one->type.nextType);
                emit(t, $1->loc, *($1->folder), ARR_IDX_ARG);
                $1->loc = t;
                $1->type = one->type.nextType;
            }
            $$ = new expression();
            $$->loc = ST->gentemp();
            $$->type = BOOL;                                    // Assign the result of the relational expression to a boolean
            emit($$->loc, "1", "", ASSIGN);
            $$->truelist = makelist(nextinstr);                 // Set the truelist to the next instruction
            emit("", $1->loc, $3->loc, GOTO_LT);                // Emit "if x < y goto ..."
            emit($$->loc, "0", "", ASSIGN);
            $$->falselist = makelist(nextinstr);                // Set the falselist to the next instruction
            emit("", "", "", GOTO);                             // Emit "goto ..."
        }
        | relational_expression GREATER_THAN shift_expression
        {
            $$ = new expression();
            symbol* one = ST->lookup($1->loc);                  // Get the first operand from the symbol table
            symbol* two = ST->lookup($3->loc);                  // Get the second operand from the symbol table
            if(two->type.type == ARRAY) {                       // If the second operand is an array, perform necessary operations
                string t = ST->gentemp(two->type.nextType);
                emit(t, $3->loc, *($3->folder), ARR_IDX_ARG);
                $3->loc = t;
                $3->type = two->type.nextType;
            }
            if(one->type.type == ARRAY) {                       // If the first operand is an array, perform necessary operations
                string t = ST->gentemp(one->type.nextType);
                emit(t, $1->loc, *($1->folder), ARR_IDX_ARG);
                $1->loc = t;
                $1->type = one->type.nextType;
            }
            $$ = new expression();
            $$->loc = ST->gentemp();
            $$->type = BOOL;                                    // Assign the result of the relational expression to a boolean
            emit($$->loc, "1", "", ASSIGN);
            $$->truelist = makelist(nextinstr);                 // Set the truelist to the next instruction
            emit("", $1->loc, $3->loc, GOTO_GT);                // Emit "if x > y goto ..."
            emit($$->loc, "0", "", ASSIGN);
            $$->falselist = makelist(nextinstr);                // Set the falselist to the next instruction
            emit("", "", "", GOTO);                             // Emit "goto ..."
        }
        | relational_expression LESS_THAN_EQUAL shift_expression
        {
            $$ = new expression();
            symbol* one = ST->lookup($1->loc);                  // Get the first operand from the symbol table
            symbol* two = ST->lookup($3->loc);                  // Get the second operand from the symbol table
            if(two->type.type == ARRAY) {                       // If the second operand is an array, perform necessary operations
                string t = ST->gentemp(two->type.nextType);
                emit(t, $3->loc, *($3->folder), ARR_IDX_ARG);
                $3->loc = t;
                $3->type = two->type.nextType;
            }
            if(one->type.type == ARRAY) {                       // If the first operand is an array, perform necessary operations
                string t = ST->gentemp(one->type.nextType);
                emit(t, $1->loc, *($1->folder), ARR_IDX_ARG);
                $1->loc = t;
                $1->type = one->type.nextType;
            }
            $$ = new expression();
            $$->loc = ST->gentemp();
            $$->type = BOOL;                                    // Assign the result of the relational expression to a boolean
            emit($$->loc, "1", "", ASSIGN);
            $$->truelist = makelist(nextinstr);                 // Set the truelist to the next instruction
            emit("", $1->loc, $3->loc, GOTO_LTE);               // Emit "if x <= y goto ..."
            emit($$->loc, "0", "", ASSIGN);
            $$->falselist = makelist(nextinstr);                // Set the falselist to the next instruction
            emit("", "", "", GOTO);                             // Emit "goto ..."
        }
        | relational_expression GREATER_THAN_EQUAL shift_expression
        {
            $$ = new expression();
            symbol* one = ST->lookup($1->loc);                  // Get the first operand from the symbol table
            symbol* two = ST->lookup($3->loc);                  // Get the second operand from the symbol table
            if(two->type.type == ARRAY) {                       // If the second operand is an array, perform necessary operations
                string t = ST->gentemp(two->type.nextType);
                emit(t, $3->loc, *($3->folder), ARR_IDX_ARG);
                $3->loc = t;
                $3->type = two->type.nextType;
            }
            if(one->type.type == ARRAY) {                       // If the first operand is an array, perform necessary operations
                string t = ST->gentemp(one->type.nextType);
                emit(t, $1->loc, *($1->folder), ARR_IDX_ARG);
                $1->loc = t;
                $1->type = one->type.nextType;
            }
            $$ = new expression();
            $$->loc = ST->gentemp();
            $$->type = BOOL;                                    // Assign the result of the relational expression to a boolean
            emit($$->loc, "1", "", ASSIGN);
            $$->truelist = makelist(nextinstr);                 // Set the truelist to the next instruction
            emit("", $1->loc, $3->loc, GOTO_GTE);               // Emit "if x >= y goto ..."
            emit($$->loc, "0", "", ASSIGN);
            $$->falselist = makelist(nextinstr);                // Set the falselist to the next instruction
            emit("", "", "", GOTO);                             // Emit "goto ..."
        }
        ;

equality_expression: 
        relational_expression
        {
            $$ = new expression();
            $$ = $1;                // Simple assignment
        }
        | equality_expression EQUAL relational_expression
        {
            $$ = new expression();
            symbol* one = ST->lookup($1->loc);                  // Get the first operand from the symbol table
            symbol* two = ST->lookup($3->loc);                  // Get the second operand from the symbol table
            if(two->type.type == ARRAY) {                       // If the second operand is an array, perform necessary operations
                string t = ST->gentemp(two->type.nextType);
                emit(t, $3->loc, *($3->folder), ARR_IDX_ARG);
                $3->loc = t;
                $3->type = two->type.nextType;
            }
            if(one->type.type == ARRAY) {                       // If the first operand is an array, perform necessary operations
                string t = ST->gentemp(one->type.nextType);
                emit(t, $1->loc, *($1->folder), ARR_IDX_ARG);
                $1->loc = t;
                $1->type = one->type.nextType;
            }
            $$ = new expression();
            $$->loc = ST->gentemp();
            $$->type = BOOL;                                    // Assign the result of the relational expression to a boolean
            emit($$->loc, "1", "", ASSIGN);
            $$->truelist = makelist(nextinstr);                 // Set the truelist to the next instruction
            emit("", $1->loc, $3->loc, GOTO_EQ);                // Emit "if x == y goto ..."
            emit($$->loc, "0", "", ASSIGN);
            $$->falselist = makelist(nextinstr);                // Set the falselist to the next instruction
            emit("", "", "", GOTO);                             // Emit "goto ..."
        }
        | equality_expression NOT_EQUAL relational_expression
        {
            $$ = new expression();
            symbol* one = ST->lookup($1->loc);                  // Get the first operand from the symbol table
            symbol* two = ST->lookup($3->loc);                  // Get the second operand from the symbol table
            if(two->type.type == ARRAY) {                       // If the second operand is an array, perform necessary operations
                string t = ST->gentemp(two->type.nextType);
                emit(t, $3->loc, *($3->folder), ARR_IDX_ARG);
                $3->loc = t;
                $3->type = two->type.nextType;
            }
            if(one->type.type == ARRAY) {                       // If the first operand is an array, perform necessary operations
                string t = ST->gentemp(one->type.nextType);
                emit(t, $1->loc, *($1->folder), ARR_IDX_ARG);
                $1->loc = t;
                $1->type = one->type.nextType;
            }
            $$ = new expression();
            $$->loc = ST->gentemp();
            $$->type = BOOL;                                    // Assign the result of the relational expression to a boolean
            emit($$->loc, "1", "", ASSIGN);
            $$->truelist = makelist(nextinstr);                 // Set the truelist to the next instruction
            emit("", $1->loc, $3->loc, GOTO_NEQ);               // Emit "if x != y goto ..."
            emit($$->loc, "0", "", ASSIGN);
            $$->falselist = makelist(nextinstr);                // Set the falselist to the next instruction
            emit("", "", "", GOTO);                             // Emit "goto ..."
        }
        ;

and_expression: 
        equality_expression
        {}
        | and_expression BITWISE_AND equality_expression
        {
            $$ = new expression();
            symbol* one = ST->lookup($1->loc);                  // Get the first operand from the symbol table
            symbol* two = ST->lookup($3->loc);                  // Get the second operand from the symbol table
            if(two->type.type == ARRAY) {                       // If the second operand is an array, perform necessary operations
                string t = ST->gentemp(two->type.nextType);
                emit(t, $3->loc, *($3->folder), ARR_IDX_ARG);
                $3->loc = t;
                $3->type = two->type.nextType;
            }
            if(one->type.type == ARRAY) {                       // If the first operand is an array, perform necessary operations
                string t = ST->gentemp(one->type.nextType);
                emit(t, $1->loc, *($1->folder), ARR_IDX_ARG);
                $1->loc = t;
                $1->type = one->type.nextType;
            }
            $$ = new expression();
            $$->loc = ST->gentemp();                            // Create a temporary variable to store the result
            emit($$->loc, $1->loc, $3->loc, BW_AND);            // Emit the quad
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
            symbol* one = ST->lookup($1->loc);                  // Get the first operand from the symbol table
            symbol* two = ST->lookup($3->loc);                  // Get the second operand from the symbol table
            if(two->type.type == ARRAY) {                       // If the second operand is an array, perform necessary operations
                string t = ST->gentemp(two->type.nextType);
                emit(t, $3->loc, *($3->folder), ARR_IDX_ARG);
                $3->loc = t;
                $3->type = two->type.nextType;
            }
            if(one->type.type == ARRAY) {                       // If the first operand is an array, perform necessary operations
                string t = ST->gentemp(one->type.nextType);
                emit(t, $1->loc, *($1->folder), ARR_IDX_ARG);
                $1->loc = t;
                $1->type = one->type.nextType;
            }
            $$ = new expression();
            $$->loc = ST->gentemp();                            // Create a temporary variable to store the result
            emit($$->loc, $1->loc, $3->loc, BW_XOR);            // Emit the quad
        }
        ;

inclusive_or_expression: 
        exclusive_or_expression
        {
            $$ = new expression();
            $$ = $1;                // Simple assignment
        }
        | inclusive_or_expression BITWISE_OR exclusive_or_expression
        {
            $$ = new expression();
            symbol* one = ST->lookup($1->loc);                  // Get the first operand from the symbol table
            symbol* two = ST->lookup($3->loc);                  // Get the second operand from the symbol table
            if(two->type.type == ARRAY) {                       // If the second operand is an array, perform necessary operations
                string t = ST->gentemp(two->type.nextType);
                emit(t, $3->loc, *($3->folder), ARR_IDX_ARG);
                $3->loc = t;
                $3->type = two->type.nextType;
            }
            if(one->type.type == ARRAY) {                       // If the first operand is an array, perform necessary operations
                string t = ST->gentemp(one->type.nextType);
                emit(t, $1->loc, *($1->folder), ARR_IDX_ARG);
                $1->loc = t;
                $1->type = one->type.nextType;
            }
            $$ = new expression();
            $$->loc = ST->gentemp();                            // Create a temporary variable to store the result
            emit($$->loc, $1->loc, $3->loc, BW_OR);             // Emit the quad
        }
        ;

logical_and_expression: 
        inclusive_or_expression
        {}
        | logical_and_expression LOGICAL_AND M inclusive_or_expression
        {
            /*
                Here, we have augmented the grammar with the non-terminal M to facilitate backpatching
            */
            backpatch($1->truelist, $3->instr);                     // Backpatching
            $$->falselist = merge($1->falselist, $4->falselist);    // Generate falselist by merging the falselists of $1 and $4
            $$->truelist = $4->truelist;                            // Generate truelist from truelist of $4
            $$->type = BOOL;                                        // Set the type of the expression to boolean
        }
        ;

logical_or_expression: 
        logical_and_expression
        {}
        | logical_or_expression LOGICAL_OR M logical_and_expression
        {
            backpatch($1->falselist, $3->instr);                    // Backpatching
            $$->truelist = merge($1->truelist, $4->truelist);       // Generate falselist by merging the falselists of $1 and $4
            $$->falselist = $4->falselist;                          // Generate truelist from truelist of $4
            $$->type = BOOL;                                        // Set the type of the expression to boolean
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
            $$->loc = ST->gentemp(one->type.type);      // Create a temporary for the expression
            $$->type = one->type.type;
            emit($$->loc, $9->loc, "", ASSIGN);         // Assign the conditional expression
            list<int> temp = makelist(nextinstr);
            emit("", "", "", GOTO);                     // Prevent fall-through
            backpatch($6->nextlist, nextinstr);         // Backpatch with nextinstr
            emit($$->loc, $5->loc, "", ASSIGN);
            temp = merge(temp, makelist(nextinstr));
            emit("", "", "", GOTO);                     // Prevent fall-through
            backpatch($2->nextlist, nextinstr);         // Backpatch with nextinstr
            convertIntToBool($1);                       // Convert the expression to boolean
            backpatch($1->truelist, $4->instr);         // When $1 is true, control goes to $4 (expression)
            backpatch($1->falselist, $8->instr);        // When $1 is false, control goes to $8 (conditional_expression)
            backpatch($2->nextlist, nextinstr);         // Backpatch with nextinstr
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
        {}
        | unary_expression assignment_operator assignment_expression
        {
            symbol* sym1 = ST->lookup($1->loc);         // Get the first operand from the symbol table
            symbol* sym2 = ST->lookup($3->loc);         // Get the second operand from the symbol table
            if($1->fold == 0) {
                if(sym1->type.type != ARRAY)
                    emit($1->loc, $3->loc, "", ASSIGN);
                else
                    emit($1->loc, $3->loc, *($1->folder), ARR_IDX_RES);
            }
            else
                emit(*($1->folder), $3->loc, "", L_DEREF);
            $$ = $1;        // Assignment 
        }
        ;

assignment_operator: 
        ASSIGN_
        {}
        | MULTIPLY_ASSIGN
        {}
        | DIVIDE_ASSIGN
        {}
        | MODULO_ASSIGN
        {}
        | ADD_ASSIGN
        {}
        | SUBTRACT_ASSIGN
        {}
        | LSHIFT_ASSIGN
        {}
        | RSHIFT_ASSIGN
        {}
        | AND_ASSIGN
        {}
        | XOR_ASSIGN
        {}
        | OR_ASSIGN
        {}
        ;

expression: 
        assignment_expression
        {}
        | expression COMMA assignment_expression
        {}
        ;

constant_expression: 
        conditional_expression
        {}
        ;

declaration: 
        declaration_specifiers init_declarator_list SEMICOLON
        {
            DataType currType = $1;
            int currSize = -1;
            // Assign correct size for the data type
            if(currType == INT)
                currSize = __INTEGER_SIZE;
            else if(currType == CHAR)
                currSize = __CHARACTER_SIZE;
            else if(currType == FLOAT)
                currSize = __FLOAT_SIZE;
            vector<declaration*> decs = *($2);
            for(vector<declaration*>::iterator it = decs.begin(); it != decs.end(); it++) {
                declaration* currDec = *it;
                if(currDec->type == FUNCTION) {
                    ST = &globalST;
                    emit(currDec->name, "", "", FUNC_END);
                    symbol* one = ST->lookup(currDec->name);        // Create an entry for the function
                    symbol* two = one->nestedTable->lookup("RETVAL", currType, currDec->pointers);
                    one->size = 0;
                    one->initVal = NULL;
                    continue;
                }

                symbol* three = ST->lookup(currDec->name, currType);        // Create an entry for the variable in the symbol table
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
                else if(currDec->li != vector<int>()) {         // Handle array types
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
                else if(currDec->pointers != 0) {               // Handle pointer types
                    three->type.type = POINTER;
                    three->type.nextType = currType;
                    three->type.pointers = currDec->pointers;
                    ST->offset += (__POINTER_SIZE - currSize);
                    three->size = __POINTER_SIZE;
                }
            }
        }
        | declaration_specifiers SEMICOLON
        {}
        ;

declaration_specifiers: 
        storage_class_specifier declaration_specifiers
        {}
        |storage_class_specifier
        {}
        | type_specifier declaration_specifiers
        {}
        | type_specifier
        {}
        | type_qualifier declaration_specifiers
        {}
        | type_qualifier
        {}
        | function_specifier declaration_specifiers
        {}
        | function_specifier
        {}
        ;

init_declarator_list: 
        init_declarator
        {
            $$ = new vector<declaration*>;      // Create a vector of declarations and add $1 to it
            $$->push_back($1);
        }
        | init_declarator_list COMMA init_declarator
        {
            $1->push_back($3);                  // Add $3 to the vector of declarations
            $$ = $1;
        }
        ;

init_declarator: 
        declarator
        {
            $$ = $1;
            $$->initVal = NULL;         // Initialize the initVal to NULL as no initialization is done
        }
        | declarator ASSIGN_ initializer
        {   
            $$ = $1;
            $$->initVal = $3;           // Initialize the initVal to the value provided
        }
        ;

storage_class_specifier: 
        EXTERN
        {}
        | STATIC
        {}
        | AUTO
        {}
        | REGISTER
        {}
        ;

type_specifier: 
        VOID_
        {
            $$ = VOID;
        }
        | CHAR_
        {
            $$ = CHAR;
        }
        | SHORT
        {}
        | INT_
        {
            $$ = INT; 
        }
        | LONG
        {}
        | FLOAT_
        {
            $$ = FLOAT;
        }
        | DOUBLE
        {}
        | SIGNED
        {}
        | UNSIGNED
        {}
        | BOOL_
        {}
        | COMPLEX
        {}
        | IMAGINARY
        {}
        | enum_specifier
        {}
        ;

specifier_qualifier_list: 
        type_specifier specifier_qualifier_list_opt
        {}
        | type_qualifier specifier_qualifier_list_opt
        {}
        ;

specifier_qualifier_list_opt: 
        specifier_qualifier_list
        {}
        | %empty
        {}
        ;

enum_specifier: 
        ENUM CURLY_BRACE_OPEN enumerator_list CURLY_BRACE_CLOSE
        {}
        | ENUM IDENTIFIER CURLY_BRACE_OPEN enumerator_list CURLY_BRACE_CLOSE
        {}
        | ENUM IDENTIFIER CURLY_BRACE_OPEN enumerator_list COMMA CURLY_BRACE_CLOSE
        {}
        | ENUM IDENTIFIER
        {}
        ;

enumerator_list: 
        enumerator
        {}
        | enumerator_list COMMA enumerator
        {}
        ;

enumerator: 
        IDENTIFIER
        {}
        | IDENTIFIER ASSIGN_ constant_expression
        {}
        ;

type_qualifier: 
        CONST
        {}
        | RESTRICT
        {}
        | VOLATILE
        {}
        ;

function_specifier: 
        INLINE
        {}
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
        {}
        | direct_declarator SQUARE_BRACE_OPEN type_qualifier_list_opt SQUARE_BRACE_CLOSE
        {
            $1->type = ARRAY;       // Array type
            $1->nextType = INT;     // Array of ints
            $$ = $1;
            $$->li.push_back(0);
        }
        | direct_declarator SQUARE_BRACE_OPEN type_qualifier_list_opt assignment_expression SQUARE_BRACE_CLOSE
        {
            $1->type = ARRAY;       // Array type
            $1->nextType = INT;     // Array of ints
            $$ = $1;
            int index = ST->lookup($4->loc)->initVal->i;
            $$->li.push_back(index);
        }
        | direct_declarator SQUARE_BRACE_OPEN STATIC type_qualifier_list assignment_expression SQUARE_BRACE_CLOSE
        {}
        | direct_declarator SQUARE_BRACE_OPEN type_qualifier_list STATIC assignment_expression SQUARE_BRACE_CLOSE
        {}
        | direct_declarator SQUARE_BRACE_OPEN type_qualifier_list_opt MULTIPLY SQUARE_BRACE_CLOSE
        {
            $1->type = POINTER;     // Pointer type
            $1->nextType = INT;
            $$ = $1;
        }
        | direct_declarator PARENTHESIS_OPEN parameter_type_list_opt PARENTHESIS_CLOSE
        {
            $$ = $1;
            $$->type = FUNCTION;    // Function type
            symbol* funcData = ST->lookup($$->name, $$->type);
            symbolTable* funcTable = new symbolTable();
            funcData->nestedTable = funcTable;
            vector<param*> paramList = *($3);   // Get the parameter list
            for(int i = 0; i < (int)paramList.size(); i++) {
                param* curParam = paramList[i];
                if(curParam->type.type == ARRAY) {          // If the parameter is an array
                    funcTable->lookup(curParam->name, curParam->type.type);
                    funcTable->lookup(curParam->name)->type.nextType = INT;
                    funcTable->lookup(curParam->name)->type.dims.push_back(0);
                }
                else if(curParam->type.type == POINTER) {   // If the parameter is a pointer
                    funcTable->lookup(curParam->name, curParam->type.type);
                    funcTable->lookup(curParam->name)->type.nextType = INT;
                    funcTable->lookup(curParam->name)->type.dims.push_back(0);
                }
                else                                        // If the parameter is a anything other than an array or a pointer
                    funcTable->lookup(curParam->name, curParam->type.type);
            }
            ST = funcTable;         // Set the pointer to the symbol table to the function's symbol table
            emit($$->name, "", "", FUNC_BEG);
        }
        | direct_declarator PARENTHESIS_OPEN identifier_list PARENTHESIS_CLOSE
        {}
        ;

parameter_type_list_opt:
        parameter_type_list
        {}
        | %empty
        {
            $$ = new vector<param*>;
        }
        ;

type_qualifier_list_opt: 
        type_qualifier_list
        {}
        | %empty
        {}
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
        {}
        | type_qualifier_list type_qualifier
        {}
        ;

parameter_type_list: 
        parameter_list
        | parameter_list COMMA ELLIPSIS
        ;

parameter_list: 
        parameter_declaration
        {
            $$ = new vector<param*>;         // Create a new vector of parameters
            $$->push_back($1);              // Add the parameter to the vector
        }
        | parameter_list COMMA parameter_declaration
        {
            $1->push_back($3);              // Add the parameter to the vector
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
        {}
        ;

identifier_list: 
        IDENTIFIER
        {}
        | identifier_list COMMA IDENTIFIER
        {}
        ;

type_name: 
        specifier_qualifier_list
        {}
        ;

initializer: 
        assignment_expression
        {
            $$ = $1;   // Simple assignment
        }
        | CURLY_BRACE_OPEN initializer_list CURLY_BRACE_CLOSE
        {}
        | CURLY_BRACE_OPEN initializer_list COMMA CURLY_BRACE_CLOSE
        {}
        ;

initializer_list: 
        designation_opt initializer
        {}
        | initializer_list COMMA designation_opt initializer
        {}
        ;

designation_opt: 
        designation
        {}
        | %empty
        {}
        ;

designation: 
        designator_list ASSIGN_
        {}
        ;

designator_list: 
        designator
        {}
        | designator_list designator
        {}
        ;

designator: 
        SQUARE_BRACE_OPEN constant_expression SQUARE_BRACE_CLOSE
        {}
        | DOT IDENTIFIER
        {}
        ;

statement: 
        labeled_statement
        {}
        | compound_statement
        | expression_statement
        | selection_statement
        | iteration_statement
        | jump_statement
        ;

labeled_statement: 
        IDENTIFIER COLON statement
        {}
        | CASE constant_expression COLON statement
        {}
        | DEFAULT COLON statement
        {}
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
        {}
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
            backpatch($4->nextlist, nextinstr);         // nextlist of N now has nextinstr
            convertIntToBool($3);                       // Convert expression to bool
            backpatch($3->truelist, $6->instr);         // Backpatching - if expression is true, go to M
            $$ = new expression();                      // Create new expression
            // Merge falselist of expression, nextlist of statement and nextlist of the last N
            $7->nextlist = merge($8->nextlist, $7->nextlist);
            $$->nextlist = merge($3->falselist, $7->nextlist);
        }
        | IF PARENTHESIS_OPEN expression N PARENTHESIS_CLOSE M statement N ELSE M statement N
        {
            /*
                This production rule has been augmented for control flow
            */
            backpatch($4->nextlist, nextinstr);         // nextlist of N now has nextinstr
            convertIntToBool($3);                       // Convert expression to bool
            backpatch($3->truelist, $6->instr);         // Backpatching - if expression is true, go to first M, else go to second M
            backpatch($3->falselist, $10->instr);
            $$ = new expression();                      // Create new expression
            // Merge nextlist of statement, nextlist of N and nextlist of the last statement
            $$->nextlist = merge($7->nextlist, $8->nextlist);
            $$->nextlist = merge($$->nextlist, $11->nextlist);
            $$->nextlist = merge($$->nextlist, $12->nextlist);
        }
        | SWITCH PARENTHESIS_OPEN expression PARENTHESIS_CLOSE statement
        {}
        ;

iteration_statement: 
        WHILE M PARENTHESIS_OPEN expression N PARENTHESIS_CLOSE M statement
        {   
            /*
                This production rule has been augmented with non-terminals like M and N to handle the control flow and backpatching
            */
            $$ = new expression();                   // Create a new expression
            emit("", "", "", GOTO);
            backpatch(makelist(nextinstr - 1), $2->instr);
            backpatch($5->nextlist, nextinstr);
            convertIntToBool($4);                   // Convert expression to bool
            $$->nextlist = $4->falselist;           // Exit loop if expression is false
            backpatch($4->truelist, $7->instr);     // Backpatching - if expression is true, go to M
            backpatch($8->nextlist, $2->instr);     // Backpatching - go to the beginning of the loop
        }
        | DO M statement M WHILE PARENTHESIS_OPEN expression N PARENTHESIS_CLOSE SEMICOLON
        {
            /*
                This production rule has been augmented with non-terminals like M and N to handle the control flow and backpatching
            */
            $$ = new expression();                  // Create a new expression  
            backpatch($8->nextlist, nextinstr);     // Backpatching 
            convertIntToBool($7);                   // Convert expression to bool
            backpatch($7->truelist, $2->instr);     // Backpatching - if expression is true, go to M
            backpatch($3->nextlist, $4->instr);     // Backpatching - go to the beginning of the loop
            $$->nextlist = $7->falselist;
        }
        | FOR PARENTHESIS_OPEN expression_statement M expression_statement N M expression N PARENTHESIS_CLOSE M statement
        {
            /*
                This production rule has been augmented with non-terminals like M and N to handle the control flow and backpatching
            */
            $$ = new expression();                   // Create a new expression
            emit("", "", "", GOTO);
            $12->nextlist = merge($12->nextlist, makelist(nextinstr - 1));
            backpatch($12->nextlist, $7->instr);    // Backpatching - go to the beginning of the loop
            backpatch($9->nextlist, $4->instr);     
            backpatch($6->nextlist, nextinstr);     
            convertIntToBool($5);                   // Convert expression to bool
            backpatch($5->truelist, $11->instr);    // Backpatching - if expression is true, go to M
            $$->nextlist = $5->falselist;           // Exit loop if expression is false
        }
        ;

jump_statement: 
        GOTO_ IDENTIFIER SEMICOLON
        {}
        | CONTINUE SEMICOLON
        {}
        | BREAK SEMICOLON
        {}
        | RETURN_ SEMICOLON
        {
            if(ST->lookup("RETVAL")->type.type == VOID) {
                emit("", "", "", RETURN);           // Emit the quad when return type is void
            }
            $$ = new expression();
        }
        | RETURN_ expression SEMICOLON
        {
            if(ST->lookup("RETVAL")->type.type == ST->lookup($2->loc)->type.type) {
                emit($2->loc, "", "", RETURN);      // Emit the quad when return type is not void
            }
            $$ = new expression();
        }
        ;

translation_unit: 
        external_declaration
        {}
        | translation_unit external_declaration
        {}
        ;

external_declaration: 
        function_definition
        {}
        | declaration
        {}
        ;

function_definition: 
        declaration_specifiers declarator declaration_list compound_statement
        {}
        | function_prototype compound_statement
        {
            ST = &globalST;                     // Reset the symbol table to global symbol table
            emit($1->name, "", "", FUNC_END);
        }
        ;

function_prototype:
        declaration_specifiers declarator
        {
            DataType currType = $1;
            int currSize = -1;
            if(currType == CHAR)
                currSize = __CHARACTER_SIZE;
            if(currType == INT)
                currSize = __INTEGER_SIZE;
            if(currType == FLOAT)
                currSize = __FLOAT_SIZE;
            declaration* currDec = $2;
            symbol* sym = globalST.lookup(currDec->name);
            if(currDec->type == FUNCTION) {
                symbol* retval = sym->nestedTable->lookup("RETVAL", currType, currDec->pointers);   // Create entry for return value
                sym->size = 0;
                sym->initVal = NULL;
            }
            $$ = $2;
        }
        ;

declaration_list: 
        declaration
        {}
        | declaration_list declaration
        {}
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
