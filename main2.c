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



void nmb_file(FILE *file, char op, FILE *result) {
    float a, b, r;
    if (op == '!')
        fscanf(file, "%f", &a);
    else
        fscanf(file, "%f %f", &a, &b);
    switch (op) {
        case '+':
            fprintf(result, "%.0f %c %.0f = %.0f", a, op, b, a + b);
            break;
        case '-':
            fprintf(result, "%.0f %c %.0f = %.0f", a, op, b, a - b);
            break;
        case '*':
            fprintf(result, "%.0f %c %.0f = %.0f", a, op, b, a * b);
            break;
        case '/':
            fprintf(result, "%.0f %c %.0f = %.0f", a, op, b, a / b);
            break;
        case '!':
            r = 1;
            for (int i = 1; i <= a; i++) {
                r = r * i;
            }
            fprintf(result, "%.0f ! = %.0f", a, r);
            break;
            break;
        case '^':
            r = a;
            if (b != 0) {
                for (int i = 1; i < b; i++) {
                    a = a * r;
                }
                fprintf(result, "%.0f ^ %.0f = %.0f", r, b, a);
            } else
                fprintf(result, "%.0f ^ %.0f = 1", r, b);
            break;
            break;

    }
}


void vct_file(FILE *file, char op, FILE *result) {
    float *V1, *V2;
    int size;
    fscanf(file, "%i", &size);
    V1 = calloc(size, sizeof(V1));
    V2 = calloc(size, sizeof(V2));
    for (int i = 0; i < size; i++)
        fscanf(file, "%f", &V1[i]);
    for (int i = 0; i < size; i++)
        fscanf(file, "%f", &V2[i]);
    float r = 0;
    switch (op) {
        case '+':
            fprintf(result, "(");
            for (int i = 0; i < size; i++) {
                if (i == size - 1)
                    fprintf(result, "%.0f", V1[i]);
                else
                    fprintf(result, "%.0f ", V1[i]);
            }
            fprintf(result, ") + (");
            for (int i = 0; i < size; i++) {
                if (i == size - 1)
                    fprintf(result, "%.0f", V2[i]);
                else
                    fprintf(result, "%.0f ", V2[i]);
            }
            fprintf(result, ") = (");
            for (int i = 0; i < size; i++) {
                if (i == size - 1)
                    fprintf(result, "%.0f", V1[i] + V2[i]);
                else
                    fprintf(result, "%.0f ", V1[i] + V2[i]);
            }
            fprintf(result, ")");
            break;
        case '-':
            fprintf(result, "(");
            for (int i = 0; i < size; i++) {
                if (i == size - 1)
                    fprintf(result, "%.0f", V1[i]);
                else
                    fprintf(result, "%.0f ", V1[i]);
            }
            fprintf(result, ") + (");
            for (int i = 0; i < size; i++) {
                if (i == size - 1)
                    fprintf(result, "%.0f", V2[i]);
                else
                    fprintf(result, "%.0f ", V2[i]);
            }
            fprintf(result, ") = (");
            for (int i = 0; i < size; i++) {
                if (i == size - 1)
                    fprintf(result, "%.0f", V1[i] - V2[i]);
                else
                    fprintf(result, "%.0f ", V1[i] - V2[i]);
            }
            fprintf(result, ")");
            break;
        case '*':
            for (int i = 0; i < size; i++)
                r = r + V1[i] * V2[i];
            fprintf(result, "<a,b> = %.0f", r);
            break;
    }
}



int main(void) {
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);
    char op, c;
    FILE *file, *result;
    file = fopen("input.txt", "r");
    result = fopen("output.txt", "w");
    while (!feof(file)) {
        fscanf(file, " %c %c", &op, &c);
        if (c == 'v') {
            vct_file(file, op, result);
        } else {
            nmb_file(file, op, result);
        }
        fprintf(result, "\n");
    }
    fclose(file);
    fclose(result);
    return EXIT_SUCCESS;
}
