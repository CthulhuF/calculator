#include <stdio.h>
#include <stdlib.h>

/* 
'+' - addition \ 
'-' - substraction } also in vector calculator 
'*' - multiplication / (scalar multiplication in vector 
'/' - division 
'^' - degree 
'!' - factorial 
'#' - exit 
'~' - switch scalar / vector calculation 

*/ //COMMANDS 


float numb_operation(char operation){
    float z = 1;
    float x, y;
    puts("Enter the number");
    scanf("%f",&x);
    if (operation != '!'){
        puts("Enter the second number");
        scanf(" %f",&y);
    }
    switch (operation) { //simple operations
        case '+':
            return x + y;
        case '-':
            return x - y;
        case '*':
            return x * y;
        case '/':
            return x / y;
        case '^': //degree
            z = x;
            for (int i=0;i<(y-1);i++) {
                z *= x;
            }
            return z;

        case '!': //factorial
            for (int i=1;i<=x;i++) {
                z = z * i;
            }
            return z;
    }
} //SIMPLE OPERATIONS 

float vector_operation(char operation){
    float *A, *B, temp;
    const
    int size;
    printf("Enter size of array");
    scanf("%i", &size);
    A = malloc(size*sizeof(float));
    B = malloc(size*sizeof(float));

    printf("First vector:\n");
    for (int i=0; i < size; i++) {
        scanf("%f", &A[i]);
    }

    printf("Second vector:\n");
    for (int i=0; i < size; i++) {
        scanf("%f", &B[i]);
    }
    printf("size:""%i""\n", size);
    switch (operation) {
        case '+':
            for (int i = 0; i < size; i++) {
                A[i] = A[i] + B[i];
                printf("%f ", A[i]);
            }
            break;

        case '-':
            for (int i = 0; i < size; i++) {
                A[i] = A[i] - B[i];
                printf("%f ", A[i]);
            }
            break;

        case '*':
            for (int i = 0; i < size; i++) {
                A[i] = A[i] * B[i];
            }

            printf("%f", &A);
            break;

    }

}//VECTOR OPERATIONS




int main() {
    int switchCalc = 0;

    char operation;
    puts("\nNow it's a scalar calculator");
    while (1 == 1) {
        puts("\nEnter the operation");
        scanf(" %c", &operation);
        if (operation == '~') {
            if (switchCalc == 1) {
                switchCalc = 0;
                puts("\nNow it's a simple calculator");
                continue;
            } else {
                switchCalc = 1;
                puts("\nNow it's a vector calculator");
                continue;
            }
        }
        if (operation == '#') {
            return 0;
        }

        if (switchCalc == 0) {
            printf(" %.2f", numb_operation(operation));
            continue;
        }
        if (switchCalc == 1) {
            printf(" %a", vector_operation(operation));
            continue;
        }
    }
}//MAIN