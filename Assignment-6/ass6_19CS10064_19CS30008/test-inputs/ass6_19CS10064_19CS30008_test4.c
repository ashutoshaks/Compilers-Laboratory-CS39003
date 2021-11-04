// include predefined functions 

int printStr (char *ch);
int printInt (int n);
int readInt (int *n);

// Global declarations
float d = 2.3;
char c; 
int i, j, k, l, m, n, o;
int w[10];                      // 1D array declaration
int a = 4, *p, b;               // pointer declaration

int maxSubArrSum (int a[], int n) { 
    int max_so_far = -1000, max_ending_here = 0; 
    int i;
    for (i = 0; i < n; i++) { 
        max_ending_here = max_ending_here + a[i]; 
        if (max_so_far < max_ending_here) {
            max_so_far = max_ending_here; 
        }
  
        if (max_ending_here < 0) {
            max_ending_here = 0; 
        }
    } 
    return max_so_far; 
} 
  
//Driver program to test maxSubArrSum
int main() { 
    int a[8];
    a[0]= -20;
    a[1]= -30;
    a[2]= 40;
    a[3]= -10;
    a[4]= -20;
    a[5]= 10;
    a[6]= 50;
    a[7]= -370;
    int max_subArr_sum = maxSubArrSum(a, 8); 
    printStr("Maximum contiguous sum is ");
    printInt(max_subArr_sum);
    printStr("\n");
    return 0; 
}
