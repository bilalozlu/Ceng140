#include <stdio.h>

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

        int flag = 1;
        arr[pos_i][pos_j] = 'X';

        while(flag) {
                flag = 0;
                for (int i = 0; i < dim_i; i++) {
                        for (int j = 0; j < dim_j; j++) {
                                if (arr[i][j] == 'X') {
                                        if (i > 0) {
                                                if (arr[i-1][j] == oldT) {
                                                        arr[i-1][j] = 'X';
                                                        flag = 1;
                                                }
                                                if (j > 0 && arr[i-1][j-1] == oldT) {
                                                        arr[i-1][j-1] = 'X';
                                                        flag = 1;
                                                }
                                                if (j < dim_j - 1 && arr[i-1][j+1] == oldT) {
                                                        arr[i-1][j+1] = 'X';
                                                        flag = 1;
                                                }
                                        }
                                        if (i < dim_i - 1) {
                                                if (arr[i+1][j] == oldT) {
                                                        arr[i+1][j] = 'X';
                                                        flag = 1;
                                                }
                                                if (j > 0 && arr[i+1][j-1] == oldT) {
                                                        arr[i+1][j-1] = 'X';
                                                        flag = 1;
                                                }
                                                if (j < dim_j - 1 && arr[i+1][j+1] == oldT) {
                                                        arr[i+1][j+1] = 'X';
                                                        flag = 1;
                                                }
                                        }
                                        if (j > 0 && arr[i][j-1] == oldT) {
                                                arr[i][j-1] = 'X';
                                                flag = 1;
                                        }
                                        if (j < dim_j -1 && arr[i][j+1] == oldT) {
                                                arr[i][j+1] = 'X';
                                                flag = 1;
                                        }
                                        arr[i][j] = newT;
                                }
                        }
                }
        }

        for (int i = 0; i < dim_i; i++) {
                for (int j = 0; j < dim_j; j++) {
                        x = arr[i][j];
                        printf("%c", x);
                }
                printf("\n");
        }
        return 0;
}
