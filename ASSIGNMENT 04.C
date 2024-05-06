NAME =SAMEER 
ROLL NO=23K-5535
SECTION=BCS2D
ASSIGNMENT =04



#include <stdio.h>

// Function to calculate mean, min, max, and range of the array
void calc_status(int arr[], int size, float *mean, int *min, int *max, int *range) {
    // Calculate mean
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    *mean = (float)sum / size;

    // Calculate min
    *min = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] < *min) {
            *min = arr[i];
        }
    }

    // Calculate max
    *max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > *max) {
            *max = arr[i];
        }
    }

    // Calculate range
    *range = *max - *min;
}

int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];
    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    float mean;
    int min, max, range;

    calc_status(arr, size, &mean, &min, &max, &range);

    printf("Mean: %.2f\n", mean);
    printf("Min: %d\n", min);
    printf("Max: %d\n", max);
    printf("Range: %d\n", range);

    return 0;
}