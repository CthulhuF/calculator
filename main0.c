#include <stdio.h>
#include <stdlib.h>

/*
'+' - addition
'-' - substraction
'*' - multiplication
'/' - division
'^' - degree
'!' - factorial
'#' - exit

*/ //list of commands


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
            if (y==0){
                printf("division by zero");
                break;
            }
            return x / y;
        case '^': //degree
            z = x;
            for (int i=0;i<(y-1);i++) {
                z *= x;
            }
            return z;

        case '!': //factorial
            if (x <= 0) {
                printf("wrong number");
                break;
            }
            for (int i = 1; i <= x; i++) {
                z = z * i;
            }
            return z;

    }
} //SIMPLE OPERATIONS





int main() {

    char operation;
    puts("\nNow it's a scalar calculator");
    while (1 == 1) {
        puts("\nEnter the operation");
        scanf(" %c", &operation);

        if (operation == '#') {
            return 0;
        }

         else {
            printf(" %.2f", numb_operation(operation));
            continue;
        }
    }
} //main