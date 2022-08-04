#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

int main() {

  setlocale (LC_ALL, "portuguese");

  int numeros [20] [10];

  for(int l = 0; l < 20; l++){
    for(int c = 0; c < 10; c++){
        numeros[l] [c] = l;
        printf("%d", numeros[l] [c]);
    }
    printf("\n");
  }
}