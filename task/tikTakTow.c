/**
 * @file tikTakTow.c
 * @brief Aufgabe 1 Vervollstänig den File Kommentar
 * 
 */
#include <stdio.h>
#include <stdlib.h>

#define SIZE 3  // Größe des Tic-Tac-Toe Spielfeldes (3x3)

/**
 * @brief Gibt das Spielfeld aus.
 *
 * Diese Funktion zeigt das aktuelle Spielfeld auf der Konsole an, indem sie
 * die Symbole der Spieler (X, O) oder leere Felder anzeigt. Die Darstellung
 * wird optisch ansprechend gemacht.
 *
 * @param board Das Spielfeld, das als 2D-Array übergeben wird.
 */
void printBoard(char board[SIZE][SIZE]) {
    printf("\nTic-Tac-Toe Spiel\n\n");
    printf("  A   B   C\n");
    printf("1 %c | %c | %c\n", board[0][0], board[0][1], board[0][2]);
    printf("  ---|---|---\n");
    printf("2 %c | %c | %c\n", board[1][0], board[1][1], board[1][2]);
    printf("  ---|---|---\n");
    printf("3 %c | %c | %c\n", board[2][0], board[2][1], board[2][2]);
    printf("\n");
}

/**
 * @brief 2: Füge einen Funktions Kommentar für die funktion checkWinner hinzu
 */
int checkWinner(char board[SIZE][SIZE]) {
    // Überprüfe horizontale Reihen
    for (int row = 0; row < SIZE; row++) {
        if (board[row][0] == board[row][1] && board[row][1] == board[row][2] && board[row][0] != ' ') {
            return (board[row][0] == 'X') ? 1 : 2;
        }
    }

    // Überprüfe vertikale Spalten
    for (int col = 0; col < SIZE; col++) {
        if (board[0][col] == board[1][col] && board[1][col] == board[2][col] && board[0][col] != ' ') {
            return (board[0][col] == 'X') ? 1 : 2;
        }
    }

    // Überprüfe diagonale Linien
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') {
        return (board[0][0] == 'X') ? 1 : 2;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ') {
        return (board[0][2] == 'X') ? 1 : 2;
    }

    return 0; // Kein Gewinner
}

/**
 * @brief Überprüft, ob das Spielfeld voll ist (kein Platz mehr für Züge).
 *
 * Diese Funktion wird verwendet, um zu überprüfen, ob alle Felder des Spielfelds
 * ausgefüllt wurden. Ein vollbesetztes Spielfeld bedeutet, dass das Spiel Unentschieden endet.
 *
 * @param board Das Spielfeld, das als 2D-Array übergeben wird.
 * @return 1, wenn das Spielfeld voll ist, andernfalls 0.
 */
int isBoardFull(char board[SIZE][SIZE]) {
    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {
            if (board[row][col] == ' ') {
                return 0; // Es gibt noch freie Felder
            }
        }
    }
    return 1; // Das Spielfeld ist voll
}

/**
 * @brief Aufgabe 3: Füge einen Funktions Kommentar für die funktion makeMove hinzu
 */
int makeMove(char board[SIZE][SIZE], char player) {
    char column;
    int row;

    printf("Spieler %c, gib deinen Zug ein (z.B. A1, B2, C3): ", player);
    scanf(" %c%d", &column, &row);

    // Umwandlung der Eingabe in Array-Index
    column = (column >= 'A' && column <= 'C') ? column - 'A' : -1;
    row = (row >= 1 && row <= 3) ? row - 1 : -1;

    // Überprüfe auf gültige Eingabe und ob das Feld leer ist
    if (column == -1 || row == -1 || board[row][column] != ' ') {
        printf("Ungültiger Zug! Versuche es erneut.\n");
        return 0; // Ungültiger Zug
    }

    board[row][column] = player;
    return 1; // Gültiger Zug
}

/**
 * @brief Aufgabe 4: Füge einen Funktions Kommentar für die funktion switchPlayer hinzu
 */
char switchPlayer(char currentPlayer) {
    return (currentPlayer == 'X') ? 'O' : 'X';
}

/**
 * @brief Löscht die Konsole.
 * 
 * Diese Funktion löscht den Inhalt der Konsole, um das Spielfeld nach jedem Zug
 * neu anzuzeigen.
 */
void clearConsole() {
    system("clear"); // Linux/Mac-Befehl zum Löschen der Konsole
}

/**
 * @brief Hauptfunktion, die das Tic-Tac-Toe Spiel steuert.
 * 
 * Diese Funktion führt das Spiel aus, wechselt die Spieler, überprüft den Gewinner
 * und gibt das Endergebnis aus. Das Spiel läuft in einer Schleife, bis ein Spieler gewonnen hat
 * oder das Spielfeld voll ist und ein Unentschieden vorliegt.
 * 
 * @return 0, wenn das Spiel erfolgreich beendet wurde.
 */
int main() {
    char board[SIZE][SIZE] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};  // Initialisiere das Spielfeld
    char currentPlayer = 'X';  // Spieler X beginnt
    int winner = 0;

    printf("Willkommen zu Tic-Tac-Toe!\n");

    // Spiel Schleife
    while (1) {
        clearConsole(); // Konsole nach jedem Zug löschen
        printBoard(board);

        // Zug des aktuellen Spielers
        while (!makeMove(board, currentPlayer)) {
            // Schleife wiederholen, bis der Zug gültig ist
        }

        // Überprüfe, ob der aktuelle Spieler gewonnen hat
        winner = checkWinner(board);
        if (winner != 0) {
            clearConsole();
            printBoard(board);
            printf("Spieler %c hat gewonnen!\n", (winner == 1) ? 'X' : 'O');
            break;
        }

        // Überprüfe, ob das Spielfeld voll ist (Unentschieden)
        if (isBoardFull(board)) {
            clearConsole();
            printBoard(board);
            printf("Das Spiel endet mit einem Unentschieden!\n");
            break;
        }

        // Wechsle den Spieler
        currentPlayer = switchPlayer(currentPlayer);
    }

    return 0;
}