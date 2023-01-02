#include <stdio.h>
#include <stdlib.h>

int search(int key, int *fr, int len) {

    for(int i = 0; i < len; i++) {
        if(fr[i] == key) {
            return 1;
        }
    }
    return 0;
}

int main() {
    int capacity = 0;
    int arr_length = 0;
    int page_faults = 0;
    int count = 0;
    int count_aux = 0;

    scanf("%d", &capacity);
    scanf("%d", &arr_length);

    int *arr = malloc(arr_length * sizeof(int));
    int *s = malloc(capacity * sizeof(int));

    for(int i = 0; i < arr_length; i++) {
        scanf("%d", &arr[i]);

    }

    for(int i = 0; i < capacity; i++) {
        s[i] = -1;
    }

    for(int i = 0; i < arr_length; i++) {
        if(search(arr[i], s, capacity) != 1) {
            int vector_aux[capacity];

            for(int j = 0; j < capacity -1; j++) {
                vector_aux[j] = s[j+1];
            }

            for(int j = 0; j < capacity -1; j++) {
                s[j] = vector_aux[j];
            }

            s[capacity - 1] = arr[i];
            page_faults++;
        }

        else {
            int aux = 0;
            for(int j = 0; j < capacity; j++) {
                if(arr[i] == s[j]) {
                    aux = j;
                }
            }

            for(int j = aux; j < capacity - 1; j++) {
                s[j] = s[j + 1];
            }

            s[capacity - 1] = arr[i];
        }
        // para vizualizar a ocupação dos quadros
        // for(int z = 0; z < capacity; z++) {
        //     printf("%d", s[z]);
        // }
        // printf("\n");

    }

    printf("%d", page_faults);
    return 0;
}