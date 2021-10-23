/**
* Vanshita Garg | 19CS10064
* Ashutosh Kumar Singh | 19CS30008
* Compilers Laboratory
* Assignment 5
*
* Source file for translation
*/

#include "ass5_19CS10064_19CS30008_translator.h"
#include <iomanip>
using namespace std;

// Global variables as defined and explained in the header file
symbol* currentSymbol;
symbolTable* currentST;
symbolTable* globalST;
quadArray quadList;
int STCount;
string blockName;

// Used for storing the last encountered type
string varType;

// Implementations of constructors and functions for the symbolType class
symbolType::symbolType(string type_, symbolType* arrType_, int width_):
    type(type_), width(width_), arrType(arrType_) {}

// Implementations of constructors and functions for the symbol class
symbol::symbol(string name_, string t, symbolType* arrType, int width): name(name_), value("-"), offset(0), nestedTable(NULL) {
    type = new symbolType(t, arrType, width);
    size = sizeOfType(type);
}

symbol* symbol::update(symbolType* t) {
    // Update the type and size for the symbol
    type = t;
    size = sizeOfType(t);
    return this;
}

// Implementations of constructors and functions for the symbolTable class
symbolTable::symbolTable(string name_): name(name_), tempCount(0) {}

symbol* symbolTable::lookup(string name) {
    // Start searching for the symbol in the symbol table
    for(list<symbol>::iterator it = table.begin(); it != table.end(); it++) {
        if(it->name == name) {
            return &(*it);
        }
    }

    // If not found, go up the hierarchy to search in the parent symbol tables
    symbol* s = NULL;
    if(this->parent != NULL) {
        s = this->parent->lookup(name);
    }

    if(currentST == this && s == NULL) {
        // If the symbol is not found, create the symbol, add it to the symbol table and return a pointer to it
        symbol* sym = new symbol(name);
        table.push_back(*sym);
        return &(table.back());
    }
    else if(s != NULL) {
        // If the symbol is found in one of the parent symbol tables, return it
        return s;
    }

    return NULL;
}

symbol* symbolTable::gentemp(symbolType* t, string initValue) {
    // Create the name for the temporary
    string name = "t" + convertIntToString(currentST->tempCount++);
    symbol* sym = new symbol(name);
    sym->type = t;
    sym->value = initValue;         // Assign the initial value, if any
    sym->size = sizeOfType(t);

    // Add the temporary to the symbol table
    currentST->table.push_back(*sym);
    return &(currentST->table.back());
}

void symbolTable::print() {
    for(int i = 0; i < 120; i++) {
        cout << '-';
    }
    cout << endl;
    cout << "Symbol Table: " << setfill(' ') << left << setw(50) << this->name;
    cout << "Parent Table: " << setfill(' ') << left << setw(50) << ((this->parent != NULL) ? this->parent->name : "NULL") << endl;
    for(int i = 0; i < 120; i++) {
        cout << '-';
    }
    cout << endl;

    // Table Headers
    cout << setfill(' ') << left << setw(25) <<  "Name";
    cout << left << setw(25) << "Type";
    cout << left << setw(20) << "Initial Value";
    cout << left << setw(15) << "Size";
    cout << left << setw(15) << "Offset";
    cout << left << "Nested" << endl;

    for(int i = 0; i < 120; i++) {
        cout << '-';
    }
    cout << endl;

    list<symbolTable*> tableList;

    // Print the symbols in the symbol table
    for(list<symbol>::iterator it = this->table.begin(); it != this->table.end(); it++) {
        cout << left << setw(25) << it->name;
        cout << left << setw(25) << checkType(it->type);
        cout << left << setw(20) << (it->value != "" ? it->value : "-");
        cout << left << setw(15) << it->size;
        cout << left << setw(15) << it->offset;
        cout << left;

        if(it->nestedTable != NULL) {
            cout << it->nestedTable->name << endl;
            tableList.push_back(it->nestedTable);
        }
        else {
            cout << "NULL" << endl;
        }
    }

    for(int i = 0; i < 120; i++) {
        cout << '-';
    }
    cout << endl << endl;

    // Recursively call the print function for the nested symbol tables
    for(list<symbolTable*>::iterator it = tableList.begin(); it != tableList.end(); it++) {
        (*it)->print();
    }

}

void symbolTable::update() {
    list<symbolTable*> tableList;
    int off_set;

    // Update the offsets of the symbols based on their sizes
    for(list<symbol>::iterator it = table.begin(); it != table.end(); it++) {
        if(it == table.begin()) {
            it->offset = 0;
            off_set = it->size;
        }
        else {
            it->offset = off_set;
            off_set = it->offset + it->size;
        }

        if(it->nestedTable != NULL) {
            tableList.push_back(it->nestedTable);
        }
    }

    // Recursively call the update function to update the offsets of symbols of the nested symbol tables
    for(list<symbolTable*>::iterator iter = tableList.begin(); iter != tableList.end(); iter++) {
        (*iter)->update();
    }
}

// Implementations of constructors and functions for the quad class
quad::quad(string res, string arg1_, string operation, string arg2_): result(res), arg1(arg1_), op(operation), arg2(arg2_) {}

quad::quad(string res, int arg1_, string operation, string arg2_): result(res), op(operation), arg2(arg2_) {
    arg1 = convertIntToString(arg1_);
}

quad::quad(string res, float arg1_, string operation, string arg2_): result(res), op(operation), arg2(arg2_) {
    arg1 = convertFloatToString(arg1_);
}

void quad::print() {
    if(op == "=")       // Simple assignment
        cout << result << " = " << arg1;
    else if(op == "*=")
        cout << "*" << result << " = " << arg1;
    else if(op == "[]=")
        cout << result << "[" << arg1 << "]" << " = " << arg2;
    else if(op == "=[]")
        cout << result << " = " << arg1 << "[" << arg2 << "]";
    else if(op == "goto" || op == "param" || op == "return")
        cout << op << " " << result;
    else if(op == "call")
        cout << result << " = " << "call " << arg1 << ", " << arg2;
    else if(op == "label")
        cout << result << ": ";

    // Binary Operators
    else if(op == "+" || op == "-" || op == "*" || op == "/" || op == "%" || op == "^" || op == "|" || op == "&" || op == "<<" || op == ">>")
        cout << result << " = " << arg1 << " " << op << " " << arg2;

    // Relational Operators
    else if(op == "==" || op == "!=" || op == "<" || op == ">" || op == "<=" || op == ">=")
        cout << "if " << arg1 << " " << op << " " << arg2 << " goto " << result;

    // Unary operators
    else if(op == "= &" || op == "= *" || op == "= -" || op == "= ~" || op == "= !")
        cout << result << " " << op << arg1;

    else
        cout << "Unknown Operator";
}

// Implementations of constructors and functions for the quadArray class
void quadArray::print() {
    for(int i = 0; i < 120; i++) {
        cout << '-';
    }
    cout << endl;
    cout << "THREE ADDRESS CODE (TAC):" << endl;
    for(int i = 0; i < 120; i++) {
        cout << '-';
    }
    cout << endl;

    int cnt = 0;
    // Print each of the quads one by one
    for(vector<quad>::iterator it = this->quads.begin(); it != this->quads.end(); it++, cnt++) {
        if(it->op != "label") {
            cout << left << setw(4) << cnt << ":    ";
            it->print();
        }
        else {
            cout << endl << left << setw(4) << cnt << ": ";
            it->print();
        }
        cout << endl;
    }
}

// Overloaded emit functions
void emit(string op, string result, string arg1, string arg2) {
    quad* q = new quad(result, arg1, op, arg2);
    quadList.quads.push_back(*q);
}

void emit(string op, string result, int arg1, string arg2) {
    quad* q = new quad(result, arg1, op, arg2);
    quadList.quads.push_back(*q);
}

void emit(string op, string result, float arg1, string arg2) {
    quad* q = new quad(result, arg1, op, arg2);
    quadList.quads.push_back(*q);
}

// Implementation of the makelist function
list<int> makelist(int i) {
    list<int> l(1, i);
    return l;
}

// Implementation of the merge function
list<int> merge(list<int> &list1, list<int> &list2) {
    list1.merge(list2);
    return list1;
}

// Implementation of the backpatch function
void backpatch(list<int> l, int address) {
    string str = convertIntToString(address);
    for(list<int>::iterator it = l.begin(); it != l.end(); it++) {
        quadList.quads[*it].result = str;
    }
}

// Implementation of the typecheck functions
bool typecheck(symbol* &s1, symbol* &s2) {
    symbolType* t1 = s1->type;
    symbolType* t2 = s2->type;

    if(typecheck(t1, t2))
        return true;
    else if(s1 = convertType(s1, t2->type))
        return true;
    else if(s2 = convertType(s2, t1->type))
        return true;
    else
        return false;
}

bool typecheck(symbolType* t1, symbolType* t2) {
    if(t1 == NULL && t2 == NULL)
        return true;
    else if(t1 == NULL || t2 == NULL)
        return false;
    else if(t1->type != t2->type)
        return false;

    return typecheck(t1->arrType, t2->arrType);
}

// Implementation of the convertType function
symbol* convertType(symbol* s, string t) {
    symbol* temp = symbolTable::gentemp(new symbolType(t));

    if(s->type->type == "float") {
        if(t == "int") {
            emit("=", temp->name, "float2int(" + s->name + ")");
            return temp;
        }
        else if(t == "char") {
            emit("=", temp->name, "float2char(" + s->name + ")");
            return temp;
        }
        return s;
    }

    else if(s->type->type == "int") {
        if(t == "float") {
            emit("=", temp->name, "int2float(" + s->name + ")");
            return temp;
        }
        else if(t == "char") {
            emit("=", temp->name, "int2char(" + s->name + ")");
            return temp;
        }
        return s;
    }

    else if(s->type->type == "char") {
        if(t == "float") {
            emit("=", temp->name, "char2float(" + s->name + ")");
            return temp;
        }
        else if(t == "int") {
            emit("=", temp->name, "char2int(" + s->name + ")");
            return temp;
        }
        return s;
    }

    return s;
}

string convertIntToString(int i) {
    return to_string(i);
}

string convertFloatToString(float f) {
    return to_string(f);
}

// Implementation of the convertIntToBool function
expression* convertIntToBool(expression* expr) {
    if(expr->type != "bool") {
        expr->falselist = makelist(nextinstr());    // Add falselist for boolean expressions
        emit("==", expr->loc->name, "0");
        expr->truelist = makelist(nextinstr());     // Add truelist for boolean expressions
        emit("goto", "");
    }
    return expr;
}

// Implementation of the convertBoolToInt function
expression* convertBoolToInt(expression* expr) {
    if(expr->type == "bool") {
        expr->loc = symbolTable::gentemp(new symbolType("int"));
        backpatch(expr->truelist, nextinstr());
        emit("=", expr->loc->name, "true");
        emit("goto", convertIntToString(nextinstr() + 1));
        backpatch(expr->falselist, nextinstr());
        emit("=", expr->loc->name, "false");
    }
    return expr;
}

void switchTable(symbolTable* newTable) {
    currentST = newTable;
}

int nextinstr() {
    return quadList.quads.size();
}

int sizeOfType(symbolType* t) {
    if(t->type == "void")
        return __VOID_SIZE;
    else if(t->type == "char")
        return __CHARACTER_SIZE;
    else if(t->type == "int")
        return __INTEGER_SIZE;
    else if(t->type == "ptr")
        return __POINTER_SIZE;
    else if(t->type == "float")
        return __FLOAT_SIZE;
    else if(t->type == "arr")
        return t->width * sizeOfType(t->arrType);
    else if(t->type == "func")
        return __FUNCTION_SIZE;
    else
        return -1;
}

string checkType(symbolType* t) {
    if(t == NULL)
        return "null";
    else if(t->type == "void" || t->type == "char" || t->type == "int" || t->type == "float" || t->type == "block" || t->type == "func")
        return t->type;
    else if(t->type == "ptr")
        return "ptr(" + checkType(t->arrType) + ")";
    else if(t->type == "arr")
        return "arr(" + convertIntToString(t->width) + ", " + checkType(t->arrType) + ")";
    else
        return "unknown";
}

int main() {
    STCount = 0;                            // Initialize STCount to 0
    globalST = new symbolTable("Global");   // Create global symbol table
    currentST = globalST;                   // Make global symbol table the currently active symbol table
    blockName = "";

    yyparse();
    globalST->update();
    quadList.print();       // Print Three Address Code
    cout << endl;
    globalST->print();      // Print symbol tables

    return 0;
}
