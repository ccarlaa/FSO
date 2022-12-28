#include <stdio.h>
#include <stdlib.h>

int main() {
    int boards = 0;
    int num_refs = 0;
    int page_faults = 0;

    scanf("%d", &boards);
    scanf("%d", &num_refs);

    int *boards_vector = malloc(boards * sizeof(int));

    // define todos os elementos do vetor como -1
    for(int i = 0; i < boards; i++) {
        boards_vector[i] = -1;
    }

    for(int i = 0; i < num_refs; i++) {
        int control = 0;
        int ref = 0;
        scanf("%d", &ref);

        //verifica se o elemento já está alocado
        for(int j = 0; j < boards; j++) {
            if(boards_vector[j] == ref) {
                control = 1;
            }
        }

        //se o elemento não estiver alocado é realizada a alocação do tipo FIFO
        if(control == 0) {
            int vector_aux[boards];

            for(int i = boards - 1; i > -1; i--) {
                vector_aux[i] = boards_vector[i + 1];
            }

            vector_aux[boards - 1] = ref;

            for(int j = 0; j < boards; j++) {
                boards_vector[j] = vector_aux[j];
            }

            page_faults++;
        }

        //para vizualizar a ocupação dos quadros
        // for(int z = 0; z < boards; z++) {
        //     printf("%d", boards_vector[z]);
        // }

        // printf(" %d\n", ref);
    }

    printf("%d", page_faults);

    return 0;
}