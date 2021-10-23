int fibn (int n) {
    if (n == 0)
        return 0;
 
    if (n == 1 || n == 2)
        return 1;
 
    // Recursive function
    else
        return (fibn(n - 1) + fibn(n - 2));
}
 
int main () {
    int n = 5;
    int i;
    int fib[n];
    // for loop to print the fibonacci series.
    for (i = 0; i < n; i++) {
        fib[i] = fibn(i+1);
    }
    return 0;
}
