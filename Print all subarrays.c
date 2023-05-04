#include<stdio.h>

void main(){
    int n;
    printf("Enter the size of an array: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the Elements Of an Array: \n");
    for(int p=0;p<n;p++){
        scanf("%d",&arr[p]);
    }
    printf("Subarrays are: \n");
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            for(int k=i;k<=j;k++){
            printf("%d ",arr[k]);
            }
            printf("\n");
        }
    }
}
