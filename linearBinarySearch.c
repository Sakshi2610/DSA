#include<stdio.h>

int linearSearch(int arr[], int size, int element){
    for (int i = 0; i < size-1; i++)
    {
        if(arr[i] == element){
            return i;
        }
    }
    return -1;
}

int binarySearch(int arr[], int size, int element){
    int low, mid, high;
    low = 0;
    high = size-1;

    while(low<=high){
        mid = (low+high),2;
        if(arr[mid] == element){
            return mid;
        }
        if(arr[mid]<element){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return -1;
}

int main(){
    //unsorted array for linear search
    // int arr[] = {23,41,5,6,3,7,4,8,9,2,3,6};
    // int size = sizeof(arr)/sizeof(int);

    //sorted array for binary search
    int arr[] = {23,41,51,61,70,80,99,108,129,152,723,986};
    int size = sizeof(arr)/sizeof(int);
    int element = 986;
    printf("Element found at index position %d", binarySearch(arr, size, element));
    return 0;
}