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
        if(i < left_length && (j >= right_length || left_array[i] <= right_array[j])) {
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

int main() {
    int *array;
    int size = 0, option, input;

    if ((array = (int*) malloc(size * sizeof(int))) == NULL) {
        printf("Erro de alocação\n");
        return 0;
    }    

    while(option != 0) {
        printf("1 - Visualizar array\n");
        printf("2 - Inserir no array\n");
        printf("3 - Fechar programa\n");

        scanf("%d", &option);
        switch (option) {
        case 1:
            for (int i = 0; i < size; i++)
            {
                printf("%d ", array[i]);
            }
            printf("\n");    
            break;
        
        case 2:
            scanf("%d", &input);
            size++;
            if ((array = (int*)realloc(array, size * sizeof(int))) == NULL)
            {
                printf("Erro de realocação\n");
                free(array);
                return 0;
            } else {
                array[size-1] = input;
                merge_sort(array, size);
            }
            break;

        case 3:
			free(array);
			return 0;   
            break;

        default:
            printf("Opção inválida\n");
            break;
        }
    }
}