#include <stdio.h>

/**
 * Liest die Eingabe des Spielers und gibt die gewählte Spalte zurück.
 * 
 * @param player Der aktuelle Spieler (1 für X, 2 für O).
 * @return Die gewählte Spalte, in der der Spieler setzen möchte.
 */
int getPlayerInput(int player) {
    int column;
    
    printf("Spieler %d, bitte eine Spalte wählen (0-6): ", player);
    while (1) {
        scanf("%d", &column);
        
        // Überprüfen, ob die Eingabe gültig ist (zwischen 0 und 6)
        if (column >= 0 && column < 7) {
            return column;
        } else {
            printf("Ungültige Eingabe. Bitte eine Zahl zwischen 0 und 6 eingeben: ");
        }
    }
}
