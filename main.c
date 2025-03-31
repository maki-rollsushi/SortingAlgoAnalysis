//Cadag, Jaycee
//Dela Cruz, Mark 
//Espinas, A Z Rain
//Lovina, John Melrick
//Morcozo, Janna

#include <stdio.h>
#include <time.h>

//Function Prototypes
void selectionSort (int[] input);
void bubbleSort (int[] input);
void insertionSort (int[] input);
void mergeSort (int[] input);
void quickSort (int[] input);
void heapSort (int[] input);




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
{
    system("clear"); 
    int choice;
    int validInput;

    while (1) {
        system("clear");
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
        printf("\n\t2. Bubble Sort\n");
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
                    return;                     
                    break;

        } else {
            printf("\n\tInvalid choice. Please enter a number between 0 and 9.");
            load();
            printf("\n\n");
            system("clear");
        }
    }
}
}

