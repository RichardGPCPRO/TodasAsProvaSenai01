#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> //tipo de dados booleano

//funções de operações matemáticas
double soma(double num1, double num2) {
    return num1 + num2;
}

double sub(double num1, double num2) {
    return num1 - num2;
}

double multi(double num1, double num2) {
    return num1 * num2;
}

double div(double num1, double num2) {
    if (num2 != 0) {
        return num1 / num2;
    } else {
        printf("Erro: Divisao por zero nao e permitida.\n");
        return 0;  //Ewvitar operação com valor inválido
    }
}

int main() {
    int op;
    double num1, num2;
    bool sair = false;

    do {
        printf("\nDigite dois valores: ");
        scanf("%lf %lf", &num1, &num2);

        printf("\nSelecione a operacao:");
        printf("\n1 - soma\n2 - subtracao\n3 - multiplicacao\n4 - divisao\n0 - sair\n");
        printf("Opcao: ");
        scanf("%d", &op);

        switch (op) {
            case 1:
                printf("Resultado: %.21f\n", soma(num1, num2));
                break;
            case 2:
                printf("Resultado: %.21f\n", sub(num1, num2));
                break;
            case 3:
                printf("Resultado: %.21f\n", multi(num1, num2));
                break;
            case 4:
                printf("Resultado: %.21f\n", div(num1, num2));
                break;
            case 0:
                printf("\nEncerrando a aplicacao.\n");
                sair = true;
                break;
            default:
                printf("\nOpcao invalida!\n");
                break;
        }

        system("pause");  //entrada do usuário
    } while (!sair);

    return 0;
}

