#include <stdio.h>
#include <locale.h>

int main()
{

  setlocale(LC_ALL, "portuguese");

  int n1;

  printf("***********************************************\n \n");
  printf("Digite qual taboada voc� gostaria de ver: ");
  scanf("%d", &n1);
  printf("\n\n***********************************************\n");
  printf("             A taboade de %d �:  \n \n", n1);
  

  for (int contador = 1; contador <= 10; contador++) {
    
      int soma = contador * n1;

      printf("                 %d x %d = %d \n", contador, n1, soma); 
  }

  printf("***********************************************");
  printf("\n \n           Essa � a taboada de %d. \n", n1);
  printf("                   FIM!\n\n");
  printf("***********************************************");
}