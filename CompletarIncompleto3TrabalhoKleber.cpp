#include<stdio.h>

#include<stdlib.h>

struct produto{

int codigo;

char descricao[50];

double preco;

int estoque;

};

struct produto p[200];

void menu(){

system("cls");

printf("\nDigite a opção desejada"); printf("\n1-Cadastro de produtos");

printf("\n3-Vendas realizadas");

printf("\n4-Gerenciamento de estoque");

printf("\n5-Sair");

printf("\nOpção: ");

}

int seq=0, vd=0;

double vendas [200];

void cadastro(){

system("cls");

p[seq].codigo-seq+1;

printf("\nDigite o nome do produto: ");

fflush(stdin);

gets(p[seq].descricao);

printf("\nDigite o preço do produto: ");

scanf("%lf",&p[seq].preco);

printf("\nDigite o estoque inicial: ");

seq++;

}

void venda(){

char resp;

int cod, cont, qtde, existe=1;

double valorTotal=0;

do{

printf("\nDigite o código do produto: ");

scanf("%i",&cod);

for(cont=0;cont<seq;cont++) {

if(cod==p[cont].codigo){

printf("\nProduto:

%s\n",p[cont].descricao);

printf("\nEstoque:

%i",p[cont].estoque);

printf("\nDigite a quantidade: ");

scanf("%i",&qtde);

p[cont].estoque-=qtde;

valorTotal=(qtde*p[cont].preco)+val

orTotal;

existe=1;

//valorTotal+=(qtde*p[cont].preco);

printf("\ndeseja mais algum

produto? s-sim n-não: ");

fflush(stdin);

scanf("%c",&resp);

}else{

existe=0;

}

}

printf("\nProduto não cadastrado!\n");

system("pause");

}

}while(resp!='n');

printf("\no valor total da venda é: %.21f

\n", valor Total);

vendas [vd]=valorTotal;

vd++;

} void relatorio(){

int x;

for(x=0;x<vd; x++) {

printf("\n*********************\n");

printf("\nVenda n: %i valor:

21f\n",x+1, vendas [x]);

//printf("Estoque atual:

%1\n",p[x].estoque);

}

system("pause");

}

void gerenciamento(){

int y, codp,qtde;

scanf("%i",&codp);

for(y=0;y<seq;y++){

if(codp==p[y].codigo){

printf("\nProduto: %s Estoque:

%i",p[y].descricao,p[y].estoque);

printf("\nDigite a quantidade ou o para

sair: ");

scanf("%i",&qtde);

if(qtde!=0){

}

}

int main(){

setlocale(LC_ALL, "Portuguese");

int op;

while(op!=5){

menu();

scanf("%i",&op);

switch(op){

case 1:

cadastro();

break;

case 2:

break;

case 3:

relatorio();

break;

case 4:

gerenciamento();

break;

case 5:

printf("\nSaindo da aplicação\n");

system("pause");

default:

printf("\nOpção inválida!\n");

}

}
