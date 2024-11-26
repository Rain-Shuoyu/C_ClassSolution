#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void swap(int *arr, int i, int j){
	int temp;
	temp = *(arr + i);
	*(arr + i) = *(arr + j);
	*(arr + j) = temp;
} 

void perm(int *arr, int p, int q){
	if(p == q){
		for(int i=0; i<=q; i++) printf("%d", arr[i]);
		printf("\n");
	}
	else{
		for(int i=p; i<=q; i++){
			swap(arr, p, i);
			perm(arr, p+1, q);
			swap(arr, p , i);
		}
	}
} 

int main(){
	int arr[] = {1, 2, 3};
	perm(arr, 0, 2);
	return 0;
}

