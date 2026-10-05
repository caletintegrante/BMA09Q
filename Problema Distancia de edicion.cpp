#include <stdio.h>
#include <string.h>

#define MAX 100

int minimo(int a, int b, int c) {

    int menor = a;

    if (b < menor) {
        menor = b;
    }

    if (c < menor) {
        menor = c;
    }

    return menor;
}

int main() {

    char X[MAX];
    char Y[MAX];

    int dp[MAX + 1][MAX + 1];

    printf("Ingrese la primera cadena: ");
    scanf("%s", X);

    printf("Ingrese la segunda cadena: ");
    scanf("%s", Y);

    int m = strlen(X);
    int n = strlen(Y);

    /*
        PROGRAMACION DINAMICA - BOTTOM-UP

        dp[i][j] representa el numero minimo
        de operaciones necesarias para transformar
        los primeros i caracteres de X
        en los primeros j caracteres de Y.
    */

    // Transformar una cadena de longitud i
    // en una cadena vacia requiere i eliminaciones.
    for (int i = 0; i <= m; i++) {
        dp[i][0] = i;
    }

    // Transformar una cadena vacia
    // en una cadena de longitud j requiere j inserciones.
    for (int j = 0; j <= n; j++) {
        dp[0][j] = j;
    }

    // Llenamos la tabla
    for (int i = 1; i <= m; i++) {

        for (int j = 1; j <= n; j++) {

            // Si los caracteres son iguales,
            // no necesitamos ninguna operacion.
            if (X[i - 1] == Y[j - 1]) {

                dp[i][j] = dp[i - 1][j - 1];

            }

            else {

                /*
                    Tenemos tres posibilidades:

                    1. Eliminar
                    2. Insertar
                    3. Sustituir

                    Elegimos la de menor costo.
                */

                int eliminar = dp[i - 1][j];

                int insertar = dp[i][j - 1];

                int sustituir = dp[i - 1][j - 1];

                dp[i][j] =
                    1 + minimo(eliminar, insertar, sustituir);
            }
        }
    }

    printf("\nDistancia de edicion = %d\n", dp[m][n]);

    return 0;
}
