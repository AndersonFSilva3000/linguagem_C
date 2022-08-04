#include <stdio.h>
#include <locale.h>

int main(){
    setlocale (LC_ALL,"portuguese");

    int a = 10;
    int* b = &a;

    printf("Valor de 'a', %d\n", a);
    printf("Endereço de 'a': %d\n", &a);
    printf("Endereço do ponteiro 'b': %d\n", &b);
    printf("Endereço de memoria para onde 'b' aponta: %d\n", b);
    printf("Valor alocado no endereço para onde 'b' aponta: %d \n", *b);

}