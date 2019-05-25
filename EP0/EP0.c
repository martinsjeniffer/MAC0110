/*******************************************************************
***         Jeniffer Florinda Martins da Silva, 10377966         ***
***                          MAC0110                             ***
***               Exercício Programa 0 - IME - 2019              ***
*******************************************************************/

#include <stdio.h>

int main()
{
    int j1, j2;            // variáveis que guardam as escolhas dos jogadores
    int jogar_novamente;   // define se haverá ou não outra rodada

    printf ("****************************\n");
    printf ("*** BEM VINDO AO JOKEMPÔ ***\n");
    printf ("****************************\n");

    jogar_novamente = 0;

    printf ("\nINSTRUÇÕES:\n0 - pedra \n1 - tesoura \n2 - papel\n\n");

    while (jogar_novamente == 0){
        printf ("Digite o que o primeiro jogador jogou: ");
        scanf  ("%d", &j1);

        printf ("Digite o que o segundo jogador jogou: ");
        scanf  ("%d", &j2);

        // EMPATE
        if (j1 == j2)
        {
            printf ("Empatou!");
        }

        // Primeiro jogador vence
        if ((j1 == 0 && j2 == 1) ||
            (j1 == 1 && j2 == 2) ||
            (j1 == 2 && j2 == 0))
        {
            printf ("O primeiro jogador ganhou!\n");
        }

        // Segundo jogador vence
        if ((j1 == 0 && j2 == 2) ||
            (j1 == 1 && j2 == 0) ||
            (j1 == 2 && j2 == 1))
        {
            printf ("O segundo jogador ganhou!\n");
        }

        printf ("\nDeseja jogar novamente?");
        printf ("\n(0 - sim, 1 - não) \n");
        scanf  ("%d", &jogar_novamente);
    }

    return 0;
}
