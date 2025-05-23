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
void selectionSort ();
void bubbleSort ();
void insertionSort ();
void mergeSort ();
void quickSort ();
void heapSort ();

//global var
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
    int choice;
    int validInput;

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

        void maxHeapify(int arr[], int n, int i) { 

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
        void buildMaxHeap(int arr[], int n) {
            for (int i = n/2 - 1; i>= 0; i--){
                maxHeapify(arr, n, i);
            }
        }

        // function to perform Heap Sort
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

