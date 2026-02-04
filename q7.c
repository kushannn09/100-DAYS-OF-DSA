/*Problem: Given an array of n integers, reverse the array in-place using two-pointer approach.*/
#include <stdio.h>
int main() {
    int n;
    scanf("%d",&n);
    int arr[100005];
    for(int i=0;i<n;i++) scanf("%d",&arr[i]);
    for(int i=0,j=n-1;i<j;i++,j--) {
        int t=arr[i]; arr[i]=arr[j]; arr[j]=t;
    }
    for(int i=0;i<n;i++) {
        printf("%d",arr[i]);
        if(i<n-1) printf(" ");
    }
    printf("\n");
    return 0;
}
