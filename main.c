//Cadag, Jaycee
//Dela Cruz, Mark 
//Espinas, A Z Rain
//Lovina, John Melrick
//Morcozo, Janna

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_RANGE 2^32

//Function Prototypes
void selectionSort ();
void bubbleSort ();
void insertionSort ();
void mergeSort ();
void quickSort ();
void copyquicksort();
void heapSort ();
void fprintarray();
void arrayincrementgenerator();
void arrayrandomgenerator();
void swap();
int sizearray();
long int partition();
long int medianOfThree();

//global var
FILE *file; 
double cpu_time_used;


//just for aesthetics
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
        for(long i = 0; i < 1010000; i++);
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
    int choice;
    int validInput;
    int size;
    int genarray;
    long int* arr;
    file = fopen("output.txt", "w");

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
        validInput = scanf("%d", &choice);

        // Clear input buffer
        while (getchar() != '\n');

        if (validInput != 1) {
            printf("\n\tInvalid input. Please enter a number between 0 and 9.");
            load();
            printf("\n\n");
            system("clear");
            continue;
        }

        size = sizearray();
        arr = malloc(size * sizeof(unsigned int));  // Dynamically allocate memory
        if (arr == NULL) {
            printf("Memory allocation failed.\n");
            return 1;  // Exit if memory allocation fails
        }

        printf("\n\n\tHow would you like your array to be generated?");
        printf("\n\t1) Random \n\t2) Incremental \n\tEnter your answer: ");
        scanf("%d", &genarray);

        if(genarray == 1)
            arrayrandomgenerator(arr, size);
        else if(genarray == 2)
            arrayincrementgenerator(arr, size);
        else
            printf("Invalid input.");

        fprintf(file, "\n\n\tOriginal array: ");
        fprintarray(file, arr, size);

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
                    quickSort(arr, 0, size-1);
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

            fprintf(file, "\n\n\tSorted array: ");
            fprintarray(file, arr, size);
            fprintf(file, "\n\tTime: %f", cpu_time_used);
            printf("\n\tTime: %f", cpu_time_used);

            printf("\n\n\tDo you want to run again? \n\t1) Try Again \n\t2) Exit \n\t3) Answer: ");
            int ans;
            scanf("%d", &ans);

            if(ans == 2)
                break;

        } else {
            printf("\n\tInvalid choice. Please enter a number between 0 and 9.");
            load();
            printf("\n\n");
            system("cls");
        }
    }
}

int sizearray(){
    int size;
    printf("\tEnter the size of your array: ");
    scanf("%d", &size);
    return size;
}

void swap(long int *a, long int *b){
    unsigned int temp = *a;
    *a = *b;
    *b = temp;
}

void arrayrandomgenerator(long int arr[], int size){
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        // Generate a random number between 0 and MAX_RANGE
        int random_number = rand() % (MAX_RANGE + 1);
        arr[i] = random_number;
    }
}


void arrayincrementgenerator(long int arr[], int size){
    int firstnum;
    printf("\tEnter the first number: ");
    scanf("%d", &firstnum);

    for(int i = 0; i < size; i++){
        arr[i] = firstnum;
        firstnum++;
    }
}


void fprintarray(FILE *file, long int arr[], int size){
    for(int i = 0; i < size; i++){
        fprintf(file, "%lu ", arr[i]);
    }
    fprintf(file, "\n\t");
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

void insertionSort (){
        //ask for number of inputs here





        clock_t start, end;
        start = clock();
    
        // start sorting operationhere
    
    
        end = clock();
        cpu_time_used = ((double) (end-start)) / CLOCKS_PER_SEC;
}

void mergeSort (){
        //ask for number of inputs here





        clock_t start, end;
        start = clock();
    
        // start sorting operationhere
    
    
        end = clock();
        cpu_time_used = ((double) (end-start)) / CLOCKS_PER_SEC;

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
        while (arr[j] > p) j--;                // Move left if larger
        
        if (i < j) swap(&arr[i], &arr[j]);  // Swap misplaced elements
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

void quickSort(long int arr[], int low, int high){
        clock_t start, end;
        start = clock();
        copyquicksort(arr, low, high);
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
