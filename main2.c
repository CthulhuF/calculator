#include <stdio.h>
#include <stdlib.h>


/*
 * 1-st sign - sign of operation
 * 2-nd sign - v/s vector or scalar calculator
 * 3-rd sign - number of coordinates
 * 4-th and next - numerical value of coordinates
 */

// please, manually create file "input.txt" in the appropriate folder of your project

// i can't provide multiplatform(ness(?)), i'm sorry (including for my english)



void nmb_file(FILE *input, char operation, FILE *output) {
    float a, b, r;
    if (operation == '!')
        fscanf(input, "%f", &a);
    else
        fscanf(input, "%f %f", &a, &b);
    switch (operation) {
        case '+':
            fprintf(output, "%.0f %c %.0f = %.0f", a, operation, b, a + b);
            break;
        case '-':
            fprintf(output, "%.0f %c %.0f = %.0f", a, operation, b, a - b);
            break;
        case '*':
            fprintf(output, "%.0f %c %.0f = %.0f", a, operation, b, a * b);
            break;
        case '/':
            fprintf(output, "%.0f %c %.0f = %.0f", a, operation, b, a / b);
            break;
        case '!':
            r = 1;
            for (int i = 1; i <= a; i++) {
                r = r * i;
            }
            fprintf(output, "%.0f ! = %.0f", a, r);
            break;
            break;
        case '^':
            r = a;
            if (b != 0) {
                for (int i = 1; i < b; i++) {
                    a = a * r;
                }
                fprintf(output, "%.0f ^ %.0f = %.0f", r, b, a);
            } else
                fprintf(output, "%.0f ^ %.0f = 1", r, b);
            break;
            break;

    }
}//SCALAR OPERATIONS


void vct_file(FILE *input, char operation, FILE *output) {
    float *V1, *V2;
    int size;
    fscanf(input, "%i", &size);
    V1 = calloc(size, sizeof(V1));
    V2 = calloc(size, sizeof(V2));
    for (int i = 0; i < size; i++)
        fscanf(input, "%f", &V1[i]);
    for (int i = 0; i < size; i++)
        fscanf(input, "%f", &V2[i]);
    float r = 0;
    switch (operation) {
        case '+':
            fprintf(output, "(");
            for (int i = 0; i < size; i++) {
                if (i == size - 1)
                    fprintf(output, "%.0f", V1[i]);
                else
                    fprintf(output, "%.0f ", V1[i]);
            }
            fprintf(output, ") + (");
            for (int i = 0; i < size; i++) {
                if (i == size - 1)
                    fprintf(output, "%.0f", V2[i]);
                else
                    fprintf(output, "%.0f ", V2[i]);
            }
            fprintf(output, ") = (");
            for (int i = 0; i < size; i++) {
                if (i == size - 1)
                    fprintf(output, "%.0f", V1[i] + V2[i]);
                else
                    fprintf(output, "%.0f ", V1[i] + V2[i]);
            }
            fprintf(output, ")");
            break;
        case '-':
            fprintf(output, "(");
            for (int i = 0; i < size; i++) {
                if (i == size - 1)
                    fprintf(output, "%.0f", V1[i]);
                else
                    fprintf(output, "%.0f ", V1[i]);
            }
            fprintf(output, ") + (");
            for (int i = 0; i < size; i++) {
                if (i == size - 1)
                    fprintf(output, "%.0f", V2[i]);
                else
                    fprintf(output, "%.0f ", V2[i]);
            }
            fprintf(output, ") = (");
            for (int i = 0; i < size; i++) {
                if (i == size - 1)
                    fprintf(output, "%.0f", V1[i] - V2[i]);
                else
                    fprintf(output, "%.0f ", V1[i] - V2[i]);
            }
            fprintf(output, ")");
            break;
        case '*':
            for (int i = 0; i < size; i++)
                r = r + V1[i] * V2[i];
            fprintf(output, "<a,b> = %.0f", r);
            break;
    }
}//VECTOR OPERATIONS



int main(void) {
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);
    char operation, c;
    FILE *input, *output;
    input = fopen("input.txt", "r");
    output = fopen("output.txt", "w");
    while (!feof(input)) {
        fscanf(input, " %c %c", &operation, &c);
        if (c == 'v') {
            vct_file(input, operation, output);
        } else {
            nmb_file(input, operation, output);
        }
        fprintf(output, "\n");
    }
    fclose(input);
    fclose(output);
    return EXIT_SUCCESS;
}//main
