#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void backtrack(int* nums, int numsSize, int*** result, int* resultSize, int index) {
    if (index == numsSize - 1) {
        // Add the current permutation to the result
        (*result)[*resultSize] = (int*)malloc(numsSize * sizeof(int));
        for (int i = 0; i < numsSize; i++) {
            (*result)[*resultSize][i] = nums[i];
        }
        (*resultSize)++;
        return;
    }

    for (int i = index; i < numsSize; i++) {
        // Swap the current element with the element at index
        swap(&nums[index], &nums[i]);

        // Recursively generate permutations for the remaining elements
        backtrack(nums, numsSize, result, resultSize, index + 1);

        // Backtrack (undo the swap) for the next iteration
        swap(&nums[index], &nums[i]);
    }
}

int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    int totalPermutations = 1;
    for (int i = 1; i <= numsSize; i++) {
        totalPermutations *= i;
    }

    // Allocate memory for the result array
    int** result = (int**)malloc(totalPermutations * sizeof(int*));
    *returnSize = 0;
    *returnColumnSizes = (int*)malloc(totalPermutations * sizeof(int));

    // Generate permutations using backtracking
    backtrack(nums, numsSize, &result, returnSize, 0);

    // Set column sizes for each row in the result array
    for (int i = 0; i < *returnSize; i++) {
        (*returnColumnSizes)[i] = numsSize;
    }

    return result;
}

int main() {
    int numsSize;
    
    // Read the size of the array from the user
    printf("Enter the size of the array: ");
    scanf("%d", &numsSize);

    // Allocate memory for the array
    int* nums = (int*)malloc(numsSize * sizeof(int));

    // Read the array elements from the user
    printf("Enter %d distinct integers for the array:\n", numsSize);
    for (int i = 0; i < numsSize; i++) {
        scanf("%d", &nums[i]);
    }

    int returnSize;
    int* returnColumnSizes;
    int** result = permute(nums, numsSize, &returnSize, &returnColumnSizes);

    // Print the result
    printf("[");
    for (int i = 0; i < returnSize; i++) {
        printf("[");
        for (int j = 0; j < returnColumnSizes[i]; j++) {
            printf("%d", result[i][j]);
            if (j < returnColumnSizes[i] - 1) {
                printf(", ");
            }
        }
        printf("]");
        if (i < returnSize - 1) {
            printf(", ");
        }
        free(result[i]); // Free memory for each permutation
    }
    printf("]\n");

    // Free memory for the arrays
    free(nums);
    free(result);
    free(returnColumnSizes);

    return 0;
}


/*
OUTPUT:
Example 1:
Enter the size of the array: 2
Enter 2 distinct integers for the array:
12
21
[[12, 21], [21, 12]]

  example 2:
Enter the size of the array: 3
Enter 3 distinct integers for the array:
1
2
3
[[1, 2, 3], [1, 3, 2], [2, 1, 3], [2, 3, 1], [3, 2, 1], [3, 1, 2]]
*/
