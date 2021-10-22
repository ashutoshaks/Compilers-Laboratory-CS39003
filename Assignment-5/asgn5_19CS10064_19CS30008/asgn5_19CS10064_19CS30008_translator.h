#ifndef __TRANSLATOR_H
#define __TRANSLATOR_H

#include <iostream>
#include <vector>
#include <list>
using namespace std;


#define __VOID_SIZE 0
#define __FUNCTION_SIZE 0
#define __CHARACTER_SIZE 1
#define __INTEGER_SIZE 4
#define __POINTER_SIZE 4
#define __FLOAT_SIZE 8


class symbol;
class symbolType;
class symbolTable;

class quad;
class quadArray;


extern symbol* currentSymbol;
extern symbolTable* currentST;
extern symbolTable* globalST;
extern quadArray quadList;
extern int tableCount;
extern string loopName;

extern char* yytext;
extern int yyparse();


class symbolType {
public:
    string type;
    int width;
    symbolType* arrType;

    symbolType(string type, symbolType* ptr = NULL, int width = 1);
};


class symbol {
public:
    string name;
    symbolType* type;
    string value;
    int size;
    int offset;
    symbolTable* nestedTable;

    symbol(string name, string t = "INTEGER", symbolType* ptr = NULL, int width = 0);
    symbol* update(symbolType* t);
};


class symbolTable {
public:
    string name;
    int tempCount;
    list<symbol> table;
    symbolTable* parent;

    symbolTable(string name = "NULL");

    symbol* lookup(string name);
    static symbol* gentemp(symbolType* type, string initValue = "");

    void print();
    void update();
};


class quad {
public:
    string op;
    string arg1;
    string arg2;
    string result;

    quad(string res, string arg1, string operation = "EQUAL", string arg2 = "");
    quad(string res, int arg1, string operation = "EQUAL", string arg2 = "");
    quad(string res, float arg1, string operation = "EQUAL", string arg2 = "");

    void print();
};


class quadArray {
public:
    vector<quad> quads;

    void print();
};


class Array {
public:
    string atype;
    symbol* loc;
    symbol* Array;
    symbolType* type;
};


class statement {
public:
    list<int> nextlist;
};


class expression {
public:
    string type;
    symbol* loc;
    list<int> truelist;
    list<int> falselist;
    list<int> nextlist;
};


void emit(string op, string result, string arg1 = "", string arg2 = "");
void emit(string op, string result, int arg1, string arg2 = "");
void emit(string op, string result, float arg1, string arg2 = "");


list<int> makelist(int i);

list<int> merge(list<int> &list1, list<int> &list2);

void backpatch(list<int> list, int i);


bool typecheck(symbol* s1, symbol* s2);

bool typecheck(symbolType* t1, symbolType* t2);


symbol* convertType(symbol* s, string type);

string convertIntToString(int i);

string convertFloatToString(float f);

expression* convertIntToBool(expression* expr);

expression* convertBoolToInt(expression* expr);


void switchTable(symbolTable* newTable);


int nextinstr();


int sizeOfType(symbolType* type);

string checkType(symbolType* type);

#endif