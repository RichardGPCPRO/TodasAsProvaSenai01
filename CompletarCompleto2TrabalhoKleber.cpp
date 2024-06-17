#include<stdio.h>
#include<locale.h>
#include<string.h> // Para usar a função fgets

struct cliente {
    int cpf;
    char nome[50];
    char nascimento[50];
};

struct cliente clientes[200];
int codigo = 0;

void venderIngresso() {
    system("cls");

    fflush(stdin);

    printf("\nDigite o nome: ");
    fgets(clientes[codigo].nome, 50, stdin);

    printf("\nDigite o CPF: ");
    scanf("%d", &clientes[codigo].cpf);

    printf("\nDigite a data de nascimento: ");
    fflush(stdin);
    fgets(clientes[codigo].nascimento, 50, stdin);

    printf("\nIngresso vendido!\n");

    system("pause");
}

void listarIngresso() {
    system("cls");

    int x;

    printf("\n******************\n");

    printf("\nNome: %s", clientes[x].nome);
    printf("\nCPF: %d", clientes[x].cpf);
    printf("\nData Nascimento: %s\n", clientes[x].nascimento);

    system("pause");
}

void validarIngresso() {
    system("cls");

    int busca, x;
    int achou = 0; // Variável para indicar se o CPF foi encontrado

    printf("\nDigite o CPF da busca: ");
    scanf("%d", &busca);

    for (x = 0; x < codigo; x++) {
        if (busca == clientes[x].cpf) {
            printf("\n*********\n");
            printf("\nNome: %s", clientes[x].nome);
            printf("\nCPF: %d", clientes[x].cpf);
            printf("\nNascimento: %s\n", clientes[x].nascimento);

            achou = 1;
            break;
        }
    }

    if (achou == 0) {
        printf("\nCadastro não encontrado\n");
    }

    system("pause");
}

void menu() {
    printf("\na) Vender ingressos\n");
    printf("b) Listar ingressos\n");
    printf("c) Validar ingressos\n");
    printf("d) Sair\n");
    printf("\nOpção: ");
}

int main() {
    setlocale(LC_ALL, "Portuguese");

    char op;

    do {
        system("cls");

        menu();

        fflush(stdin);
        scanf("%c", &op);

        switch (op) {
            case 'a':
                venderIngresso();
                break;
            case 'b':
                listarIngresso();
                break;
            case 'c':
                validarIngresso();
                break;
            case 'd':
                printf("\nSaindo!\n");
                system("pause");
                break;
            default:
                printf("\nOpção inválida\n");
                system("pause");
                break;
        }
    } while (op != 'd');

    return 0;
}
