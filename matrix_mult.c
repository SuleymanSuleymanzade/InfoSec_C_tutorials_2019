#include<stdio.h>

int mx1[4][3] = {
    {1,3,5},
    {3,1,5},
    {7,8,3},
    {4,2,3}
};

int mx2[3][2] = {
    {1, 4},
    {2, 5},
    {6, 7}
};

int res[128][128];

int main(){
    for(int row1 = 0; row1 < 4; row1++){
        for(int col2 = 0; col2 < 2; col2++){
            for(int k = 0; k < 3; k++){
                res[row1][col2] += mx1[row1][k] * mx2[k][col2];
            }
        } 
    }
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 2; j++){
            printf("%2d ", res[i][j]);
        }
        printf("\n");
    }
}
