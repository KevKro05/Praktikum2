#include <stdio.h>
#include <stdlib.h>

void numberConvert(int zahl, int zielsystem, char ausgabe[]);
void read_number(int* number);
void read_number_system(int* number_system);

int main(void) {
    int input, number_system;

    printf("Geben Sie die Ausgangszahl ein: ");
    read_number(&input);

    printf("In welches Zahlensystem wollen Sie die Zahl umrechnen: ");
    read_number_system(&number_system);

    char output[32];
    numberConvert(input, number_system, output);

    printf("%s\n", output);

    return 0;
}

void numberConvert(int zahl, int zielsystem, char ausgabe[]) {
    int rest[32];

    for (int i = 0; i < 32; i++) {
        rest[i] = 0;
    }

    int i = 0;
    while (zahl > 0) {
        rest[i] = zahl % zielsystem;
        zahl = zahl / zielsystem;
        i++;
    }

    ausgabe[i] = '\0';
    for (int j = i - 1, a = 0; j >= 0; j--, a++) {
        if (rest[j] < 10) {
            ausgabe[a] = (char) (rest[j] + '0');
        } else {
            ausgabe[a] = (char) (rest[j] - 10 + 'A');
        }
    }
}

void read_number(int* number) {
    char input[32];

    fgets(input, sizeof(input), stdin);

    for (int i = 0; i < (int)sizeof(input); i++) {
        if (input[i] == '\n') {
            break;
        }

        int num = input[i] - '0';
        if (num < 0 || num > 9) {
            printf("Es sind nur natürliche Zahlen erlaubt. Bitte versuche es erneut.\n");
            read_number(number);
            return;
        }
    }

    *number = atoi(input);
}

void read_number_system(int* number_system) {
    char input[32];

    fgets(input, sizeof(input), stdin);

    int num = atoi(input);

    if (num < 2 || num > 16) {
        printf("Es sind nur Zahlen zwischen 2 und 16 erlaubt.\n");
        read_number_system(number_system);
        return;
    }

    *number_system = num;
}
