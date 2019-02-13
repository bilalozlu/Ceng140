#include <stdio.h>

void recurse(int dim_i, int dim_j, char arr[dim_i][dim_j], int pos_i, int pos_j, char oldT, char newT) {
        arr[pos_i][pos_j] = newT;
        if (pos_i > 0) {
                if (arr[pos_i-1][pos_j] == oldT) {
                        recurse(dim_i, dim_j, arr, pos_i-1, pos_j, oldT, newT);
                }
                if (pos_j > 0 && arr[pos_i-1][pos_j-1] == oldT) {
                        recurse(dim_i, dim_j, arr, pos_i-1, pos_j-1, oldT, newT);
                }
                if (pos_j < dim_j - 1 && arr[pos_i-1][pos_j+1] == oldT) {
                        recurse(dim_i, dim_j, arr, pos_i-1, pos_j+1, oldT, newT);
                }
        }
        if (pos_i < dim_i - 1) {
                if (arr[pos_i+1][pos_j] == oldT) {
                        recurse(dim_i, dim_j, arr, pos_i+1, pos_j, oldT, newT);
                }
                if (pos_j > 0 && arr[pos_i+1][pos_j-1] == oldT) {
                        recurse(dim_i, dim_j, arr, pos_i+1, pos_j-1, oldT, newT);
                }
                if (pos_j < dim_j - 1 && arr[pos_i+1][pos_j+1] == oldT) {
                        recurse(dim_i, dim_j, arr, pos_i+1, pos_j+1, oldT, newT);
                }
        }
        if (pos_j > 0 && arr[pos_i][pos_j-1] == oldT) {
                recurse(dim_i, dim_j, arr, pos_i, pos_j-1, oldT, newT);
        }
        if (pos_j < dim_j -1 && arr[pos_i][pos_j+1] == oldT) {
                recurse(dim_i, dim_j, arr, pos_i, pos_j+1, oldT, newT);
        }
}

int main(){
        int dim_i,dim_j, pos_i, pos_j;
        char x, oldT, newT;
        scanf("%d %d\n", &dim_i, &dim_j);
        char arr[dim_i][dim_j];

        for (int i = 0; i < dim_i; i++) {
                for (int j = 0; j < dim_j; j++) {
                        scanf("%c\n", &x);
                        arr[i][j] = x;
                }
        }

        scanf("%d %d %c", &pos_i, &pos_j, &newT);
        oldT = arr[pos_i][pos_j];

        recurse(dim_i, dim_j, arr, pos_i, pos_j, oldT, newT);

        for (int i = 0; i < dim_i; i++) {
                for (int j = 0; j < dim_j; j++) {
                        x = arr[i][j];
                        printf("%c", x);
                }
                printf("\n");
        }
        return 0;
}
