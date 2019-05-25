#include <stdio.h>

int contadigitos (int numero, int digito) {
    int resto, somadig;
    somadig = 0;

    while (numero > 0){
        resto = numero % 10;
        if (resto == digito)
            somadig++;
    }

    return (somadig);
}

int main (){
    int n, d, qntsdig;

    printf ("n: ");
    scanf ("%d", &n);
    printf ("d: ");
    scanf ("%d", &d);
    printf ("aaaaaaa");
    
    qntsdig = contadigitos(n, d);
    

    printf("%d repete %d vezes", d, qntsdig);

    return 0;
}
