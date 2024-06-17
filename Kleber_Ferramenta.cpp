#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>

typedef struct {
    int codigo;
    char nome[40];
    int quantidade;
    int disponivel;
} ferramenta;

typedef struct {
    char nomeLocatario[40];
    int ferramentaEmprestada;
    int qtdeEmprestada;
    char dataEntrada[40];
    char dataSaida[40];
} emprestimo;

// Função para limpar o buffer de entrada
void limparBuffer() {
    char c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Função de cadastro de ferramentas
void cadastrarFerramentas(ferramenta ferramentas[], int contador) {
    system("cls");
    ferramentas[contador].codigo = contador + 1;
    printf("\nDigite o nome da ferramenta: ");
    fgets(ferramentas[contador].nome, 40, stdin);
    ferramentas[contador].nome[strcspn(ferramentas[contador].nome, "\n")] = '\0'; // Remove o '\n' do fgets
    printf("\nDigite a quantidade da ferramenta: ");
    scanf("%d", &ferramentas[contador].quantidade);
    ferramentas[contador].disponivel = ferramentas[contador].quantidade;
    limparBuffer();
}

// Função de listar as ferramentas cadastradas
void listarFerramentas(ferramenta ferramentas[], int contador) {
    system("cls");
    int x;
    for (x = 0; x < contador; x++) {
        printf("\nCodigo: %d", ferramentas[x].codigo);
        printf("\nNome: %s", ferramentas[x].nome);
        printf("\nQuantidade: %d", ferramentas[x].quantidade);
        printf("\nDisponível: %d\n", ferramentas[x].disponivel);
    }
    system("pause");
}

// Função de buscar as ferramentas por nome
void buscarFerramentas(ferramenta ferramentas[], int contador) {
    system("cls");
    char nomeFerramenta[40];
    printf("\nDigite o nome da ferramenta: ");
    fgets(nomeFerramenta, 40, stdin);
    nomeFerramenta[strcspn(nomeFerramenta, "\n")] = '\0'; // Remove o '\n' do fgets
    int encontrado = 0;
    for (int x = 0; x < contador; x++) {
        if (strcmp(nomeFerramenta, ferramentas[x].nome) == 0) {
            printf("\nCodigo: %d", ferramentas[x].codigo);
            printf("\nNome: %s", ferramentas[x].nome);
            printf("\nQuantidade: %d", ferramentas[x].quantidade);
            printf("\nDisponível: %d\n", ferramentas[x].disponivel);
            encontrado = 1;
            break;
        }
    }
    if (!encontrado) {
        printf("\nFerramenta não encontrada.\n");
    }
    system("pause");
}

// Função de atualização da quantidade de ferramentas
void atualizarQuantidade(ferramenta ferramentas[], int contador) {
    system("cls");
    int codigo, novaQuantidade, diferencaQuantidade;
    printf("\nDigite o código da ferramenta: ");
    scanf("%d", &codigo);
    limparBuffer();
    int encontrado = 0;
    for (int x = 0; x < contador; x++) {
        if (codigo == ferramentas[x].codigo) {
            printf("\nDigite a nova quantidade de ferramentas: ");
            scanf("%d", &novaQuantidade);
            limparBuffer();
            if (novaQuantidade >= 0) {
                diferencaQuantidade = novaQuantidade - ferramentas[x].quantidade;
                ferramentas[x].quantidade = novaQuantidade;
                ferramentas[x].disponivel += diferencaQuantidade;
                printf("\nQuantidade atualizada com sucesso!\n");
            } else {
                printf("\nValores negativos não são permitidos!\n");
            }
            encontrado = 1;
            break;
        }
    }
    if (!encontrado) {
        printf("\nFerramenta não encontrada.\n");
    }
    system("pause");
}

// Função de reserva de ferramentas
void reservarFerramenta(ferramenta ferramentas[], int codEmprestimo, emprestimo emprestar[], int contador) {
    system("cls");
    int qtde;
    printf("Digite o nome do locatário: ");
    fgets(emprestar[codEmprestimo].nomeLocatario, 40, stdin);
    emprestar[codEmprestimo].nomeLocatario[strcspn(emprestar[codEmprestimo].nomeLocatario, "\n")] = '\0'; // Remove o '\n' do fgets

    printf("Digite o código da ferramenta: ");
    scanf("%d", &emprestar[codEmprestimo].ferramentaEmprestada);
    limparBuffer();

    int encontradoFerramenta = 0;
    for (int x = 0; x < contador; x++) {
        if (emprestar[codEmprestimo].ferramentaEmprestada == ferramentas[x].codigo) {
            encontradoFerramenta = 1;
            do {
                printf("Digite a quantidade de ferramentas: ");
                scanf("%d", &qtde);
                limparBuffer();
                if (qtde < 0) {
                    printf("Quantidade negativa não é permitida!\n");
                }
            } while (qtde < 0);
            if (qtde <= ferramentas[x].disponivel) {
                emprestar[codEmprestimo].qtdeEmprestada = qtde;
                ferramentas[x].disponivel -= qtde;
                printf("\nEmpréstimo realizado com sucesso!\n");
            } else {
                printf("\nQuantidade solicitada superior à disponível.\n");
            }
            break;
        }
    }
    if (!encontradoFerramenta) {
        printf("\nFerramenta não encontrada.\n");
    }
    system("pause");
}

// Função de devolução de ferramentas
void devolverFerramenta(ferramenta ferramentas[], int codEmprestimo, emprestimo emprestar[], int contador) {
    system("cls");
    int codDev, qtde;
    printf("Digite o código da ferramenta a ser devolvida: ");
    scanf("%d", &codDev);
    limparBuffer();

    int encontradoEmprestimo = 0;
    for (int x = 0; x < contador; x++) {
        if (codDev == emprestar[x].ferramentaEmprestada) {
            encontradoEmprestimo = 1;
            printf("Quantas ferramentas estão sendo devolvidas: ");
            scanf("%d", &qtde);
            limparBuffer();
            emprestar[x].qtdeEmprestada -= qtde;
            ferramentas[x].disponivel += qtde;
            printf("\nDevolução realizada com sucesso!\n");
            break;
        }
    }
    if (!encontradoEmprestimo) {
        printf("\nEmpréstimo não encontrado.\n");
    }
    system("pause");
}

// Função de listagem de empréstimos
void listarEmprestimo(emprestimo emprestar[], int codEmprestimo, ferramenta ferramentas[], int contador) {
    system("cls");
    if (codEmprestimo > 0) {
        for (int x = 0; x < codEmprestimo; x++) {
            printf("\nNome do locatário: %s", emprestar[x].nomeLocatario);
            for (int y = 0; y < contador; y++) {
                if (emprestar[x].ferramentaEmprestada == ferramentas[y].codigo) {
                    printf("\nFerramenta: %s", ferramentas[y].nome);
                    printf("\nQuantidade emprestada: %d", emprestar[x].qtdeEmprestada);
                    break;
                }
            }
            printf("\nData da saída: %s\n", emprestar[x].dataSaida);
        }
    } else {
        printf("\nNenhum empréstimo realizado ainda.\n");
    }
    system("pause");
}

// Função do menu principal
int menu() {
    int opcao;
    system("cls");
    printf("\n1- Adicionar ferramentas");
    printf("\n2- Listar ferramentas");
    printf("\n3- Buscar ferramentas");
    printf("\n4- Atualizar quantidade");
    printf("\n5- Reservar ferramenta");
    printf("\n6- Devolver ferramenta");
    printf("\n7- Listar empréstimos");
    printf("\n8- Sair");
    printf("\nOpção: ");
    scanf("%d", &opcao);
    limparBuffer();
    return opcao;
}

// Função principal
int main() {
    setlocale(LC_ALL, "Portuguese");

    int opcao, codigoEmprestimo = 0, contador = 0;
    ferramenta ferramentas[100];
    emprestimo emprestar[100];

    do {
        opcao = menu();
        switch (opcao) {
            case 1:
                cadastrarFerramentas(ferramentas, contador);
                contador++;
                break;
            case 2:
                listarFerramentas(ferramentas, contador);
                break;
            case 3:
                buscarFerramentas(ferramentas, contador);
                break;
            case 4:
                atualizarQuantidade(ferramentas, contador);
                break;
            case 5:
                reservarFerramenta(ferramentas, codigoEmprestimo, emprestar, contador);
                codigoEmprestimo++;
                break;
            case 6:
                devolverFerramenta(ferramentas, codigoEmprestimo, emprestar, contador);
                break;
            case 7:
                listarEmprestimo(emprestar, codigoEmprestimo, ferramentas, contador);
                break;
            case 8:
                printf("\nSaindo do programa...\n");
                break;
            default:
                printf("\nOpção inválida!\n");
        }
    } while (opcao != 8);

    return 0;
}
