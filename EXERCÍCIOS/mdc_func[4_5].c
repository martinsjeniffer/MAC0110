#include <stdio.h>

int maximodivisorcomum (int a, int b)
{
    int resto;

    resto = a % b;
    while (resto != 0)
    {
        a = b;
        b = resto;
        resto = a % b;
    }

    return (b);
}

int main()
{
    int n, i, mdc, /*novo_mdc,*/ num;

    printf ("n: ");
    scanf ("%d", &n);

    printf ("1o. numero da sequencia: ");
    scanf ("%d", &mdc);

    for (i = 1; i < n; i++)
    {
        printf ("%do. numero da sequencia: ", i+1);
        scanf ("%d", &num);

        mdc = maximodivisorcomum (mdc, num);
    }

    printf ("mdc: %d\n", mdc);
    return 0;
}