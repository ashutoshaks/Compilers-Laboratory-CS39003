/*
    Ashutosh Kumar Singh
    19CS30008
    Compilers Laboratory - Assignment 2
*/

#include "myl.h"

int main()
{
    printStr("************ Testing the library ************\n");
    printStr("*********************************************\n");

    printStr("\n******* Testing the printStr function *******\n");
    printStr("\nString #1 : ");
    char* str1 = "This is my own library.";
    int lenStr1 = printStr(str1);
    printStr("\nNo. of characters printed : ");
    printInt(lenStr1);
    printStr("\n\nString #2 : ");
    char* str2 = "Another test string";
    int lenStr2 = printStr(str2);
    printStr("\nNo. of characters printed : ");
    printInt(lenStr2);

    printStr("\n\n******* Testing the printInt function *******\n");
    printStr("\nInteger #1 : ");
    int num1 = 5473816;
    int lenNum1 = printInt(num1);
    printStr("\nNo. of characters printed : ");
    printInt(lenNum1);
    printStr("\n\nInteger #2 : ");
    int num2 = -26859;
    int lenNum2 = printInt(num2);
    printStr("\nNo. of characters printed : ");
    printInt(lenNum1);

    printStr("\n\n******* Testing the printFlt function *******\n");
    printStr("\nFloat #1 : ");
    float float1 = 11.78456;
    int lenFloat1 = printFlt(float1);
    printStr("\nNo. of characters printed : ");
    printInt(lenFloat1);
    printStr("\n\nFloat #2 : ");
    float float2 = -0.625;
    int lenFloat2 = printFlt(float2);
    printStr("\nNo. of characters printed : ");
    printInt(lenFloat2);

    printStr("\n\n******** Testing the readInt function ********\n");
    printStr("\nEnter Integer #1 : ");
    int n1;
    int flag1 = readInt(&n1);
    if(flag1 == ERR)
        printStr("Not a valid Integer");
    else {
        printStr("Integer entered : ");
        printInt(n1);
    }

    printStr("\n\nEnter Integer #2 : ");
    int n2;
    int flag2 = readInt(&n2);
    if(flag2 == ERR)
        printStr("Not a valid Integer");
    else {
        printStr("Integer entered : ");
        printInt(n2);
    }

    printStr("\n\n******** Testing the readFlt function ********\n");
    printStr("\nEnter Float #1 : ");
    float f1;
    int flag3 = readFlt(&f1);
    if(flag3 == ERR)
        printStr("Not a valid Float");
    else {
        printStr("Float entered : ");
        printFlt(f1);
    }

    printStr("\n\nEnter Float #2 : ");
    float f2;
    int flag4 = readFlt(&f2);
    if(flag4 == ERR)
        printStr("Not a valid Float");
    else {
        printStr("Float entered : ");
        printFlt(f2);
    }
    printStr("\n\n");

}
