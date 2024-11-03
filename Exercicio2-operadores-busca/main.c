#include "lib.h"
#include "metodo-ordenador.h"
#define SIZE 100
// 1000000

int main() {
  int vetor[SIZE];
  int merge[SIZE];

  gerar_crescente(vetor, SIZE);
  merge_sort(merge, 0, SIZE - 1);

  // printf("Vetor ordenado:\n");
  // for (int i = 0; i < SIZE; i++) {
  //   printf("%d ", vetor[i]);
  // }
  // printf("\n");

  printf("Terminou\n");

  return 0;
}
