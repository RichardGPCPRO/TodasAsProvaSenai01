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

// Fun��o para limpar o buffer de entrada
void limparBuffer() {
    char c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Fun��o de cadastro de ferramentas
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

// Fun��o de listar as ferramentas cadastradas
void listarFerramentas(ferramenta ferramentas[], int contador) {
    system("cls");
    int x;
    for (x = 0; x < contador; x++) {
        printf("\nCodigo: %d", ferramentas[x].codigo);
        printf("\nNome: %s", ferramentas[x].nome);
        printf("\nQuantidade: %d", ferramentas[x].quantidade);
        printf("\nDispon�vel: %d\n", ferramentas[x].disponivel);
    }
    system("pause");
}

// Fun��o de buscar as ferramentas por nome
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
            printf("\nDispon�vel: %d\n", ferramentas[x].disponivel);
            encontrado = 1;
            break;
        }
    }
    if (!encontrado) {
        printf("\nFerramenta n�o encontrada.\n");
    }
    system("pause");
}

// Fun��o de atualiza��o da quantidade de ferramentas
void atualizarQuantidade(ferramenta ferramentas[], int contador) {
    system("cls");
    int codigo, novaQuantidade, diferencaQuantidade;
    printf("\nDigite o c�digo da ferramenta: ");
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
                printf("\nValores negativos n�o s�o permitidos!\n");
            }
            encontrado = 1;
            break;
        }
    }
    if (!encontrado) {
        printf("\nFerramenta n�o encontrada.\n");
    }
    system("pause");
}

// Fun��o de reserva de ferramentas
void reservarFerramenta(ferramenta ferramentas[], int codEmprestimo, emprestimo emprestar[], int contador) {
    system("cls");
    int qtde;
    printf("Digite o nome do locat�rio: ");
    fgets(emprestar[codEmprestimo].nomeLocatario, 40, stdin);
    emprestar[codEmprestimo].nomeLocatario[strcspn(emprestar[codEmprestimo].nomeLocatario, "\n")] = '\0'; // Remove o '\n' do fgets

    printf("Digite o c�digo da ferramenta: ");
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
                    printf("Quantidade negativa n�o � permitida!\n");
                }
            } while (qtde < 0);
            if (qtde <= ferramentas[x].disponivel) {
                emprestar[codEmprestimo].qtdeEmprestada = qtde;
                ferramentas[x].disponivel -= qtde;
                printf("\nEmpr�stimo realizado com sucesso!\n");
            } else {
                printf("\nQuantidade solicitada superior � dispon�vel.\n");
            }
            break;
        }
    }
    if (!encontradoFerramenta) {
        printf("\nFerramenta n�o encontrada.\n");
    }
    system("pause");
}

// Fun��o de devolu��o de ferramentas
void devolverFerramenta(ferramenta ferramentas[], int codEmprestimo, emprestimo emprestar[], int contador) {
    system("cls");
    int codDev, qtde;
    printf("Digite o c�digo da ferramenta a ser devolvida: ");
    scanf("%d", &codDev);
    limparBuffer();

    int encontradoEmprestimo = 0;
    for (int x = 0; x < contador; x++) {
        if (codDev == emprestar[x].ferramentaEmprestada) {
            encontradoEmprestimo = 1;
            printf("Quantas ferramentas est�o sendo devolvidas: ");
            scanf("%d", &qtde);
            limparBuffer();
            emprestar[x].qtdeEmprestada -= qtde;
            ferramentas[x].disponivel += qtde;
            printf("\nDevolu��o realizada com sucesso!\n");
            break;
        }
    }
    if (!encontradoEmprestimo) {
        printf("\nEmpr�stimo n�o encontrado.\n");
    }
    system("pause");
}

// Fun��o de listagem de empr�stimos
void listarEmprestimo(emprestimo emprestar[], int codEmprestimo, ferramenta ferramentas[], int contador) {
    system("cls");
    if (codEmprestimo > 0) {
        for (int x = 0; x < codEmprestimo; x++) {
            printf("\nNome do locat�rio: %s", emprestar[x].nomeLocatario);
            for (int y = 0; y < contador; y++) {
                if (emprestar[x].ferramentaEmprestada == ferramentas[y].codigo) {
                    printf("\nFerramenta: %s", ferramentas[y].nome);
                    printf("\nQuantidade emprestada: %d", emprestar[x].qtdeEmprestada);
                    break;
                }
            }
            printf("\nData da sa�da: %s\n", emprestar[x].dataSaida);
        }
    } else {
        printf("\nNenhum empr�stimo realizado ainda.\n");
    }
    system("pause");
}

// Fun��o do menu principal
int menu() {
    int opcao;
    system("cls");
    printf("\n1- Adicionar ferramentas");
    printf("\n2- Listar ferramentas");
    printf("\n3- Buscar ferramentas");
    printf("\n4- Atualizar quantidade");
    printf("\n5- Reservar ferramenta");
    printf("\n6- Devolver ferramenta");
    printf("\n7- Listar empr�stimos");
    printf("\n8- Sair");
    printf("\nOp��o: ");
    scanf("%d", &opcao);
    limparBuffer();
    return opcao;
}

// Fun��o principal
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
                printf("\nOp��o inv�lida!\n");
        }
    } while (opcao != 8);

    return 0;
}
