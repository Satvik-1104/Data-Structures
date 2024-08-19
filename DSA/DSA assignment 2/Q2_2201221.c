#include <stdio.h>
#include <limits.h>
int main(){
    int n;
    printf("enter the size of array: ");
    scanf("%d", &n);
    int a[n];
    printf("enter the elements of the array: ");
    for (int i=0;i<n;i++){
        scanf("%d", &a[i]);
    }
    printf("the entered array is: \n");
    for (int i=0;i<n;i++){
        printf("%d ", a[i]);
    }
    printf("\n");
    int m1 = INT_MIN, m2 = INT_MIN;
    for (int i=0;i<n;i++){
        if (a[i]>m1){
            m2=m1;
            m1=a[i];
        }
        else if (a[i]>m2&&a[i]<m1)
            m2=a[i];
    }
    printf("the second largest integer is: %d", m2);
}
