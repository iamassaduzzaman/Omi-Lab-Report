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
int my_strcmp(const char *str1, const char *str2) {
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
    char *keywords[] = {"if", "else", "while", "for", "int", "float", "char", "return"};
    int num_keywords = 8;
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

// Function to check if a string is a number
int is_number(char *str) {
    int len = my_strlen(str);
    if (len == 0) {
        return 0;
    }
    for (int i = 0; i < len; i++) {
        if (!my_isdigit(str[i])) {
            return 0;
        }
    }
    return 1;
}

// Function to check if a character is a delimiter
int is_delimiter(char ch) {
    switch (ch) {
        case ' ':
        case '\n':
        case '\t':
        case '{':
        case '}':
        case '(':
        case ')':
        case ';':
        case '<':
        case '>':
        case '=':
        case '+':
        case '-':
        case '*':
        case '/':
            return 1;
        default:
            return 0;
    }
}

int main() {
    char sentence[1000];
    char token[100];
    int sentence_len, i = 0, j = 0;

    printf("Enter a sentence of code: ");
    
    // Custom function to read an entire line
    int k = 0;
    char ch;
    while ((ch = getchar()) != '\n' && k < 999) {
        sentence[k++] = ch;
    }
    sentence[k] = '\0';
    sentence_len = k;

    while (i < sentence_len) {
        // Skip leading delimiters
        while (i < sentence_len && is_delimiter(sentence[i]) && sentence[i] != ' ') {
            // Handle single-character delimiters
            printf("%c : (Not classified as keyword or identifier)\n", sentence[i]);
            i++;
        }
        while (i < sentence_len && sentence[i] == ' ') {
            i++;
        }

        if (i >= sentence_len) {
            break;
        }
        
        j = 0;
        
        // Check for identifier/keyword/number
        if (my_isalpha(sentence[i]) || sentence[i] == '_') {
            while (i < sentence_len && (my_isalnum(sentence[i]) || sentence[i] == '_')) {
                token[j++] = sentence[i++];
            }
            token[j] = '\0';
            
            if (is_keyword(token)) {
                printf("%s : Keyword\n", token);
            } else if (is_valid_identifier(token)) {
                printf("%s : Identifier\n", token);
            } else {
                printf("%s : (Not classified as keyword or identifier)\n", token);
            }
        }
        // Check for number
        else if (my_isdigit(sentence[i])) {
            while (i < sentence_len && my_isdigit(sentence[i])) {
                token[j++] = sentence[i++];
            }
            token[j] = '\0';
            printf("%s : (Not classified as keyword or identifier)\n", token);
        }
        // Handle other delimiters which were not space
        else if (is_delimiter(sentence[i])) {
            printf("%c : (Not classified as keyword or identifier)\n", sentence[i]);
            i++;
        }
    }

    return 0;
}