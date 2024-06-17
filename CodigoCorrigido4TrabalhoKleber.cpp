#include <stdio.h>
#include <stdlib.h>  //srand e rand
#include <time.h>    // tempo

int main() {
    int numeros[10][6], linha, coluna, apoio;

    srand(time(NULL));  // Numero aleatorio

    // Gerar os números
    for (linha = 0; linha < 10; linha++) {
        for (coluna = 0; coluna < 6; coluna++) {
            numeros[linha][coluna] = 1 + rand() % 60;
        }

        // Garantir que os números são únicos na linha exemplo gpt 
        for (coluna = 0; coluna < 6; coluna++) {
            apoio = 0;
            while (apoio < coluna) {
                if (numeros[linha][apoio] == numeros[linha][coluna]) {
                    numeros[linha][coluna] = 1 + rand() % 60;
                    apoio = 0;  // Reinicia a verificação desde o início
                } else {
                    apoio++;
                }
            }
        }
    }

    // Imprimir os números
    for (linha = 0; linha < 10; linha++) {
        for (coluna = 0; coluna < 6; coluna++) {
            printf("[%2d] ", numeros[linha][coluna]);  //Para dois dígitos
        }
        printf("\n");
    }

    return 0;
}

