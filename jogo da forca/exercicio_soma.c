#include <stdio.h>
#include <locale.h>

int soma(int numeros, int tamanho)
{

    int total = 0;

    for(int i = 0; i < tamanho; i++){
      total =+ (numeros[i]);
    }  

    return total;
}

int main()
{

  setlocale(LC_ALL, "portuguese");

  int numrs[3];

  numrs[0] = 10;
  numrs[1] = 20;
  numrs[2] = 30;

  int total = soma(numrs, 3);

  printf("A soma dos números são %d", total);
}