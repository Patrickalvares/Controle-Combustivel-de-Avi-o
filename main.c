#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

//Variaveis Globais
float kmTotal = 0;
float media = 0;
float tanque = 0;
float kmPlanejado = 0;
float kmAlternativo = 0;
float gasAtual = 0;
float gasNecessario = 0;
float gasFalta = 0;

void limparTela() {
  fprintf(stdout, "\033[2J\033[0;0f");
  fflush(stdout);
}
void leitura() {
  printf("Qual a média em litros por quilômetros do avião?\n->");
  scanf("%f", & media);
  __fpurge(stdin);

  limparTela();
  printf("Qual a capacidade máxima em litros do tanque do avião?\n->");
  scanf("%f", & tanque);
  __fpurge(stdin);

  limparTela();
  printf("Qual a quantidade de quilômetros do trecho planejado?\n->");
  scanf("%f", & kmPlanejado);
  __fpurge(stdin);

  limparTela();
  printf("Qual a quantidade de quilômetros do trecho alternativo?\n->");
  scanf("%f", & kmAlternativo);
  __fpurge(stdin);

  limparTela();
  printf("Qual a quantidade de combustível em litros já na aeronave?\n->");
  scanf("%f", & gasAtual);
  __fpurge(stdin);
}
void calculo() {
  kmTotal = (kmPlanejado + kmAlternativo) * 1.3;
  gasNecessario = media * kmTotal;
}
void resultado() {
  limparTela();
  printf("O trajeto maximo (planejado + alternativo + margem de segurança) é de: \n%f KM.", kmTotal);

  printf("\n\nSerão necessarios %f litros para todo o trajeto.\n", gasNecessario);
  if (gasNecessario > tanque) {
    printf("\nO tanque deste avião não é grande o suficiente para essa viagem.\n\n*VÔO REPROVADO*");
  } else {
    printf("\nO tanque deste avião é grande o suficiente para essa viagem.\n\n");
    gasFalta = gasNecessario - gasAtual;
    printf("Será necessario abastecer %f litros para o vôo.\n\n*VÔO APROVADO*", gasFalta);
  }
}

int main() {

  setlocale(LC_ALL, "Portuguese");
  printf("Bem vindo ao controle de abastecimento de aeronaves.\n\n");
  leitura();
  calculo();
  resultado();
}