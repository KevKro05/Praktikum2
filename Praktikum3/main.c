#include <stdio.h>

int split(char *string, char splitChar, char **parts, int maxParts, int maxLength);

int main(void) {
    char partsbuf[10][200];
    char *parts[10];

    for (int i = 0; i < 10; i++) {
        parts[i] = partsbuf[i];
    }

    int k = split("Blau;Gelb;Rot", ';', parts, 5, 200);

    printf("%d\n", k);

    for (int i = 0; i < k; i++) {
        printf("%s\n", parts[i]);
    }

    return 0;
}

int split(char *string, char splitChar, char **parts, int maxParts, int maxLength) {
    int counter = 0;

    // i = index von string, j = position von einem char in einem part
    for (int i = 0, j = 0; i < maxLength && counter < maxParts; i++) {
        if (string[i] == '\0') {
            parts[counter][j] = '\0';
            break;
        }

        if (string[i] == splitChar) {
            parts[counter][j] = '\0';
            counter += 1;
            j = 0;
            continue;
        }

        parts[counter][j] = string[i];
        j++;
    }

    return counter+1;
}
