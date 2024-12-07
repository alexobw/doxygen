# Variablen
CC = gcc                  # C-Compiler
CFLAGS = -Wall -g          # Compiler-Optionen

SRC = main.c src/board.c src/input.c src/output.c  # Quellcode-Dateien
OBJ = main.o board.o input.o output.o  # Objekt-Dateien
EXEC = 4gewinnt             # Name der ausführbaren Datei
DOXYGEN = doxygen           # Doxygen-Befehl
DOXYFILE = Doxyfile         # Doxygen-Konfigurationsdatei

# Ziel: Standardziel, das die Anwendung erstellt und die Doxygen-Dokumentation generiert
all: $(EXEC) doxygen-doc

# Ziel: Erstelle die ausführbare Datei aus den Objektdateien
$(EXEC): $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

# Ziel: Kompiliere main.o aus main.c
main.o: main.c
	$(CC) $(CFLAGS) -c main.c

# Ziel: Kompiliere board.o aus board.c
board.o: src/board.c
	$(CC) $(CFLAGS) -c src/board.c

# Ziel: Kompiliere input.o aus input.c
input.o: src/input.c
	$(CC) $(CFLAGS) -c src/input.c

# Ziel: Kompiliere output.o aus output.c
output.o: src/output.c
	$(CC) $(CFLAGS) -c src/output.c

# Ziel: Generiere die Doxygen-Dokumentation
doxygen-doc:
	$(DOXYGEN) $(DOXYFILE)

# Ziel: Bereinigen der generierten Dateien
clean:
	rm -f $(OBJ) $(EXEC)
	rm -rf doc/

force:
	touch $(SRC)
