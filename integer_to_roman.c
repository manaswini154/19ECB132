#include <stdio.h>
#include <string.h>

// Function to convert integer to Roman numeral
char* intToRoman(int num) {
    // Define Roman numeral symbols and their corresponding values
    char* symbols[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};

    // Allocate memory for the result
    char* result = (char*)malloc(20 * sizeof(char));
    if (result == NULL) {
        printf("Memory allocation failed.\n");
        return NULL;
    }
    result[0] = '\0';

    // Loop through the symbols and values, appending the corresponding symbol to result
    for (int i = 0; i < 13; i++) {
        while (num >= values[i]) {
            strcat(result, symbols[i]);
            num -= values[i];
        }
    }

    return result;
}

int main() {
    int num;
    printf("Enter an integer: ");
    scanf("%d", &num);

    if (num <= 0 || num >= 4000) {
        printf("Please enter an integer between 1 and 3999.\n");
        return 1;
    }

    char* roman = intToRoman(num);
    if (roman != NULL) {
        printf("Roman numeral: %s\n", roman);
        free(roman);
    }

    return 0;
}


/*
OUTPUT:
Example1:
Enter an integer: 45
Roman numeral: XLV

Example2:
Enter an integer: 3567
Roman numeral: MMMDLXVII
  */
