/**
* Vanshita Garg | 19CS10064
* Ashutosh Kumar Singh | 19CS30008
* Compilers Laboratory
* Assignment 6
*
* File for Target Code Generation
*/

#include "ass6_19CS10064_19CS30008_translator.h"
using namespace std;


extern symbolTable globalST;
extern symbolTable* ST;
extern quadArray quadList;

vector<string> stringConsts;
map<int, string> labels;


int main() {
    ST = &globalST;
    yyparse();

    return 0;
}