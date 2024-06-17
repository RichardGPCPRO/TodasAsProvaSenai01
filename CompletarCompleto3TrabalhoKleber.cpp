#include <stdio.h>
#include <stdlib.h>

// Estrutura cliente
struct cliente {
    int cpf;
    char nascimento[50];
};

// vetor de clientes
struct cliente clientes[200];

// Variável global para controlar o número de clientes registrados
int codigo = 0;

// Função para vender ingresso
void venderIngresso() {
    system("cls");

    printf("\nDigite o nome: ");
    fflush(stdin);
    gets(clientes[codigo].nome); // Corrigido para armazenar o nome do cliente

    printf("\nDigite o CPF: ");
    scanf("%i", &clientes[codigo].cpf);

    printf("\nDigite a data de nascimento: ");
    fflush(stdin);
    gets(clientes[codigo].nascimento);

    printf("\nIngresso vendido com sucesso!\n");
    system("pause");

    codigo++; // código para o próximo cliente
}

// Função para listar ingressos vendidos
void listarIngresso() {
    system("cls");

    printf("\n******************\n");

    for (int x = 0; x < codigo; x++) {
        printf("\nNome: %s", clientes[x].nome);
        printf("\nCPF: %i", clientes[x].cpf);
        printf("\nData Nascimento: %s\n", clientes[x].nascimento);
        printf("\n******************\n");
    }

    system("pause");
}


void validarIngresso() {
  //ajuda gpt >>

int main() {
    setlocale(LC_ALL, "Portuguese");

    int opcao;

    do {
        system("cls");

        printf("\n******************\n");
        printf("\n1 - Vender Ingresso\n");
        printf("2 - Listar Ingressos Vendidos\n");
        printf("3 - Validar Ingresso\n");
        printf("0 - Sair\n");
        printf("\nDigite a opção desejada: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                venderIngresso();
                break;
            case 2:
                listarIngresso();
                break;
            case 3:
                validarIngresso();
                break;
            case 0:
                printf("\nEncerrando o programa...\n");
                break;
            default:
                printf("\nOpção inválida! Tente novamente.\n");
                break;
        }

    } while (opcao != 0);

    return 0;
}

