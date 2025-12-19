#include <stdio.h>
#include <string.h>

void ausgabe(int spielfeld[]);
int bedroht(int spielfeld[], int zeile, int spalte);
void setze(int spielfeld[]);

int main(void){
    int spielfeld[8];

    spielfeld[0] = 0;
    spielfeld[1] = 1;
    spielfeld[2] = 2;
    spielfeld[3] = 3;
    spielfeld[4] = 4;
    spielfeld[5] = 5;
    spielfeld[6] = 6;
    spielfeld[7] = 7;

    int i = bedroht(spielfeld,1,2);
    printf("bedroht: %d\n",i);

    ausgabe(spielfeld);
}

void setze(int spielfeld[]){
    for (int i = 0; i < 8; i++){
        for (int j = 0; j < 8; j++){
            if (bedroht(spielfeld,i,j) == 0){
                spielfeld[i] = j;
            }
        }
    }
}

int bedroht(int spielfeld[], int zeile, int spalte){
    //Dame in Spalte
    if (spielfeld[zeile] > 0){
        printf("Spalte\n");
        return 1;
    }

    //Dame in Zeile
    for (int i = 0; i < 8; i++){
        if (spielfeld[i] == zeile){
            printf("Zeile\n");
            return 1;
        }
    }

    //Diagonal oben -> unten
    int zeiletmp = spalte - zeile;
    for (int spaltetmp = 0 ; zeiletmp < 8; spaltetmp++){
        if (spielfeld[spaltetmp] == zeiletmp){
            printf("oben -> unten\n");
            return 1;
        }
        zeiletmp++;
    }

    //Diagonale unten -> oben
    zeiletmp = spalte + zeile;
    for (int spaltetmp = 0; zeiletmp > 0 ; spaltetmp++){
        if (spielfeld[spaltetmp] == zeiletmp){
            printf("unten -> oben\n");
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
            }else{
                printf("   ");
            }
            printf("|");
        }
        printf("\n");
    }

}