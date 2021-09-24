%{
    #include <stdio.h>
    extern int yylex();
    void yyerror(char *s);
    extern char* yytext;
    extern int yylineno;
%}

%union {
    int intval;
    float floatval;
    char charval;
    char *strval;
}

%token AUTO BREAK CASE CHAR CONST CONTINUE DEFAULT DO DOUBLE ELSE ENUM EXTERN FLOAT FOR GOTO IF INLINE INT LONG REGISTER RESTRICT RETURN SHORT SIGNED SIZEOF STATIC STRUCT SWITCH TYPEDEF UNION UNSIGNED VOID VOLATILE WHILE BOOL COMPLEX IMAGINARY

%token SQUARE_BRACE_OPEN SQUARE_BRACE_CLOSE PARENTHESIS_OPEN PARENTHESIS_CLOSE CURLY_BRACE_OPEN CURLY_BRACE_CLOSE 
%token DOT ARROW INCREMENT DECREMENT BITWISE_AND MULTIPLY ADD SUBTRACT BITWISE_NOR NOT DIVIDE MODULO 
%token LSHIFT RSHIFT LESS_THAN GREATER_THAN LESS_THAN_EQUAL GREATER_THAN_EQUAL EQUAL NOT_EQUAL BITWISE_XOR BITWISE_OR 
%token LOGICAL_AND LOGICAL_OR QUESTION_MARK COLON SEMICOLON ELLIPSIS 
%token ASSIGN MULTIPLY_ASSIGN DIVIDE_ASSIGN MODULO_ASSIGN ADD_ASSIGN SUBTRACT_ASSIGN LSHIFT_ASSIGN RSHIFT_ASSIGN AND_ASSIGN XOR_ASSIGN OR_ASSIGN COMMA HASH

%token IDENTIFIER
%token <intval> INTEGER_CONSTANT
%token <floatval> FLOATING_CONSTANT
%token <charval> CHAR_CONSTANT
%token <strval> STRING_LITERAL

%nonassoc PARENTHESIS_CLOSE
%nonassoc ELSE

%start translation_unit

%%

primary_expression: IDENTIFIER
                  | constant
                  | STRING_LITERAL
                  | PARENTHESIS_OPEN expression PARENTHESIS_CLOSE
                  ;

constant: INTEGER_CONSTANT
        | FLOATING_CONSTANT
        | CHAR_CONSTANT
        ;

postfix_expression: primary_expression
                  | postfix_expression SQUARE_BRACE_OPEN expression SQUARE_BRACE_CLOSE
                  | postfix_expression PARENTHESIS_OPEN argument_expression_list_opt PARENTHESIS_CLOSE
                  | postfix_expression DOT IDENTIFIER
                  | postfix_expression ARROW IDENTIFIER
                  | postfix_expression INCREMENT
                  | postfix_expression DECREMENT
                  | PARENTHESIS_OPEN type_name PARENTHESIS_CLOSE CURLY_BRACE_OPEN initializer_list CURLY_BRACE_CLOSE
                  | PARENTHESIS_OPEN type_name PARENTHESIS_CLOSE CURLY_BRACE_OPEN initializer_list COMMA CURLY_BRACE_CLOSE
                  ;

argument_expression_list_opt: argument_expression_list
                            |
                            ;

argument_expression_list: assignment_expression
                        | argument_expression_list COMMA assignment_expression
                        ;

unary_expression: postfix_expression
                | INCREMENT unary_expression
                | DECREMENT unary_expression
                | unary_operator cast_expression
                | SIZEOF unary_expression
                | SIZEOF PARENTHESIS_OPEN type_name PARENTHESIS_CLOSE
                ;

unary_operator: BITWISE_AND
              | MULTIPLY
              | ADD
              | SUBTRACT
              | BITWISE_NOR
              | NOT
              ;

cast_expression: unary_expression
               | PARENTHESIS_OPEN type_name PARENTHESIS_CLOSE cast_expression
               ;

multiplicative_expression: cast_expression
                         | multiplicative_expression MULTIPLY cast_expression
                         | multiplicative_expression DIVIDE cast_expression
                         | multiplicative_expression MODULO cast_expression
                         ;

additive_expression: multiplicative_expression
                   | additive_expression ADD multiplicative_expression
                   | additive_expression SUBTRACT multiplicative_expression
                   ;

shift_expression: additive_expression
                | shift_expression LSHIFT additive_expression
                | shift_expression RSHIFT additive_expression
                ;

relational_expression: shift_expression
                     | relational_expression LESS_THAN shift_expression
                     | relational_expression GREATER_THAN shift_expression
                     | relational_expression LESS_THAN_EQUAL shift_expression
                     | relational_expression GREATER_THAN_EQUAL shift_expression
                     ;

equality_expression: relational_expression
                   | equality_expression EQUAL relational_expression
                   | equality_expression NOT_EQUAL relational_expression
                   ;

and_expression: equality_expression
              | and_expression BITWISE_AND equality_expression
              ;

exclusive_or_expression: and_expression
                       | exclusive_or_expression BITWISE_XOR and_expression
                       ;

inclusive_or_expression: exclusive_or_expression
                       | inclusive_or_expression BITWISE_OR exclusive_or_expression
                       ;

logical_and_expression: inclusive_or_expression
                      | logical_and_expression LOGICAL_AND inclusive_or_expression
                      ;

logical_or_expression: logical_and_expression
                     | logical_or_expression LOGICAL_OR logical_and_expression
                     ;

conditional_expression: logical_or_expression
                      | logical_or_expression QUESTION_MARK expression COLON conditional_expression
                      ;

assignment_expression: conditional_expression
                     | unary_expression assignment_operator assignment_expression
                     ;

assignment_operator: ASSIGN
                   | MULTIPLY_ASSIGN
                   | DIVIDE_ASSIGN
                   | MODULO_ASSIGN
                   | ADD_ASSIGN
                   | SUBTRACT_ASSIGN
                   | LSHIFT_ASSIGN
                   | RSHIFT_ASSIGN
                   | AND_ASSIGN
                   | XOR_ASSIGN
                   | OR_ASSIGN
                   ;

expression: assignment_expression
          | expression COMMA assignment_expression
          ;

constant_expression: conditional_expression
                   ;

declaration: declaration_specifiers init_declarator_list_opt SEMICOLON
           ;

init_declarator_list_opt: init_declarator_list
                         |
                         ;

declaration_specifiers: storage_class_specifier declaration_specifiers_opt
                      | type_specifier declaration_specifiers_opt
                      | type_qualifier declaration_specifiers_opt
                      | function_specifier declaration_specifiers_opt
                      ;

declaration_specifiers_opt: declaration_specifiers
                          |
                          ;

init_declarator_list: init_declarator
                    | init_declarator_list COMMA init_declarator
                    ;

init_declarator: declarator
               | declarator ASSIGN initializer
               ;

storage_class_specifier: EXTERN
                       | STATIC
                       | AUTO
                       | REGISTER
                       ;

type_specifier: VOID
              | CHAR
              | SHORT
              | INT
              | LONG
              | FLOAT
              | DOUBLE
              | SIGNED
              | UNSIGNED
              | BOOL
              | COMPLEX
              | IMAGINARY
              | enum_specifier
              ;

specifier_qualifier_list: type_specifier specifier_qualifier_list_opt
                        | type_qualifier specifier_qualifier_list_opt
                        ;

specifier_qualifier_list_opt: specifier_qualifier_list
                            |
                            ;

enum_specifier: ENUM identifier_opt CURLY_BRACE_OPEN enumerator_list CURLY_BRACE_CLOSE
              | ENUM identifier_opt CURLY_BRACE_OPEN enumerator_list COMMA CURLY_BRACE_CLOSE
              | ENUM IDENTIFIER
              ;

identifier_opt: IDENTIFIER
              |
              ;

enumerator_list: enumerator
               | enumerator_list COMMA enumerator
               ;

enumerator: IDENTIFIER
          | IDENTIFIER ASSIGN constant_expression
          ;

type_qualifier: CONST
              | RESTRICT
              | VOLATILE
              ;

function_specifier: INLINE
                  ;

declarator: pointer_opt direct_declarator
          ;

pointer_opt: pointer
           |
           ;

direct_declarator: IDENTIFIER
                 | PARENTHESIS_OPEN declarator PARENTHESIS_CLOSE
                 | direct_declarator SQUARE_BRACE_OPEN type_qualifier_list_opt assignment_expression_opt SQUARE_BRACE_CLOSE
                 | direct_declarator SQUARE_BRACE_OPEN STATIC type_qualifier_list_opt assignment_expression SQUARE_BRACE_CLOSE
                 | direct_declarator SQUARE_BRACE_OPEN type_qualifier_list STATIC assignment_expression SQUARE_BRACE_CLOSE
                 | direct_declarator SQUARE_BRACE_OPEN type_qualifier_list_opt MULTIPLY SQUARE_BRACE_CLOSE
                 | direct_declarator PARENTHESIS_OPEN parameter_type_list PARENTHESIS_CLOSE
                 | direct_declarator PARENTHESIS_OPEN identifier_list_opt PARENTHESIS_CLOSE
                 ;

type_qualifier_list_opt: type_qualifier_list
                       |
                       ;

assignment_expression_opt: assignment_expression
                         |
                         ;

identifier_list_opt: identifier_list
                   |
                   ;

pointer: MULTIPLY type_qualifier_list_opt
       | MULTIPLY type_qualifier_list_opt pointer
       ;

type_qualifier_list: type_qualifier
                   | type_qualifier_list type_qualifier
                   ;

parameter_type_list: parameter_list
                   | parameter_list COMMA ELLIPSIS
                   ;

parameter_list: parameter_declaration
              | parameter_list COMMA parameter_declaration
              ;

parameter_declaration: declaration_specifiers declarator
                     | declaration_specifiers
                     ;

identifier_list: IDENTIFIER
               | identifier_list COMMA IDENTIFIER
               ;

type_name: specifier_qualifier_list
         ;

initializer: assignment_expression
           | CURLY_BRACE_OPEN initializer_list CURLY_BRACE_CLOSE
           | CURLY_BRACE_OPEN initializer_list COMMA CURLY_BRACE_CLOSE
           ;

initializer_list: designation_opt initializer
                | initializer_list COMMA designation_opt initializer
                ;

designation_opt: designation
               |
               ;

designation: designator_list ASSIGN
           ;

designator_list: designator
               | designator_list designator
               ;

designator: SQUARE_BRACE_OPEN constant_expression SQUARE_BRACE_CLOSE
          | DOT IDENTIFIER
          ;

statement: labeled_statement
         | compound_statement
         | expression_statement
         | selection_statement
         | iteration_statement
         | jump_statement
         ;

labeled_statement: IDENTIFIER COLON statement
                 | CASE constant_expression COLON statement
                 | DEFAULT COLON statement
                 ;

compound_statement: CURLY_BRACE_OPEN block_item_list_opt CURLY_BRACE_CLOSE
                  ;

block_item_list_opt: block_item_list
                   |
                   ;

block_item_list: block_item
               | block_item_list block_item
               ;

block_item: declaration
          | statement
          ;

expression_statement: expression_opt SEMICOLON
                    ;

expression_opt: expression
              |
              ;

selection_statement: IF PARENTHESIS_OPEN expression PARENTHESIS_CLOSE statement
                   | IF PARENTHESIS_OPEN expression PARENTHESIS_CLOSE statement ELSE statement
                   | SWITCH PARENTHESIS_OPEN expression PARENTHESIS_CLOSE statement
                   ;

iteration_statement: WHILE PARENTHESIS_OPEN expression PARENTHESIS_CLOSE statement
                   | DO statement WHILE PARENTHESIS_OPEN expression PARENTHESIS_CLOSE SEMICOLON
                   | FOR PARENTHESIS_OPEN expression_opt SEMICOLON expression_opt SEMICOLON expression_opt PARENTHESIS_CLOSE statement
                   | FOR PARENTHESIS_OPEN  declaration expression_opt SEMICOLON expression_opt PARENTHESIS_CLOSE statement
                   ;

jump_statement: GOTO IDENTIFIER SEMICOLON
              | CONTINUE SEMICOLON
              | BREAK SEMICOLON
              | RETURN expression_opt SEMICOLON
              ;

translation_unit: external_declaration
                | translation_unit external_declaration
                ;

external_declaration: function_definition
                    | declaration
                    ;

function_definition: declaration_specifiers declarator declaration_list_opt compound_statement
                   ;

declaration_list_opt: declaration_list
                    |
                    ;

declaration_list: declaration
                | declaration_list declaration
                ;



%%

void yyerror(char *s) {
    printf("Error occurred: %s\n", s);
    printf("Error is in this line %s\n", yytext);
	printf("Line no. is %d", yylineno);
}
