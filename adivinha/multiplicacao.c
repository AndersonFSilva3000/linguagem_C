#include <stdio.h>
#include <locale.h>

int main()
{
  setlocale(LC_ALL, "portuguese");

  int x;
  int y;

  printf("Digite um n�mero: ");
  scanf("%d", &x);

  printf("Digite outro n�mero: ");
  scanf("%d", &y);

  int total = x * y;

  printf("A multimplica��o de %d x %d � igual: %d", x, y, total);
}