#include <stdio.h>


//Questão 1:
int main()
{
    float x, y;
    printf("Digite 2 valores com uma casa decimal:\n");
    scanf("%f", &x);
    scanf("%f", &y);
    
    if(x == 0 && y == 0){
        printf("Origem");
    }else if(x > 0 && y > 0){
        printf("Q1");
    }else if(x < 0 && y > 0){
        printf("Q2");
    }else if(x < 0 && y < 0){
        printf("Q3");
    }else if(x > 0 && y < 0){
        printf("Q4");
    }

    return 0;
}

//Questão 2:
int main(){
    double a, b, c;
    printf("Digite 3 valores maiores que 0 de um triângulo:\n");
    scanf("%lf", &a);
    scanf("%lf", &b);
    scanf("%lf", &c);
    
    if(a > b){
        if(b > c){
            printf("%.3lf %.3lf %.3lf\n", a, b, c);
        }else if( a > c){
            printf("%.3lf %.3lf %.3lf\n", a, c, b);
        }else{
            printf("%.3lf %.3lf %.3lf\n", c, a, b);
        }
    }else if(b > c){
        if(a > c){
            printf("%.3lf %.3lf %.3lf\n", b, a, c);
        }else{
            printf("%.3lf %.3lf %.3lf\n", b, c, a);
        }
    }else{
        printf("%.3lf %.3lf %.3lf\n", c, b, a);
    }
    
    if(a >= b + c){
        printf("NÃO FORMA TRIÂNGULO\n");
    }
    
    if((a * a) == ((b*b)+(c*c))){
        printf("TRIÂNGULO RETÂNGULO\n");
    }else if((a*a) > ((b*b)+(c*c))){
        printf("TRIÂNGULO OBTUSANGULO\n");
    }else if((a*a) < ((b*b)+(c*c))){
        printf("TRIÂNGULO ACUTANGULO\n");
    }
    
    if(a == b && b == c){
        printf("TRIÂNGULO EQUILÁTERO\n");
    }else{
        printf("TRIÂNGULO ISÓSCELES");
    }
    
    return 0;
}

//Questão 3:
int main()
{
    int a, b, tempo;
    printf("Digite quando inicou e quando terminou o jogo:\n");
    scanf("%d", &a);
    scanf("%d", &b);
    
    tempo = a - b;
    
    if(a == b){
        printf("O JOGO DUROU 24 HORAS");
    }else if(a < b){
        tempo = tempo * (-1);
    }
    
    printf("O JOGO DUROU %d HORA(S)", tempo);
}

//Questão 4:
int main()
{
    int num;
    int impar=0, par=0, posi=0, nega=0;
    printf("Digite alguns números (digite 001 para encerrar o processo):\n");
    scanf("%d", &num);
    
    while (num != 001){
        if(num % 2 == 0){
            par += 1;
        }
        if(num % 2 !=0){
            impar += 1;
        }
        if(num >= 0){
            posi += 1;
        }
        if(num < 0){
            nega += 1;
        }
    }

   
    printf("%d valor(es) impar(es)\n %d valor(es) par(es)\n %d valor(es) positivo(s)\n %d valor(es) negativo(s)", impar, par, posi, nega);
    
    return 0;
}

//Questão 5:
int main()
{
    int v;
    printf("quantas vezes o processo irá se repetir? \n");
    scanf("%d", &v);
    
    for(int i = 0; i < v; i++){
        float n1, n2, n3;
        scanf("%f%f%f", &n1, &n2, &n3);
        printf("Media ponderada: %.2f\n", (n1 * 2 + n2 * 3 + n3 * 5) / 10);
    }
    
    return 0;
}

//Questão 6 (não sei o que to fazendo de errado)
int main()
{
    int x, y, imp=0;
    printf("Digite dois números inteiros: \n");
    scanf("%d%d", &x, &y);
    
    if(x > y){
        for(int i = y; i <x; i++){
            if(i % 2 != 0){
                imp = i + i;
            }
        }
    }else{
        for(int i = x; i <y; i++){
            if(i % 2 != 0){
                imp = i + i;
            }
        }
    }
    
    printf("%d", imp);
}

//Questão 7
int main()
{
    int v;
    printf("quantas vezes o processo irá se repetir? \n");
    scanf("%d", &v);
    
    for(int i = 0; i < v; i++){
        int x, y, imp=0;
        printf("Digite dois valores inteiros: ");
        scanf("%d%d", &x, &y);
        if(x > y){
        for(int i = y; i <x; i++){
            if(i % 2 != 0){
                imp = i + i;
            }
        }
        }else{
        for(int i = x; i <y; i++){
            if(i % 2 != 0){
                imp = i + i;
            }
        }
        }
    
    printf("%d", imp);
    }
    
}