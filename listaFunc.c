#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

//Questão 1
int tipo_triangulo(float x, float y, float z);

int main(){

    float x, y, z;
    printf("Digite os tres lados do triangulo: \n");
    scanf("%f%f%f", &x, &y, &z);
    int result = tipo_triangulo(x,y,z);
    if(result == 0){
        printf("Nao e um triangulo.\n");
    }
    if(result == 1){
        printf("Triangulo equilatero\n");
    }
    if(result == 2){
        printf("Triangulo Isoceles");
    }
    if(result == 3){
        printf("Triangulo escaleno");
    }

    return 0;
}

int tipo_triangulo(float x, float y, float z){

    if(x > y + z || y > x + z || z > x + y){
        return 0;
    }
    if(x == y && y == z){
        return 1;
    }
    if(x == y || y == z || z == x){
        return 2;
    }
    if(x != y && y != z){
        return 3;
    }

}

//Questão 2
int maior(int a, int b, int c);

int main(){

    int a, b, c;
    printf("Digite tres valores inteiros: \n");
    scanf("%d%d%d", &a, &b, &c);
    int result = maior(a,b,c);
    printf("O maior valor e: %d", result);
    return 0;
}

int maior(int a, int b, int c){

    if( a > b && a > c){
    return a;
   }
    if( b > a && b > c){
        return b;
    }
    if(c > a && c > b){
        return c;
    }
}

//Questão 3
int digit(char x);

int main(){
    int x;
    printf("Digite um digito: \n");
    scanf("%d", &x);
    int result = digit(x);
    printf("%d", result);
    return 0;

}

int digit(char x){
    if(x >= 0 && x <= 9){
        int resulto = x;
        return resulto;
    }
}

//Questão 4
int impar(int x, int y);

int main(){

    int x, y;
    printf("Digite dois valores inteiros \n");
    scanf("%d%d", &x, &y);
    int im = impar(x, y);
    printf("a soma dos impares entre %d e %d eh: %d", x, y, im);
}

int impar(int x, int y){

    if (x < y){
        int posicao = 0;
        int somaI = 0;
        for(int i = x; i < y; i++){
            if(i % 2 == 0){
                posicao = i + 1;
                somaI = posicao + somaI;
            }
        }
        return somaI;
    }

    if(x > y){
        int posicao = 0;
        int somaI = 0;
        for(int i = y; i < x; i++){
            if(i % 2 == 0){
                posicao = i + 1;
                somaI = posicao + somaI;
            }
        }
        return somaI;
    }

}

//Questao 5

bool eh_primo(int n);

int main() {
    int k, n, cont = 0;

    printf("Digite um valor para k: ");
    scanf("%d", &k);

    printf("Digite um valor para n: ");
    scanf("%d", &n);

    printf("Os %d primeiros números primos acima de %d são:\n", n, k);

    for (int i = k + 1; cont < n; i++) {
        if (eh_primo(i)) {
            printf("%d ", i);
            cont++;
        }
    }

    printf("\n");

    return 0;
}

bool eh_primo(int n) {
    if (n <= 1) {
        return false;
    }

    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }

    return true;
}

//Questao 6

int fibonacci(int n);

int main() {
    int n;

    printf("Digite um valor para n: ");
    scanf("%d", &n);

    printf("Os %d primeiros termos da sequência de Fibonacci são:\n", n);

    for (int i = 0; i < n; i++) {
        printf("%d ", fibonacci(i));
    }

    printf("\n");

    return 0;
}

int fibonacci(int n) {
    int a = 0, b = 1, c;

    if (n == 0) {
        return a;
    }

    for (int i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }

    return b;
}

//Questao 7

int soma_especial(int n, int k, int x);

int main() {
    int n, k, x, resultado;

    printf("Digite o valor de n: ");
    scanf("%d", &n);

    printf("Digite o valor de k: ");
    scanf("%d", &k);

    printf("Digite o valor de x: ");
    scanf("%d", &x);

    resultado = soma_especial(n, k, x);

    printf("O somatorio dos %d primeiros termos multiplos de %d a partir de %d eh: %d\n", n, k, x, resultado);

    return 0;
}

int soma_especial(int n, int k, int x) {
    int soma = 0;
    int termos_somados = 0;
    int i = x;

    while (termos_somados < n) {
        if (i % k == 0) {
            soma += i;
            termos_somados++;
        }
        i++;
    }
    return soma;
}

//Questao 8:

int soma_iterativa(int n);
int soma_recursiva(int n);

int main() {
    int n, soma, soma2;
    
    printf("Digite um valor para n: ");
    scanf("%d", &n);
    
    soma = soma_iterativa(n);
    soma2 = soma_recursiva(n);
    
    printf("A soma dos numeros de 1 a %d eh: %d\n", n, soma);
    printf("A soma dos numeros de 1 a %d eh: %d\n", n, soma2);

    return 0;
}

int soma_iterativa(int n) {
    int soma = 0;
    
    for (int i = 1; i <= n; i++) {
        soma += i;
    }
    
    return soma;
}

int soma_recursiva(int n) {
    if (n == 1) {
        return 1;
    } else {
        return n + soma_recursiva(n-1);
    }
}


//Questao 9

float harmonica_recursiva(float N);
float harmonica_iterativa(float N);

int main(){

float N;

printf("Digite o numero de termos:\n");
scanf("%f", &N);


printf("\nSomatorio iterativo:%.2f", harmonica_iterativa(N));
printf("\nSomatorio recursivo:%.2f", harmonica_recursiva(N));

return 0;
}

float harmonica_iterativa(float N){
    float divisao, valor = 0;

    for ( int i = 1; i <= N; i++){
        divisao = (1.0)/i;
        printf("\n 1/%d", i);
        valor += divisao;
    }
 return valor;
}
float harmonica_recursiva(float N){
    if ( N == 0){
        return 0;
    } else {    
        return 1.0/N + harmonica_recursiva(N - 1);
    }
}

//Questao 10: