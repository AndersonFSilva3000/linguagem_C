#include <stdio.h>
#include <locale.h>
#include <string.h>
#include "forca.h"
#include <time.h>
#include <stdlib.h>

// Variáveis global.
char palavrasecreta[TAMANHO_PALAVRA];
char chutes[26];
int chutesdados = 0;

int chutes_errados()
{

    int erros = 0;

    for (int i = 0; i < chutesdados; i++)
    {
        int existe = 0;

        for (int j = 0; j < strlen(palavrasecreta); j++)
        {
            if (chutes[i] == palavrasecreta[j])
            {
                existe = 1;
                break;
            }
        }
        if (!existe)
            erros++;
    }
    return erros;
}

int enforcou()
{

    return chutes_errados() >= 5;
}

void abertura()
{
    printf("******************************\n");
    printf("*        JOGO DE FORCA       *\n");
    printf("******************************\n\n");
}

void chute()
{
    char chute;
    scanf(" %c", &chute);

    chutes[chutesdados] = chute;
    chutesdados++;
}

int jachutou(char letra)
{
    int achou = 0;

    for (int j = 0; j < chutesdados; j++)
    {
        if (chutes[j] == letra)
        {
            achou = 1;
            break;
        }
    }

    return achou;
}

int ganhou()
{

    for (int i = 0; i < strlen(palavrasecreta); i++)
    {
        if (!jachutou(palavrasecreta[i]))
        {
            return 0;
        }
    }
    return 1;
}

void desenhaforca()
{
    int erros = chutes_errados();

    printf("  _______      \n");
    printf(" |/      |     \n");
    printf(" |      %c%c%c    \n", (erros >= 1 ? '(' : ' '), (erros >= 1 ? '_' : ' '), (erros >= 1 ? ')' : ' '));
    printf(" |      %c%c%c   \n", (erros >= 3 ? '\\' : ' '), (erros >= 2 ? '|' : ' '), (erros >= 3 ? '/' : ' '));
    printf(" |       %c     \n", (erros >= 2 ? '|' : ' '));
    printf(" |      %c %c   \n", (erros >= 4 ? '/' : ' '), (erros >= 4 ? '\\' : ' '));
    printf(" |             \n");
    printf("_|___          \n");
    printf("\n\n");

    for (int i = 0; i < strlen(palavrasecreta); i++)
    {

        if (jachutou(palavrasecreta[i]))
        {
            printf("%c ", palavrasecreta[i]);
        }
        else
        {
            printf("_ ");
        }
    }
    printf("\n");
}

void adicionarpalavra()
{
    char quer;

    printf("Você desejar adicionar uma nova plavra ? [S/N]");
    scanf(" %c", &quer);

    if (quer == 'S')
    {
        char novapalavra[TAMANHO_PALAVRA];

        printf("Digite a nova palavra em letra maiúscula: ");
        scanf("%s", novapalavra);

        FILE *f;

        f = fopen("palavras.txt", "r+");
        if (f == 0)
        {
            printf("Banco de dados de palavras não disponivel! \n\n");
            exit(1);
        }

        int qtd;
        fscanf(f, "%d", &qtd);
        qtd++;
        fseek(f, 0, SEEK_SET);
        fprintf(f, "%d", qtd);

        fseek(f, 0, SEEK_END);
        fprintf(f, "\n%s", novapalavra);

        fclose(f);
    }
}

void escolhepalavra()
{
    FILE *f;

    f = fopen("palavras.txt", "r");
    if (f == 0)
    {
        printf("Banco de dados de palavras não disponível. \n\n");
        exit(1);
    }

    int qttdepalavras;
    fscanf(f, "%d", &qttdepalavras);

    srand(time(0));
    int randomico = rand() % qttdepalavras;

    for (int i = 0; i <= randomico; i++)
    {
        fscanf(f, "%s", palavrasecreta);
    }
    fclose(f);
}

int main()
{

    setlocale(LC_ALL, "portuguese");

    abertura();
    escolhepalavra();

    do
    {
        desenhaforca();
        chute();

    } while (!ganhou() && !enforcou());

    if (ganhou())
    {
        printf("\n PARABÉNS!!! Você ganhou!\n\n");

        printf("       ___________      \n");
        printf("      '._==_==_=_.'     \n");
        printf("      .-\\:      /-.    \n");
        printf("     | (|:.     |) |    \n");
        printf("      '-|:.     |-'     \n");
        printf("        \\::.    /      \n");
        printf("         '::. .'        \n");
        printf("           ) (          \n");
        printf("         _.' '._        \n");
        printf("        '-------'       \n\n");
    }
    else
    {
        printf("\nPuxa, infelizmente você perdeu!\n\n");
        printf("\nA Palavra secreta era: %s\n\n", palavrasecreta);

        printf("    _______________         \n");
        printf("   /               \\       \n");
        printf("  /                 \\      \n");
        printf("//                   \\/\\  \n");
        printf("\\|   XXXX     XXXX   | /   \n");
        printf(" |   XXXX     XXXX   |/     \n");
        printf(" |   XXX       XXX   |      \n");
        printf(" |                   |      \n");
        printf(" \\__      XXX      __/     \n");
        printf("   |\\     XXX     /|       \n");
        printf("   | |           | |        \n");
        printf("   | I I I I I I I |        \n");
        printf("   |  I I I I I I  |        \n");
        printf("   \\_             _/       \n");
        printf("     \\_         _/         \n");
        printf("       \\_______/           \n");
    }

    adicionarpalavra();
}