#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFFER 128

void mem_leak(void);

int main(void) {
    char* name = NULL;
    int* age = NULL;
    name = (char*) calloc(BUFFER, sizeof(char)); // Allocate array using calloc
    age = (int*) malloc(sizeof(float)); // Allocate a float using malloc
    mem_leak(); // Creates memory leak allocated memory not freed
    printf("Enter your name: ");
    scanf("%s", name);
    printf("Enter your age: ");
    scanf("%d", age);
    // Arrays are like pointers, print each character of the name
    for (int i = 0; i < strlen(name); ++i) { // strlen fail if didn't use calloc!
        printf("%c\n", name[i]);
    }
    // Don't forget to free the memory. Can't free munch don't have pointer!
    free(name), free(age);
    return 0;
}
// This function creates memory leaks, should return the munch pointer!
void mem_leak(void) {
    char* munch = NULL;
    munch = (char*) calloc(BUFFER * 1000, sizeof(char));
}
