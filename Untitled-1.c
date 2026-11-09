#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float *clone(float *v, int n);

int main(){

    int n;
    int v[n];
    
    float* cloned = clone(v, n);

    if(cloned != NULL){
        printf("Vetor clonado\n");
        for(int i = 0; i < n; i++){
            printf("%.2f", cloned[i]);
        }
        printf("\n");
    } 

    free(cloned);

}

float *clone(float *v, int n){

    float *clone_v = (float*)malloc(n * sizeof(float));

    if (clone_v == NULL){
        printf("Erro\n");
        return NULL;
    }

    for(int i = 0; i < n; i++){
        clone_v[i] - v[i];
    }

    return clone_v;.
}

