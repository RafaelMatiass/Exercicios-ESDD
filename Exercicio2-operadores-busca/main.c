#include <stdio.h>
#include "lib.h"

#define SIZE 1000000
#define INDEX_SIZE 1000 

int main() {
  int vetor[SIZE];
  int key = 38266;  
  bloco_indice indice[INDEX_SIZE]; 

  gerar_crescente(vetor, SIZE);

  cria_indice(vetor, indice, SIZE, INDEX_SIZE);

  int pos = busca_sequencial_indexada(vetor, SIZE, indice, INDEX_SIZE, key);

  if (pos != -1) {
    printf("Elemento %d encontrado na posição %d.\n", key, pos);
  } else {
    printf("Elemento %d não encontrado.\n", key);
  }

  printf("Vetor ordenado:\n");
  for (int i = 0; i < SIZE; i++) {
    printf("%d ", vetor[i]);
  }
  printf("\n");

  printf("Terminou\n");
  return 0;
}
