#include <stdio.h>

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

int main() {
    char expression[100];
    int i = 0;
    int j;
    char token_buffer[10];
    char ch;

    printf("Enter a single-line arithmetic expression:\n");
    
    // Read the single line of input
    while ((ch = getchar()) != '\n' && i < 99) {
        expression[i++] = ch;
    }
    expression[i] = '\0';
    
    i = 0; // Reset index to process the expression
    
    printf("Output:\n");
    
    while (expression[i] != '\0') {
        // Skip whitespace
        if (expression[i] == ' ') {
            i++;
            continue;
        }
        
        // Check for single-letter identifiers
        if (my_isalpha(expression[i])) {
            printf("IDENTIFIER: %c\n", expression[i]);
            i++;
            continue;
        }
        
        // Check for numbers (positive integers)
        if (my_isdigit(expression[i])) {
            j = 0;
            while (my_isdigit(expression[i])) {
                token_buffer[j++] = expression[i++];
            }
            token_buffer[j] = '\0';
            printf("NUMBER: %s\n", token_buffer);
            continue;
        }
        
        // Check for operators
        if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/') {
            printf("OPERATOR: %c\n", expression[i]);
            i++;
            continue;
        }
        
        // Check for parentheses
        if (expression[i] == '(' || expression[i] == ')') {
            printf("PARENTHESIS: %c\n", expression[i]);
            i++;
            continue;
        }
        
        // If none of the above, it's an unclassified character
        i++;
    }

    return 0;
}