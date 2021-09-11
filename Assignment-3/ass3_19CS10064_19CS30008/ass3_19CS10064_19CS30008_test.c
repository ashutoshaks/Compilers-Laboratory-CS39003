/* Test File */
#include "myl.h"
#define ASSGN 3

typedef unsigned long long ull;

static const double pi = 3.14;
auto Bool b = true;
enum week {Mon = 1, Tue, Wed, Thur, Fri, Sat, Sun};

struct node {
    int value;
	struct node* next;
};

union test {
	int p;
};

inline char toUpper (char ch);

void main ()
{
	// testing identifiers and constants
    short signed int number0 = 40;	// integer-constant
    enum week _day = Sun;			// enum- constant
    float f1_ = 23.56;				// floating-constant
    float f2_ = 23.E-2;
    float f3_ = 23.56e+3;
    float f4_ = .56E2;
    float f5_ = 232e3;
    char _1 = '$';					// character-constant
    char _2 = '\b';

    // testing string literals
    char s[2] = "";
    char str[] = "This is a test string\\\"\'\n";

    // testing punctuators
    int a = 1, b = 1;
    a++;
    a--;
    a = a&b;
    a = a*b;
    a = a+b;
    a = a-b;
    a = !b;
    a = ~b;
    a = a/b;
    a = a%b;
    a = a<<b;
    a = a>>b;
    a = a^b;
    a = a|b;
    a = (a) ? a : b;
    a *= b;
    a /= b;
    a %= b;
    a += b;
    a -= b;
    a <<= b;
    a >>= b;
    a &= b;
    a ^= b;
    a |= b, b = 0;

    struct node *head;
    if (!head) {
    	head = head -> next;
    }

    switch (_day) {
    	case 1:	
    		break;
		default:;
    }

    do {
        n -= 1;
    } while (n > 1)

    for (int i = 0; (i < 3 && i >= 0) || (i > 100 && i != 101); i++) {
    	continue;
    }
 
    if (t <= 30) {
        break;
    } else {
    	t = 30;
    }

    //	testing comments

    // this is a single line comment
    /* this comment is a multi line comment. 
    We will briefly check one single line just after this! */
}