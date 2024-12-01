#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int rows;
    int cols;
    float **data;
} matrix_t;

float relu(float x) {
    if (x <= 0) return 0;
    return x;
}

void dot(matrix_t a, matrix_t b, matrix_t out) {
    // assume len(a[0]) == len(b[0])
    int rows = a.rows;
    int cols = a.cols;
    for (int r=0; r<rows; r++) {
        for (int c=0; c<cols; c++) {
            out.data[r][0] += a.data[r][c] * b.data[r][c];
        }
    }
}

void printMatrix(matrix_t m) {
    int rows = m.rows;
    int cols = m.cols;
    for (int r=0; r<rows; r++) {
        for (int c=0; c<cols; c++) {
            printf("%f ", m.data[r][c]);
        }
        printf("\n");
    }
}

int main() {
    // w = torch.tensor([1.0, 1.0])
    matrix_t weights;
    weights.rows = 1;
    weights.cols = 2;
    weights.data = malloc(weights.rows * sizeof(float *));
    for (int r=0; r<weights.rows; r++) 
        weights.data[r] = malloc(weights.cols * sizeof(float));
    weights.data[0][0] = 2.0f;
    weights.data[0][1] = 2.0f;

    // x = torch.tensor([3.0, 7.0])
    matrix_t input;
    input.rows = 1;
    input.cols = 2;
    input.data = malloc(input.rows * sizeof(float *));
    for (int r=0; r<input.rows; r++) 
        input.data[r] = malloc(input.cols * sizeof(float));
    input.data[0][0] = 3.0f;
    input.data[0][1] = 7.0f;   

    // o = w @ x
    matrix_t out;
    out.rows = 1;
    out.cols = 1;
    out.data = malloc(out.rows * sizeof(float *));
    for (int r=0; r<out.rows; r++) 
        out.data[r] = malloc(out.cols * sizeof(float));
    dot(weights, input, out);

    // p = F.relu(o)
    float z = out.data[0][0];
    float o = relu(z);

    printf("%f", o);
}