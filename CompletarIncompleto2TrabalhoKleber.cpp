double div(double num1, double num2){

double resultado;

resultado=num1/num2;

return resultado;

{

int main(){

int op;

double num1, num2;

do{

printf("\nDigite dois valores: ");

scanf("%lf %f", &num1, &num2);

printf("\nSelecione a operacao:");

printf("\n1- soma\n2 sub\n3- multi\n4

div\n- sain");

printf("\nopcao: ");

scanf("%i",&op);

switch(op){

case 1:

printf("Resultado:

%.21f\n", soma(num1, num2));

break;

case 2:

printf("Resultado:

%.21f\n", sub(num1, num2));

system("pause");

break;

case 3:

printf("Resultado:

%.21f\n",multi(num1, num2));

system("pause");

break;
case 4:

printf("Resultado:

%.21f\n",div(num1, num2));

} else {

printf("Erro: Divisão por zero

não é permitida.\n");

}

system("pause");

break;

case 0:

printf("\nEncerrando a

aplicacao\n");

break;

default: printf("\nopcao invalida!\n");

}

}while(op!=0);

return 0;

}
