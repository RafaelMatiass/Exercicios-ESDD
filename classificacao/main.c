#include "lib.h"

int main() {
  int vetor[100000];

  gerar_crescente(vetor, 100000);

  for(int i = 0; i < 100000; i++){
    printf("%6d ", vetor[i]);
  }

  return 0;
}