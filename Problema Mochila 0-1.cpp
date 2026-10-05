#include <stdio.h>

#define MAX_N 100
#define MAX_W 1000

int main() {

    int n, W;

    int peso[MAX_N];
    int valor[MAX_N];

    int dp[MAX_N + 1][MAX_W + 1];

    printf("Ingrese el numero de objetos: ");
    scanf("%d", &n);

    printf("Ingrese la capacidad de la mochila: ");
    scanf("%d", &W);

    // Ingresamos los pesos
    printf("\nIngrese el peso de cada objeto:\n");

    for (int i = 0; i < n; i++) {
        scanf("%d", &peso[i]);
    }

    // Ingresamos los valores
    printf("\nIngrese el valor de cada objeto:\n");

    for (int i = 0; i < n; i++) {
        scanf("%d", &valor[i]);
    }

    /*
        PROGRAMACION DINAMICA - BOTTOM-UP

        dp[i][w] representa el maximo valor
        que podemos obtener utilizando los primeros
        i objetos y una capacidad w.
    */

    // Caso base:
    // Si no tenemos objetos, el valor es 0.
    for (int w = 0; w <= W; w++) {
        dp[0][w] = 0;
    }

    // Si la capacidad es 0, el valor tambien es 0.
    for (int i = 0; i <= n; i++) {
        dp[i][0] = 0;
    }

    // Llenamos la tabla
    for (int i = 1; i <= n; i++) {

        for (int w = 1; w <= W; w++) {

            /*
                Si el objeto no cabe,
                no podemos tomarlo.
            */
            if (peso[i - 1] > w) {

                dp[i][w] = dp[i - 1][w];

            }
            else {

                /*
                    Tenemos dos posibilidades:

                    1. NO tomar el objeto
                    2. TOMAR el objeto

                    Elegimos la que tenga mayor valor.
                */

                int noTomar = dp[i - 1][w];

                int tomar =
                    valor[i - 1] +
                    dp[i - 1][w - peso[i - 1]];

                if (tomar > noTomar) {
                    dp[i][w] = tomar;
                }
                else {
                    dp[i][w] = noTomar;
                }
            }
        }
    }

    printf("\nValor maximo = %d\n", dp[n][W]);

    return 0;
}
