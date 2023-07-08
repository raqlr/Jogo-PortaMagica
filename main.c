#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN_SECRET 1
#define MAX_SECRET 100
#define MAX_CHANCES 7

int main() {
  int secret;
  int guess;
  int chances;
  char playAgain;

  srand(time(0)); // Inicializa a semente do gerador de números aleatórios

  do {
    secret = rand() % (MAX_SECRET - MIN_SECRET + 1) + MIN_SECRET;
    chances = MAX_CHANCES;

    char nome;
    printf("\nBem-vindo à porta mágica! Tente descobrir a senha de 1 a 100.\n");
    
    while (chances > 0) {
      printf("Suas chances: %d\n", chances);
      printf("\nDigite o seu palpite: ");
      scanf("%d", &guess);

      if (guess == secret) {
        printf("Parabéns! Você acertou a senha da porta mágica.\n");
        break;
      } else if (guess < secret) {
        printf("DICA: O número é maior do que %d.\n", guess);
      } else {
        printf("DICA: O número é menor do que %d.\n", guess);
      }

      chances--;
    }

    if (chances == 0) {
      printf("Você não conseguiu descobrir a senha da porta mágica. Você morreu!\n");
    }

    printf("\n\nDeseja jogar novamente? (Digitar 's' = sim; 'n' = não): ");
    scanf(" %c", &playAgain);

  } while (playAgain == 'S' || playAgain == 's');

  printf("Obrigado por jogar a porta mágica!\n");
  return 0;
}
