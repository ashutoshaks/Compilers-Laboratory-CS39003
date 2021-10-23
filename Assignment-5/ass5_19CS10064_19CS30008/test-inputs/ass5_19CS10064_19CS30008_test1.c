// Declarations (variables(int, float, char), 1D array, 2D array, functions) and arithmetic operations

// Global declarations
float d = 2.3;
char c;	
int i, j, k, l, m, n, o;
int w[10];                      // 1D array declaration
float f[20][50];                // 2D array declaration
int a = 4, *p, b;               // pointer declaration

void func (int i, float d) {
    d = (float)(i ^ 7);
    return;
}

int main () {
    // Variable Declaration
    int x = 120;
    int y = 17;
    char ch = 'c', d = 'a';     // character definitions

    // Arithmetic Operations
    i = x + y;
    j = x - y;
    k = x * y;
    l = x / y;
    m = x % y;
    n = x & y;
    o = x | y;
    
    y = i << 2;
    x = i >> 1;

    return 0;
}
