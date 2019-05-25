#include <stdio.h>
#define MAX 1000

int main(){
    FILE *arquivo_de_entrada;
    char nome_arquivo[80];
    int in_out[MAX], nusp[MAX], horas[MAX], minutos[MAX];
    int i;


    /********************************************/
    /**               CABEÇALHO                **/
    /********************************************/
    printf("\nBem vindo ao Sistema Estatístico de Uso do Salão de Estudos\n");
    printf("\tBiblioteca 'Carlos Benjamin de Lyra' - IME\n");
    printf("\t   Universidade de São Paulo \n\n");

    printf("Digite o nome do arquivo de dados: ");
    scanf("%s", nome_arquivo);

    arquivo_de_entrada = fopen(nome_arquivo, "r");
    
    i = 0;
    while (!feof(arquivo_de_entrada)) {
        fscanf(arquivo_de_entrada, "%d %d %d:%d", &in_out[i], &nusp[i], &horas[i], &minutos[i]);
       
        i++;
    }

    fclose(arquivo_de_entrada);
    printf("\narquivo lido!\n");


    return 0;
}