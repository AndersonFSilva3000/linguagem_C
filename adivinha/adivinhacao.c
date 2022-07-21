#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    setlocale(LC_ALL, "portuguese");
    printf("*******************************************\n");
    printf("* Bem vindo ao nosso jogo de Adivinha��o. *\n");
    printf("*******************************************\n");

    int segundos = time(0);
    srand(segundos);

    int numerogrande = rand();

    int numerosecreto = numerogrande % 100;
    
    int chute;
    int tentativa;
    double pontos = 100;
    int acertou = 0;

    int nivel;

    printf("Qual n�vel de dificuldade voc� quer jogar ?\n");
    printf("(1)F�cil (2)M�dio (3)Dif�cil\n\n");
    printf("Escolha: ");
    scanf("%d", &nivel);

    switch (nivel)
    {
    case 1:
        tentativa = 25;
        break;
    
    case 2:
        tentativa = 10;
        break;

    default:
        tentativa = 5;
        break;
    }

    for(int contador = 1; contador <= tentativa; contador++){
    {

        printf("Tentativa %d \n", contador);
        printf("Qual � o seu chute ? \n");
        scanf("%d", &chute);

        if (chute < 0)
        {

            printf("Voc� n�o pode chutar n�meros negativos.\n");
            continue;
        }

        acertou = (chute == numerosecreto);
        int maior = (chute > numerosecreto);

        if (acertou)
        {
            break;
        }
            else if (maior)
        {
                printf("Seu n�mero � maior que o n�mero secreto. \n");
        }

            else
        {
                printf("Seu n�mero � menor que o n�mero secreto. \n");
        }

        double pontosperdidos = (double)(abs)(chute - numerosecreto) / (double)2;
        pontos = pontos - pontosperdidos;
    }
}
    if (acertou){
            printf("\n\nVoc� ganhou.");
            printf("Voc� acertou em %d tentativas. \n", tentativa);
            printf("Total de pontos: %.1f \n", pontos);
        }else{
            printf("\n\nInfelizmente voc� perdeu!");
        }   
}