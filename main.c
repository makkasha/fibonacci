#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

#define N 100

uint64_t* fibonacci(uint64_t n){
    //Allocate a chunk of heap memory for the array
    uint64_t* array = (uint64_t*)calloc((int)N, sizeof(uint64_t));
    //Initialise the variables
    uint64_t t1 = 0, t2 = 1;
    if (array != NULL){//Error handling
        //Calculate the fibonacci numbers and store them in the array
        for (uint64_t i = 1; i < n; ++i) {
            uint64_t nextTerm = 1;
            nextTerm = t1 + t2;
            t1 = t2;
            t2 = nextTerm;
            *(array + i) = t1;
        }
        return array; //Returns a pointer to the first element of a dynamically allocated array of fibonacci numbers
    }
    else{
        return NULL;
    }

}

void print_array(uint64_t* array, uint64_t length){ //Function to print an array using pointers
    for(uint64_t i = 0; i < length; i++){
        printf("array[%llu]: %" PRIu64 "\n", i, *(array + i));
    }
}

int main() {
    print_array(fibonacci((int)N), (int)N);
    return 0;
}
