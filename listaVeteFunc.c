#include <stdio.h>
#include <stdlib.h>

//Questão 1:

int compara(float vet1[], float vet2[], int n){

    for(int i = 0; i < n; i++){
        if(vet1[i] != vet2[i]){
        return 1;
    }
}

return 0;

}

int main(){

    int n;

    printf("Digite o tamanho dos dois vetores: ");
    scanf("%d", &n);

    int vet1[n], vet2[n];

    for(int i = 0; i < n; i++){
        printf("Digite o %dº valor do primeiro vetor: ", i + 1);
        scanf("%d", &vet1[i]);
    }

    for(int i = 0; i < n; i++){
        printf("Digite o %dº valor do segundo vetor: ", i + 1);
        scanf("%d", &vet2[i]);
    }

    printf("primeiro vetor:\n");
        for(int i = 0; i < n; i++){
        printf("%d : %d\n", i, vet1[i]);
    }

    printf("segundo vetor:\n");
        for(int i = 0; i < n; i++){
        printf("%d : %d\n", i, vet2[i]);
    }

    int tamanho = compara(vet1, vet2, n);

    if(tamanho == 0){
        printf("são iguais!");
    }else{
        printf("são diferentes");
    }
}

//Questão 2:

void fibonacci(long long int v[], int n){

    v[0] = v[1] = 1;

    for (int i = 2 ; i < n ; i++ ){
        v[i] = v[i - 1] + v[i - 2];
    }
}

int main(){

    int n;
    printf("Digite o tamanho do vetor: ", n);
    scanf("%d", &n);

    long long int v[n];

    fibonacci(v, n);

    for(int i = 0; i < n; i++){
        printf("%d : %lld\n", i, v[i]);
    }
}

//Questão 3:

int eh_primo(int n) {
    if (n <= 1) {
        return 0;
    }
    for (int i = 2; i < n; i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

int soma_primos(int v[], int n) {
    int soma = 0;
    for (int i = 0; i < n; i++) {
        if (eh_primo(v[i])) {
            soma += v[i];
        }
    }
    return soma;
}

int main() {
    
    int n;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);
    int v[n];
    
    for(int i = 0; i < n; i++){
     printf("Digite o %dº valor: ", i + 1 );
     scanf("%d", &v[i]);
    }
    for(int i = 0; i < n; i++){
     printf("%d : %d\n", i, v[i]);
    }
    
    int resultado = soma_primos(v, n);
    printf("A soma dos numeros primos no vetor é: %d\n", resultado);
    return 0;
}

//Questão 4:

void busca_todos(int v[], int n, int chave, int indices[]){
    
    int j = 0;
    
    for(int i=0; i < n; i++){
        if(v[i] == chave){
            indices[j++] = i;
        }
    }
    for (int i = j; i < n; i++) {
        indices[i] = -1;
    }
}

int main() {
    
    int n, chave;
    
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);
    int v[n], indices[n];
    
    for(int i = 0; i < n; i++){
     printf("Digite o %dº valor: ", i + 1 );
     scanf("%d", &v[i]);
    }
    
    printf("Digite o valor a ser buscado: ");
    scanf("%d", &chave);
    
    busca_todos (v, n, chave, indices);
    
    printf("Vetor v:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    
    printf("\nÍndices:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", indices[i]);
    }
    
    printf("\n");
    
    return 0;
}

//Questão 5:

int busca_seq_rec(int v[], int n, int chave, int i){
    
    if (i == n) {
        return -1;
    }
    
    if (v[i] == chave) {
        return i; 
    }
    
    return busca_seq_rec(v, n, chave, i+1);
}

int main(){
    
    int n, chave;
    
    printf("Digite o tamanho do vetor: ", n);
    scanf("%d", &n);
    
    int v[n];
    
    for(int i = 0; i < n; i++){
        printf("Digite o %dº valor do vetor: ", i + 1);
        scanf("%d", &v[i]);
    }
    
    printf("Digite o valor a ser buscado: ");
    scanf("%d", &chave);
    
    int indice = busca_seq_rec (v, n, chave, 0);
    
    if(indice == -1){
        printf("Não encontrado!\n");
    }else{
    printf("Encontrado em %d.", indice);
    }
}