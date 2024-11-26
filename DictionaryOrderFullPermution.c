#include <stdio.h>
#include <stdlib.h>

void swap(int *arr, int i, int j){
    int temp = arr[j];
	for(int k=j; k>i; k--) arr[k] = arr[k-1];
	arr[i] = temp;
}

void swap_back(int *arr,  int i, int j){
	int temp = arr[i];
	for(int k=i; k<j; k++) arr[k] = arr[k+1];
	arr[j] = temp;
} 

void perm(int *arr, int p, int q){
    if(p == q){
        for(int i = 0; i <= q; i++) printf("%d", arr[i]);
        printf("\n");
    } else {
        for(int i = p; i <= q; i++){
            swap(arr, p, i);
            perm(arr, p + 1, q);
            swap_back(arr, p, i);
        }
    }
}

int main(){
    int arr[] = {1, 2, 3, 4};
    perm(arr, 0, 3);
    return 0;
}
