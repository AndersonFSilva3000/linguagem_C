#include <stdio.h>
#include <locale.h>

void potencia(int *resultado, int a, int b)
{
  for (int i = 1; i < b; i++)
  {
    (*resultado) =* a;
  }
    
}

int main()
{

  setlocale(LC_ALL, "portuguese");

  int n1;
  int n2;
  int resultado = 1;

  printf("Digite o n�mero que ser� a base: ");
  scanf("%d", &n1);

  printf("Digite o n�mero que ser� o expoente: ");
  scanf("%d", &n2);

  potencia(&resultado, n1, n2);

  printf("O resultado da potencia �: %d", resultado);

}