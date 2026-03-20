#include <stdio.h>

#define N 10   // number of elements
#define B 10   // number of buckets

// Insertion sort for each bucket
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void bucketSort(int arr[], int n) {
    int buckets[B][N];      // buckets as 2D array
    int bucketCount[B] = {0};

    // Distribute elements into buckets
    for (int i = 0; i < n; i++) {
        int bi = arr[i] / 10;   // bucket index (for range 0–99)
        buckets[bi][bucketCount[bi]++] = arr[i];
    }

    // Sort each bucket
    for (int i = 0; i < B; i++) {
        if (bucketCount[i] > 0) {
            insertionSort(buckets[i], bucketCount[i]);
        }
    }

    // Concatenate buckets back into original array
    int idx = 0;
    for (int i = 0; i < B; i++) {
        for (int j = 0; j < bucketCount[i]; j++) {
            arr[idx++] = buckets[i][j];
        }
    }
}

int main() {
    int arr[N] = {29, 25, 3, 49, 9, 37, 21, 43, 31, 15};

    printf("Original array:\n");
    for (int i = 0; i < N; i++) {
        printf("%d ", arr[i]);
    }

    bucketSort(arr, N);

    printf("\nSorted array:\n");
    for (int i = 0; i < N; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}