//Cadag, Jaycee
//Dela Cruz, Mark
//Espinas, A Z Rain
//Lovina, John Melrick
//Morcozo, Janna

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//Function Prototypes
void selectionSort();
void bubbleSort();
void insertionSort();
void mergeSort();
void merge();
void mergeSortRecursive();
void quickSort();
void copyquicksort();
long int medianOfThree();
long int partition();
void heapSort();
void maxHeapify();
void buildMaxHeap();
void performHeapSort();

//Helper functions
void swap();
int sizearray();
void arrayrandomgenerator(long int arr[], int size);
void arrayincrementgenerator(long int arr[], int size);
void printarray(FILE *file, long int arr[], int size);
void initArrayAndGet(long int arr[], int size);

//global var
double cpu_time_used;
#define Max_Range 1000000

//just for aesthetics
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

int main() {
    system("cls");
    FILE *file; 
    file = fopen("output.txt", "w");
    int choice;
    int validInput;
    char cont; 
    int size;
    long int *arr;

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
        printf("\t4. Merge Sort\n");
        printf("\t5. Quicksort\n");
        printf("\t6. HeapSort\n");
        printf("\t0. Exit\n\n");

        printf("\n\tEnter your choice: ");
        validInput = scanf("%d", &choice);

        if(choice == 0){
            printf("\n\tExiting...");
            load();
            return 0;
            break;
        }

        // Clear input buffer
        while (getchar() != '\n');

        if (validInput != 1) {
            printf("\n\tInvalid input. Please enter a number between 0 and 9.");
            load();
            printf("\n\n");
            continue;
        }

        
        size = sizearray();
        arr = malloc(size * sizeof(unsigned int));  // Dynamically allocate memory
        if (arr == NULL) {
            printf("Memory allocation failed.\n");
            return 1;  // Exit if memory allocation fails
        }
        initArrayAndGet(arr, size);
        
        fprintf(file, "\n\tOriginal array: ");
        printarray(file, arr, size);

        if (choice >= 0 && choice <= 9) {
            switch (choice) {
            case 1:
                selectionSort(arr, size);
                break;
            case 2:
                bubbleSort(arr, size);
                break;
            case 3:
                insertionSort(arr, size);
                break;
            case 4:
                mergeSort(arr, size);
                break;
            case 5:
                quickSort(arr, size);
                break;
            case 6:
                heapSort(arr, size);
                break;
            }

            fprintf(file, "\n\n\tSorted array: ");
            printarray(file, arr, size);
            fprintf(file, "\n\tTime: %f", cpu_time_used);
            printf("\n\tTime: %f", cpu_time_used);
            free(arr);

            printf("\n\tDo you want to try again? (Y/N): ");
            scanf(" %c", &cont);

            if(cont == 'N'){
                printf("\n\tExiting...");
                load();
                return 0;
                break;
            }
            system("cls");
            
        } else {
            printf("\n\tInvalid choice. Please enter a number between 0 and 9.");
            load();
            printf("\n\n");
        }
    }
}

void initArrayAndGet(long int arr[], int size) {
        long int genarray;
        do{
            printf("\n\tHow would you like your array to be generated?");
            printf("\n\t1) Random \n\t2) Incremental \n\tEnter your answer: ");
            scanf("%d", &genarray);
            if(genarray != 1 && genarray != 2){
                printf("\n\tInvalid input. please input 1 or 2.\n");
            }
        }while(genarray != 1 && genarray != 2);

        if (genarray == 1)
            arrayrandomgenerator(arr, size);
        else
            arrayincrementgenerator(arr, size);
}

void selectionSort(long int arr[], int size){
        clock_t start, end;
        start = clock();

        // start sorting operationhere
        int i, j, minIndex, temp;
        for (i = 0; i < size - 1; i++) {
            // Find the index of the smallest (minimum) element
            minIndex = i;
            for (j = i + 1; j < size; j++) {
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

void bubbleSort(long int arr[], int size){
        clock_t start, end;
        start = clock();

        // start sorting operationhere
        for (int i = 0; i < size - 1; i++) {
            for (int j = 0; j < size - i - 1; j++) {
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

void insertionSort(long int arr[], int size){

        clock_t start, end;
        start = clock();

        // insertion sort
        for (int i = 1; i < size; i++) {
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

void mergeSort(long int arr[], int size){
        clock_t start, end;
        start = clock();
        mergeSortRecursive(arr, 0, size-1);
        end = clock();
        cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
}

// merge sort
void merge(long int arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    long int leftArr[n1], rightArr[n2];

    for (i = 0; i < n1; i++)
        leftArr[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        rightArr[j] = arr[mid + 1 + j];

    i = 0;
    j = 0;
    k = left;
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

    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

void mergeSortRecursive(long int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSortRecursive(arr, left, mid);
        mergeSortRecursive(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

void swap(long int *a, long int *b){
    unsigned int temp = *a;
    *a = *b;
    *b = temp;
}

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

    return arr[low];  // Return pivot value
}

long int partition(long int arr[], int low, int high) {
    int p = medianOfThree(arr, low, high);  // Used median of three as pivot
    int i = low + 1;
    int j = high;

    while (i <= j) {
        while (i <= high && arr[i] <= p) i++;  // Move right if smaller
        while (arr[j] > p) 
            j--;                // Move left if larger
        if (i < j) swap(&arr[i], &arr[j]);  // Swap  elements
    }

    swap(&arr[low], &arr[j]);  // Place pivot in its correct position
    return j;
}

void copyquicksort(long int arr[], int low, int high){
    if(low < high){
        int pi = partition(arr, low, high);
        copyquicksort(arr, low, pi-1);
        copyquicksort(arr, pi+1, high);
    }
}

void quickSort(long int arr[], int size){
        clock_t start, end;
        start = clock();
        copyquicksort(arr, 0, size-1);
        end = clock();
        cpu_time_used = ((double) (end-start)) / CLOCKS_PER_SEC;
}

void maxHeapify(long int arr[], int n, int i) {

    int largest = i; // initialize largest as root
    int left = 2 * i + 1; //left child
    int right = 2 * i + 2; //right child

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

// function to build a Max-Heap from the given array
void buildMaxHeap(long int arr[], int n) {
    for (int i = n/2 - 1; i>= 0; i--){
        maxHeapify(arr, n, i);
    }
}

// function to perform Heap Sort
void performmHeapSort(long int arr[], int n) {
    buildMaxHeap(arr, n);

    for (int i = n - 1; i > 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        maxHeapify(arr, i, 0);
    }
}

void heapSort(long int arr[], int size){
        clock_t start, end;
        start = clock();
        performmHeapSort(arr, size);
        end = clock();
        cpu_time_used = ((double) (end-start)) / CLOCKS_PER_SEC;
}

int sizearray() {
    int size;
    printf("\n\tEnter the size of your array: ");
    scanf("%d", &size);
    return size;
}

void arrayrandomgenerator(long int arr[], int size) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        int random_number = rand() % (Max_Range + 1);
        arr[i] = random_number;
    }
}

void arrayincrementgenerator(long int arr[], int size) {
    int firstnum;
    printf("\n\tEnter the first number: ");
    scanf("%d", &firstnum);

    for (int i = 0; i < size; i++) {
        arr[i] = firstnum;
        firstnum++;
    }
}

void printarray(FILE *file, long int arr[], int size){
    for(int i = 0; i < size; i++){
        fprintf(file, "%lu ", arr[i]);
    }
    fprintf(file, "\n\t");
}