
/*
 *   Test file to check basic statements, expression, readInt and printInt  
 *   library functions created in assignment 2
 *   also checks the recursive fib function to check the function 
 *   call and return methodology
*/

int printStr (char *ch);
int printInt (int n);
int readInt (int *n);

// Global declarations
float d = 2.3;
char c; 
int i, j, k, l, m, n, o;
int w[10];                      // 1D array declaration
int a = 4, *p, b;               // pointer declaration

int main () {
    // Variable Declaration
    int x;
    int y;
    printStr("Enter x: ");
    readInt(&x);
    printStr("Enter y: ");
    readInt(&y);
    char ch = 'c', d = 'a';     // character definitions

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
    n = x & y;
    printStr("n = x & y = ");
    printInt(n);
    printStr("\n");
    o = x | y;
    printStr("o = x | y = ");
    printInt(o);
    printStr("\n");
    
    y = i << 2;
    x = i >> 1;

    return 0;
}