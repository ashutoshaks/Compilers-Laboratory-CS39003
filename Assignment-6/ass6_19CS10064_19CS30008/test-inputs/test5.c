/**  
 * Tests : pointers , array arithemtic printIntng array elements 
 * printIntng pointers, pointer rithmetic , operations.
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

// Typecasting and pointers
void swap (int *xp, int *yp) {                      // test : pointers
    int temp = *&(*xp);
    *xp = *yp;
    *yp = temp;
    return;
}

void sort (int *arr, int n) {
    int i, j, min_idx;
    i = 0;
    j = 0;
    for (i = 0; i < n-1; i++) {
        min_idx = i;
        for (j = i+1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        swap(&arr[min_idx], &arr[i]);
    }
    return;
}

int main() {
    int arr[6];
    printStr("Enter 6 array elements: ");
    for (i = 0; i < 6; i++) {  
        readInt(&arr[i]);      
    }

    // test :  print numbers
    printStr("Entered array is :");
    for (i = 0; i < 6; i++) {  
        printInt(arr[i]);
        printStr("\n");         
    }
    int n = 6;
    sort(arr, 5);
    printStr("Sorted array is :");
    for (i = 0; i < 6; i++) {  
        printInt(arr[i]);
        printStr("\n");         
    }
    return 0;
}

