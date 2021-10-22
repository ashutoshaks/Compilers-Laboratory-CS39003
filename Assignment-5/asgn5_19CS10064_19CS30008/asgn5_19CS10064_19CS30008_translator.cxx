#include "asgn5_19CS10064_19CS30008_translator.h"
#include <iomanip>
using namespace std;

symbol* currentSymbol;
symbolTable* currentST;
symbolTable* globalST;
quadArray quadList;
int STCount;
string blockName;


symbolType::symbolType(string type_, symbolType* arrType_ = NULL, int width_ = 1):
    type(type_), width(width_), arrType(arrType_) {}


symbol::symbol(string name_, string t, symbolType* arrType, int width): name(name_) {
    type = new symbolType(t, arrType, width);
    value = "-";
    size = sizeOfType(type);
    offset = 0;
    nestedTable = NULL;
}


symbol* symbol::update(symbolType* t) {
    type = t;
    size = sizeOfType(t);
    return this;
}


symbolTable::symbolTable(string name_): name(name_), tempCount(0) {}


symbol* symbolTable::lookup(string name) {
    for(list<symbol>::iterator it = table.begin(); it != table.end(); it++) {
        if(it->name == name) {
            return &(*it);
        }
    }

    symbol* s = NULL;
    if(this->parent != NULL) {
        s = this->parent->lookup(name);
    }

    if(currentST == this && s == NULL) {
        symbol* sym = new symbol(name);
        table.push_back(*sym);
        return &(table.back());
    }
    else if(s != NULL) {
        return s;
    }

    return NULL;
}


symbol* symbolTable::gentemp(symbolType* t, string initValue) {
    string name = "t" + convertIntToString(currentST->tempCount++);
    symbol* sym = new symbol(name);
    sym->type = t;
    sym->value = initValue;
    sym->size = sizeOfType(t);
    currentST->table.push_back(*sym);
    return &(currentST->table.back());
}


void symbolTable::print() {
    list<symbolTable*> tableList;
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
    cout << setfill(' ') << left << setw(20) <<  "Name";
    cout << left << setw(25) << "Type";
    cout << left << setw(17) << "Initial Value";
    cout << left << setw(12) << "Size";
    cout << left << setw(11) << "Offset";
    cout << left << "Nested" << endl;

    for(int i = 0; i < 120; i++) {
        cout << '-';
    }
    cout << endl;

    for(list<symbol>::iterator it = this->table.begin(); it != this->table.end(); it++) {
        cout << left << setw(20) << it->name;
        cout << left << setw(25) << checkType(it->type);
        cout << left << setw(17) << it->value;
        cout << left << setw(12) << it->size;
        cout << left << setw(11) << it->offset;
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

    for(list<symbolTable*>::iterator it = tableList.begin(); it != tableList.end(); it++) {
        (*it)->print();
    }

}


void symbolTable::update() {
    list<symbolTable*> tableList;
    int off_set;

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

    for(list<symbolTable*>::iterator iter = tableList.begin(); iter != tableList.end(); iter++) {
        (*iter)->update();
    }
}


quad::quad(string res, string arg1_, string operation = "EQUAL", string arg2_ = ""): result(res), arg1(arg1_), op(operation), arg2(arg2_) {}

quad::quad(string res, int arg1_, string operation = "EQUAL", string arg2_ = ""): result(res), op(operation), arg2(arg2_) {
    arg1 = convertIntToString(arg1_);
}

quad::quad(string res, float arg1_, string operation = "EQUAL", string arg2_ = ""): result(res), op(operation), arg2(arg2_) {
    arg1 = convertFloatToString(arg1_);
}


void quad::print() {
    if(op == "=")
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

    else if(op == "+" || op == "-" || op == "*" || op == "/" || op == "%" || op == "^" || op == "|" || op == "&&" || op == "<<" || op == ">>")
        cout << result << " = " << arg1 << " " << op << " " << arg2;

    else if(op == "==" || op == "!=" || op == "<" || op == ">" || op == "<=" || op == ">=")
        cout << "if " << arg1 << " " << op << " " << arg2 << " goto " << result;

    else if(op == "= &" || op == "= *" || op == "= -" || op == "= ~" || op == "= !")
        cout << result << " " << op << arg1;

    else
        cout << "Unknown Operator";
}


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

    int cnt = 100;
    for(vector<quad>::iterator it = this->quads.begin(); it != this->quads.end(); it++, cnt++) {
        if(it->op != "label") {
            cout << setw(4) << cnt << ":    ";
            it->print();
        }
        else {
            cout << endl << cnt << ": ";
            it->print();
        }
        cout << endl;
    }
}

void emit(string op, string result, string arg1 = "", string arg2 = "") {
    quad* q = new quad(result, arg1, op, arg2);
    quadList.quads.push_back(*q);
}

void emit(string op, string result, int arg1, string arg2 = "") {
    quad* q = new quad(result, arg1, op, arg2);
    quadList.quads.push_back(*q);
}

void emit(string op, string result, float arg1, string arg2 = "") {
    quad* q = new quad(result, arg1, op, arg2);
    quadList.quads.push_back(*q);
}


list<int> makelist(int i) {
    list<int> l(1, i);
    return l;
}

list<int> merge(list<int> &list1, list<int> &list2) {
    list1.merge(list2);
    return list1;
}

void backpatch(list<int> l, int address) {
    string str = convertIntToString(address);
    for(list<int>::iterator it = l.begin(); it != l.end(); it++) {
        quadList.quads[*it].result = str;
    }
}


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

expression* convertIntToBool(expression* expr) {
    if(expr->type != "bool") {
        expr->falselist = makelist(nextinstr());
        emit("==", expr->loc->name, "0");
        expr->truelist = makelist(nextinstr());
        emit("goto", "");
    }
    return expr;
}

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
    else if(t->type == "int")
        return __INTEGER_SIZE;
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
    STCount = 0;
    globalST = new symbolTable("Global");
    currentST = globalST;
    blockName = "";

    yyparse();

    globalST->update();

    quadList.print();

    globalST->print();

    return 0;
}