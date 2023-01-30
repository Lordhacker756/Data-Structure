#include<stdio.h>

int arr[100];

int main(){
    int n, i, j, temp;
    printf("Enter size of the array ");
    scanf("%d", &n);
    printf("Enter the elements of the array ");
    for(i =0; i< n; i++){
        scanf("%d", &arr[i]);
    }
    // Now our idea is to take the minimum element in the unsorted array and place it in the min index
    for(i=0; i<n-1 ; i++){
        int minIndex = i;
        for(j = i+1; j<n; j++){
            if(arr[minIndex]>arr[j]){
                minIndex = j;
            }
        }        
        if(minIndex != i){
            // Swap i and minIndex
            temp = arr[i];
            arr[i] = arr[minIndex]; 
            arr[minIndex] = temp;
        }
    }
    for(i = 0; i < n ;i++){
        printf("%d", arr[i]);
    }
}