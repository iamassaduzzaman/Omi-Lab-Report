#include <stdio.h>

int main() {
    char input_code[4096];
    char str[4096];
    int input_index = 0;
    int str_index = 0;
    int ch;

    printf("Enter code block (end with Ctrl+D or Ctrl+Z on Windows):\n");

    // Read all input into a buffer
    while ((ch = getchar()) != EOF && input_index < 4095) {
        input_code[input_index++] = (char)ch;
    }
    input_code[input_index] = '\0';

    input_index = 0;

    // Process the input_code string to remove comments
    while (input_code[input_index] != '\0') {
        // Check for multi-line comment start: /*
        if (input_code[input_index] == '/' && input_code[input_index + 1] == '*') {
            input_index += 2; // Skip '/*'
            // Find the end of the multi-line comment: */
            while (input_code[input_index] != '\0') {
                if (input_code[input_index] == '*' && input_code[input_index + 1] == '/') {
                    input_index += 2; // Skip '*/'
                    break;
                }
                input_index++;
            }
        }
        // Check for single-line comment start: //
        else if (input_code[input_index] == '/' && input_code[input_index + 1] == '/') {
            input_index += 2; // Skip '//'
            // Find the end of the line
            while (input_code[input_index] != '\0' && input_code[input_index] != '\n') {
                input_index++;
            }
            // Preserve the newline character
            if (input_code[input_index] == '\n') {
                str[str_index++] = input_code[input_index++];
            }
        }
        // If it's not a comment, copy the character to the output string
        else {
            str[str_index++] = input_code[input_index++];
        }
    }
    
    // Add null terminator to the cleaned string
    str[str_index] = '\0';

    printf("Cleaned code:\n");
    printf("%s", str);

    return 0;
}