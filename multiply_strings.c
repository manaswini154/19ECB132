#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* multiplyStrings(char* num1, char* num2) {
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    int lenResult = len1 + len2;

    // Allocate memory for the result
    char* result = (char*)malloc((lenResult + 1) * sizeof(char));
    result[lenResult] = '\0';

    // Initialize the result with '0'
    for (int i = 0; i < lenResult; i++) {
        result[i] = '0';
    }

    // Multiply each digit and add to the result
    for (int i = len1 - 1; i >= 0; i--) {
        int carry = 0;

        for (int j = len2 - 1; j >= 0; j--) {
            int product = (num1[i] - '0') * (num2[j] - '0') + (result[i + j + 1] - '0') + carry;
            carry = product / 10;
            result[i + j + 1] = (product % 10) + '0';
        }

        result[i] += carry;
    }

    // Find the first non-zero digit in the result
    int startIndex = 0;
    while (startIndex < lenResult && result[startIndex] == '0') {
        startIndex++;
    }

    // If the result is zero, return "0"
    if (startIndex == lenResult) {
        strcpy(result, "0");
        return result;
    }

    // Shift the result to remove leading zeros
    for (int i = 0; i < lenResult - startIndex + 1; i++) {
        result[i] = result[startIndex + i];
    }

    return result;
}

int main() {
    char num1[100];
    char num2[100];

    // Read input from the user
    printf("Enter the first number: ");
    scanf("%s", num1);

    printf("Enter the second number: ");
    scanf("%s", num2);

    char* result = multiplyStrings(num1, num2);

    // Print the product
    printf("Product: %s\n", result);

    free(result); // Free memory allocated for the result

    return 0;
}

/*
OUTPUT:
example 1:
Enter the first number: 345
Enter the second number: 65
Product: 22425
*/
