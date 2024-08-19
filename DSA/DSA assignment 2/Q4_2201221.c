#include <stdio.h>
int main(){
int m,n;
printf("enter the order of matrix(mxn): ");
scanf("%d %d", &m, &n);
int a[m][n], b[n][m];
printf("enter the elements of the matrix: ");
for (int i=0;i<m;i++){
    for (int j=0;j<n;j++){
        scanf("%d", &a[i][j]);
    }
 }
 printf("given matrix is: \n");
 for (int i=0;i<m;i++){
     for (int j=0;j<n;j++){
         printf("%d ", a[i][j]);
     }
     printf("\n");
  }
  for (int i=0;i<m;i++){
    for (int j=0;j<n;j++){
        b[j][i]=a[i][j];
    }
  }
  printf("transpose of the given matrix is: \n");
    for (int i=0;i<n;i++){
     for (int j=0;j<m;j++){
         printf("%d ", b[i][j]);
     }
     printf("\n");
  }
}

