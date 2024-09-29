#include <stdio.h>

// Função que intercala duas sublistas ordenadas
void intercala(int colecao[], int inicio, int fim, int meio) {
  int i, j, k;
  int n1 = meio - inicio + 1;
  int n2 = fim - meio;

  // Arrays temporários
  int esquerda[n1], direita[n2];

  // Copia os dados para os arrays temporários
  for (i = 0; i < n1; i++)
    esquerda[i] = colecao[inicio + i];
  for (j = 0; j < n2; j++)
    direita[j] = colecao[meio + 1 + j];

  // Mescla os arrays temporários de volta em colecao[]
  i = 0; // Índice inicial do primeiro subarray
  j = 0; // Índice inicial do segundo subarray
  k = inicio; // Índice inicial do array mesclado

  while (i < n1 && j < n2) {
      if (esquerda[i] <= direita[j]) {
        colecao[k] = esquerda[i];
        i++;
      } else {
        colecao[k] = direita[j];
        j++;
      }
    k++;
  }

  // Copia os elementos restantes de esquerda[], se houver
  while (i < n1) {
    colecao[k] = esquerda[i];
    i++;
    k++;
  }

  // Copia os elementos restantes de direita[], se houver
  while (j < n2) {
    colecao[k] = direita[j];
    j++;
    k++;
  }
}

// Função recursiva que implementa o Merge Sort
void merge(int colecao[], int inicio, int fim) {
  if (inicio < fim) {
    int meio = (inicio + fim) / 2;
    merge(colecao, inicio, meio);
    merge(colecao, meio + 1, fim);
    intercala(colecao, inicio, fim, meio);
  }
}

int main() {
  int tamanho, i;

  // Lê o tamanho da coleção
  scanf("%d", &tamanho);

  // Declara o array com o tamanho especificado
  int colecao[tamanho];

  // Lê os elementos da coleção
  for (i = 0; i < tamanho; i++) {
    scanf("%d", &colecao[i]);
  }

  // Chama a função de merge sort
  merge(colecao, 0, tamanho - 1);

  // Imprime a coleção ordenada
  for (i = 0; i < tamanho; i++) {
      printf("%d ", colecao[i]);
  }

  return 0;
}
