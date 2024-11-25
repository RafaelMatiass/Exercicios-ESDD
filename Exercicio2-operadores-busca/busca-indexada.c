#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 1000000
#define INDEX_SIZE 1000 

typedef struct {
  int kindex;  
  int pos;     
} tabela_indice;

void cria_indice(int v[], tabela_indice indice[], int n, int tam_indice) {
  int intervalo = n / tam_indice; // n é o numero que a tabela vai ter
  for (int i = 0; i < tam_indice; i++) {
    indice[i].kindex = v[i * intervalo];
    indice[i].pos = i * intervalo;
  }
}

int busca_sequencial_indexada(int v[], int n, tabela_indice indice[], int tam_indice, int x) {
  int i;

  for (i = 0; i < tam_indice && indice[i].kindex <= x; i++);

  if (i == 0) {
    return -1;
  }

  i = indice[i - 1].pos;
  while (i < n && v[i] < x) {
    i++;
  }

  if (i < n && v[i] == x) {
    return i;  
  } else {
    return -1; 
  }
}



