int printStr (char *ch);
int printInt (int n);
int readInt (int *n);

// Global declarations
float d = 2.3;
char c; 
int i, j, k, l, m, n, o;
int w[10];                      // 1D array declaration
int a = 4, *p, b;               // pointer declaration

int main() {
    {
        /*
        test do while
        */
        int do_iterator = 20;
        do  {
                printStr("\nEntered for ");
                printInt(do_iterator++);          // incrementor in printStr
                printStr("time.");
            } while (do_iterator < 100);

      	// scope management 
        { 
            int w = 10;
            printStr("\nScope 1:");
            printInt(w);
            { 
                int w = 2;
                printStr("\nScope 2:");
                printInt(w);
                { 
                    int w = 3;
                    if ( w = 9) {
                        printStr("Entered in the w = 9 condition if block.\n");
                    }
                    printStr("\nScope 3:");
                    printInt(w);
                    printStr("\n");
            }
        }
    }
  return 0;
}
