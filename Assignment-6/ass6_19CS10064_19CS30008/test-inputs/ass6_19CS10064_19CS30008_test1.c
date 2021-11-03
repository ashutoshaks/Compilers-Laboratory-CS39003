int printStr(char *c);
int printInt(int i);
int readInt(int *eP);

int factorial ( int z);		// function declaration
int main()
{
	printStr("factorial Program::\n");
	int x,c;
	printStr("Input : \n");
	int z=readInt(&c);
	int m;
	m=factorial(z);
	printInt(z);
	printStr("! ");
	printStr(" is ");
	printInt(m);
	printStr("\n");
	return 0;
}

// function call
int factorial(int z)
{
	if(z==1)
		return 1;
	else
	{
		return z*factorial(z-1);
	}
}