#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>

//Questão 1: 
int contem( char s[], char c );

int main() {

	char str[20], car;
	
	printf("Digite uma string: ");
	fgets(str, 20, stdin);
	
	printf("Digite um caractere: ");
	scanf(" %c", &car);
	
	printf("str = %s e car = %c\n", str, car);
	
	if( contem( str, car ) )
		printf("%s contem o caractere '%c'\n", str, car);
	else
		printf("%s nao contem o caractere '%c'\n", str, car);

	return 0;
}

int contem( char s[], char c ){
	int i;
	for( i = 0 ; s[i] != 0 ; i++ ){
		if( s[i] == c )
			return 1;
	}
	return 0;
}

//Questão 2:
int contem( char s[], int cont, char c );

int main(){

	char str[20], car;
	int cont, total;
	
	printf("Digite uma string: ");
	fgets(str, 20, stdin);
	
	printf("Digite um caractere: ");
	scanf(" %c", &car);
	
	total = contem(str, cont, car);
	
	if( contem( str, cont, car))
		printf("o caracter '%c' ocorre %d vezes.", car, total);
	else
		printf("a string nao contem o caractere '%c'\n", str, car);

	return 0;
}

int contem( char s[], int cont, char c){
	int i;
	
	for( i = 0 ; s[i] != 0 ; i++ ){
		if( s[i] == c )
		    cont++;
	}
	
	return cont;
}

//Questão 3:
void concatena(char str1[], char str2[]);

int main(){
    
    char str1[50];
    char str2[50];
    
    printf("Digite a primeira string de no máximo 50 caracteres: ");
    fgets(str1, 50, stdin);
    printf("Digite a segunda string de no máximo 50 caracteres: ");
    fgets(str2, 50, stdin);
    
    concatena(str1, str2);
    
    printf("%s\0", str1);
    
    return 0;
}

void concatena(char str1[], char str2[]){
    
    int tam1=0, tam2=0;
    
    while(str1[tam1] != '\0'){
        tam1++;
    }
    
    while(str2[tam2] != '\0'){
        tam2++;
    }
    
    for(int i = 0; i < tam2; i++){
        str1[tam1 + i] = str2[i];
    }
}

//Questão 4:
int eh_palindrome(char s[]);

int main(){
    
    char s[50];
    int result;
    
    printf("Digite uma string: ");
    fgets(s, 50, stdin);
    
    result = eh_palindrome(s);
    
    if(result > 0){
        printf("É palíndrome.");
    }else{
        printf("Não é palíndrome.");
    }
    
    return 0;

}

int eh_palindrome(char s[]){
    
    int i=0, j=0, len=0;
    
    while(s[len] != '\0'){
        len++;
    }
    len--;
    
    while(i<j){
        if(s[i] != s[len - j]){
            return 0;
        }
        i++;
        j++;
    }
    return 1;
}

//Questão 5:
int main(){
    
    char s[50];
    
    printf("Digite uma string: ");
    fgets(s, 50, stdin);
    
    for(int i = 0; s[i] != '\0'; i++){
        if(s[i]>='a' && s[i] <='z'){
            s[i] -= 32;
        }
    }
    
    printf("%s", s);
    
    return 0;

}

//Questão 6: da dando algum erro e não consegui identificar
int main() {

    char s[50];
    int cont = 1;

    printf("Digite uma string: ");
    fgets(s, 50, stdin);

    for(int i = 0; s[i] != '\0'; i++) {
        if(s[i] >= '0' && s[i] <= '9') {
            cont = 1;
        } else {
            cont = 0;
            break;
        }
    }

    if(cont == 1) {
        printf("A string: |%s| contém somente dígitos.\n", s);
    } else {
        printf("A string: |%s| não contém somente dígitos.\n", s);
    }

    return 0;
}

//Questão 7:
int main() {
    
    char s[10];
    int sum = 0;

    printf("Digite uma string: ");
    fgets(s, 10, stdin);

    for(int i = 0; s[i] != '\0'; i++){
        if(s[i] >= '0' && s[i] <= '9'){
            sum += (s[i] - '0');
        }
    }

    printf("O valor inteiro é: %d\n", sum);
    
    return 0;
}

//Questão 8: tive que pesquisar na net pra resolver esse aqui nao vou mentir, mas meu problema era com o scanf, nao sabia desse sscanf com dois s para ler as datas
int main() {

    char data[11];
    int dia, mes, ano;
    
    printf("Digite a data no formato DD/MM/AAAA: ");
    fgets(data, 11, stdin);
    
    if (data[2] != '/' || data[5] != '/') {
        printf("Formato inválido.\n");
        return 1;
    }
    
    for (int i = 0; i < 10; i++) {
        if (i == 2 || i == 5) {
            continue;
        }
        if (data[i] < '0' || data[i] > '9') {
            printf("Formato inválido.\n");
            return 1;
        }
    }
    
    sscanf(data, "%d/%d/%d", &dia, &mes, &ano);
    
    printf("Dia: %d\n", dia);
    printf("Mês: %d\n", mes);
    printf("Ano: %d\n", ano);
    
    return 0;
}

//Questão 9:
void trim(char str[]);

int main() {
    char str[50];
    
    printf("Digite uma string: ");
    fgets(str, 50, stdin);
    
    trim(str);
    
    printf("%s\n", str);
    
    return 0;
}

void trim(char str[]) {
    int i, j;
    int len = 0;
    
    while (str[len] != '\0') {
        len++;
    }
    
    while (len > 0 && str[len - 1] == ' ') {
        len--;
        str[len] = '\0';
    }
    
    i = 0;
    while (str[i] == ' ') {
        i++;
    }
    if (i > 0) {
        j = 0;
        while (i <= len) {
            str[j] = str[i];
            i++;
            j++;
        }
        str[j] = '\0';
        len = len - i + j;
    }
    
    i = 0;
    while (i < len) {
        if (str[i] == ' ') {
            j = i;
            while (j <= len) {
                str[j] = str[j+1];
                j++;
            }
            len--;
        } else {
            i++;
        }
    }
}

//Questão 10:
void inverteString(char s[]);

int main() {
    
    char s[50];
    
    printf("Digite uma string: ");
    fgets(s, 50, stdin);
    
    printf("String original: %s\n", s);
    inverteString(s);
    printf("String invertida: %s\n", s);

    return 0;
}

void inverteString(char s[]){
    int i, j;
    char temp;
    
    int len = 0;
    while(s[len] != '\0') {
        len++;
    }
    
    char s2[len + 1]; 
    j = 0;
    for(i = len - 1; i >= 0; i--) {
        s2[j] = s[i];
        j++;
    }
    s2[j] = '\0';  
    
    for(i = 0; i < len; i++) {
        s[i] = s2[i];
    }
}

//Questão 11:
void remove_char(char *s, char c);

int main() {
    char s[50], c;

    printf("Digite uma string: ");
    fgets(s, 50, stdin);

    printf("Digite um char: ");
    scanf("%c", &c);

    remove_char(s, c);

    printf("%s", s);

    return 0;
}

void remove_char(char *s, char c) {
    int i, j;
    for (i = 0, j = 0; s[i] != '\0'; i++) {
        if (s[i] == c) {
           for(j = i; s[j] != '\0'; j++){
               s[j] = s[j + 1];
           }
           i--;
        }
    }
}