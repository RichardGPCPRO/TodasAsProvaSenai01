#include <stdio.h>

int main() {
    double producao;
    int qtdeCaminhao;

    printf("\nDigite a producao: ");
    scanf("%lf", &producao);  // %lf para double

    printf("\nDigite qtde de caminhoes: ");
    scanf("%i", &qtdeCaminhao);

    double caminhoes[qtdeCaminhao][3], capacidadeTotal = 0, custoTotal = 0;
    int linha;

    for (linha = 0; linha < qtdeCaminhao; linha++) {
        printf("\nDigite capacidade do caminhao: ");
        scanf("%lf", &caminhoes[linha][0]);  //%lf para double
        capacidadeTotal += caminhoes[linha][0];

        printf("\nDigite a quilometragem percorrida: ");
        scanf("%lf", &caminhoes[linha][1]);  // %lf para double

        printf("\nDigite o valor por KM rodado: ");
        scanf("%lf", &caminhoes[linha][2]);  // indice [2] e formato para %lf para double
    }

    if (capacidadeTotal >= producao) {
        printf("\nEmpresa Apta!\n");
        printf("\nProducao: %.21f\n", producao);

        double custoTransp;

        for (linha = 0; linha < qtdeCaminhao; linha++) {
            printf("[%lf] [%lf] [%lf]\n", caminhoes[linha][0], caminhoes[linha][1], caminhoes[linha][2]);

            if (caminhoes[linha][0] >= 45) {
                custoTransp = (caminhoes[linha][0] * caminhoes[linha][1]) * (caminhoes[linha][2] * 0.75);
            } else {
                custoTransp = (caminhoes[linha][0] * caminhoes[linha][1]) * caminhoes[linha][2];
            }

            custoTotal += custoTransp;
            producao -= caminhoes[linha][0];

            printf("\nCaminhao %d", linha + 1);
            printf("\nCusto total: %.21f", custoTotal);
            printf("\nProducao restante: %.21f", producao);
        }
    } else {
        printf("\nCapacidade total dos caminhoes é insuficiente para a produção.\n");
    }

    printf("Fim do programa\n");

    return 0;
}

