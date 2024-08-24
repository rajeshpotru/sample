#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h> // Added for strcmp function

bool isoperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

bool isvalidIdentifier(const char* str) {
    if (isalpha(str[0]))
        return false;
    for (int i = 1; str[i] != '\0'; i++) {
        if (!isalnum(str[i]))
            return false;
    }
    return true;
}

bool isvalidInteger(const char* str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (!isdigit(str[i]))
            return false;
    }
    return true;
}

int main() {
    char input[100];
    printf("Enter the input String: ");
    scanf("%99[^\n]", input);

    char* token = strtok(input, "\n");
    while (token != NULL) {
        if (strcmp(token, "is valid identifier:") == 0) {
            // Handle valid identifier case
            // ...
        } else if (isvalidIdentifier(token)) {
            printf("Token '%s' type: Identifier\n", token);
        } else if (isvalidInteger(token)) {
            printf("Token '%s' type: Integer\n", token);
            return 0;
        }
