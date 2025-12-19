#include <stdio.h>
#include <string.h>

void ausgabe(int spielfeld[]);
int bedroht(int spielfeld[], int zeile, int spalte);
void setze(int spielfeld[], int spalte, int zeile);

int main(void){
    int spielfeld[8];
    //Arr -1 setzen
    for (int i = 0; i < 8; i++){
        spielfeld[i] = -1;
    }

    setze(spielfeld, 0,0);
    ausgabe(spielfeld);
}

void setze(int spielfeld[], int spalte,int zeile){
    if (spalte > 8){
        return;
    }
    for (zeile; zeile < 8; zeile++){
        if (bedroht(spielfeld, zeile, spalte)) {
            continue;
        }else{
            spielfeld[spalte] = zeile;
            setze(spielfeld, ++spalte, 0);
        }
    }
}

int bedroht(int spielfeld[], int zeile, int spalte){
    //Vertikal
    if (spielfeld[spalte] > 0){
       return 1;
    }

    //Horizontal
    for (int i = 0; i < 8; i++){
        if (spielfeld[i] == zeile) {
            return 1;
        }
    }


    //Diagonal oben -> unten
    int zeiletmp = spalte - zeile;
    for (int spaltetmp = 0 ; zeiletmp < 8; spaltetmp++){
        if (spielfeld[spaltetmp] == zeiletmp){
            return 1;
        }
        zeiletmp++;
    }

    //Diagonale unten -> oben
    zeiletmp = spalte + zeile;
    for (int spaltetmp = 0; zeiletmp > 0 ; spaltetmp++){
        if (spielfeld[spaltetmp] == zeiletmp){
            return 1;
        }
        zeiletmp--;
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

}