#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/**
 * Liest die Eingabe eines Spielers für den nächsten Zug ein.
 * Validiert die Eingabe und fordert den Spieler zur erneuten Eingabe auf, wenn die Eingabe ungültig ist.
 * 
 * @param player Der aktuelle Spieler (1 für X, 2 für O).
 * @return Eine gültige Spaltennummer (0 bis 6).
 */
int getPlayerInput(int player) {
    int column;
    char input[10];
    
    while (1) {
        printf("Spieler %d, wähle eine Spalte (0-6): ", player);
        fgets(input, 10, stdin);

        // Überprüfen, ob die Eingabe eine Zahl ist
        if (sscanf(input, "%d", &column) != 1 || column < 0 || column >= 7) {
            printf("Ungültige Eingabe. Bitte gib eine Zahl zwischen 0 und 6 ein.\n");
            continue;  // Weiter mit der nächsten Eingabeaufforderung
        }
        return column;  // Gültige Eingabe
    }
}
