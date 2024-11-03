#include <stdio.h>
#include <stdbool.h>
#include <time.h>

#define TAM 100
// 1000000

void merge_sort(int colecao[], int inicio, int fim);
void intercala(int colecao[], int inicio, int fim, int meio);

long long int comp_merge = 0; 
long long int trocas_merge = 0;

// MERGE SORT
void merge_sort(int colecao[], int inicio, int fim) {
  static clock_t t; 
  if (inicio == 0 && fim != 0) { 
    t = clock();
  }

  if (inicio < fim) {
    int meio = (inicio + fim) / 2;
    merge_sort(colecao, inicio, meio);
    merge_sort(colecao, meio + 1, fim);
    intercala(colecao, inicio, fim, meio);
  }

  if (inicio == 0 && fim == TAM-1) { 
    t = clock() - t;
    printf("Tempo de execucao Merge Sort: %lf ms\n", ((double)t) / ((CLOCKS_PER_SEC / 1000)));
    printf("\n\n");
  }
}

void intercala(int colecao[], int inicio, int fim, int meio) {
  int pos_livre, inicio_arquivo1, inicio_arquivo2, i;
  int tamanho = fim - inicio + 1;
  int arquivo_aux[tamanho];


  inicio_arquivo1 = inicio;
  inicio_arquivo2 = meio + 1;
  pos_livre = 0;

  while (inicio_arquivo1 <= meio && inicio_arquivo2 <= fim) {
    comp_merge++;
    if (colecao[inicio_arquivo1] <= colecao[inicio_arquivo2]) {
      arquivo_aux[pos_livre] = colecao[inicio_arquivo1];
      trocas_merge++; 
      inicio_arquivo1++;
    } else {
      arquivo_aux[pos_livre] = colecao[inicio_arquivo2];
      trocas_merge++; 
      inicio_arquivo2++;
    } 
    pos_livre++;
  }

  while (inicio_arquivo1 <= meio) {
    arquivo_aux[pos_livre++] = colecao[inicio_arquivo1++];
    trocas_merge++; 
  }

  while (inicio_arquivo2 <= fim) {
    arquivo_aux[pos_livre++] = colecao[inicio_arquivo2++];
    trocas_merge++; 
  }

  for (i = 0; i < tamanho; i++) {
    colecao[inicio + i] = arquivo_aux[i];
  }

  if (inicio == 0 && fim == TAM-1) { 
    printf("############## ORDENAÇÃO ##############\n\n");
    printf("Quantidade de Comparacoes - Merge Sort: %lld\n", comp_merge);
    printf("Quantidade de Trocas - Merge Sort: %lld\n", trocas_merge);
  }
  
}