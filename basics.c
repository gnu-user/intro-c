#include <stdio.h>
#define AGE_INCREMENT 5
double square(int val);
typedef struct {
    char* name;
    int age;
} person;
typedef enum { red, blue, green } colour;

int main(void){
    person student;
    student.name = "Bob";
    student.age = 20;
    for (int i = 0; i < 10; ++i) {        
        switch (student.age) {
        case 20:
            printf("young\n");
            break;
        case 30:
            printf("forever 21\n");
            printf("Their age doubled: %f\n", square(student.age));
            break;
        default:
            break;
        }
        student.age += AGE_INCREMENT;
    } return 0;
}
double square(int val) {
    return (double) val * val;
}
