
int printStr(char *c);
int printInt(int i);
int readInt(int *eP);


int e=5;			// test : scope of global variables

int main()
{
  	// scope management 
  { int w=1;
    printStr("\nScope1:");printInt(w);
    { 
      int w=2;
      printStr("\nScope2:");printInt(w);
      { 
        int w=3;
        if ( w = 9)printStr("I entered it");
        printStr("\nScope3:");printInt(w);

      }
    }

  }
    /*
    test do while
    */
    int do_iterator=0;
    do {
      printStr("\nHi this is my ");
      printInt(do_iterator++);			// incrementor in printStr
      printStr("loop");

      }while(do_iterator<10);



  return 0;
}
