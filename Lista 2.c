#include <stdio.h>
#include <math.h>

//Questão 1:
int main()
{
    int k, n;
    float a=0;
    scanf("%d", &n);
    for (k = n; k >= 1; k = k - 1) a = a + 1.0 / k;
    printf("%8.4f\n", a);

    return 0;
}

//Questão 2:
int main()
{
    int n=1, k;
    float a=0;
    scanf("%d", &k);
    for(n=k; k >= 1; pow((-1),n+1)) a = a + 1.0 / k;
    printf("%.3f\n", a);
    
    return 0;   
}

//Questão 3:

//a)
int main()
{
    int k, n;
    float a=0;
    scanf("%d", &n);
    for (k = 1; k <= n; k = k + 2) a = a + (4/k) / k + 2;
    printf("%.3f\n", a);

    return 0; 
}

//b)

//Questão 4:
int main()
{
    int fat, n = 0, e=0, k;
    scanf("%d", &k);
    float a;
    fat = 1;
    while(n <= k){
        fat = fat * k;
        a = 1 / fat;
    }
    printf("%4f\n", a);

    return 0; 
}

//Questão 5:
int main() {
	double x = 1;
	int n, i;

	printf("Digite a quantidade de termos N: ");
	scanf("%d", &n);
	
	double e_x = 0;
	double termo = 1;
	
	for( i = 0 ; i <= n ; i++ ){
		e_x += termo;
		termo *= x/(i+1);		
	}
	
	printf("e elevado a %.3lf (%d termos): %.15lf\n", x, n, e_x);
	
	return 0;
}

//Questão 6:
int main()
{
    int k, n=0, x;
    float a=0;
    int fat = 1;
    int fatk = 1;
    scanf("%d", &k);
    while(k != 1){
        fatk = fat * k - 1;
    }
    for (k = n; k; k = x / (fatk)) a = (pow((-1),n) pow(x, 2*n+1)) / (2*fatk);
    printf("%.3f\n", a);

    return 0;
}

//Questão 7