/**
 * @file output.c
 * @brief Funktionen zur Ausgabe des Spiels.
 * 
 * Diese Datei enthält Funktionen, die das Spielfeld und den Gewinner anzeigen.
 */

#include <stdio.h>

#define ROWS 6  ///< Anzahl der Reihen im Spielfeld
#define COLS 7  ///< Anzahl der Spalten im Spielfeld

/**
 * @brief Gibt das Spielfeld auf der Konsole aus.
 * 
 * Diese Funktion gibt das aktuelle Spielfeld in der Konsole aus, wobei 'X' und 'O'
 * die Spielfiguren der Spieler repräsentieren. Freie Felder werden durch Leerzeichen
 * angezeigt.
 * 
 * @param board Das Spielfeld als 2D-Array.
 */
void printBoard(char board[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("| %c ", board[i][j]);
        }
        printf("|\n");
    }
    printf("\n");
}

/**
 * @brief Gibt den Gewinner auf der Konsole aus.
 * 
 * Diese Funktion gibt den Gewinner des Spiels aus. Sie zeigt entweder
 * "Spieler 1 gewinnt" oder "Spieler 2 gewinnt" an, je nach Ergebnis.
 * 
 * @param winner Die Nummer des Gewinners (1 für Spieler 1, 2 für Spieler 2).
 */
void printWinner(int winner) {
    if (winner == 1) {
        printf("Spieler 1 (X) gewinnt!\n");
    } else if (winner == 2) {
        printf("Spieler 2 (O) gewinnt!\n");
    }
}
