#include <stdio.h>

// Function to get the length of a string without using strlen
int my_strlen(char *str) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

// Function to check if a string matches the regular expression a(a|b)*a
int match_regex(char *str) {
    int len = my_strlen(str);

    // The string must be at least 2 characters long (for the starting and ending 'a')
    if (len < 2) {
        return 0;
    }

    // Check if the string starts with 'a'
    if (str[0] != 'a') {
        return 0;
    }

    // Check if the string ends with 'a'
    if (str[len - 1] != 'a') {
        return 0;
    }

    // Check the middle part of the string
    // It must contain zero or more 'a's or 'b's
    for (int i = 1; i < len - 1; i++) {
        if (str[i] != 'a' && str[i] != 'b') {
            return 0;
        }
    }

    // If all checks pass, the string matches the regex
    return 1;
}

int main() {
    char input_str[100];
    int i = 0;
    int ch;

    printf("Enter a string to check against the regex 'a(a|b)*a': ");

    // Read a single line of input
    while ((ch = getchar()) != '\n' && i < 99) {
        input_str[i++] = (char)ch;
    }
    input_str[i] = '\0';

    if (match_regex(input_str)) {
        printf("'%s' MATCHES the regular expression 'a(a|b)*a'.\n", input_str);
    } else {
        printf("'%s' DOES NOT MATCH the regular expression 'a(a|b)*a'.\n", input_str);
    }

    return 0;
}