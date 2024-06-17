#include<stdio.h>
#include<stdlib.h>
#include<string.h> // Para usar a função gets

struct produto {
    int codigo;
    char descricao[50];
    double preco;
    int estoque;
};

struct produto p[200];
int seq = 0, vd = 0;
double vendas[200];

void menu() {
    system("cls");
    printf("\nDigite a opção desejada\n");
    printf("1 - Cadastro de produtos\n");
    printf("2 - Vendas realizadas\n");
    printf("3 - Relatório de vendas\n");
    printf("4 - Gerenciamento de estoque\n");
    printf("5 - Sair\n");
    printf("Opção: ");
}

void cadastro() {
    system("cls");

    p[seq].codigo = seq + 1;

    printf("\nDigite o nome do produto: ");
    fflush(stdin);
    gets(p[seq].descricao);

    printf("\nDigite o preço do produto: ");
    scanf("%lf", &p[seq].preco);

    printf("\nDigite o estoque inicial: ");
    scanf("%d", &p[seq].estoque);

    seq++;
}

void venda() {
    char resp;
    int cod, cont, qtde, existe = 0;
    double valorTotal = 0;

    do {
        system("cls");
        printf("\nDigite o código do produto: ");
        scanf("%d", &cod);

        for (cont = 0; cont < seq; cont++) {
            if (cod == p[cont].codigo) {
                printf("\nProduto: %s\n", p[cont].descricao);
                printf("Estoque: %d\n", p[cont].estoque);

                printf("Digite a quantidade: ");
                scanf("%d", &qtde);

                if (qtde <= p[cont].estoque && qtde > 0) {
                    p[cont].estoque -= qtde;
                    valorTotal += qtde * p[cont].preco;
                    existe = 1;
                } else {
                    printf("Quantidade inválida ou estoque insuficiente!\n");
                    existe = 0;
                }

                printf("\nDeseja mais algum produto? (s-sim / n-não): ");
                fflush(stdin);
                scanf("%c", &resp);
                break;
            }
        }

        if (!existe) {
            printf("\nProduto não cadastrado!\n");
            system("pause");
        }

    } while (resp != 'n');

    printf("\nO valor total da venda é: R$ %.2f\n", valorTotal);
    vendas[vd] = valorTotal;
    vd++;
    system("pause");
}

void relatorio() {
    int x;
    system("cls");
    printf("\nRelatório de Vendas\n");

    for (x = 0; x < vd; x++) {
        printf("\n*********************\n");
        printf("Venda nº %d\n", x + 1);
        printf("Valor: R$ %.2f\n", vendas[x]);
    }

    system("pause");
}

void gerenciamento() {
    int codp, qtde, y;

    system("cls");
    printf("\nGerenciamento de Estoque\n");

    printf("\nDigite o código do produto para gerenciar o estoque: ");
    scanf("%d", &codp);

    for (y = 0; y < seq; y++) {
        if (codp == p[y].codigo) {
            printf("\nProduto: %s\n", p[y].descricao);
            printf("Estoque atual: %d\n", p[y].estoque);

            printf("\nDigite a quantidade para atualizar o estoque (ou 0 para sair): ");
            scanf("%d", &qtde);

            if (qtde != 0) {
                p[y].estoque += qtde;
                printf("Estoque atualizado com sucesso!\n");
            }

            break;
        }
    }

    system("pause");
}

int main() {
    setlocale(LC_ALL, "Portuguese");

    int op = 0;

    while (op != 5) {
        menu();
        scanf("%d", &op);

        switch (op) {
            case 1:
                cadastro();
                break;
            case 2:
                venda();
                break;
            case 3:
                relatorio();
                break;
            case 4:
                gerenciamento();
                break;
            case 5:
                printf("\nSaindo da aplicação\n");
                break;
            default:
                printf("\nOpção inválida!\n");
                break;
        }
    }

    return 0;
}
