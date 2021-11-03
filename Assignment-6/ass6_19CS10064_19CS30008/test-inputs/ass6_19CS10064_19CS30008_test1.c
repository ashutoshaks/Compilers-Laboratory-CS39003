int printStr(char *c);
int printInt(int i);
int readInt(int *eP);

// int factorial ( int z);		// function declaration
// int main()
// {
// 	printStr("factorial Program::\n");
// 	int x,c;
// 	printStr("Input : \n");
// 	int z=readInt(&c);
// 	int m;
// 	m=factorial(z);
// 	printInt(z);
// 	printStr("! ");
// 	printStr(" is ");
// 	printInt(m);
// 	printStr("\n");
// 	return 0;
// }

// // function call
// int factorial(int z)
// {
// 	if(z==1)
// 		return 1;
// 	else
// 	{
// 		return z*factorial(z-1);
// 	}
// }

int merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
 
    int L[6], R[6];
 
    for(i = 0; i < n1; i++)
    {
        L[i] = arr[l + i];
    }
    for(j = 0; j < n2; j++)
    {
    	int zz=m+1+j;
        R[j] = arr[zz];
    }
 
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
    return 0;
}
 

int mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l+(r-l)/2; 
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
    return 0;
}
 
 

int printArray(int A[], int size)
{
    int i;
    for (i=0; i < size; i++)
    {
        printInt(A[i]);
        printStr(" ");
    }
    printStr("\n");
    return 0;
}
 
int main()
{
    printStr("Merge Sort \n");
    
    int arr[6];
    arr[0]=3;
    arr[1]=5;
    arr[2]=9;
    arr[3]=13;
    arr[4]=23;
    arr[5]=4;
    int arr_size = 6;
 
    printStr("Given array :: \n");
    printArray(arr, arr_size);
 
    mergeSort(arr, 0, arr_size - 1);
 
    printStr("Sorted array :: \n");
    printArray(arr, arr_size);
    return 0;
}