#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include "fogefoge.h"
#include "mapa.h"

MAPA m;
POSICAO heroi;

// Função para finalizar o jogo, 'provisoria'
int acabou()
{
    return 0;
}

// Função que move o @.
void move(char direcao)
{

    if (direcao != 'a' &&
        direcao != 'w' &&
        direcao != 's' &&
        direcao != 'd')
        return;

    m.matriz[heroi.x][heroi.y] = '.';

    switch (direcao)
    {
    case 'a':
        m.matriz[heroi.x][heroi.y - 1] = '@';
        heroi.y--;
        break;
    case 'w':
        m.matriz[heroi.x - 1][heroi.y] = '@';
        heroi.x--;
        break;
    case 's':
        m.matriz[heroi.x + 1][heroi.y] = '@';
        heroi.x++;
        break;
    case 'd':
        m.matriz[heroi.x][heroi.y + 1] = '@';
        heroi.y++;
        break;
    }
}

int main()
{

    setlocale(LC_ALL, "portuguese");

    lemapa(&m);
    encontra_mapa(&m, &heroi, '@');

    do
    {
        imprimemapa(&m);

        char comando;

        scanf(" %c", &comando);
        move(comando);

    } while (!acabou());

    liberamapa(&m);
}