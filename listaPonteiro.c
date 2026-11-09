#include <stdio.h>

//Questão 1:
void inc_dec(int *a, int *b);

int main()
{
    int a, b;
    
    printf("Digite dois números inteiros: \n");
    scanf("%d", &a);
    scanf("%d", &b);
    
    printf("%d\n", a);
    printf("%d\n", b);
    
    inc_dec(&a, &b);
    
    printf("incremento: %d\ndecremento: %d\n", a, b);
    
    return 0;
}

void inc_dec(int *a, int *b){
    
    (*a)++;
    (*b)--;
}

//Questão 2:
void troca_valor(float *x, float *y);

int main()
{
    float a, b;
    
    printf("Digite dois números: \n");
    scanf("%f", &a);
    scanf("%f", &b);
    
    printf("a:%f\n", a);
    printf("b:%f\n", b);
    
    troca_valor(&a, &b);
    
    printf("a: %f\nb: %f\n", a, b);
    
    return 0;
}

void troca_valor(float *x, float *y){
    
    float aux = *x;
    
    *x = *y;
    *y = aux;
}

//Questão 3:

void calcula_circulo(float raio, float *pPerimetro, float *pArea);

int main()
{
    float raio, pPerimetro, pArea;
    
    printf("Digite o raio do círculo: \n");
    scanf("%f", &raio);
    
    printf("raio: %f\n", raio);
    
    calcula_circulo(raio, &pPerimetro, &pArea);
    
    printf("perímetro: %f\nárea: %f\n", pPerimetro, pArea);
    
    return 0;
}

void calcula_circulo(float raio, float *pPerimetro, float *pArea){
    
    *pPerimetro = 2 * 3,14 * raio;
    *pArea = 3,14 * (raio * raio);
}

//Questão 4:
void cacula_hora(int totalMinutos, int *ph, int *pm);

int main()
{
    int totalMinutos, ph, pm;
    
    printf("Digite quantos minutos foram passados: \n");
    scanf("%d", &totalMinutos);
    
    printf("minutos passados: %d\n", totalMinutos);
    
   cacula_hora(totalMinutos, &ph, &pm);
    
    printf("horas: %d\nminutos: %d\n", ph, pm);
    
    return 0;
}

void cacula_hora(int totalMinutos, int *ph, int *pm){
    
    *ph = totalMinutos/60;
    *pm = totalMinutos % 60;
    
}

//Questão 5:
void max_min(int vet[], int tam, int *pMin, int *pMax);

int main()
{   
    int n, pMin, pMax;
    
    printf("Digite o tamanho do vetor: \n");
    scanf("%d", &n);
    
    int vet[n];
    
    for(int i = 0; i < n; i++){
        printf("Digite o %dº valor: ", i + 1 );
        scanf("%d", &vet[i]); 
    }
    
    for(int i = 0; i < n; i++){
        printf("%d : %d\n", i, vet[i]); 
    }
    
    max_min(vet, n, &pMin, &pMax);
    
    if(pMin == pMax){
        printf("O vetor possui apenas valores iguais! No caso : %d\n", pMax);
    }else{
    
    printf("Valor máximo: %d\nValor mínimo: %d\n", pMax, pMin);
    }
    
    return 0;
    
}

void max_min(int vet[], int n, int *pMin, int *pMax){
    
    *pMin = vet[0];
    *pMax = vet[0];
    
    for(int i= 0; i < n; i++){
        if(vet[i] > *pMax){
            *pMax = vet[i];
        }
    }

    for(int i = 0; i < n; i++){
        if (vet[i] < *pMin){
            *pMin = vet[i];
        }
    }
}

//Questão 6:
void max_vetor(float vet[], int tam, float *pMax, int *pIndice);

int main()
{   
    float pMax;
    int pIndice, tam;
    
    printf("Digite o tamanho do vetor: \n");
    scanf("%d", &tam);
    
    float vet[tam];
    
    for(int i = 0; i < tam; i++){
        printf("Digite o %dº valor: ", i + 1 );
        scanf("%f", &vet[i]); 
    }
    
    for(int i = 0; i < tam; i++){
        printf("%d : %f\n", i, vet[i]); 
    }
    
    max_vetor(vet, tam, &pMax, &pIndice);
    
    printf("Valor máximo: %f\nIndice desse valor: %d\n", pMax, pIndice);
    
    return 0;
    
}

void max_vetor(float vet[], int tam, float *pMax, int *pIndice){
    
    *pMax = vet[0];
    *pIndice = 0;
    
    for(int i= 0; i < tam; i++){
        if(vet[i] > *pMax){
            *pMax = vet[i];
            *pIndice = i;
        }
    }

}

//Questão 7:
void min_matriz(float mat[3][4], float *pMin, int *pI, int *pJ);

int main()
{   
    float mat[3][4], pMin;
    int pI, pJ;
    
    printf("Digite a matriz:\n");
    
    for(int i=0; i<3; i++){
        for(int j=0; j<4; j++){
            printf("M[%d,%d]=", i, j);
            scanf("%f", &mat[i][j]);
        }
    }
    
    for(int i=0; i<3; i++){
        for(int j=0; j<4; j++){
         printf("%f ", mat[i][j]);
        }
        printf("\n");
    }

    min_matriz(mat, &pMin, &pI, &pJ);
    
    printf("Valor minimo: %f, Coordenadas: Coluna:%d, Linha:%d", pMin, pI, pJ);
    
    return 0;
    
}

void min_matriz(float mat[3][4], float *pMin, int *pI, int *pJ){
    
    *pMin = mat[0][0];
    *pI = 0;
    *pJ = 0;
    
    for(int i= 0; i < 3; i++){
        for(int j = 0; j < 4; j++){
            if(mat[i][j] < *pMin){
                *pMin = mat[i][j];
                *pI= i;
                *pJ = j;
            }
        } 
    }
}

