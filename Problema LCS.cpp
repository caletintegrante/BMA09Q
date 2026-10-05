#include <stdio.h>
#include <string.h>

#define MAX 100

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

        dp[i][j] representa la longitud de la LCS
        entre los primeros i caracteres de X
        y los primeros j caracteres de Y.
    */

    // Caso base:
    // Si una cadena tiene longitud 0,
    // no existe subsecuencia común.
    for (int i = 0; i <= m; i++) {
        dp[i][0] = 0;
    }

    for (int j = 0; j <= n; j++) {
        dp[0][j] = 0;
    }

    // Llenamos la tabla
    for (int i = 1; i <= m; i++) {

        for (int j = 1; j <= n; j++) {

            // Si los caracteres son iguales
            if (X[i - 1] == Y[j - 1]) {

                dp[i][j] = dp[i - 1][j - 1] + 1;

            }

            // Si son diferentes
            else {

                if (dp[i - 1][j] > dp[i][j - 1]) {
                    dp[i][j] = dp[i - 1][j];
                }
                else {
                    dp[i][j] = dp[i][j - 1];
                }
            }
        }
    }

    printf("\nLongitud de la LCS = %d\n", dp[m][n]);

    return 0;
}
