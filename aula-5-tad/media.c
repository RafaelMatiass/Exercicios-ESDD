#include<stdio.h>

int main() {
  int media_final, divisor = 0;
  int media = 0;
  int nota;

  do {
    divisor++;
    nota = 0;
    printf("Digite uma nota: ");
    scanf("%d", &nota);

    media += nota;
  } while (nota != -1);

  media_final = media / divisor;
  printf("Media: %d", media_final);
  
  return 0;
}