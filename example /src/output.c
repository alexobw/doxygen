#include <stdio.h>

/**
 * Gibt das Spielfeld auf der Konsole aus.
 * 
 * @param board Das Spielfeld als 2D-Array.
 */
void printBoard(char board[6][7]) {
    printf("\n4 GEWINNT SPIEL\n");
    for (int row = 0; row < 6; row++) {
        for (int col = 0; col < 7; col++) {
            printf("| %c ", board[row][col]);
        }
        printf("|\n");
        for (int col = 0; col < 7; col++) {
            printf(" ----");
        }
        printf("\n");
    }
    printf("  0    1    2    3    4    5    6\n\n");
}

/**
 * Gibt den Gewinner des Spiels aus.
 * 
 * @param winner Der Gewinner des Spiels (1 für X, 2 für O).
 */
void printWinner(int winner) {
    if (winner == 1) {
        printf("\nHerzlichen Glückwunsch, Spieler X gewinnt!\n");
    } else if (winner == 2) {
        printf("\nHerzlichen Glückwunsch, Spieler O gewinnt!\n");
    }
}
