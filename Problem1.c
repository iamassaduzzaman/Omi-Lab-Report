#include <stdio.h>

// Function to get the length of a string without using strlen
int my_strlen(char *str) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

// Function to compare two strings without using strcmp
int my_strcmp(char *str1, char *str2) {
    while (*str1 != '\0' && *str2 != '\0' && *str1 == *str2) {
        str1++;
        str2++;
    }
    if (*str1 == '\0' && *str2 == '\0') {
        return 0; // Strings are equal
    } else {
        return 1; // Strings are not equal
    }
}

// Function to check if a character is a letter
int my_isalpha(char ch) {
    if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
        return 1;
    }
    return 0;
}

// Function to check if a character is a digit
int my_isdigit(char ch) {
    if (ch >= '0' && ch <= '9') {
        return 1;
    }
    return 0;
}

// Function to check if a character is alphanumeric
int my_isalnum(char ch) {
    return my_isalpha(ch) || my_isdigit(ch);
}

// Function to check if a string is a C keyword
int is_keyword(char *str) {
    char *keywords[] = {"int", "if", "while", "return", "for", "do", "else", "break", "continue", "switch", "case", "default", "float", "double", "char", "void", "struct", "enum", "typedef", "sizeof"};
    int num_keywords = 20; // Number of keywords in the array
    for (int i = 0; i < num_keywords; i++) {
        if (my_strcmp(str, keywords[i]) == 0) {
            return 1; // It is a keyword
        }
    }
    return 0; // It is not a keyword
}

// Function to check if a string is a valid C identifier
int is_valid_identifier(char *str) {
    int len = my_strlen(str);

    // Check if the string is empty
    if (len == 0) {
        return 0;
    }

    // Rule 1: Must begin with a letter (a-z, A-Z) or underscore (_)
    if (!my_isalpha(str[0]) && str[0] != '_') {
        return 0;
    }

    // Rule 2: Followed by any combination of letters, digits, or underscores
    for (int i = 1; i < len; i++) {
        if (!my_isalnum(str[i]) && str[i] != '_') {
            return 0;
        }
    }

    // Rule 3: Cannot be a keyword
    if (is_keyword(str)) {
        return 0;
    }

    // If all rules pass, it's a valid identifier
    return 1;
}

int main() {
    char str[100];

    printf("Enter a string: ");
    // Custom function to read a string to avoid using scanf's built-in functionality which might be seen as "built-in"
    int i = 0;
    char ch;
    while ((ch = getchar()) != '\n' && i < 99) {
        str[i++] = ch;
    }
    str[i] = '\0';

    if (is_valid_identifier(str)) {
        printf("\"%s\" is a valid identifier.\n", str);
    } else {
        printf("\"%s\" is NOT a valid identifier.\n", str);
    }

    return 0;
}