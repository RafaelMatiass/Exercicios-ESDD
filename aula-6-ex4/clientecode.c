#include <stdio.h>
#include "queue.h"

int main() {

    T_Queue fila;
    T_Info input;
    T_Info auxiliar;

    fila = init(20);
    
    for(int i = 0; i< 20; i++){
        printf("Digite o valor");
        scanf("%d", &input);
        if (enqueue(fila, input)) {
            printf("%d inserido com sucesso, \n", input);
        } else {
            printf("Erro ao inserir %d.\n", input);
        }
    }

    auxiliar = init(20);
    while (!is_empty(fila)) {
        dequeue(fila, &input);

        if (input == 0) {
            enqueue(auxiliar, input);
        } else if (input % 2 == 1) {
            enqueue(auxiliar, input);
        }
    }
    destroy(fila);
    return 0;
}