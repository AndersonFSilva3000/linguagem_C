#include <stdio.h>
#include <stdlib.h>
#include "mapa.h"

// Função que encontra a posição do @
void encontra_mapa(MAPA *m, POSICAO *p, char c)
{

  for (int i = 0; i < m->linhas; i++)
  {
    for (int j = 0; j < m->colunas; j++)
    {
      if (m->matriz[i][j] == c)
      {
        p->x = i;
        p->y = j;
        break;
      }
    }
  }
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

// Função que imprime o mapa na tela.
void imprimemapa(MAPA *m)
{
  for (int i = 0; i < m->linhas; i++)
  {
    printf("%s\n", m->matriz[i]);
  }
}
