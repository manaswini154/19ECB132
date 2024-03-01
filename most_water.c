#include <stdio.h>
#include <stdlib.h>

int maxArea(int* height, int heightSize) {
    int maxWater = 0;
    int left = 0;
    int right = heightSize - 1;
    
    while (left < right) {
        // Calculate the current water container volume
        int currentWater = (right - left) * (height[left] < height[right] ? height[left] : height[right]);
        
        // Update maxWater if current water is greater
        if (currentWater > maxWater)
            maxWater = currentWater;
        
        // Move the pointer with smaller height towards the center
        if (height[left] < height[right])
            left++;
        else
            right--;
    }
    
    return maxWater;
}

int main() {
    int heightSize;
    
    printf("Enter the number of elements in the height array: ");
    scanf("%d", &heightSize);
    
    int *height = (int *)malloc(heightSize * sizeof(int));
    if (height == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }
    
    printf("Enter the elements of the height array: ");
    for (int i = 0; i < heightSize; ++i) {
        scanf("%d", &height[i]);
    }
    
    printf("Maximum amount of water: %d\n", maxArea(height, heightSize));
    
    free(height);
    
    return 0;
} 

/*
OUTPUT:
Enter the number of elements in the height array: 5
Enter the elements of the height array: 4
5
6
7
8
Maximum amount of water: 16
*/
