#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    printf("\nWelcome to the Puzzle Mini-Game!\n");
    printf("Solve the puzzle to proceed.\n\n");

    // Simple Number Guessing Puzzle
    int secretNumber, guess, attempts = 3;
    srand(time(NULL)); // Seed the random number generator
    secretNumber = rand() % 10 + 1; // Random number between 1 and 10

    printf("Guess the secret number (between 1 and 10). You have %d attempts.\n", attempts);

    while (attempts > 0) {
        printf("Enter your guess: ");
        scanf("%d", &guess);

        if (guess == secretNumber) {
            printf("\nCongratulations! You guessed the correct number.\n");
            printf("The chest unlocks, revealing valuable items.\n");
            return 0; // Success
        } else if (guess < secretNumber) {
            printf("Too low! Try again.\n");
        } else {
            printf("Too high! Try again.\n");
        }

        attempts--;
        printf("Attempts remaining: %d\n", attempts);
    }

    printf("\nYou've run out of attempts. The chest remains locked.\n");
    printf("Better luck next time!\n");

    return 1; // Failure
}
