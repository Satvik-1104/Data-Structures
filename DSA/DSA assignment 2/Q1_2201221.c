#include <stdio.h>
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
    for (int i=0;i<n;i++){
        for (int j=i+1;j<n;j++){
        if (a[i]%2!=0){
            int temp = 0;
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
        else
            continue;
    }
    }
    for (int i=0;i<n;i++){
        for (int j=i+1;j<n;j++){
        if (a[i]%2!=0){
            int temp = 0;
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
        else
            continue;
    }
    }
    for (int i=0;i<n;i++){
        printf("%d ", a[i]);
    }
}
