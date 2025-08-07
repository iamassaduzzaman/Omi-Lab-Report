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

int main() {
    char token[10];
    int token_index = 0;
    int ch;

    printf("Enter operators one per line (end with Ctrl+D or Ctrl+Z on Windows):\n");
    
    while ((ch = getchar()) != EOF) {
        if (ch == '\n') {
            token[token_index] = '\0'; // Null-terminate the token
            
            if (token_index > 0) {
                printf("%s : ", token);
                
                int len = my_strlen(token);

                if (len == 1) {
                    if (my_strcmp(token, "+") == 0 || my_strcmp(token, "-") == 0 || my_strcmp(token, "*") == 0 || my_strcmp(token, "/") == 0 || my_strcmp(token, "%") == 0) {
                        printf("Arithmetic Operator\n");
                    } else if (my_strcmp(token, "=") == 0) {
                        printf("Assignment Operator\n");
                    } else if (my_strcmp(token, "<") == 0 || my_strcmp(token, ">") == 0) {
                        printf("Relational Operator\n");
                    } else if (my_strcmp(token, "!") == 0) {
                        printf("Logical Operator\n");
                    } else {
                        printf("Invalid Operator\n");
                    }
                } else if (len == 2) {
                    if (my_strcmp(token, "==") == 0 || my_strcmp(token, "!=") == 0 || my_strcmp(token, "<=") == 0 || my_strcmp(token, ">=") == 0) {
                        printf("Relational Operator\n");
                    } else if (my_strcmp(token, "&&") == 0 || my_strcmp(token, "||") == 0) {
                        printf("Logical Operator\n");
                    } else {
                        printf("Invalid Operator\n");
                    }
                } else {
                    printf("Invalid Operator\n");
                }
            }
            token_index = 0; // Reset for the next line
        } else {
            // Store character, but prevent buffer overflow
            if (token_index < 9) {
                token[token_index++] = (char)ch;
            }
        }
    }

    // Process the last token if the input ends without a newline
    if (token_index > 0) {
        token[token_index] = '\0';
        printf("%s : ", token);
        
        int len = my_strlen(token);

        if (len == 1) {
            if (my_strcmp(token, "+") == 0 || my_strcmp(token, "-") == 0 || my_strcmp(token, "*") == 0 || my_strcmp(token, "/") == 0 || my_strcmp(token, "%") == 0) {
                printf("Arithmetic Operator\n");
            } else if (my_strcmp(token, "=") == 0) {
                printf("Assignment Operator\n");
            } else if (my_strcmp(token, "<") == 0 || my_strcmp(token, ">") == 0) {
                printf("Relational Operator\n");
            } else if (my_strcmp(token, "!") == 0) {
                printf("Logical Operator\n");
            } else {
                printf("Invalid Operator\n");
            }
        } else if (len == 2) {
            if (my_strcmp(token, "==") == 0 || my_strcmp(token, "!=") == 0 || my_strcmp(token, "<=") == 0 || my_strcmp(token, ">=") == 0) {
                printf("Relational Operator\n");
            } else if (my_strcmp(token, "&&") == 0 || my_strcmp(token, "||") == 0) {
                printf("Logical Operator\n");
            } else {
                printf("Invalid Operator\n");
            }
        } else {
            printf("Invalid Operator\n");
        }
    }

    return 0;
}