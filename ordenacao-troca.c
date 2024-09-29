#include <stdio.h>

void bubble_sort (int colecao[], int tamanho) {
  int i, j, pos_menor, aux;
  
  for (i = 0; i < tamanho; i++) {
    for(j=0; j<tamanho; j++){
      if(colecao[j] > colecao[j+1]){
        aux = colecao[j];
        colecao[j] = colecao[j+1];
        colecao[j+1] = aux;
      }
    }
  }
  
  for (i = 0; i < tamanho; i++) {
    printf ("%d ", colecao[i]);
  }
  printf ("\n");
}

int main () {
  int tamanho, i;
  scanf ("%d",&tamanho);
  
  int  colecao[tamanho];
  for (i = 0; i < tamanho; i++) {
    scanf ("%d",&colecao[i]);
  }
  
  bubble_sort(colecao, tamanho);
}