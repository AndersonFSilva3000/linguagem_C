#include <stdio.h>
#include <locale.h>

void potencia(int a, int b)
{
  int resultado = 1;
  for (int i = 1; i <= b; i++)
  {
    resultado = resultado * a;
  }

  printf("O resultado da potencia : %d", resultado);
}

int main()
{

  setlocale(LC_ALL, "portuguese");

  int n1;
  int n2;

  printf("           CALCULANDO POTNCIA.\n\n");

  printf("Digite o nmero que ser a base: ");
  scanf("%d", &n1);
  printf("Digite o nmero que ser o expoente: ");
  scanf("%d", &n2);

  potencia(n1, n2);
}