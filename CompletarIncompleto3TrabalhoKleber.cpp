#include<stdio.h>

#include<locale.h>

struct cliente{

int cpf;
char nascimento[50]; };

struct cliente clientes [200];

int codigo=0;

void vender Ingresso(){

system("cls");

fflush(stdin);

gets(clientes[codigo].nome);

printf("\nDigite o CPF: ");

scanf("%i",&clientes [codigo].cpf);

printf("\nDigite a data de nascimento "),

fflush(stdin);

gets(clientes [codigo] nascimento);

printf("\nTegresso vendidoal\n"), system("pause);

}

void listarIngresso(){

system("cls");

int x;

printf("\n******************\n");

printf("\nNome: %s", clientes[x].nome);

printf("\nCPF: %i", clientes[x].cpf);

printf("\nData Nascimento

%s\n", clientes [x].nascimento);

}

system("pause");

}

void validarIngresso(){

system("cls");


