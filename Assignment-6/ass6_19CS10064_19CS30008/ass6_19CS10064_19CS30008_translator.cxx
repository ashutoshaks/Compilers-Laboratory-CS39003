/**
* Vanshita Garg | 19CS10064
* Ashutosh Kumar Singh | 19CS30008
* Compilers Laboratory
* Assignment 6
*
* Source file for translation
*/

#include "ass6_19CS10064_19CS30008_translator.h"
#include <iomanip>
using namespace std;


int nextinstr = 0;

int symbolTable::tempCount = 0;

quadArray quadList;
symbolTable globalST;
symbolTable* ST = &globalST;       // initialize to &globalST in main


void symbolValue::setInitVal(int val) {
    c = f = i = val;
    p = NULL;
}

void symbolValue::setInitVal(char val) {
    c = f = i = val;
    p = NULL;
}

void symbolValue::setInitVal(float val) {
    c = f = i = val;
    p = NULL;
}

symbol::symbol(): nestedTable(NULL) {}


// Implementations of constructors and functions for the symbolTable class
symbolTable::symbolTable(): offset(0) {}


symbol* symbolTable::lookup(string name, DataType t, int pc, bool ok) {
    if(table.count(name) == 0) {
        if(ok)
            cout << "*** " << name << " *** haha\n";
        symbol* sym = new symbol();
        sym->name = name;
        sym->type.type = t;
        sym->offset = offset;
        sym->initVal = NULL;

        if(pc == 0) {
            sym->size = sizeOfType(t);
            offset += sym->size;
        }
        else {
            sym->size = __POINTER_SIZE;
            sym->type.nextType = t;
            sym->type.pointers = pc;
            sym->type.type = ARRAY;
        }
        symbols.push_back(sym);
        table[name] = sym;
    }
    if(ok)
        cout << "*** " << name << " *** hoho\n";
    return table[name];
}


symbol* symbolTable::searchGlobal(string name) {
    return (table.count(name) ? table[name] : NULL);
}


string symbolTable::gentemp(DataType t) {
    // Create the name for the temporary
    string tempName = "t" + to_string(symbolTable::tempCount++);
    
    symbol* sym = new symbol();
    sym->name = tempName;
    sym->size = sizeOfType(t);
    sym->offset = offset;
    sym->type.type = t;
    sym->initVal = NULL;

    offset += sym->size;
    symbols.push_back(sym);
    table[tempName] = sym;  // Add the temporary to the symbol table

    return tempName;
}

void symbolTable::print(string tableName) {
    for(int i = 0; i < 120; i++) {
        cout << '-';
    }
    cout << endl;
    cout << "Symbol Table: " << setfill(' ') << left << setw(50) << tableName;
    // cout << "Parent Table: " << setfill(' ') << left << setw(50) << ((this->parent != NULL) ? this->parent->name : "NULL") << endl;
    for(int i = 0; i < 120; i++)
        cout << '-';
    cout << endl;

    // Table Headers
    cout << setfill(' ') << left << setw(25) <<  "Name";
    cout << left << setw(25) << "Type";
    cout << left << setw(20) << "Initial Value";
    cout << left << setw(15) << "Size";
    cout << left << setw(15) << "Offset";
    cout << left << "Nested" << endl;

    for(int i = 0; i < 120; i++)
        cout << '-';
    cout << endl;

    vector<pair<string, symbolTable*>> tableList;

    // Print the symbols in the symbol table
    for(int i = 0; i < (int)symbols.size(); i++) {
        symbol* sym = symbols[i];
        cout << left << setw(25) << sym->name;
        cout << left << setw(25) << checkType(sym->type);
        cout << left << setw(20) << getInitVal(sym);
        cout << left << setw(15) << sym->size;
        cout << left << setw(15) << sym->offset;
        cout << left;

        if(sym->nestedTable != NULL) {
            string nestedTableName = tableName + "." + sym->name;
            cout << nestedTableName << endl;
            tableList.push_back({nestedTableName, sym->nestedTable});
        }
        else
            cout << "NULL" << endl;
    }

    for(int i = 0; i < 120; i++)
        cout << '-';
    cout << endl << endl;

    // Recursively call the print function for the nested symbol tables
    for(vector<pair<string, symbolTable*>>::iterator it = tableList.begin(); it != tableList.end(); it++) {
        pair<string, symbolTable*> p = (*it);
        p.second->print(p.first);
    }

}

quad::quad(string res_, string arg1_, string arg2_, opcode op_): op(op_), arg1(arg1_), arg2(arg2_), result(res_) {}


string quad::print() {
    string out = "";
    if(op >= ADD && op <= BW_XOR) {
        out += (result + " = " + arg1 + " ");
        switch(op) {
            case ADD: out += "+"; break;
            case SUB: out += "-"; break;
            case MULT: out += "*"; break;
            case DIV: out += "/"; break;
            case MOD: out += "%"; break;
            case SL: out += "<<"; break;
            case SR: out += ">>"; break;
            case BW_AND: out += "&"; break;
            case BW_OR: out += "|"; break;
            case BW_XOR: out += "^"; break;
        }
        out += (" " + arg2);
    }
    else if(op >= BW_U_NOT && op <= U_NEG) {
        out += (result + " = ");
        switch(op) {
            case BW_U_NOT: out += "~"; break;
            case U_PLUS: out += "+"; break;
            case U_MINUS: out += "-"; break;
            case REFERENCE: out += "&"; break;
            case DEREFERENCE: out += "*"; break;
            case U_NEG: out += "!"; break;
        }
        out += arg1;
    }
    else if(op >= GOTO_EQ && op <= IF_FALSE_GOTO) {
        out += ("if " + arg1 + " ");
        switch(op) {
            case GOTO_EQ: out += "=="; break;
            case GOTO_NEQ: out += "!="; break;
            case GOTO_GT: out += ">"; break;
            case GOTO_GTE: out += ">="; break;
            case GOTO_LT: out += "<"; break;
            case GOTO_LTE: out += "<="; break;
            case IF_GOTO: out += "!= 0"; break;
            case IF_FALSE_GOTO: out += "== 0"; break;
        }
        out += (" " + arg2 + " goto " + result);
    }
    else if(op >= CtoI && op <= CtoF) {
        out += (result + " = ");
        switch(op) {
            case CtoI: out += "CharToInt"; break;
            case ItoC: out += "IntToChar"; break;
            case FtoI: out += "FloatToInt"; break;
            case ItoF: out += "IntToFloat"; break;
            case FtoC: out += "FloatToChar"; break;
            case CtoF: out += "CharToFloat"; break;
        }
        out += ("(" + arg1 + ")");
    }

    else if(op == ASSIGN)
        out += (result + " = " + arg1);
    else if(op == GOTO)
        out += ("goto " + result);
    else if(op == RETURN)
        out += ("return " + result);
    else if(op == PARAM)
        out += ("param " + result);
    else if(op == CALL) {
        if(arg2.size() > 0)
            out += (arg2 + " = ");
        out += ("call " + result + ", " + arg1);
    }
    else if(op == ARR_IDX_ARG)
        out += (result + " = " + arg1 + "[" + arg2 + "]");
    else if(op == ARR_IDX_RES)
        out += (result + "[" + arg2 + "] = " + arg1);
    else if(op == FUNC_BEG)
        out += (result + ": ");
    else if(op == FUNC_END) {
        out += ("function " + result + " ends");
    }
    else if(op == L_DEREF)
        out += ("*" + result + " = " + arg1);

    return out;
}


// Implementations of constructors and functions for the quadArray class
void quadArray::print() {
    for(int i = 0; i < 120; i++)
        cout << '-';
    cout << endl;
    cout << "THREE ADDRESS CODE (TAC):" << endl;
    for(int i = 0; i < 120; i++)
        cout << '-';
    cout << endl;

    int cnt = 0;
    // Print each of the quads one by one
    for(int i = 0; i < (int)quads.size(); i++) {
        // if(it->op != "label") {
        //     cout << left << setw(4) << cnt << ":    ";
        //     it->print();
        // }
        // else {
        //     cout << endl << left << setw(4) << cnt << ": ";
        //     it->print();
        // }

        cout << i << ":    " << quads[i].print() << endl;
    }
}


expression::expression(): fold(0), folder(NULL) {}


// Overloaded emit functions

void emit(string result, string arg1, string arg2, opcode op) {
    quad q(result, arg1, arg2, op);
    quadList.quads.push_back(q);
    nextinstr++;
}

void emit(string result, int constant, opcode op) {
    quad q(result, to_string(constant), "", op);
    quadList.quads.push_back(q);
    nextinstr++;
}

void emit(string result, char constant, opcode op) {
    quad q(result, to_string(constant), "", op);
    quadList.quads.push_back(q);
    nextinstr++;
}

void emit(string result, float constant, opcode op) {
    quad q(result, to_string(constant), "", op);
    quadList.quads.push_back(q);
    nextinstr++;
}


// Implementation of the makelist function
list<int> makelist(int i) {
    list<int> l(1, i);
    return l;
}

// Implementation of the merge function
list<int> merge(list<int> list1, list<int> list2) {
    list1.merge(list2);
    return list1;
}

// Implementation of the backpatch function
void backpatch(list<int> l, int address) {
    string str = to_string(address);
    for(list<int>::iterator it = l.begin(); it != l.end(); it++) {
        quadList.quads[*it].result = str;
    }
}


// Implementation of the convertToType function
void convertToType(expression* arg, expression* res, DataType toType) {
    if(res->type == toType)
        return;

    if(res->type == FLOAT) {
        if(toType == INT)
            emit(arg->loc, res->loc, "", FtoI);
        else if(toType == CHAR)
            emit(arg->loc, res->loc, "", FtoC);
    }
    else if(res->type == INT) {
        if(toType == FLOAT)
            emit(arg->loc, res->loc, "", ItoF);
        else if(toType == CHAR)
            emit(arg->loc, res->loc, "", ItoC);
    }
    else if(res->type == CHAR) {
        if(toType == FLOAT)
            emit(arg->loc, res->loc, "", CtoF);
        else if(toType == INT)
            emit(arg->loc, res->loc, "", CtoI);
    }
}


void convertToType(string t, DataType to, string f, DataType from) {
    if(to == from)
        return;
    
    if(from == FLOAT) {
        if(to == INT)
            emit(t, f, "", FtoI);
        else if(to == CHAR)
            emit(t, f, "", FtoC);
    }
    else if(from == INT) {
        if(to == FLOAT)
            emit(t, f, "", ItoF);
        else if(to == CHAR)
            emit(t, f, "", ItoC);
    }
    else if(from == CHAR) {
        if(to == FLOAT)
            emit(t, f, "", CtoF);
        else if(to == INT)
            emit(t, f, "", CtoI);
    }
}


// Implementation of the convertIntToBool function
void convertIntToBool(expression* expr) {
    if(expr->type != BOOL) {
        expr->type = BOOL;
        expr->falselist = makelist(nextinstr);    // Add falselist for boolean expressions
        emit("", expr->loc, "", IF_FALSE_GOTO);
        expr->truelist = makelist(nextinstr);     // Add truelist for boolean expressions
        emit("", "", "", GOTO);
    }
}


int sizeOfType(DataType t) {
    if(t == VOID)
        return __VOID_SIZE;
    else if(t == CHAR)
        return __CHARACTER_SIZE;
    else if(t == INT)
        return __INTEGER_SIZE;
    else if(t == POINTER)
        return __POINTER_SIZE;
    else if(t == FLOAT)
        return __FLOAT_SIZE;
    else if(t == FUNCTION)
        return __FUNCTION_SIZE;
    else
        return 0;
}

string checkType(symbolType t) {
    if(t.type == VOID)
        return "void";
    else if(t.type == CHAR)
        return "char";
    else if(t.type == INT)
        return "int";
    else if(t.type == FLOAT)
        return "float";
    else if(t.type == FUNCTION)
        return "function";

    else if(t.type == POINTER) {
        string tp = "";
        if(t.nextType == CHAR)
            tp += "char";
        else if(t.nextType == INT)
            tp += "int";
        else if(t.nextType == FLOAT)
            tp += "float";
        tp += string(t.pointers, '*');
        return tp;
    }

    else if(t.type == ARRAY) {
        string tp = "";
        if(t.nextType == CHAR)
            tp += "char";
        else if(t.nextType == INT)
            tp += "int";
        else if(t.nextType == FLOAT)
            tp += "float";
        vector<int> dim = t.dims;
        for(int i = 0; i < (int)dim.size(); i++) {
            if(dim[i])
                tp += "[" + to_string(dim[i]) + "]";
            else
                tp += "[]";
        }
        if((int)dim.size() == 0)
            tp += "[]";
        return tp;
    }

    else
        return "unknown";
}


string getInitVal(symbol* sym) {
    if(sym->initVal != NULL) {
        if(sym->type.type == INT)
            return to_string(sym->initVal->i);
        else if(sym->type.type == CHAR)
            return to_string(sym->initVal->c);
        else if(sym->type.type == FLOAT)
            return to_string(sym->initVal->f);
        else
            return "-";
    }
    else
        return "-";
}

// int main() {
//     STCount = 0;                            // Initialize STCount to 0
//     globalST = new symbolTable("Global");   // Create global symbol table
//     currentST = globalST;                   // Make global symbol table the currently active symbol table
//     blockName = "";

//     yyparse();
//     globalST->update();
//     quadList.print();       // Print Three Address Code
//     cout << endl;
//     globalST->print();      // Print symbol tables

//     return 0;
// }
