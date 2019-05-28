#include <stdio.h>
#define MAX 1000

void time (int in_out[], int nusp[], int horas[], int minutos[], int min_conv[], int permanencia[][3], int size) {
    int j, i, t = 0;
    int same_usp;

    printf ("\nLISTA DE USUÁRIOS NO SALÃO DE LEITURA \n");
    printf ("\n NUSP \t  Hora de Entrada  Tempo de permanência\n");
    for (i = 0, same_usp = 0; i < size ; i++, t++) {
        for (j = i + 1; j <= size; j++) {
            if (nusp[i] == nusp[j]) {
                same_usp = 1;
            }
            else same_usp = 0;
        }

        if (same_usp == 0) {
            permanencia[t][0] = nusp[i];
            permanencia[t][1] = horas[i];                           // hora de entrada 
            permanencia[t][2] = minutos[i];                         // minuto de entrada
            permanencia[t][3] = 24*60 - min_conv[i];                // contabilização dos minutos de permanencia
            //printf("    a    ");
        }

        if (same_usp  == 1) {
            permanencia[t][0] = nusp[i];                            // nusp que será analisado
            permanencia[t][1] = horas[i];                           // hora de entrada 
            permanencia[t][2] = minutos[i];                         // minuto de entrada
            permanencia[t][3] = min_conv[j] - min_conv[i];          // contabilização dos minutos de permanencia 
            //printf("    aaaa    ");
        }   
        
        printf("%8d \t %02d:%02d \t\t%4d minutos\n", permanencia[i][0], permanencia[i][1], permanencia[i][2], permanencia[i][3]);
    }
}


/*void ordenar (int permanencia[][3], int size) {
    int contador, i, t, aux;
    for (contador = 1, t = 0; contador < size; contador++, t++) {
        for (i = 0; i < size - 1; i++) {
            if (permanencia[t][i] > permanencia[t][i + 1]) {
                aux = permanencia[t][i];
                permanencia[t][i] = permanencia[t][i + 1];
                permanencia[t][i + 1] = aux;
            }
        }
    }

    for (i = 0; i < size; i++) {
        printf("%d", permanencia[t][i]);
    }
}*/

int quant_usuarios (int nusp[], int in_out[], int size) {
    int usuarios = 1, j, i;

    for (i = 0; i < size; i++){
        for (j = i + 1; j < size; j++){
            if (in_out[i] == 0 && in_out[j] == 0){
                if (nusp[i] != nusp[j]) usuarios++;
            }
        }
    }

    return usuarios;
}

int quant_visitas (int in_out[], int size) {
    int visitas = 0, i;

    for (i = 0; i < size; i++){
        if (in_out[i] == 0) visitas++;
    }

    return visitas;
}


int main(){
    FILE *arquivo_de_entrada;
    char nome_arquivo[80];
    int in_out[MAX], nusp[MAX], horas[MAX], minutos[MAX], min_conv[MAX];
    int i, j, size, usuarios, visitas;
    int permanencia[MAX][3];

    /****** Zera a matriz de permanencia e o vetor de conversão ******/
    for (i = 0; i < MAX; i++) {
       permanencia[i][0] = 0;
       permanencia[i][1] = 0;
       permanencia[i][2] = 0;
       permanencia[i][3] = 0;
       min_conv[i]       = 0;
    }
    /*****************************************************************/


    /********************************************/
    /**               CABEÇALHO                **/
    /********************************************/
    printf("\nBem vindo ao Sistema Estatístico de Uso do Salão de Estudos\n");
    printf("\tBiblioteca 'Carlos Benjamin de Lyra' - IME\n");
    printf("\t   Universidade de São Paulo \n\n");

    /********************************************/
    /**            Carrega arquivo             **/
    /********************************************/
    printf("Digite o nome do arquivo de dados: ");
    scanf("%s", nome_arquivo);

    arquivo_de_entrada = fopen(nome_arquivo, "r");
    
    i = 0;
    while (!feof(arquivo_de_entrada)) {
        if (fscanf(arquivo_de_entrada, "%d %d %d:%d", &in_out[i], &nusp[i], &horas[i], &minutos[i]) != 4) continue;
        else {
            min_conv[i] = (horas[i]*60) + minutos[i];    // converte o tempo em minutos
            i++;
        }
    }
    size = i;                                            // número de linhas do arquivo

    /********************************************/
    /**                FUNÇÕES                 **/
    /********************************************/
    time(in_out, nusp, horas, minutos, min_conv, permanencia, size);
    usuarios = quant_usuarios(nusp, in_out, size);
    visitas  = quant_visitas(in_out, size);
    printf ("\nNo período tivemos %d usuários diferentes e %d visitas no Salão de Estudos\n", usuarios, visitas);
    fclose(arquivo_de_entrada);


    return 0;
}