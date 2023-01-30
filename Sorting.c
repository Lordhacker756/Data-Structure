#include<stdio.h>
#include<stdlib.h>

void bubbleSort();
void selectionSort();
void insertionSort();
void printArray();

int arr[50], n;

int main()
{
    int i, ch;
    
    printf("Enter size of the array: ");
    scanf("%d", &n);
    printf("Enter the elements of the array: ");
    
    for( i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    printf("Enter 1 for bubble sort \n2 for selection sort \n3 for Insertion sort");
    scanf("%d", &ch);

    switch(ch){
        case 1:
            bubbleSort();
            break;

        case 2:
            selectionSort();
            break;

        case 3:
            insertionSort();
            break;

        default:
            printf("Invalid choice");
    }
    return 0;
}

void bubbleSort(){
    int temp, i, j;
    // The main idea behind this is compare the adjacent elements and swap
    for(i = 0; i < n-1 ; i++){
        for(j=i+1; j<n; j++){
            if(arr[i]>arr[j]){
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    printArray(n);
}

void selectionSort(){
    int i, j, min, temp;
    for(i = 0; i < n-1 ; i++ )
    {
        min = i;
        for(j = i+1; j<n ; j++){
            if(arr[j]<arr[i]){
                min = j;
            }
        }
        if(min != i){
            temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp; 
        }
    }
    printArray(n);
}

void insertionSort(){
    int current, i, j;
    for( i = 1; i < n ; i++){
        current = arr[i];
        j = i-1;
        while(arr[j]>current && j>=0){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = current;
    }
    printArray();
}

void printArray(){
    int i;
    for( i = 0; i< n ;i++){
        printf("%2d", arr[i]);
    }
}