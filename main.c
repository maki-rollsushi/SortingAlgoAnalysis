// Cadag, Jaycee
// Dela Cruz, Mark 
// Espinas, A Z Rain
// Lovina, John Melrick
// Morcozo, Janna Carla

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_RANGE 1000000

// Function Prototypes
// Sorting Algorithms
void selectionSort (long int array[], int N);
void bubbleSort (long int array[], int N);
void insertionSort ();
void mergeSort ();
void quickSort ();
void heapSort ();

// Global Variable
double cpu_time_used;

// Data Generation Methods
// Random Number Generator
void generateRandomNumbers(long int array[], int N) {
    srand(time(0));
    for (int i = 0; i < N; i++) {
        array[i] = rand() % (MAX_RANGE + 1);
    }
}

// Increasing Sequence
void generateIncreasingSequence(long int array[], int N, int X) {
    for (int i = 0; i < N; i++) {
        array[i] = X + i;
    }
}

// Functions for aesthetics
void load(void){
    int dots = 0;
    while (dots < 6) {
        printf(".");      
        fflush(stdout);     
        for (long i = 0; i < 101000000; i++);
            dots++;
    }
    printf("\n");
}
void loadFast(void){
    int dots = 0;
    while (dots < 5) {          
        for (long i = 0; i < 1010000; i++);
            dots++;
    }
}
void printCenter(char* text) {
    int width = 80;  
    int len = strlen(text);


    int padding = (width-len)/2;
    // Print the padding
    for (int i =0; i < padding; i++) {
        printf(" ");
    }
    
    // Print the text
    loadFast();
    printf("%s\n", text);
}

int main(){
    system("cls"); 
    int N, X, choiceS, choiceN, choiceD;
    int validInput;

    // Open output file
    FILE *ofp = fopen("output.txt", "w");
    if (!ofp) {
        printf("Error opening file!\n");
        return 1;
    }

    while (1) {
        system("cls");
        printf("\n\n");

        // Display title
        char* title[] = {
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
        printf("\t4. Merge Sort\n");
        printf("\t5. Quicksort\n");
        printf("\t6. HeapSort\n");
        printf("\t0. Exit\n\n");

        printf("\n\tEnter your choice: ");
        
        validInput = scanf("%d", &choiceS);

        // Clear input buffer
        while (getchar() != '\n');

        if (validInput != 1) {
            printf("\n\tInvalid input. Please enter a number between 0 and 9.");
            load();
            printf("\n\n");
            system("clear");
            continue;
        }

        // Prompt user to enter the number of integers (N) to be sorted
        while (1) {
            printf("\nSelect number of integers (N) to be sorted:");
            printf("\n1. 10      4. 10000");
            printf("\n2. 100     5. 100000");
            printf("\n3. 1000    6. 1000000");
            printf("\nEnter your choice: ");
            scanf("%d", &choiceN);

            switch (choiceN) {
                case 1: N = 10;
                    break;
                case 2: N = 100;
                    break;
                case 3: N = 1000;
                    break;
                case 4: N = 10000;
                    break;
                case 5: N = 100000;
                    break;
                case 6: N = 1000000;
                    break;
                default: printf("\nInvalid choice. Please enter a number between 1 and 6.\n");
                    load();
                    continue;
            }
            break;
        }
        
        // Declare array with size N
        long int input[N];

        // Select data generation method
        while (1) {
            printf("\nData Generation Method");
            printf("\n1. Randomly Generated Integers");
            printf("\n2. Increasing Sequence");
            printf("\n0. Exit");
            printf("\nEnter your choice: ");
            scanf("%d", &choiceD);

            if (choiceD == 0) {
                printf("\nExiting program...\n");
                return 0;
            } else if (choiceD == 1) {
                generateRandomNumbers(input, N);
                break;
            } else if (choiceD == 2) {
                printf("\nEnter the starting value of the sequence: ");
                scanf("%d", &X);
                generateIncreasingSequence(input, N, X);
                break;
            } else {
                printf("\n\tInvalid choice. Please enter a number between 0 and 2.\n");
                load();
            }
        }

        // Write original data to output file
        fprintf(ofp, "Original Data: ");
        for (int i = 0; i < N; i++) {
            fprintf(ofp, "%d ", input[i]);
        }
        fprintf(ofp, "\n\n");

        if (choiceS >= 0 && choiceS <= 9) {
            switch (choiceS) {
                case 1:
                    selectionSort(input, N);
                    printf("\nSelection Sort Time: %.2f seconds\n", cpu_time_used);

                    // Write sorted data to output file
                    fprintf(ofp, "Sorted Data using Selection Sort: ");
                    for (int i = 0; i < N; i++) {
                        fprintf(ofp, "%d ", input[i]);
                    }
                    fprintf(ofp, "\n");
                    break;
                case 2:
                    bubbleSort(input, N);
                    printf("\nBubble Sort Time: %.2f seconds\n", cpu_time_used);
                    break;
                case 3:
                    insertionSort();
                    break;
                case 4:
                    mergeSort();
                    break;
                case 5:
                    quickSort();
                    break;
                case 6:
                    heapSort();
                    break;
                case 0:
                    printf("\n\tExiting...");
                    load();
                    system("clear");
                    return 0;                     
                    break;
            }
        } else {
            printf("\n\tInvalid choice. Please enter a number between 0 and 9.");
            load();
            printf("\n\n");
            system("cls");
        }
    }
}

void selectionSort (long int array[], int N) {
    clock_t start, end;
    start = clock();

    int i, j, minIndex, temp;
    for (i = 0; i < N - 1; i++) {
        // Find the index of the smallest (minimum) element
        minIndex = i;
        for (j = i + 1; j < N; j++) {
            if (array[j] < array[minIndex]) {
                minIndex = j;
            }
        }
        // Swap the smallest element with the current element
        temp = array[i];
        array[i] = array[minIndex];
        array[minIndex] = temp;
    }

    end = clock();
    cpu_time_used = ((double) (end-start)) / CLOCKS_PER_SEC;
}
void bubbleSort (long int array[], int N) {
        clock_t start, end;
        start = clock();

        for (int i = 0; i < N - 1; i++) {
            for (int j = 0; j < N - i - 1; j++) {
                // Compare adjacent elements
                if (array[j] > array[j + 1]) {
                    // Swap if the current element is greater than the next element
                    int temp = array[j];
                    array[j] = array[j + 1];
                    array[j + 1] = temp;
                }   
            }
        }
    
        end = clock();
        cpu_time_used = ((double) (end-start)) / CLOCKS_PER_SEC;
}
void insertionSort () {
        //ask for number of inputs here





        clock_t start, end;
        start = clock();
    
        // start sorting operation here
    
    
        end = clock();
        cpu_time_used = ((double) (end-start)) / CLOCKS_PER_SEC;

}
void mergeSort () {
        //ask for number of inputs here





        clock_t start, end;
        start = clock();
    
        // start sorting operation here
    
    
        end = clock();
        cpu_time_used = ((double) (end-start)) / CLOCKS_PER_SEC;

}
void quickSort () {
        //ask for number of inputs here





        clock_t start, end;
        start = clock();
    
        // start sorting operation here
    
    
        end = clock();
        cpu_time_used = ((double) (end-start)) / CLOCKS_PER_SEC;

}
void heapSort () {
    clock_t start, end;
    start = clock();

    void maxHeapify(int arr[], int n, int i) { 
        int largest = i; // initialize largest as root
        int left = 2 * i + 1; // left child
        int right = 2 * i + 2; // right child
        
        // if left child is larger than root
        if (left < n && arr[left] > arr[largest])
            largest = left;

        // if right child is larger than root
        if (right < n && arr[right] > arr[largest])
            largest = right;
        
        // if largest is not root, swap and continue heapifying
        if (largest != i) {
            int temp = arr[i];
            arr[i] = arr[largest];
            arr[largest] = temp;

            maxHeapify(arr, n, largest);
        }
    }

    // Function to build a Max-Heap from the given array
    void buildMaxHeap(int arr[], int n) {
        for (int i = n/2 - 1; i>= 0; i--){
            maxHeapify(arr, n, i);
        }
    }

    // Function to perform Heap Sort
    performmHeapSort(int arr[], int n) {
        buildMaxHeap(arr, n);

        for (int i = n - 1; i > 0; i--) {
            int temp = arr[0];
            arr[0] = arr[i];
            arr[i] = temp;

            maxHeapify(arr, i, 0);
        }
    }

    end = clock();
    cpu_time_used = ((double) (end-start)) / CLOCKS_PER_SEC;
}

