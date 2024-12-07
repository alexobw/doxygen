#include <stdio.h>

#define ROWS 6
#define COLS 7

/**
 * Überprüft, ob das Spielfeld voll ist (keine freien Felder mehr).
 * Gibt 1 zurück, wenn das Spielfeld voll ist, andernfalls 0.
 * 
 * @param board Das Spielfeld als 2D-Array.
 * @return 1, wenn das Spielfeld voll ist, andernfalls 0.
 */
int checkFullBoard(char board[ROWS][COLS]) {
    for (int col = 0; col < COLS; col++) {
        if (board[0][col] == ' ') {
            return 0; // Es gibt noch freie Felder in der obersten Reihe
        }
    }
    return 1; // Das Spielfeld ist voll
}

/**
 * Setzt das Zeichen des aktuellen Spielers auf das Spielfeld.
 * Gibt 1 zurück, wenn der Zug erfolgreich war, andernfalls 0.
 * 
 * @param board Das Spielfeld als 2D-Array.
 * @param column Die Spalte, in die der Spieler setzen möchte.
 * @param player Der Spieler (1 für X, 2 für O).
 * @return 1 bei Erfolg, 0 bei ungültigem Zug (z.B. volle Spalte).
 */
int makeMove(char board[ROWS][COLS], int column, int player) {
    if (column < 0 || column >= COLS || board[0][column] != ' ') {
        return 0; // Ungültiger Zug oder Spalte voll
    }

    // Finde den ersten freien Platz in der angegebenen Spalte
    for (int row = ROWS - 1; row >= 0; row--) {
        if (board[row][column] == ' ') {
            board[row][column] = (player == 1) ? 'X' : 'O';
            return 1; // Erfolgreicher Zug
        }
    }
    return 0; // Sollte niemals erreicht werden, da die Eingabe überprüft wurde
}

/**
 * Überprüft, ob ein Spieler gewonnen hat.
 * Überprüft horizontale, vertikale und diagonale Gewinnbedingungen.
 * 
 * @param board Das Spielfeld als 2D-Array.
 * @return 1 für Spieler X, 2 für Spieler O, 0 wenn kein Gewinner.
 */
int checkWinner(char board[ROWS][COLS]) {
    // Horizontale Überprüfung
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS - 3; col++) {
            if (board[row][col] != ' ' && 
                board[row][col] == board[row][col + 1] && 
                board[row][col] == board[row][col + 2] && 
                board[row][col] == board[row][col + 3]) {
                return (board[row][col] == 'X') ? 1 : 2; // X gewinnt = Spieler 1, O gewinnt = Spieler 2
            }
        }
    }

    // Vertikale Überprüfung
    for (int col = 0; col < COLS; col++) {
        for (int row = 0; row < ROWS - 3; row++) {
            if (board[row][col] != ' ' && 
                board[row][col] == board[row + 1][col] && 
                board[row][col] == board[row + 2][col] && 
                board[row][col] == board[row + 3][col]) {
                return (board[row][col] == 'X') ? 1 : 2;
            }
        }
    }

    // Diagonale Überprüfung (von oben links nach unten rechts)
    for (int row = 0; row < ROWS - 3; row++) {
        for (int col = 0; col < COLS - 3; col++) {
            if (board[row][col] != ' ' && 
                board[row][col] == board[row + 1][col + 1] && 
                board[row][col] == board[row + 2][col + 2] && 
                board[row][col] == board[row + 3][col + 3]) {
                return (board[row][col] == 'X') ? 1 : 2;
            }
        }
    }

    // Diagonale Überprüfung (von oben rechts nach unten links)
    for (int row = 0; row < ROWS - 3; row++) {
        for (int col = 3; col < COLS; col++) {
            if (board[row][col] != ' ' && 
                board[row][col] == board[row + 1][col - 1] && 
                board[row][col] == board[row + 2][col - 2] && 
                board[row][col] == board[row + 3][col - 3]) {
                return (board[row][col] == 'X') ? 1 : 2;
            }
        }
    }

    return 0; // Kein Gewinner
}
