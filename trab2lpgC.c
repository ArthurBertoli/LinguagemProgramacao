//Alunos: Arthur Bertoli Silva e Guilherme Augusto Santos
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Data{
	int dia, mes, ano;
};

struct Artista{
    char nome[50];
    char nacionalidade[50];
};

struct Musica{
	char musica[500];
    int duracao;
	char estilo[30];
    struct Artista artista;
	struct Data data_cadastro;
};

void le_musica( struct Musica *p );
void mostra_musica( struct Musica x );
void mostra_vetor( struct Musica *v, int n );
int busca_musica( struct Musica *v, int n, char *chave );
int busca_musica_artista( struct Musica *v, int n, char *chave );
int busca_musica_nacionalidade( struct Musica *v, int n, char *chave );
int busca_musica_estilo( struct Musica *v, int n, char *chave );
void ordena_vetor( struct Musica *v, int n );
void salva_arquivo(struct Musica *v, int n);

int main(int argc, char *argv[]) {
	int n = 0;  
	int i;
	struct Musica *v = NULL; 
	FILE *f; 
	
	f = fopen( "musicas.txt", "rt" );
	if( f == NULL ){
		printf("Arquivo de cadastro nao encontrado!\n");
	}
	else{
		fscanf( f, "%d", &n );
		v = malloc( sizeof( struct Musica ) * n );
		for( i = 0 ; i < n ; i++ ){
			fscanf(f, " %[^\n]", v[i].musica );
            fscanf(f, "%d", &v[i].duracao);
			fscanf(f, " %[^\n]", v[i].estilo );
			fscanf(f, " %[^\n]", v[i].artista.nome);
            fscanf(f, " %[^\n]", v[i].artista.nacionalidade);
			fscanf(f, "%d/%d/%d", &v[i].data_cadastro.dia, &v[i].data_cadastro.mes, &v[i].data_cadastro.ano );
		}
		fclose( f ); 
		printf("%d registros carregados do arquivo!\n", n );
	}

	int opcao, idx;
	char chave[30];
	do{
		printf("1-Cadastrar Musica\n2-Remover Cadastro\n3-Exibir Todas as Muscias\n4-Consultar Registros\n5-Ordenar Registro\n6-Sair\n");
		scanf("%d", &opcao);
		
		switch( opcao ){
			case 1:
				n++;
				v = realloc( v, sizeof( struct Musica ) * n );
				getchar();
				le_musica( &v[n-1] );
				salva_arquivo(v, n);
				break;
            case 2:
                printf("Digite o nome da musica que deseja remover:\n");
                scanf(" %[^\n]", chave );
                idx = busca_musica( v, n, chave );
                if( idx == -1 )
                    printf("Musica nao encontrado!\n");
                else{
                    for(int k = idx; k < n-1; k++){
                        v[k] = v[k+1];
                    }
                    n--;
                    v = realloc( v, sizeof(struct Musica) * n);
                    salva_arquivo(v, n);
                }
                break;

			case 3:
				mostra_vetor( v, n );
				break;

			case 4:
                printf("Escolha uma opção:\n1-Busca pelo nome da musica\n2-Busca pela nacionalidade\n3-Busca pelo nome do Artista\n4-Busca pelo estilo de musica\n");
                int escolha;
                scanf("%d", &escolha);
                switch(escolha){
                    case 1:
                        printf("Digite o nome do musica: ");
                        scanf(" %[^\n]", chave );
                        idx = busca_musica( v, n, chave );
                        if( idx == -1 )
                            printf("Musica nao encontrado!\n");
                        else{
                            printf("Musica %d:", idx);
                            mostra_musica( v[idx] );
                        }
                        break;

                    case 2:
                        printf("Digite a nacionalidade: ");
                        scanf(" %[^\n]", chave );
                        idx = busca_musica_nacionalidade( v, n, chave );
                        if( idx == -1 )
                            printf("Nacionalidade nao encontrada!\n");
                        else{
                            printf("Musica %d:", idx);
                            mostra_musica( v[idx] );
                        }
                        break;

                    case 3:
                        printf("Digite o nome do artista: ");
                        scanf(" %[^\n]", chave );
                        idx = busca_musica_artista( v, n, chave );
                        if( idx == -1 )
                            printf("Artista nao encontrado!\n");
                        else{
                            printf(" %d:", idx);
                            mostra_musica( v[idx] );
                        }
                        break;
                    case 4:
                        printf("Digite o estilo: ");
                        scanf(" %[^\n]", chave );
                        idx = busca_musica_estilo( v, n, chave );
                        if( idx == -1 )
                            printf("Estilo nao encontrado!\n");
                        else{
                            printf(" %d:", idx);
                            mostra_musica( v[idx] );
                        }
                        break;
                }
                break;
			
			case 5:
				ordena_vetor( v, n );
				printf("Vetor ordenado!\n");
				break;			
			
		    }
	}while( opcao != 6);
	f = fopen( "musicas.txt", "wt" ); 
	if( f == NULL ){
		printf("Erro na gravacao do arquivo!\n");
		return 1;
	}
	fprintf( f, "%d\n", n );
	for( i = 0 ; i < n ; i++ ){
		fprintf( f, "%s\n", v[i].musica );
		fprintf( f, "%s\n", v[i].estilo );
		fprintf( f, "%d/%d/%d\n", v[i].data_cadastro.dia, v[i].data_cadastro.mes, v[i].data_cadastro.ano );
	}
	fclose( f );
	
	salva_arquivo(v, n);
    free(v);

	return 0;
}

void le_musica( struct Musica *p ){
	printf("Digite o nome da musica: ");
	scanf("%[^\n]", p->musica);
	printf("Digite a duracao da musica em segundos: ");
	scanf("%d", &p->duracao);
	printf("Digite o estilo da musica: ");
	scanf(" %[^\n]", p->estilo);
    printf("Digite o nome do Artista: ");
    scanf(" %[^\n]", p->artista.nome);
    printf("Digite a nacionalidade do Artista: ");
    scanf(" %[^\n]", p->artista.nacionalidade);
	printf("Digite a data de registro\n");
	int dataValida = 0;  
    while (!dataValida) {
    printf("Digite o dia: ");
    scanf("%d", &p->data_cadastro.dia);
        if (p->data_cadastro.dia > 31 || p->data_cadastro.dia < 1) {
        printf("Dia inválido! Digite novamente.\n");
        } else {
        dataValida = 1;  
        }
    }
    dataValida = 0;  
    while (!dataValida) {
    printf("Digite o mês: ");
    scanf("%d", &p->data_cadastro.mes);
        if (p->data_cadastro.mes > 12 || p->data_cadastro.mes < 1) {
        printf("Mês inválido! Digite novamente.\n");
        } else {
        dataValida = 1; 
        }
    }
	printf("Digite o ano: ");
	scanf("%d", &p->data_cadastro.ano);
}

void mostra_musica(struct Musica x) {
    printf(" %s | %s | %s | %02d/%02d/%04d |\n", x.musica, x.artista.nome, x.artista.nacionalidade, x.data_cadastro.dia, x.data_cadastro.mes, x.data_cadastro.ano);
}


void mostra_vetor( struct Musica *v, int n ){
	if( n == 0 )
		printf("Nao ha musicas cadastrados!\n");
	else{
		int i;
		printf("Lista de musicas cadastrados:\n");
		printf("    Título |  Artista  |  Nacionalidade  |  Data Cadastramento \n");
		for( i = 0 ; i < n ; i++ ){
			printf("%d: ", i+1 );
			mostra_musica( v[i] );
		}
	}
}

int busca_musica( struct Musica *v, int n, char *chave ){
	int i;
	for( i = 0 ; i < n ; i++ )
		if( strcmp( v[i].musica, chave ) == 0 )
			return i;
	
	return -1;
}
int busca_musica_artista( struct Musica *v, int n, char *chave ){
	int i;
	for( i = 0 ; i < n ; i++ )
		if( strcmp( v[i].artista.nome, chave ) == 0 )
			return i;
	
	return -1;
}
int busca_musica_nacionalidade( struct Musica *v, int n, char *chave ){
	int i;
	for( i = 0 ; i < n ; i++ )
		if( strcmp( v[i].artista.nacionalidade, chave ) == 0 )
			return i;
	
	return -1;
}

int busca_musica_estilo( struct Musica *v, int n, char *chave ){
	int i;
	for( i = 0 ; i < n ; i++ )
		if( strcmp( v[i].estilo, chave ) == 0 )
			return i;
	
	return -1;
}

void ordena_vetor( struct Musica *v, int n ){
	int i;
	for( i = 0 ; i < n-1 ; i++ ){
		int j, i_menor = i;
		for( j = i+1 ; j < n ; j++ ){
			if( strcmp( v[j].musica, v[i_menor].musica ) < 0 ){
				i_menor = j;
			}
		}
		struct Musica aux = v[i];
		v[i] = v[i_menor];
		v[i_menor] = aux;
	}
}

void salva_arquivo(struct Musica *v, int n){
    FILE *f = fopen("musicas.txt", "wt"); 
    if (f == NULL) {
        printf("Erro na gravação do arquivo!\n");
        return;
    }
    fprintf(f, "%d\n", n);
    for (int i = 0; i < n; i++) {
        fprintf(f, "%s\n", v[i].musica);
        fprintf(f, "%s\n", v[i].estilo);
        fprintf(f, "%s\n", v[i].artista.nome);
        fprintf(f, "%s\n", v[i].artista.nacionalidade);
        fprintf(f, "%d/%d/%d\n", v[i].data_cadastro.dia, v[i].data_cadastro.mes, v[i].data_cadastro.ano);
    }
    fclose(f); 
}