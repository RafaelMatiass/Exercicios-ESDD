#include "lib.h"

void gerar_crescente(int arr[], int size){
  srand(time(NULL));

  arr[0] = rand() % 100;
  for (int i = 1; i < size; i++){
    arr[i] = arr[i - 1] + (rand() % 9);
  }
}

void criar_indices(int arr[], int indices[], int arr_size, int index_size) {
  for (int i = 0; i < index_size; i++) {
    indices[i] = i * (arr_size / index_size);  
  }
}
