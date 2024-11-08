#include <stdio.h>
#include "lib.h"

#define SIZE 100
#define INDEX_SIZE 10 // Tamanho do índice

int main() {
  int vetor[SIZE];
  int key = 60;  // Chave a ser buscada
  bloco_indice indice[INDEX_SIZE]; // Array de índice

  // Gera valores aleatórios e ordena o vetor
  gerar_crescente(vetor, SIZE);

  // Cria o índice
  cria_indice(vetor, indice, SIZE, INDEX_SIZE);

  // Realiza a busca sequencial indexada
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
