
/*
 *   Test file to check basic statements, expression, readInt and printInt  
 *   library functions created in assignment 2
 *   also checks the recursive fib function to check the function 
 *   call and return methodology
*/

int printStr (char *ch);
int printInt (int n);
int readInt (int *eP);

// Global declarations
float d = 2.3;
char c; 
int i, j, k, l, m;
int w[10];                      // 1D array declaration
int a = 4, *p, b;               // pointer declaration

int main () {
    // Variable Declaration
    int x;
    int y;
    int flag;
    printStr("Enter x: ");
    x = readInt(&flag);
    printStr("Enter y: ");
    y = readInt(&flag);
    char ch = 'c';     // character definitions

    // Arithmetic Operations
    i = x + y;
    printStr("i = x + y = ");
    printInt(i);
    printStr("\n");

    j = x - y;
    printStr("j = x - y = ");
    printInt(j);
    printStr("\n");

    k = x * y;
    printStr("k = x * y = ");
    printInt(k);
    printStr("\n");

    l = x / y;
    printStr("l = x / y = ");
    printInt(l);
    printStr("\n");

    m = x % y;
    printStr("m = x % y = ");
    printInt(m);
    printStr("\n");

    return 0;
}