int printInt (int n);
int printStr (char *ch);
int readInt (int *n);

int global_var = 0;		                                               // test : global variable

int binarySearch (int a[], int l, int r, int x) {   
    while (l <= r) {	
        int mid = (l + r) / 2;
        if (a[mid] == x) {	                                           // test : conditionals
            printStr("Index of x: ");  
            printInt(mid);
            printStr("\n");	                                           
            return mid;
        } else if (a[mid] < x) {		                               // test :  array arithmetic
            l = mid + 1;
        } else {   
            r = mid - 1;
        }
    }
    printStr("Element not found!");   
    printStr("\n");
    return -1;			
}

int main() {
    global_var++;

    int a[10];		// test : 1-D array declaration
    int i, n;

    // test :  read numbers
    printStr("Enter 10 array elements: ");
    for (i = 0; i < 10; i++) {	
        int c;
        a[i] = readInt(&c);			 
    }

    // test :  print numbers
    printStr("Entered array :");
    for (i = 0; i < 10; i++) {  
        printInt(a[i]);
        printStr("\n");         
    }

    int x;
    printStr("Number to search: ");
    readInt(&x);
    int index = binarySearch(a, 0 ,9 ,index);
    if (index == -1) {
        printStr("invalid search: not found");
    } else { 
        printStr("Position: ");
        printInt(index);
    }
    printStr("\n");
    return 0;
}