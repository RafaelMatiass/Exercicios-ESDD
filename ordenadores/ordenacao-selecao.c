#include <stdio.h>

void selection_sort (int colecao[], int tamanho) {
  int i, j, pos_menor, aux;
  
  for (i = 0; i < tamanho; i++) {
    pos_menor = i;
    for(j=i+1; j<tamanho; j++){
      if(colecao[j] < colecao[pos_menor]){
        pos_menor = j;
      }
    }
    aux = colecao[i];
    colecao[i] = colecao[pos_menor];
    colecao[pos_menor] = aux;
  }
  
  for (i = 0; i < tamanho; i++) {
    printf ("%d ", colecao[i]);
  }
  printf ("\n");
}

main () {
  int max, i;
  scanf ("%d",&max);
  
  int  vetor[max];
  for (i = 0; i < max; i++) {
    scanf ("%d",&vetor[i]);
  }
  
  selection_sort (vetor, max);
}