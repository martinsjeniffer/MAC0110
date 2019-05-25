/*******************************************************************
***         Jeniffer Florinda Martins da Silva, 10377966         ***
***                          MAC0110                             ***
***               Exercício Programa 2 - IME - 2019              ***
*******************************************************************/

#include <stdio.h>
#define c1 10000
#define c2 1.34

// Função que devolve a parte fracionária de um número real;
double frac (double num);

// Função que devolve o valor absoluto de um número real;
double modulo (double num);

// Função que calcula sen(x) por uma aproximação em série de Taylor;
double seno (double x);


double frac (double num) {
    double frac;

    frac = num - ((int) num);

    return frac;
}


double modulo (double num) {
    double modulo;

    if (num < 0)
        modulo = num * (-1);
    if (num >= 0)
        modulo = num;

    return modulo;
}


double seno (double x) {
    int i;
    double fat, pot, seno, seno_termo, sinal;

    seno = 0.0;

    pot = x;
    fat = 1;
    sinal = 1.0; 

    seno_termo = pot / fat;
    seno = sinal * seno_termo;

    for (i = 1; seno_termo > 0.000000001; i = i + 2) {
        sinal = sinal * (-1.0);
        pot = pot * x * x;
        fat = fat * (i + 1) * (i + 2);         

        seno_termo = pot / fat;
        seno = seno + (sinal * seno_termo);
    }

    return seno;
}


int main() {
    int simulacoes, jogador = 0, banca = 0, carta = 0;
    int pt_jog = 0, pt_banca = 0;
    int lim, i;
    double x, pct;

    printf ("Digite a semente (0 < x < 1): ");
    scanf ("%lf", &x);

    printf ("Digite o número de simulações para cada limiar: ");
    scanf ("%d", &simulacoes);


    for (lim = 12; lim <= 20; lim++) {
        jogador = banca = pt_jog = pt_banca = 0;
        for (i = 0; i <= simulacoes; i++) {
            jogador = banca =  0;

           while (jogador <= lim) {
                x = frac(c1 * modulo(seno(x)) + c2);
                carta = 13 * x + 1;

                if (carta > 10)
                    carta = 10;

                jogador += carta;    
           }

            if (jogador < 21) {
                while (banca <= 21 && banca != jogador) {
                    x = frac(c1 * modulo(seno(x)) + c2);
                    carta = 13 * x + 1;
            
                    if (carta > 10)
                        carta = 10;

                    banca += carta;
                }
            }

            if (jogador == 21 || (jogador > banca && jogador <= 21 && banca <= 21) || 
                banca > 21)
                pt_jog++;       
            else
                pt_banca++;
        
            



       }

        pct =  (100.0 * (double) pt_jog / (double) simulacoes);
        
        printf ("\n%d (%4.1lf%) : ", lim, pct);
        for (i = 0; i < pct; i++){
            printf ("*");
        }
    }
    printf ("\n");

    return 0;
}

