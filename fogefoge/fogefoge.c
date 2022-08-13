#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include "fogefoge.h"
#include "mapa.h"
#include "time.h"
#include "ui.h"

MAPA m;
POSICAO heroi;

int tempilula = 0;

int praondeofantasmavai(int xatual, int yatual, 
                int* xdestino, int* ydestino){
    
    int opcoes[4][2] = {
        {xatual , yatual+1},
        {xatual+1, yatual},
        {xatual, yatual-1},
        {xatual-1, yatual}
    };

    srand(time(0));
    for(int i = 0; i < 10; i++){
        int posicao = rand() % 4;

        if(podeandar(&m, FANTASMA, opcoes[posicao][0], opcoes[posicao][1])){
            *xdestino = opcoes[posicao][0];
            *ydestino = opcoes[posicao][1];

            return 1;
           }     
    }
    return 0;
}


void fantasma(){
    MAPA copia;

    copia_mapa(&copia, &m);

     for(int i = 0; i < copia.linhas; i++){
         for(int j = 0; j < copia.colunas; j++){
            if(copia.matriz[i][j] == FANTASMA) {
                
                int xdestino;
                int ydestino;

                int encontrou = praondeofantasmavai(i, j, &xdestino, &ydestino);

                if(encontrou){
                    andanomapa(&m, i, j, xdestino, ydestino);
                }
            }
         }
     }
     liberamapa(&copia);
}


// Fun��o para finalizar o jogo, 'provisoria'
int acabou()
{
    POSICAO pos;
    
    int perdeu = !encontra_mapa(&m, &pos, HEROI);
    int ganhou = !encontra_mapa(&m, &pos, FANTASMA);

    return ganhou || perdeu;
}

int ehdirecao(char direcao)
{
    return direcao == ESQUERDA ||
           direcao == CIMA ||
           direcao == BAIXO ||
           direcao == DIREITA;
}

// Fun��o que move o @.
void move(char direcao)
{
    if (!ehdirecao(direcao))
        return;

    int proximox = heroi.x;
    int proximoy = heroi.y;

    switch (direcao)
    {
    case ESQUERDA:
        proximoy--;
        break;
    case CIMA:
        proximox--;
        break;
    case BAIXO:
        proximox++;
        break;
    case DIREITA:
        proximoy++;
        break;
    }   

    if (!podeandar(&m, HEROI, proximox, proximoy))
    {
        return;
    }

    if(ehpersonagem(&m, PILULA, proximox, proximoy)){
        tempilula = 1;
    }

    andanomapa(&m, heroi.x, heroi.y, proximox, proximoy);
    heroi.x = proximox;
    heroi.y = proximoy;
}


void explodepilula() {

    if(!tempilula) return;

    explodepilula2(heroi.x, heroi.y, 0,1,3);
    explodepilula2(heroi.x, heroi.y, 0,-1,3);
    explodepilula2(heroi.x, heroi.y, 1,0,3);
    explodepilula2(heroi.x, heroi.y, -1,0,3);

    tempilula = 0;
}


void explodepilula2(int x, int y, int somax, int somay, int qtd) {
     if(qtd == 0) return;

     int novox = x+somax;
     int novoy =y+somay;   

     if(!ehvalida(&m, novox, novoy+1)) return;
     if(ehparede(&m, novox, novoy+1)) return;

     m.matriz[novox][novoy+1] = VAZIO;
     explodepilula(novox, novoy, somax, somay, qtd-1);   
}

int main()
{

    setlocale(LC_ALL, "portuguese");

    lemapa(&m);
    encontra_mapa(&m, &heroi, HEROI);

    do
    {
        printf("Tem pilula: %s\n", (tempilula ? "SIM" : "NÃO"));
        imprimimapa(&m);

        char comando;
        scanf(" %c", &comando);
        
        if(ehdirecao(comando)) move(comando);
        if(comando == BOMBA) explodepilula();

        fantasma();

    } while (!acabou());

    liberamapa(&m);
}