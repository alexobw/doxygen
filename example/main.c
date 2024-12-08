/**
 * @file main.c
 * @brief Hauptprogramm für das Vier-Gewinnt-Spiel.
 * 
 * Diese Datei enthält die `main`-Funktion und steuert den Spielablauf,
 * indem sie Funktionen für die Spiellogik, die Eingabe und die Ausgabe
 * aus anderen Dateien aufruft.
 */

#include <stdio.h>
#include <stdlib.h>

#define ROWS 6  ///< Anzahl der Reihen im Spielfeld
#define COLS 7  ///< Anzahl der Spalten im Spielfeld

extern int checkFullBoard(char board[ROWS][COLS]);
extern int makeMove(char board[ROWS][COLS], int column, int player);
extern int checkWinner(char board[ROWS][COLS]);
extern int getPlayerInput(int player);
extern void printBoard(char board[ROWS][COLS]);
extern void printWinner(int winner);

/**
 * @brief Main-Funktion, um das Spiel zu starten.
 * 
 * Das Spiel läuft solange, bis ein Gewinner ermittelt wurde oder das Spielfeld voll ist.
 * Die Funktion wechselt zwischen den beiden Spielern, nimmt Eingaben entgegen,
 * führt Züge aus und zeigt das Spielfeld sowie den Gewinner an.
 * 
 * @return 0, wenn das Programm erfolgreich beendet wurde.
 */
int main() {
    char board[ROWS][COLS] = {{' ', ' ', ' ', ' ', ' ', ' ', ' '}, 
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
