#include <stdio.h>
#include <stdlib.h>

#define ROWS 6
#define COLS 7

extern int checkFullBoard(char board[ROWS][COLS]);
extern int makeMove(char board[ROWS][COLS], int column, int player);
extern int checkWinner(char board[ROWS][COLS]);
extern int getPlayerInput(int player);
extern void printBoard(char board[ROWS][COLS]);
extern void printWinner(int winner);

/**
 * Main-Funktion, um das Spiel zu starten.
 * Das Spiel läuft solange, bis ein Gewinner ermittelt wurde oder das Spielfeld voll ist.
 */
int main() {
    char board[6][7] = {{' ', ' ', ' ', ' ', ' ', ' ', ' '}, 
                        {' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {' ', ' ', ' ', ' ', ' ', ' ', ' '}, 
                        {' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {' ', ' ', ' ', ' ', ' ', ' ', ' '}, 
                        {' ', ' ', ' ', ' ', ' ', ' ', ' '}};  // Spielfeld initialisieren

    int currentPlayer = 1;  // 1 für Spieler 1 (X), 2 für Spieler 2 (O)
    int column, winner = 0;
    
    while (!winner && !checkFullBoard(board)) {
        system("clear"); // Bildschirm nach jedem Zug neu laden (Linux/Unix/Mac)
        printBoard(board);  // Spielfeld ausgeben

        column = getPlayerInput(currentPlayer);  // Eingabe des Spielers einholen

        // Überprüfen, ob die Spalte voll ist
        if (!makeMove(board, column, currentPlayer)) {
            printf("\nUngültiger Zug! Diese Spalte ist bereits voll. Versuche es mit einer anderen Spalte.\n");
            continue;  // Spieler muss es erneut versuchen
        }

        // Überprüfen, ob jemand gewonnen hat
        winner = checkWinner(board);

        // Wechselt den Spieler
        currentPlayer = (currentPlayer == 1) ? 2 : 1;  
    }

    system("clear");  // Bildschirm nach dem Spielende neu laden
    printBoard(board);  // Endgültiges Spielfeld anzeigen

    if (winner != 0) {
        printWinner(winner);  // Gewinner anzeigen
    } else {
        printf("\nDas Spiel endet mit einem Unentschieden! Es gibt keinen Gewinner.\n");
    }

    return 0;
}
