#ifndef MATRIX_H_
#define MATRIX_H_

#include <stdbool.h>
#define M 10
#define N 9
#define P 12

/* predefined shortcut */
#define DECLARE_MATRIX(col, row) \
    typedef struct { int values[col][row]; } Mat
#if (M >= N && M >= P)
    DECLARE_MATRIX(M, M);
#elif (N >= M && N >= P)
    DECLARE_MATRIX(N, N);
#else
    DECLARE_MATRIX(P, P);
#endif

typedef struct {
    int row, col;
    void *priv;
} Matrix;

typedef struct {
    void (*assign)(Matrix *thiz, int row, int col, Mat);
    bool (*equal)(const Matrix *l, const Matrix *r);
    bool (*mul)(Matrix *dst, const Matrix *l, const Matrix *r);
} MatrixAlgo;

/* Available matrix providers */
extern MatrixAlgo NaiveMatrixProvider;

#endif /* MATRIX_H_ */
