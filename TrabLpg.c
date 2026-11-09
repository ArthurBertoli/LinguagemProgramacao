// Alunos: Arthur Bertoli & Guilherme Augusto Santos.

#include <stdio.h>
#include <stdlib.h>
#define M 8
#define N 10

int verifica(int n, int i, int mat[][N], int j);
void mostrarC(int mat[M][N], int li);

int main() {

    int a, b, c, d, e, f, g, j, k, l, i, n, ic, cont = -1, contt = 0;
    int mat[M][N], intersec[N];

    for(i = 0; i < M; i ++){
        intersec[i] = 0;
    }

    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++) {
            mat[i][j] = 0;
        }
    }

    do {
        printf("\nGerenciamento de Conjuntos\n\nMenu:\n\n1-Criar um novo conjunto vazio.\n2-Inserir dados em um conjunto");
        printf("\n3-Remover um conjunto\n4-Fazer a uniao entre dois conjuntos\n5-Fazer a interseccao entre dois conjuntos");
        printf("\n6-Mostrar um conjunto\n7-Mostrar todos os conjuntos\n8-Fazer busca por um valor\n9-Sair do programa\n\nEscolha uma opção.\n");
        scanf(" %d", &n);

        switch (n) {

            case 1:
                if (cont < M - 1) {
                    cont++;
                    printf("Conjunto Criado!\n");
                }else {
                    printf("Voce atingiu o limite de vetores criados!\n");
                }
                break;

            case 2:
                if (cont == -1) {
                    printf("Voce ainda não tem conjuntos criados, digite 1 no menu para criar.\n");
                    break;

                } else {
                    printf("Digite qual conjunto você quer trabalhar:\n");
                    scanf("%d", &ic);

                    if (ic > cont) {
                        printf("O conjunto %d não foi criado!\n", ic);
                    } else if (ic >= 0 && ic <= cont) {
                        printf("Digite os valores do conjunto %d:\n", ic);
                        int indice = 0;
                        for (int k = 0; mat[ic][k] != 0; k++) indice = k;

                        if (indice == 0) indice--;

                        for (j = indice + 1; j < N; j++) {
                            scanf("%d", &mat[ic][j]);
                            fflush(stdout);

                            if (mat[ic][j] == 0) {
                                break;
                            }

                            int ver = verifica(mat[ic][j], ic, mat, j);
                            if (ver == 0) {
                                printf("O valor '%d' já está no conjunto\n", mat[ic][j]);
                                j--;
                            }
                        }

                        printf("Valores inseridos no conjunto %d:\n", ic);
                        for (j = 0; j < N; j++) {
                            if (mat[ic][j] == 0) {
                                break;
                            }
                            printf("%d ", mat[ic][j]);
                        }
                        printf("\n");
                    }
                }
                break;

            case 3:

                if (cont == -1) {
                    printf("Voce ainda não tem conjuntos criados, digite 1 no menu para criar.\n");
                    break;
                }

                printf("Diga qual conjunto irá querer remover:\n");
                scanf("%d", &a);

                if (a < 0 || a > cont) {
                    printf("Conjunto inválido!\n");
                }else{

                    for (j = 0; j < N; j++) {
                        mat[a][j] = 0;
                    }

                    for (i = a + 1; i <= cont; i++) {
                        for (j = 0; j < N; j++) {
                            mat[i - 1][j] = mat[i][j];
                        }
                    }
                    for (j = 0; j < N; j++) {
                        mat[cont][j] = 0;
                    }
                    cont--;

                    printf("Conjunto removido com sucesso!\n");
                }

                break;

            case 4:

                if (cont == -1) {
                    printf("Voce ainda não tem conjuntos criados, digite 1 no menu para criar.\n");
                    break;
                }
                if(cont + 2 > 8){
                    printf("Nao é possivel criar mais conjuntos pois atingiu o limite de conjuntos, remova um para continuar!");
                    break;
                }

                printf("Digite o conjunto 1 \n");
                scanf("%d", &b);
                printf("Digite o conjunto 2 \n");
                scanf("%d", &c);

                if (b < 0 || b > cont || c < 0 || c > cont) {
                    printf("Conjunto inválido!\n");
                }else{

                    cont++;

                    int pos = 0;

                    for(int i = 0; mat[b][i] != 0; i++){
                        pos = i;
                    }
                    pos++;

                    for(int i = 0; i < pos; i++){
                        mat[cont][i] = mat[b][i];
                    }

                    int pos2 = 0;

                    for(int i = 0; mat[c][i] != 0; i++){
                        int tes = verifica(mat[c][i], b, mat, pos);
                        if(tes == 1){
                            mat[cont][pos] = mat[c][i];
                            pos++;
                        }

                    }

                    printf("Conjunto unido com sucesso!\n");
                }

                break;

            case 5:
                if (cont == -1) {
                    printf("Voce ainda não tem conjuntos criados, digite 1 no menu para criar.\n");
                    break;
                }
                printf("Digite o conjunto 1: \n");
                scanf("%d", &f);
                printf("Digite o conjunto 2: \n");
                scanf("%d", &g);
                if (f < 0 || f > cont || g < 0 || g > cont) {
                    printf("Conjuntos inválidos!\n");
                }else{
                    contt = 0;

                    for (j = 0; mat[f][j] != 0; j++) {
                        for (k = 0; mat[g][k] != 0; k++) {
                            if (mat[f][j] == mat[g][k]) {
                                intersec[contt] = mat[f][j];
                                contt++;
                                break;
                            }
                        }
                    }
                    if (cont < M - 1) {
                        cont++;
                        for (i = 0; i < contt; i++) {
                            mat[cont][i] = intersec[i];
                        }
                        printf("Conjunto interseccionado com sucesso!\n");
                    } else {
                        printf("Você atingiu o limite de conjuntos criados!\n");
                    }
                }
                break;

            case 6:
                printf("Digite qual conjuntos você desejar consultar: \n");
                scanf("%d", &d);
                if (d < 0 || d > cont) {
                    printf("Conjunto não existente!\n");
                } else {
                    mostrarC(mat, d);
                }
                break;

            case 7:
                if(cont == -1){
                    printf("Nenhum conjunto foi criado ainda, digite 1 no menu para criar.\n");
                }else{
                    printf("\nTodos os conjuntos:\n");
                    for (i = 0; i <= cont; i++) {
                        printf("Conjunto %d = ", i);
                        if (mat[i][0] == 0) printf("vazio");
                        for (j = 0; mat[i][j] != 0; j++) {
                            printf("%d ", mat[i][j]);
                        }
                        printf("\n");
                    }
                    printf("\n");
                }
                break;

            case 8:
                printf("Digite o valor a ser buscado:\n");
                scanf("%d", &e);

                if (e <= 0) {
                    printf("Valor inválido");
                }else{
                    l = -1;
                    for (i = 0; i < M; i++) {
                        for (j = 0; j < N; j++) {
                            if (e == mat[i][j]) {
                                l= i;
                                printf("Valor localizado no índice: %d\n", i);

                            }
                        }
                    }
                }
                if(l == - 1){
                    printf("Valor não encontrado!\n");
                }


                break;

            case 9:
                printf("Encerrando o programa...\n");
                break;

            default:
                printf("Valor inválido, Digite valores apenas entre 1-9!");
        }

    } while (n != 9);

    system("pause");
    return 0;
}
int verifica(int n, int i, int mat[][N], int j){
    for(int k = 0; k < j; k++){
        if( n == mat[i][k]){
            return 0;
        }
    }
    return 1;
}

void mostrarC(int mat[M][N], int li) {
    if (mat[li][0] == 0) {
        printf("Conjunto %d: vazio\n", li);
        return;
    }
    printf("Conjunto %d: ", li);
    for (int j = 0; mat[li][j] != 0; j++) {
        printf("%d ", mat[li][j]);
    }
    printf("\n");
}