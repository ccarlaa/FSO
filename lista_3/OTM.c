#include <stdio.h>
#include <stdlib.h>

int predict(int *pg, int *fr, int pn, int index, int len) {
    int res = -1;
    int farthest = index;

    for(int i = 0; i < len; i++) {
        int j = 0;
        for(j = index; j < pn; j++) {
            if(fr[i] == pg[j]) {
                if(j > farthest) {
                    farthest = j;
                    res = i;
                }
                break;
            }
        }

        if(j == pn) {
            return i;
        }
    }

    return (res == -1) ? 0 : res;
}

int search(int key, int *fr, int len) {

    for(int i = 0; i < len; i++) {
        if(fr[i] == key) {
            return 1;
        }
    }
    return 0;
}

int optimal_page(int *pg, int pn, int fn) {
    int fr[fn];
    int hit = 0;
    int index = 0;

    for(int i = 0; i < fn; i++) {
        fr[i] = -1;
    }

    for(int i = 0; i < pn; i++) {
        if(search(pg[i], fr, fn)) {
            hit++;
            continue;
        }

        if(index < fn) {
            fr[index++] = pg[i];
        }
        else {
            int j = predict(pg, fr, pn, i + 1, fn);
            fr[j] = pg[i];
        }
    }

    // printf("%d\n", hit);
    printf("%d\n", pn - hit);
}


int main() {
    int fn = 0;
    int pn = 0;

    scanf("%d", &fn);
    scanf("%d", &pn);

    int *pg = malloc(pn * sizeof(int));

    for(int i = 0; i < pn; i++) {
        scanf("%d", &pg[i]);
    }

    optimal_page(pg, pn, fn);
}