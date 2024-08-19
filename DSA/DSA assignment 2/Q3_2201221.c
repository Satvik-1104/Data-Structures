#include <stdio.h>
int main(){
 int n;
 printf("enter the order of the square matrix: ");
 scanf("%d", &n);
 int m[n][n];
 printf("enter the elements of the matrix: ");
 for (int i=0;i<n;i++){
    for (int j=0;j<n;j++){
        scanf("%d", &m[i][j]);
    }
 }
 printf("given matrix is: \n");
for (int i=0;i<n;i++){
    for (int j=0;j<n;j++){
        printf("%d ", m[i][j]);
    }
    printf("\n");
 }
 int d1=0, d2=0;
 for (int i=0;i<n;i++){
    d1+=m[i][i];
 }
 printf("sum of 1st diagonal is: %d\n", d1);
 for (int i=0;i<n;i++){
    for (int j=0;j<n;j++){
        if (i+j==(n-1)){
            d2+=m[i][j];
        }
    }
}
printf("sum of 2nd diagonal is: %d\n", d2);
int d;
d=d1-d2;
    if (d<0)
        d*=(-1);
printf("the absolute difference of the sums of 2 diagonals is: %d", d);
return 0;
}
