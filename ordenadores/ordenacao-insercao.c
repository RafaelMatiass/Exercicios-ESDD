#include <stdio.h>

void insert_sort (int colecao[], int tamanho) {
  int i, j, aux;
  
  for (i = 1; i < tamanho; i++) {
   aux = colecao[i];
    for(j = i-1; j >= 0 && colecao[j] > aux; j--){
      colecao[j+1] = colecao[j];
    }
    colecao[j+1] = aux;
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
  
  insert_sort(colecao, tamanho);
}