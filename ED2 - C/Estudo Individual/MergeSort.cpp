#include <stdio.h>
#include <stdlib.h>

void merge_sorted_arrays(int *array, int left, int middle, int right) {
    int left_length = middle - left + 1;
    int right_length = right - middle;

    int left_array[left_length];
    int right_array[right_length];

    int i, j, k;

    for(i = 0; i < left_length; i++ ) {	
		left_array[i] = array[left + i];
	} 
    for(i = 0; i < right_length; i++){
		right_array[i] = array[middle + 1 + i];
	}

    for(i = 0, j = 0, k = left; k <= right; k++) {
        if(i < left_length && j >= right_length || left_array[i] <= right_array[j]) {
        	array[k] = left_array[i];
			i++;	
		} else {
			array[k] = right_array[j];
			j++;
		}
    }
}

void merge_sort_recursion(int *array, int left, int right) {
    if (left < right){
    	int middle = left + (right - left) / 2;

    	merge_sort_recursion(array, left, middle);
    	merge_sort_recursion(array, middle + 1, right);

    	merge_sorted_arrays(array, left, middle, right);
    }
}

void merge_sort(int *array, int length) {
    merge_sort_recursion(array, 0, length - 1);
} 

int main(){
    int array[10] = {9,4,1,3,5,6,2,8,7,0};
    int length = 10;   

    merge_sort(array, length);

    for (int i = 0; i < length; i++) {
        printf("%d ", array[i]);
    }
    return 0;
}