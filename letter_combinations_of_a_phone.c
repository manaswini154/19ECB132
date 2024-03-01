#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Mapping of digits to letters
const char *digit_mapping[] = {
    "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
};

void backtrack(char *digits, int index, char *current_combination, char ***result, int *result_size) {
    // If the combination is complete, add it to the result
    if (index == strlen(digits)) {
        (*result)[*result_size] = strdup(current_combination);
        (*result_size)++;
        return;
    }

    // Get the letters corresponding to the current digit
    const char *letters = digit_mapping[digits[index] - '0'];

    // Explore all possible letters for the current digit
    for (int i = 0; i < strlen(letters); i++) {
        // Append the current letter to the combination
        current_combination[index] = letters[i];

        // Recursively call the function for the next digit
        backtrack(digits, index + 1, current_combination, result, result_size);
    }
}

char **letter_combinations(char *digits, int *return_size) {
    // Handle empty input
    if (digits == NULL || *digits == '\0') {
        *return_size = 0;
        return NULL;
    }

    // Calculate the maximum possible combinations
    int max_combinations = 1;
    for (int i = 0; i < strlen(digits); i++) {
        max_combinations *= strlen(digit_mapping[digits[i] - '0']);
    }

    // Allocate memory for the result array
    char **result = (char **)malloc(max_combinations * sizeof(char *));
    *return_size = 0;

    // Allocate memory for the current combination
    char *current_combination = (char *)malloc(strlen(digits) + 1);

    // Start the backtracking process
    backtrack(digits, 0, current_combination, &result, return_size);

    // Free memory for the current combination
    free(current_combination);

    return result;
}

int main() {
    printf("Enter a string of digits: ");

    // Read input from the user
    char digits[100];
    scanf("%s", digits);

    int return_size;

    char **result = letter_combinations(digits, &return_size);

    // Print the result
    printf("[");
    for (int i = 0; i < return_size; i++) {
        printf("\"%s\"", result[i]);
        if (i < return_size - 1) {
            printf(", ");
        }
        free(result[i]); // Free memory for each string in the result
    }
    printf("]\n");

    // Free memory for the result array
    free(result);

    return 0;
}
