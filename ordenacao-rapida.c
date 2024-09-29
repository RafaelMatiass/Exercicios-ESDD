#include <stdio.h>

void partition(int x[], int lb, int ub, int *pivot) {
    int i = lb;
    int j = ub;
    int pivot_value = x[lb];

    while (i < j) {
        while (x[i] <= pivot_value && i < ub) {
            i++;
        }
        while (x[j] > pivot_value) {
            j--;
        }
        if (i < j) {
            // Swap x[i] and x[j]
            int temp = x[i];
            x[i] = x[j];
            x[j] = temp;
        }
    }
    // Swap pivot element with x[j]
    x[lb] = x[j];
    x[j] = pivot_value;
    *pivot = j;
}

void quicksort(int x[], int lb, int ub) {
    if (lb >= ub) {
        return;
    }
    
    int j;
    partition(x, lb, ub, &j);
    
    quicksort(x, lb, j - 1);
    quicksort(x, j + 1, ub);
}

int main() {
    int tamanho, i;
    printf("Informe o tamanho do array: ");
    scanf("%d", &tamanho);
    
    int colecao[tamanho];
    printf("Informe os elementos do array: \n");
    for (i = 0; i < tamanho; i++) {
        scanf("%d", &colecao[i]);
    }
    
    quicksort(colecao, 0, tamanho - 1);

    printf("Array ordenado: \n");
    for (i = 0; i < tamanho; i++) {
        printf("%d ", colecao[i]);
    }
    
    return 0;
}
