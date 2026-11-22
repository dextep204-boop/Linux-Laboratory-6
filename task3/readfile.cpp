
#include <cstdio>
#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s filename\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");

    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    if (fseek(file, 0, SEEK_SET) != 0) {
        perror("Error seeking file");
        fclose(file);
        return 1;
    }

    int ch;

    while ((ch = fgetc(file)) != EOF) {
        if (fputc(ch, stdout) == EOF) {
            fprintf(stderr, "Error writing output\n");
            fclose(file);
            return 1;
        }
    }

    if (ferror(file)) {
        fprintf(stderr, "Error reading file\n");
        fclose(file);
        return 1;
    }

    if (fclose(file) != 0) {
        perror("Error closing file");
        return 1;
    }

    return 0;
}
