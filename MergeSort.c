#include<stdio.h>
#include<stdlib.h>

void merge(int *arr, int start, int mid, int end){
    int len1 = mid - start + 1;
    int len2 = end - mid;
    int i = 0, j = 0, k = 0;
    int *sort = (int *)malloc(sizeof(int)*(end - start + 1));

    while(len1 != 0 || len2 != 0){
        if(len1 != 0 && len2 != 0){
            if(arr[start + j] < arr[mid + 1 + k]){
                sort[i] = arr[start + j];
                j++;
                len1 --;
            }
            else{
                sort[i] = arr[mid + 1 + k];
                k++;
                len2 --;
            }
        }
        else if(len1 != 0 && len2 == 0){
            sort[i] = arr[start + j];
            j++;
            len1 --;
        }
        else if(len2 != 0 && len1 == 0){
            sort[i] = arr[mid + 1 + k];
            k++;
            len2--;
        }
        i++;
    }

    for(int i=0; i< end - start + 1; i++){
        arr[start + i] = sort[i];
    }
    free(sort);
}

void mergeSort(int *arr, int start, int end){
    int mid = start + (end - start)/2;

    if(start == end || end - start == 1){
        merge(arr, start, mid, end);
    }

    else{
        mergeSort(arr, start, mid);
        mergeSort(arr, mid + 1, end);
        merge(arr, start, mid, end);
    }
}