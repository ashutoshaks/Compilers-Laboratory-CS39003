// Function calls and conditional statements (ternary and if-else)

int max (int x, int y) {
    int ans;
    if (x > y)                      // if-else
        ans = x;
    else
        ans = y;

    if(ans < 0)
        ans = -ans;
    return ans;
}


int min (int x, int y) {
    int ans;
    ans = x > y ? y:x;              // ternary
    return ans;
}

void print (char *ch) {
    // print the char array
    return;
}

void print_greater (int m, int n) {
    char greater_m[] = "m > n";
    char greater_n[] = "n > m";
    m > n ? print(greater_m) : print(greater_n);
    return;
}

int add(int a, int b) {
    int i = min(a, b);            // nested function calls
    int j = max(a, b);
    int j = 0;
    int d = j + i;
    return d;
}

int main() {
    int a, b, sum;
    a = 1, b = 52;
    sum = add(a, b);
    return 0;
}
