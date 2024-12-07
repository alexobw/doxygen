# Variablen
CC = gcc                  # C-Compiler
CFLAGS = -Wall -g          # Compiler-Optionen

SRC = tikTakTow.c   # Quellcode-Dateien
OBJ = tikTakTow.o  # Objekt-Dateien
EXEC = tikTakTow             # Name der ausführbaren Datei
DOXYGEN = doxygen           # Doxygen-Befehl
DOXYFILE = Doxyfile         # Doxygen-Konfigurationsdatei

# Ziel: Standardziel, das die Anwendung erstellt und die Doxygen-Dokumentation generiert
all: $(EXEC) doxygen-doc

# Ziel: Erstelle die ausführbare Datei aus den Objektdateien
$(EXEC): $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

# Ziel: Kompiliere main.o aus main.c
tikTakTow.o: tikTakTow.c
	$(CC) $(CFLAGS) -c tikTakTow.c

# Ziel: Generiere die Doxygen-Dokumentation
doxygen-doc:
	$(DOXYGEN) $(DOXYFILE)

# Ziel: Bereinigen der generierten Dateien
clean:
	rm -f $(OBJ) $(EXEC)
	rm -rf doc/

force:
	touch $(SRC)
