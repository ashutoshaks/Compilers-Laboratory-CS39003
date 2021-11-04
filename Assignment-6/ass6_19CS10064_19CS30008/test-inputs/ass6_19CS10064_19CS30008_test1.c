int printStr (char *ch);
int printInt (int n);
int readInt (int *eP);

int global_var = 0;                                               // test : global variable

int binarySearch (int a[], int l, int r, int x) {   
    while (l <= r) {
        int mid = (l + r) / 2;
        if (a[mid] == x) {                                           // test : conditionals                                         
            return mid;
        } else if (a[mid] < x) {                               // test :  array arithmetic
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

    int a[10];                                              // test : 1-D array declaration
    int i, n, c;

    // test :  read numbers
    printStr("Enter 10 array elements in sorted order, separated by newlines:\n");
    for (i = 0; i < 10; i++) {
        a[i] = readInt(&c); 
    }

    // test :  print numbers
    printStr("Entered array : ");
    for (i = 0; i < 10; i++) {  
        printInt(a[i]);
        printStr(" ");         
    }
    printStr("\n");

    int x;
    printStr("Number to search: ");
    x = readInt(&c);
    int index = binarySearch(a, 0, 9, x);
    if (index == -1) {
        printStr("Invalid search, not found");
    } else { 
        printStr("Element found\n");
        printStr("Position: ");
        printInt(index);
    }
    printStr("\n");
    return 0;
}
