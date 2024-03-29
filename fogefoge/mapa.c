#include <stdio.h>
#include <stdlib.h>
#include "mapa.h"
#include <string.h>

int ehvalida(MAPA *m, int x, int y)
{
  if (x >= m->linhas)
  {
    return 0;
  }
  if (y >= m->colunas)
  {
    return 0;
  }
  return 1;
}

void andanomapa(MAPA* m, int xorigem, int yorigem,
                int xdestino, int ydestino)
{
  char personagem = m->matriz[xorigem][yorigem];
  m->matriz[xdestino][ydestino] = personagem;
  m->matriz[xorigem][yorigem] = VAZIO;
}

// Função que encontra a posição do @
int encontra_mapa(MAPA *m, POSICAO *p, char c)
{

  for (int i = 0; i < m->linhas; i++)
  {
    for (int j = 0; j < m->colunas; j++)
    {
      if (m->matriz[i][j] == c)
      {
        p->x = i;
        p->y = j;
        return 1;
      }
    }
  }
  return 0;
}

// Função para ler o mapa
void lemapa(MAPA *m)
{
  FILE *f;

  f = fopen("mapa.txt", "r");
  if (f == 0)
  {
    printf("ERRO na leitura do mapa.\n");
    exit(1);
  }

  fscanf(f, "%d %d", &(m->linhas), &(m->colunas));
  alocamapa(m);

  for (int i = 0; i < m->linhas; i++)
  {
    fscanf(f, "%s", m->matriz[i]);
  }

  fclose(f);
}

// Função malloc
void alocamapa(MAPA *m)
{

  m->matriz = malloc(sizeof(char *) * m->linhas);

  for (int i = 0; i < m->linhas; i++)
  {
    m->matriz[i] = malloc(sizeof(char) * m->colunas + 1);
  }
}

// Função para liberar o mapa e a função malloc
void liberamapa(MAPA *m)
{
  for (int i = 0; i < m->linhas; i++)
  {
    free(m->matriz[i]);
  }
  free(m->matriz);
}

void copia_mapa(MAPA* destino, MAPA* origem){
    destino->linhas = origem->linhas;
    destino->colunas = origem->colunas;
    alocamapa(destino);
    for(int i = 0; i < origem->linhas; i++ ){
        strcpy(destino->matriz[i], origem->matriz[i]);
    }
}

int podeandar(MAPA* m, char persongem, int x, int y){
    return
        ehvalida(m, x, y ) &&
        !ehparede(m, x, y) &&
        !ehpersonagem(m, persongem, x, y);
}

int ehparede(MAPA* m, int x, int y){
    return
        m->matriz[x][y] == PAREDE_VERTICAL ||
        m->matriz[x][y] == PAREDE_HORIZONTAL;
}

int ehpersonagem(MAPA* m, char personagem, int x , int y){
    return
        m->matriz[x][y] == personagem;
}

