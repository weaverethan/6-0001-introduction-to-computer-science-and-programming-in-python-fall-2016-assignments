#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "reverse.h"

void reverse(char *str, int len) {
    // Allocate memory for reversed string
    char *reversed = malloc(len + 1);

    if (reversed == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return;
    }

    int pos = 0;
    int caret = len;

    // Iterate through the string to reverse words
    for (int i = len - 1; i >= 0; --i) {
        if (i == -1 || str[i] == ' ') {
            for (int j = i + 1; j < caret; ++j) {
                reversed[pos++] = str[j];
            }
            if (i != -1) {
                reversed[pos++] = ' ';
            }
            caret = i;
        }
    }

    // Null-terminate the reversed string
    reversed[pos] = '\0';

    // Print the reversed string
    printf("%s\n", reversed);

    // Free the allocated memory
    free(reversed);
}

/*int main() {
    // Example usage
    char input[] = "Hello World!";
    int length = sizeof(input) - 1; // Length excluding the null terminator
    backwards(input, length);

    return 0;
}*/