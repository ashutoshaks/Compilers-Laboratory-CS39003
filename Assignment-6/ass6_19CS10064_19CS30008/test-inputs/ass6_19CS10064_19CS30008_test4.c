// Typecasting and pointers
void swap (int *xp, int *yp) {                      // pointers
    int temp = *xp;
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
    arr[0] = 1.3;                                   // type casting float -> int
    arr[1] = -4.5;
    arr[2] = (int)7.34;
    arr[3] =  8.56;
    arr[4] = -342.0;
    arr[5] = 0.6;
    int n = 6;
    sort(arr, 5);
    
    return 0;
}
