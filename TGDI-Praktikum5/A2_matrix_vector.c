#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ZEILEN 4
#define SPALTEN 4

void printMatrix(int arr[ZEILEN][SPALTEN]);
void printVector(int *arr);
void multiplyMaVe(int matrix[ZEILEN][SPALTEN], int *vector, int *ergebnis);

int main(void){
    srand(time(NULL));
    int matrix_a[ZEILEN][SPALTEN];
    int vektor_a[ZEILEN] = {0};
    int vektor_b[ZEILEN];

    for (int i = 0; i < ZEILEN; i++){
        for (int j = 0; j < SPALTEN; j++){
            matrix_a[i][j] = (rand() % 64) - 32;
        }
    }

    for (int i = 0; i < ZEILEN; i++){
        vektor_b[i] = (rand() % 64) - 32;
    }

    printMatrix(matrix_a);
    printVector(vektor_b);

    multiplyMaVe(matrix_a, vektor_b,vektor_a);
    printVector(vektor_a);


}

void printMatrix(int arr[ZEILEN][SPALTEN]){
    for (int i = 0; i < ZEILEN; i++){
        for (int j = 0; j < SPALTEN; j++){
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void printVector(int *arr){
    for (int i = 0; i < ZEILEN; i++){
        printf("%d\n", arr[i]);
    }
    printf("\n");
}

void multiplyMaVe(int matrix[ZEILEN][SPALTEN], int* vector, int *ergebnis){
    for (int i = 0; i < ZEILEN; i++){
        for (int j = 0; j < SPALTEN; j++){
            ergebnis[i] += matrix[i][j] * vector[j];
        }
    }
}