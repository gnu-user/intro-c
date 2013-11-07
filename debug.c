#include <stdio.h>

#define DEBUG

int main(void) {
#ifdef DEBUG
     printf("Debugging program\n");
#else
     printf("Running normally\n");
#endif
     return 0;
}