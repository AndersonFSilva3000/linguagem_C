#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

  struct registro
  {
      char nome[20];
      char telefone[20];
  };
   struct registro reg;


int main(void)
{

  setlocale(LC_ALL, "portuguese");

    printf("\n**********************************************************\n");
    printf("*                   TESTANDO STRUCT                      *");
    printf("\n**********************************************************\n");

    printf("Digite seu nome: ");
    scanf(" %s", &(reg.nome));

    printf("Digite o número de seu telefone: ");
    scanf("%s", &(reg.telefone));

    printf("\n**********************************************************\n");
    printf("*Olá %s ! Número salvo em nosso scruct com sucesso.*", reg.nome);
    printf("\n**********************************************************\n");
  return (0);
}