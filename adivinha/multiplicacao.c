#include <stdio.h>
#include <locale.h>

int main()
{
  setlocale(LC_ALL, "portuguese");

  int x;
  int y;

  printf("Digite um número: ");
  scanf("%d", &x);

  printf("Digite outro número: ");
  scanf("%d", &y);

  int total = x * y;

  printf("A multimplicação de %d x %d é igual: %d", x, y, total);
}