#include <stdio.h>

int main() {
    int choice;

    printf("Which operation would you like to perform?\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);

    printf("You selected option %d\n", choice);

    return 0;
}