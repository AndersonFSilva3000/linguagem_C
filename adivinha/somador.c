#include <stdio.h>

int main(){

  int soma = 0;

  for(int somador = 1; somador <= 100; somador++){

    soma = soma + somador;
  }

  printf("%d", soma);
}