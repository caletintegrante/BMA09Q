#include <stdio.h>

#define MAX 100

int main() {

    int n;

    printf("Ingrese el tamaño de la matriz: ");
    scanf("%d", &n);

    int matriz[MAX][MAX];
    int dp[MAX][MAX];

    // Ingresamos los costos de cada celda
    printf("Ingrese los valores de la matriz:\n");

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }

    /*
        PROGRAMACION DINAMICA - BOTTOM-UP

        dp[i][j] representa el costo minimo
        para llegar desde (0,0) hasta (i,j).
    */

    dp[0][0] = matriz[0][0];

    // Primera fila
    for (int j = 1; j < n; j++) {
        dp[0][j] = dp[0][j - 1] + matriz[0][j];
    }

    // Primera columna
    for (int i = 1; i < n; i++) {
        dp[i][0] = dp[i - 1][0] + matriz[i][0];
    }

    // Resto de la tabla
    for (int i = 1; i < n; i++) {

        for (int j = 1; j < n; j++) {

            // Elegimos el camino de menor costo
            if (dp[i - 1][j] < dp[i][j - 1]) {
                dp[i][j] = dp[i - 1][j] + matriz[i][j];
            }
            else {
                dp[i][j] = dp[i][j - 1] + matriz[i][j];
            }
        }
    }

    printf("\nCosto minimo = %d\n", dp[n - 1][n - 1]);

    return 0;
}
