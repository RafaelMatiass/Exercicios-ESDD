#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100
#define INDEX_SIZE 10 // tamanho dos indices de tabela

typedef struct {
    int kindex;  // chave do índice
    int pos;     // posição inicial no vetor principal
} tabela_indice;

// Função para criar o índice com base em um vetor ordenado
void cria_indice(int v[], tabela_indice indice[], int n, int tam_indice) {
  int intervalo = n / tam_indice; // n é o numero que a tabela vai ter
  for (int i = 0; i < tam_indice; i++) {
    indice[i].kindex = v[i * intervalo];
    indice[i].pos = i * intervalo;
  }
}

// Função de busca sequencial indexada
int busca_sequencial_indexada(int v[], int n, tabela_indice indice[], int tam_indice, int x) {
  int i;

  // Aqui faz uma busca no índice para encontrar a tabeka onde o elemento pode estar
  for (i = 0; i < tam_indice && indice[i].kindex <= x; i++);

  // Verifica se o índice sugere que o elemento não está presente
  if (i == 0) {
    return -1;  // O elemento é menor que o primeiro índice
  }

  // Começa a busca sequencial no bloco identificado
  i = indice[i - 1].pos;
  while (i < n && v[i] < x) {
    i++;
  }

  // Verifica se encontrou o elemento
  if (i < n && v[i] == x) {
    return i;  // Retorna a posição onde x foi encontrado
  } else {
    return -1;  // Não encontrou x
  }
}



