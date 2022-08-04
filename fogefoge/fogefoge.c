#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

int main() {

  setlocale (LC_ALL, "portuguese");

  char mapa [5] [10 + 1];

  FILE* f;

  f = fopen("mapa.txt", "r");
  if(f == 0) {
    printf("ERRO na leitura do mapa.\n");
    exit(1);
  }

  for(int i = 0; i < 5; i++){
    fscanf(f, "%s", mapa[i]);
  }

  for(int i = 0; i < 5 ; i++){
    printf("%s\n", mapa[i]);
  }
  fclose(f);
}