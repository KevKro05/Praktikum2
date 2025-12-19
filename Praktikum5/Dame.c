#include <stdio.h>

void ausgabe(int spielfeld[]);
int bedroht(int spielfeld[], int zeile, int spalte);
int setze(int spielfeld[], int spalte);
void findeLoesungen(int spielfeld[]);

int main(void){
    int spielfeld[8];
    findeLoesungen(spielfeld);
}

int setze(int spielfeld[], int spalte) {
    if (spalte == 8) {
        ausgabe(spielfeld);
        return 1;
    }
    int count = 0;
    for (int z = 0; z < 8; z++) {
        if (!bedroht(spielfeld, z, spalte)) {
            spielfeld[spalte] = z;
            count += setze(spielfeld, spalte + 1);
        }
    }

    return count;
}

int bedroht(int spielfeld[], int zeile, int spalte){
    for (int i = 0; i < spalte; i++) {
        int z = spielfeld[i];

        // gleiche Zeile
        if (z == zeile)
            return 1;

        // gleiche Diagonale
        if (z == zeile - (spalte - i))
            return 1;

        if (z == zeile + (spalte - i))
            return 1;
    }
    return 0;
}

void ausgabe(int spielfeld[]){
    for (int i = 0; i < 8; i++){
        printf("|");
        for (int j = 0; j < 8; j++)
        {
            if (spielfeld[j] == i){
                printf(" D ");
            }else printf("   ");
            printf("|");
        }
        printf("\n");
    }
    printf("\n\n");
}

void findeLoesungen(int spielfeld[]) {
    int c = 0;
    for (int start = 0; start < 8; start++)
    {
        for (int k = 0; k < 8; k++) {
            spielfeld[k] = -1;
        }
        spielfeld[0] = start;
        c += setze(spielfeld, 1);

    }
    printf("Gefundene Lösungen: %d", c);
}