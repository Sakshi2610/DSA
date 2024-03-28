#include<stdio.h>

//Traversal of array
void display(int arr[], int n){
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

//insertion of specific element to the specified index
int indDeletion(int arr[], int size, int index){
    for (int i=index; i < size-1; i++){
        arr[i] = arr[i+1];
    }
}

int main() {
    int arr[100] = {4,2,7,1,9,3};
    int size = 6, index = 3;
    display(arr, size);
    indDeletion(arr, size, index);
    size -= 1;
    display(arr, size);
    return 0;
}
