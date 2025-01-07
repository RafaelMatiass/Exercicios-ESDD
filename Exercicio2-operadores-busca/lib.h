#include <time.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int kindex;
  int pos;
} bloco_indice;

void gerar_crescente(int arr[], int size);
void merge_sort(int v[], int inicio, int fim);
void cria_indice(int v[], bloco_indice indice[], int n, int tam_indice);
int busca_sequencial_indexada(int v[], int n, bloco_indice indice[], int tam_indice, int x);