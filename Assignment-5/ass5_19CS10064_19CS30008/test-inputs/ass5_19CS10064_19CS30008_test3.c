// Arrays (multidimensional), loops and nested loops

int N = 4;

void getCF (int mat[N][N], int temp[N][N], int p, int q, int n) {
    int i = 0, j = 0, row = 0, col = 0;
 
    for (row = 0; row < n; row++) {                       // nested for loop
        for (col = 0; col < n; col++) {
            if (row != p && col != q) {
                temp[i][j++] = mat[row][col];
            }
            if (j == n - 1) {
                j = 0;
                i++;
            }
        }
    }
    return;
}

int main() {
    int p[5];                                   // 1D integer array
    int i = 0;

    while (i < 5) {                             // while loop
        p[i++] = i; 
    }

    int sum = 0, n = 5;
    i = 0;
    do {                                        // do-while loop
        sum = sum + p[i++];
    } while (i < n);

    int mat[N][N];

    int x = 0, y = 0, val = 20;

    for (x = 0; x < N; x++) {
        for (y = 0; y < N; y++) {
            mat[x][y] = val++;
        }
    }

    int cofactor[N][N];
    getCF(mat, cofactor, 0, 0, N);

    return 0;
}
