// function calling and conditional statements (ternery and if-else)

int max (int x, int y) {
    int ans;
    if (x > y)  					        // if-else
   	    ans = x;
    else
   	    ans = y;
    return ans;
}

int min (int x, int y) {
    int ans;
    ans = (x > y) ? y:x; 		    // ternery
    return ans;
}

void print (char *ch) {
    return;
}

void print_greater (int m, int n) {
    char greater_m[] = "m is greater than n";
    char greater_n[] = "n is greater than m";
    (m > n) ? print(greater_m) : print(greater_n);
    return;
}

int add(int a, int b) {
  	int i = min(a, b);           // nested function calls
  	int j = max(a, b);
  	int d = j + i;
  	return d;
}

int main() {
  	int a, b, sum;
  	a = 1, b = 52;
  	sum = add(a, b);
  	return 0;
}