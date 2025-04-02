/* Programming Project 1: EMPIRICAL ANALYSIS OF SORTING ALGORITHMS
 *  Subject: CS 111 - Design and Analysis of Algorithms
 *  Course and Bloc: BSCS 2A
 *  Project Members:
 *      Cadag, Jaycee D.
 *      Dela Cruz, Mark L.
 *      Espinas, A Z Rain L.
 *      Lovina, John Melrick M.
 *      Morcozo, Janna Carla R.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Constants
#define MAX_RANGE 1000000

// Function Prototypes (Sorting Algorithms)
void selectionSort(long int arr[], int N);
void bubbleSort(long int arr[], int N);
void insertionSort(long int arr[], int N);
void mergeSort(long int arr[], int N);
void merge(long int arr[], int left, int mid, int right);
void performMergeSort(long int arr[], int left, int right);
void quickSort(long int arr[], int N);
long int medianOfThree(long int arr[], int low, int high);
long int partition(long int arr[], int low, int high);
void performQuickSort(long int arr[], int low, int high);
void heapSort(long int arr[], int N);
void maxHeapify(long int arr[], int N, int i);
void buildMaxHeap(long int arr[], int N);
void performHeapSort(long int arr[], int N);

// Helper functions
int sizeArray();
void initArrayAndGet(long int arr[], int N);
void arrayRandomGenerator(long int arr[], int N);
void arrayIncrementGenerator(long int arr[], int N);
void swap(long int *a, long int *b);
void printArray(FILE *file, long int arr[], int N);

// Global variable
double cpu_time_used;

// Functions for aesthetics
void load(void) {
    int dots = 0;
    while (dots < 6) {
        printf(".");
        fflush(stdout);
        for (long i = 0; i < 101000000; i++);
        dots++;
    }
    printf("\n");
}

void loadFast(void) {
    int dots = 0;
    while (dots < 5) {
        for (long i = 0; i < 1010000; i++);
        dots++;
    }
}

void printCenter(char *text) {
    int width = 80;
    int len = strlen(text);

    int padding = (width - len) / 2;
    // Print the padding
    for (int i = 0; i < padding; i++) {
        printf(" ");
    }

    // Print the text
    loadFast();
    printf("%s\n", text);
}

// Main function
int main() {
    system("cls");

    // Open output file
    FILE *file; 
    file = fopen("output.txt", "w");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    int choice;         // User's choice for sorting algorithm
    int N;              // Number of integers to be sorted (array size)
    long int *arr;      // Input array

    while (1) {
        printf("\n\n");

        // Display title
        char *title[] = {
            "|------------------------|",
            "|-- SORTING ALGORITHMS --|",
            "|------------------------|"
        };
        for (int i = 0; i < 3; i++) {
            printCenter(title[i]);
        }
        printf("\n");

        // Menu options
        printf("\t1. Selection Sort\n");
        printf("\t2. Bubble Sort\n");
        printf("\t3. Insertion Sort\n");
        printf("\t4. Mergesort\n");
        printf("\t5. Quicksort\n");
        printf("\t6. Heapsort\n");
        printf("\t0. Exit\n");

        printf("\n\tEnter your choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("\n\tInvalid input. Please enter a number between 0 and 6.");
            while (getchar() != '\n');  // Clear input buffer
            continue;
        }

        if (choice == 0){
            printf("\n\n\tExiting...");
            fclose(file);   // Close the file
            load();
            return 0;
            break;
        }

        if (choice < 0 || choice > 6) {
            printf("\n\tInvalid choice. Please enter a number between 0 and 6.");
            load();
            printf("\n\n");
            continue;
        }
        break;  // Exit the loop if valid input is received  
    }

    N = sizeArray();
    arr = malloc(N * sizeof(long int));             // Dynamically allocate memory
    if (arr == NULL) {
        printf("\n\tMemory allocation failed.\n");
        fclose(file);                               // Close the file
        return 1;                                   // Exit if memory allocation fails
    }

    // Initialize the array based on user input
    initArrayAndGet(arr, N);
    
    fprintf(file, "\n\tOriginal array: ");
    printArray(file, arr, N);

    // Sort the array based on user choice
    switch (choice) {
        case 1:
            selectionSort(arr, N);
            break;
        case 2:
            bubbleSort(arr, N);
            break;
        case 3:
            insertionSort(arr, N);
            break;
        case 4:
            mergeSort(arr, N);
            break;
        case 5:
            quickSort(arr, N);
            break;
        case 6:
            heapSort(arr, N);
            break;
    }

    fprintf(file, "\n\n\tSorted array: ");
    printArray(file, arr, N);
    fprintf(file, "\n\tTime: %fs\n", cpu_time_used);
    printf("\n\tTime: %fs\n", cpu_time_used);

    free(arr);      // Free allocated memory
    fclose(file);   // Close the file
    return 0;       // Exit the program
}

int sizeArray() {
    int N;
    printf("\n\tEnter the size of your array: ");
    scanf("%d", &N);
    return N;
}

void initArrayAndGet(long int arr[], int N) {
    long int genarray;
    do {
        printf("\n\tHow would you like your array values to be generated?");
        printf("\n\t1) Random \n\t2) Incremental \n\tEnter your answer: ");
        scanf("%d", &genarray);
        if(genarray != 1 && genarray != 2){
            printf("\n\tInvalid input. Please input 1 or 2.\n");
        }
    } while(genarray != 1 && genarray != 2);

    if (genarray == 1)
        arrayRandomGenerator(arr, N);
    else
        arrayIncrementGenerator(arr, N);
}

void arrayRandomGenerator(long int arr[], int N) {
    srand(time(NULL));
    for (int i = 0; i < N; i++) {
        arr[i] = rand() % (MAX_RANGE + 1);
    }
}

void arrayIncrementGenerator(long int arr[], int N) {
    int X;
    printf("\n\tEnter your starting value: ");
    scanf("%d", &X);

    for (int i = 0; i < N; i++) {
        arr[i] = X + i;
    }
}

// Selection sort
void selectionSort(long int arr[], int N){
    clock_t start, end;
    start = clock();

    // Selection sort operation
    int i, j, minIndex, temp;

    // Loop through the array to find the smallest element
    for (i = 0; i < N - 1; i++) {
        minIndex = i;
        for (j = i + 1; j < N; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        // Swap the smallest element with the current element
        temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }

    end = clock();
    cpu_time_used = ((double) (end-start)) / CLOCKS_PER_SEC;
}

// Bubble sort
void bubbleSort(long int arr[], int N){
    clock_t start, end;
    start = clock();

    // Bubble sort operation
    // Loop through the array to compare adjacent elements and swap them if they are in the wrong order
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N - i - 1; j++) {
            // Compare adjacent elements
            if (arr[j] > arr[j + 1]) {
                // Swap if the current element is greater than the next element
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    end = clock();
    cpu_time_used = ((double) (end-start)) / CLOCKS_PER_SEC;
}

// Insertion sort
void insertionSort(long int arr[], int N){
    clock_t start, end;
    start = clock();

    // Insertion sort operation
    // Loop through the array to insert each element into its correct position in the sorted section
    for (int i = 1; i < N; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }

    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
}

// Mergesort
void mergeSort(long int arr[], int N){
        clock_t start, end;
        start = clock();

        // Mergesort operation
        performMergeSort(arr, 0, N - 1);

        end = clock();
        cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
}

// Function to merge two sorted subarrays into a single sorted array
void merge(long int arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;    // Size of left subarray
    int n2 = right - mid;       // Size of right subarray

    // Temporary arrays to hold the left and right subarrays
    long int leftArr[n1], rightArr[n2];

    // Copy elements into left subarray
    for (i = 0; i < n1; i++)
        leftArr[i] = arr[left + i];
    // Copy elements into right subarray
    for (j = 0; j < n2; j++)
        rightArr[j] = arr[mid + 1 + j];
    
    // Merge the two subarrays back into the main array
    i = 0;
    j = 0;
    k = left;

    // Compare elements from both subarrays and insert the smaller one into arr[]
    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    // Copy any remaining elements from the left subarray
    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    // Copy any remaining elements from the right subarray
    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

// Recursive function to implement mergesort
void performMergeSort(long int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;        // Find the middle index of the current segment
        performMergeSort(arr, left, mid);         // Recursively sort the left half of the array
        performMergeSort(arr, mid + 1, right);    // Recursively sort the right half of the array
        merge(arr, left, mid, right);               // Merge the two sorted halves
    }
}

// Quicksort
void quickSort(long int arr[], int N){
    clock_t start, end;
    start = clock();

    // Quicksort operation
    performQuickSort(arr, 0, N - 1);
    
    end = clock();
    cpu_time_used = ((double) (end-start)) / CLOCKS_PER_SEC;
}

// Recursive function to perform quicksort using the median-of-three method
void performQuickSort(long int arr[], int low, int high){
    if(low < high){
        int pi = partition(arr, low, high);     // Partition the array and get the pivot index
        performQuickSort(arr, low, pi-1);          // Recursively sort the left subarray (elements less than the pivot)
        performQuickSort(arr, pi+1, high);         // Recursively sort the right subarray (elements greater than the pivot)
    }
}

// Function to choose the pivot using the median-of-three method
long int medianOfThree(long int arr[], int low, int high) {
    int mid = low + (high - low) / 2;  // Calculate the middle index

    // Swap values to ensure arr[low] contains the median
    if (arr[mid] < arr[low])
        swap(&arr[mid], &arr[low]);
    if (arr[high] < arr[low])
        swap(&arr[high], &arr[low]);
    if (arr[mid] > arr[high])
        swap(&arr[mid], &arr[high]);

    // The median is now stored at arr[mid], so swap it with arr[low] to use as pivot
    swap(&arr[mid], &arr[low]);

    return arr[low];    // Return pivot value
}

// Function to create partitions for quicksort
long int partition(long int arr[], int low, int high) {
    int p = medianOfThree(arr, low, high);      // Use median of three as pivot
    int i = low + 1;
    int j = high;

    while (i <= j) {
        while (i <= high && arr[i] <= p) i++;   // Move right if smaller
        while (arr[j] > p) 
            j--;                                // Move left if larger
        if (i < j) swap(&arr[i], &arr[j]);      // Swap  elements
    }

    swap(&arr[low], &arr[j]);                   // Place pivot in its correct position
    return j;
}

// Function to swap two elements
void swap(long int *a, long int *b){
    unsigned int temp = *a;
    *a = *b;
    *b = temp;
}

// Heapsort
void heapSort(long int arr[], int N){
    clock_t start, end;
    start = clock();

    // Heapsort operation
    performHeapSort(arr, N);

    end = clock();
    cpu_time_used = ((double) (end-start)) / CLOCKS_PER_SEC;
}

// Recursive function to max-heapify the input array
void maxHeapify(long int arr[], int N, int i) {

    int largest = i;        // Initialize largest as root
    int left = 2 * i + 1;   // Left child
    int right = 2 * i + 2;  // Right child

    // If left child is larger than root
    if (left < N && arr[left] > arr[largest])
        largest = left;

    // If right child is larger than root
    if (right < N && arr[right] > arr[largest])
        largest = right;

    // If largest is not root, swap and continue heapifying
    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

    maxHeapify(arr, N, largest);
    }
}

// Function to build a max-heap from the given array
void buildMaxHeap(long int arr[], int N) {
    for (int i = N / 2 - 1; i >= 0; i--){
        maxHeapify(arr, N, i);
    }
}

// Function to perform heapsort
void performHeapSort(long int arr[], int N) {
    buildMaxHeap(arr, N);

    for (int i = N - 1; i > 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        maxHeapify(arr, i, 0);
    }
}

// Function to write the original and sorted data to the output file
void printArray(FILE *file, long int arr[], int N){
    for(int i = 0; i < N; i++){
        fprintf(file, "%lu ", arr[i]);
    }
    fprintf(file, "\n\t");
}
