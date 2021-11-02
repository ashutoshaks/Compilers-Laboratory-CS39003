
// //test file to check basic statements, expression, readInt and printInt library 

// //functions created in assignment 2

// //also checks the recursive fibonacci function to check the function call and return methodology


// int printStr(char *c);
// int printInt(int i);
// int readInt(int *eP);
// int e=5;								// global var testing
// int fibonacci(int n)
// {
//     if(n<=2)
//         return 1;
//     printStr("debug1 \n");
//     int d;
//     printInt(n);
//     printStr("debug2 \n");
//     d=fibonacci(n-1);			// recursive calls
//     int c;
//     //printStr("5 \n");
//     c=fibonacci(n-2);
//     int e;
//     e=d+c;
//     //printStr("6 \n");
//     return e;
// }

// int main()
// {
//   int a=5;
//   int result;
// 	result = fibonacci ( a) ; // function invocation
// 	printStr("\nResult = \n");
// 	printInt(result);
//   return 0;
// }

int printStr(char *c);
int printInt(int i);
int readInt(int *eP);

int solve(int a)
{
    if(a <= 5)
        return 1;
    return 0;
}

void main()
{
    int a = 5;
    int ans = solve(a);
    printInt(ans);

    return;
}
