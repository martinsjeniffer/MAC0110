#include <stdio.h>
#define MAX 500

int main(){
    FILE *arquivo_de_entrada;
    char nome_arquivo[80];
    //int in_out = 0, nusp = 0, horas = 0, minutos = 0;
    int in_out[MAX], nusp[MAX], horas[MAX], minutos[MAX];


    /********************************************/
    /**               CABEÇALHO                **/
    /********************************************/
    printf("\nBem vindo ao Sistema Estatístico de Uso do Salão de Estudos\n");
    printf("\tBiblioteca 'Carlos Benjamin de Lyra' - IME\n");
    printf("\t   Universidade de São Paulo \n\n");


    printf("Digite o nome do arquivo de dados: ");
    scanf("%s", &nome_arquivo);

    arquivo_de_entrada = fopen(nome_arquivo, "r");
    fprintf (arquivo_de_entrada, nome_arquivo);

    while (!feof(arquivo_de_entrada)) {
        if (fscanf(arquivo_de_entrada, "%d %d %d %d:%d", &in_out, &nusp, &horas, &minutos) != 4) {
            continue;
        }
        printf ("%d %d %d %d:%d", in_out, nusp, horas, minutos);
        fclose(arquivo_de_entrada);
    }


    return 0;
}