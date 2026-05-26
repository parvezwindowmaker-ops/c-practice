#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_HISTORY 100

// History storage
char history[MAX_HISTORY][100];
int historyCount = 0;

// Function declarations
double parseExpression(char *expr);
void addToHistory(char *expr, double result);
void showHistory();

// Parser functions
double parseTerm(char **expr);
double parseFactor(char **expr);

// Skip spaces
void skipSpaces(char **expr) {
    while (**expr == ' ') {
        (*expr)++;
    }
}

// Add calculation to history
void addToHistory(char *expr, double result) {
    if (historyCount < MAX_HISTORY) {
        sprintf(history[historyCount], "%s = %.2lf", expr, result);
        historyCount++;
    }
}

// Display history
void showHistory() {
    printf("\n--- Calculation History ---\n");

    if (historyCount == 0) {
        printf("No history available.\n");
        return;
    }

    for (int i = 0; i < historyCount; i++) {
        printf("%d. %s\n", i + 1, history[i]);
    }
}

// Parse numbers and parentheses
double parseFactor(char **expr) {
    skipSpaces(expr);

    double result = 0;

    // Handle parentheses
    if (**expr == '(') {
        (*expr)++;
        result = parseExpression(*expr);

        while (**expr != ')') {
            (*expr)++;
        }

        (*expr)++;
    }
    else {
        result = strtod(*expr, expr);
    }

    return result;
}

// Handle multiplication and division
double parseTerm(char **expr) {
    double result = parseFactor(expr);

    while (1) {
        skipSpaces(expr);

        char op = **expr;

        if (op != '*' && op != '/') {
            break;
        }

        (*expr)++;

        double next = parseFactor(expr);

        if (op == '*') {
            result *= next;
        }
        else {
            result /= next;
        }
    }

    return result;
}

// Handle addition and subtraction
double parseExpression(char *expr) {
    double result = parseTerm(&expr);

    while (1) {
        skipSpaces(&expr);

        char op = *expr;

        if (op != '+' && op != '-') {
            break;
        }

        expr++;

        double next = parseTerm(&expr);

        if (op == '+') {
            result += next;
        }
        else {
            result -= next;
        }
    }

    return result;
}

int main() {
    char input[100];

    printf("=== Advanced Calculator ===\n");

    while (1) {
        printf("\nEnter expression (or 'history' / 'exit'): ");
        fgets(input, sizeof(input), stdin);

        // Remove newline
        input[strcspn(input, "\n")] = '\0';

        // Exit
        if (strcmp(input, "exit") == 0) {
            printf("Goodbye!\n");
            break;
        }

        // Show history
        if (strcmp(input, "history") == 0) {
            showHistory();
            continue;
        }

        // Calculate result
        double result = parseExpression(input);

        printf("Result = %.2lf\n", result);

        addToHistory(input, result);
    }

    return 0;
}