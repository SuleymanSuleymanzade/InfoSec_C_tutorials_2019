#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int mx[1024][1024];

int max(int a, int b){return a > b ? a : b;}

int get_sum(int s_r, int e_r, int s_c, int e_c){
    int temp = 0;
    for(int  i = s_r; i < e_r; i++){
        for(int j = s_c; j < e_c; j++){
            temp += mx[i][j];
        }
    }
    return temp;
}

int main(){

   int n, m;
   int a, b;
   scanf("%d %d", &n, &m);
   for(int i = 0; i < n; i++){
       for(int j = 0; j < m; j++){
            scanf("%d", &mx[i][j]);
       }
   }
   int max_p = -1e9;

   for(int i = 0; i < n; i++){
       for(int j = 0; j < m; j++){
           if((i + a <= n) && (j + b <= m)){
            int temp_s = get_sum(i, i+a, j, j+b);
            max_p = max(temp_s, max_p);
            printf("max_p: %d \n", max_p);
           }
       }
   } 
   printf("%d\n", max_p);

return 0;
}
