// Nested if else and recursive functions  

int fact (int n) {                               // recursive functions
    if (n == 0) 
        return 1; 
    return n * fact(n-1); 
} 

int main() {  
    int n;
    n = -5;

    if (n > 10) {
        n = 10;
    } else {
        if (n < 0) {                            // nested if-else
            n = 0;
        } else {
            n = 5;
        }
    }
    int fact_n = fact(n); 
    return 0;  
}
