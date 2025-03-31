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
void merge(int arr[], int left, int mid, int right);
void quickSort();
void heapSort();

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

//Helper functions
int sizearray();
void arrayrandomgenerator(int arr[], int size);
void arrayincrementgenerator(int arr[], int size);
void printarray(int arr[], int size);
int* initArrayAndGet(int* size_ptr);

int main() {
    system("cls");
    int choice;
    int validInput;

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

        // Clear input buffer
        while (getchar() != '\n');

        if (validInput != 1) {
            printf("\n\tInvalid input. Please enter a number between 0 and 9.");
            load();
            printf("\n\n");
            continue;
        }

        if (choice >= 0 && choice <= 9) {
            switch (choice) {
            case 1:
                selectionSort();
                break;
            case 2:
                bubbleSort();
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
                return 0;
                break;
            }

        } else {
            printf("\n\tInvalid choice. Please enter a number between 0 and 9.");
            load();
            printf("\n\n");
        }
    }
}

int* initArrayAndGet(int* size_ptr) {
    *size_ptr = sizearray();
    int *arr = malloc(*size_ptr * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return NULL;
    }
    int genarray;
    printf("How would you like your array to be generated?");
    printf("\n1) Random \n2) Incremental \nEnter your answer: ");
    scanf("%d", &genarray);

    if (genarray == 1)
        arrayrandomgenerator(arr, *size_ptr);
    else if (genarray == 2)
        arrayincrementgenerator(arr, *size_ptr);
    else
        printf("Invalid input.");

    printf("Original array: ");
    printarray(arr, *size_ptr);
    return arr;
}

void selectionSort (){

    //ask for number of inputs here





    clock_t start, end;
    start = clock();

    // start sorting operationhere


    end = clock();
    cpu_time_used = ((double) (end-start)) / CLOCKS_PER_SEC;
}
void bubbleSort (){
        //ask for number of inputs here





        clock_t start, end;
        start = clock();

        // start sorting operationhere


        end = clock();
        cpu_time_used = ((double) (end-start)) / CLOCKS_PER_SEC;

}
void insertionSort() {
        int size;
        int *arr = initArrayAndGet(&size);
        if (arr == NULL) return;

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

        printf("Sorted array: ");
        printarray(arr, size);
        printf("Time: %f\n", cpu_time_used);
        free(arr);
}

void mergeSort() {
        int size;
        int *arr = initArrayAndGet(&size);
        if (arr == NULL) return;

        clock_t start, end;
        start = clock();

        // merge sort
        void mergeSortRecursive(int arr[], int left, int right) {
            if (left < right) {
                int mid = left + (right - left) / 2;
                mergeSortRecursive(arr, left, mid);
                mergeSortRecursive(arr, mid + 1, right);
                merge(arr, left, mid, right);
            }
        }
        mergeSortRecursive(arr, 0, size - 1);

        end = clock();
        cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("Sorted array: ");
        printarray(arr, size);
        printf("Time: %f\n", cpu_time_used);
        free(arr);
}

void merge(int arr[], int left, int mid, int right) {
        int i, j, k;
        int n1 = mid - left + 1;
        int n2 = right - mid;

        int leftArr[n1], rightArr[n2];

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
void quickSort (){
        //ask for number of inputs here





        clock_t start, end;
        start = clock();

        // start sorting operationhere


        end = clock();
        cpu_time_used = ((double) (end-start)) / CLOCKS_PER_SEC;

}
void heapSort (){
        //ask for number of inputs here





        clock_t start, end;
        start = clock();

        // start sorting operationhere


        end = clock();
        cpu_time_used = ((double) (end-start)) / CLOCKS_PER_SEC;

}

int sizearray() {
    int size;
    printf("Enter the size of your array: ");
    scanf("%d", &size);
    return size;
}

void arrayrandomgenerator(int arr[], int size) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        int random_number = rand() % (Max_Range + 1);
        arr[i] = random_number;
    }
}

void arrayincrementgenerator(int arr[], int size) {
    int firstnum;
    printf("Enter the first number: ");
    scanf("%d", &firstnum);

    for (int i = 0; i < size; i++) {
        arr[i] = firstnum;
        firstnum++;
    }
}

void printarray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
