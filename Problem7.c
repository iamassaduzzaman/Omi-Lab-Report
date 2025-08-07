#include <stdio.h>

// Function to get the length of a string without using strlen
int my_strlen(char *str) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

// Function to check if a string matches the logic implied by the sample outputs
int match_regex(char *str) {
    int len = my_strlen(str);
    int b_count = 0;

    // Check if every character is an 'a' or a 'b' and count the 'b's
    for (int i = 0; i < len; i++) {
        if (str[i] != 'a' && str[i] != 'b') {
            return 0; // Found an invalid character
        }
        if (str[i] == 'b') {
            b_count++;
        }
    }

    // The string must contain at least two 'b's to match
    if (b_count >= 2) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    char input_str[100];
    int i = 0;
    int ch;

    printf("Enter a string to check: ");

    // Read a single line of input
    while ((ch = getchar()) != '\n' && i < 99) {
        input_str[i++] = (char)ch;
    }
    input_str[i] = '\0';

    if (match_regex(input_str)) {
        printf("'%s' MATCHES the regular expression.\n", input_str);
    } else {
        printf("'%s' DOES NOT MATCH the regular expression.\n", input_str);
    }

    return 0;
}