#include<stdio.h>
#include<stdlib.h>

void linear_search();
void recursive_linear(int, int);
void binary_search();
void recursive_binary(int, int, int, int);

int arr[50], n, lb, ub, mid;

int main()
{
    int i, ch, key;
    
    printf("Enter size of the array: ");
    scanf("%d", &n);
    printf("Enter the elements of the array: ");
    
    for( i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    printf("Enter 1 for linear search \n2 for recursive linear search \n3 for binary search \n4 for recursive binary search ");
    scanf("%d", &ch);

    switch(ch){
        case 1:
            linear_search();
            break;

        case 2:
            printf("Enter key to search: ");
            scanf("%d", &key);
            recursive_linear(n, key);
            break;

        case 3:
            binary_search();
            break;

        case 4:
        printf("Enter key to search: ");
            scanf("%d", &key);
            recursive_binary(key, n, 0, n-1);
            break;

        default:
            printf("Invalid choice");
    }
    return 0;
}

void linear_search(){
    int key, i;
    printf("Enter key to search: ");
    scanf("%d", &key);
    for(i = 0; i<n; i++){
        if(arr[i]==key){
            printf("Element found!");
            return;
        }
    }
    printf("Element was not found!");
}

void recursive_linear(int n, int key){
    int i;
    if( n == 0){
        printf("Element was not found");
        return;
    }
    else if( arr[n] == key){
        printf("Element was found");
        return;
    }
    else{
        recursive_linear(n-1, key);
    }
}
void binary_search(){
    int key;
    printf("Enter key to search ");
    scanf("%d", &key);
    lb = 0;
    ub = n-1;
    mid = (lb+ub)/2;
    while(lb<=ub){
        if(arr[mid]==key){
            printf("Element was found!");
            return;
        }
        else if(arr[mid]<key){
            lb = mid+1;
        }
        else{
            ub = mid -1;
        }
    }
    printf("Element was not found!");
}
void recursive_binary(int key, int n, int lb, int ub){
    int mid = lb+ub/2;
    while(lb<=ub){
        if(arr[mid]==key){
            printf("Element was found!");
            return;
        }
        else if(arr[mid]<key){
            recursive_binary(key, n, mid+1, ub);
        }
        else
        recursive_binary(key, n, lb, mid-1);
    }
}