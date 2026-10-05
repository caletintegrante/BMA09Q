#include <stdio.h>
#include <limits.h>

#define MAX_MONEDAS 100
#define MAX_CANTIDAD 10000

int minimo(int a, int b) {

    if (a < b) {
        return a;
    }

    return b;
}

int main() {

    int n;
    int cantidad;

    int monedas[MAX_MONEDAS];
    int dp[MAX_CANTIDAD + 1];

    printf("Ingrese el numero de tipos de monedas: ");
    scanf("%d", &n);

    printf("Ingrese las monedas:\n");

    for (int i = 0; i < n; i++) {
        scanf("%d", &monedas[i]);
    }

    printf("Ingrese la cantidad que desea formar: ");
    scanf("%d", &cantidad);

    /*
        PROGRAMACION DINAMICA - BOTTOM-UP

        dp[x] representa el numero minimo
        de monedas necesarias para formar x.
    */

    // Caso base:
    // Para formar 0 necesitamos 0 monedas.
    dp[0] = 0;

    // Inicializamos los demas estados
    // con un valor muy grande.
    for (int x = 1; x <= cantidad; x++) {
        dp[x] = INT_MAX;
    }

    // Calculamos dp[1], dp[2], ..., dp[cantidad]
    for (int x = 1; x <= cantidad; x++) {

        // Probamos todas las monedas
        for (int i = 0; i < n; i++) {

            int moneda = monedas[i];

            // La moneda debe poder utilizarse
            if (moneda <= x) {

                // Evitamos trabajar con INT_MAX
                if (dp[x - moneda] != INT_MAX) {

                    dp[x] =
                        minimo(
                            dp[x],
                            dp[x - moneda] + 1
                        );
                }
            }
        }
    }

    if (dp[cantidad] == INT_MAX) {

        printf("\nNo es posible formar la cantidad.\n");

    }
    else {

        printf(
            "\nNumero minimo de monedas = %d\n",
            dp[cantidad]
        );
    }

    return 0;
}
