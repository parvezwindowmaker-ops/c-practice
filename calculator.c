#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

int getFloat(const char *prompt, float *value)
{
    char input[100];

    while (1)
    {
        printf("%s", prompt);

        if (!fgets(input, sizeof(input), stdin))
            return 0;

        if (sscanf(input, "%f", value) == 1)
            return 1;

        printf("Invalid input. Try again.\n");
    }
}

float operations(int op, float num1, float num2)
{
    switch (op)
    {
    case 1: // Addition
        return num1 + num2;
        break;
    case 2: // Subtraction
        return num1 - num2;
        break;
    case 3: // Multiplication
        return num1 * num2;
        break;
    case 4: // Division
        if (num2 == 0)
        {
            printf("Error: Division by zero is not allowed.\n");
            return 0; // or handle as needed
        }
        return (float)num1 / num2;
    default:
        return -1; // Invalid operation
        break;
    }
}

int main()
{
    int number;
    char input[100];
    printf("Which operation would you like to perform?\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");

    do
    {
        printf("Enter the number: ");
        // Empying the input buffer to avoid infinite loop when user enters non-integer value
        //  scanf("%d",&number);
        //  while (getchar() != '\n');
        fgets(input, sizeof(input), stdin);
        // sscanf(input, "%d", &number);
        if (sscanf(input, "%d", &number) != 1)
        {
            number = -1;
        }
    } while (number < 1 || number > 4);
    // printf("%d", number);

    // memset(input, 0, sizeof(input));

    float num1, num2, result;

    getFloat("Enter a number 1: ", &num1);
    getFloat("Enter a number 2: ", &num2);

    result = operations(number, num1, num2);
    
    char sign[] = { '+', '-', '*', '/'};

    printf("%.2f %c %.2f = %.2f\n", num1, sign[number - 1], num2, result);
    return 0;
}
