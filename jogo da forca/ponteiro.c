#include <stdio.h>
#include <locale.h>

int main(){
    setlocale (LC_ALL,"portuguese");

    int a = 10;
    int* b = &a;

    printf("Valor de 'a', %d\n", a);
    printf("Endere�o de 'a': %d\n", &a);
    printf("Endere�o do ponteiro 'b': %d\n", &b);
    printf("Endere�o de memoria para onde 'b' aponta: %d\n", b);
    printf("Valor alocado no endere�o para onde 'b' aponta: %d \n", *b);

}