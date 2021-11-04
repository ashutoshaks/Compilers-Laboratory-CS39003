// the program tests : function declaration , calling , global variable scope, some operators : / % * ... 
int printInt (int n);
int printStr (char * ch);
int readInt (int *n);

int global_var = 0;		                                               // test : global variable
int counter =0;

int fibn (int n);

int main () {
	counter++;
	global_var = counter;
    int n;
    printStr("Enter n: ");
    readInt(&n);
    int i;
    int fib[n];
    // for loop to print the fibonacci series.
    for (i = 0; i < n; i++) {
        fib[i] = fibn(i+1);
        counter++;
		global_var = counter;
    }
    for (i = 0; i < n; i++) {
        printStr("Fib[i+1] = ");
        printInt(fib[i]);
        printStr("\n");
    }
    return 0;
}

int fibn (int n) {
	counter++;
	global_var = counter;

    if (n == 0) {
        return 0;
    }
 
    if (n == 1 || n == 2) {
        return 1;
    }
 
    // Recursive function
    else {
        return (fibn(n - 1) + fibn(n - 2));
    }
}