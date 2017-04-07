#include "matrix.h"
#include <stdlib.h>
#include <stdio.h>

struct naive_priv {
    int **values;
};

#define PRIV(x) \
    ((struct naive_priv *) ((x)->priv))

static void assign(Matrix *thiz, int row, int col, Mat data)
{
    thiz->row = row;
    thiz->col = col;

    struct naive_priv *temp = malloc(sizeof(struct naive_priv));
    temp->values = (int **) malloc(row * sizeof(int *));
    for (int i = 0; i < row; ++i)
        temp->values[i] = (int *) malloc(col * sizeof(int));
    thiz->priv = temp;

    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            PRIV(thiz)->values[i][j] = data.values[i][j];
}

static const float epsilon = 1 / 10000.0;

static bool equal(const Matrix *l, const Matrix *r)
{
    for (int i = 0; i < l->row; i++)
        for (int j = 0; j < l->col; j++)
            if (PRIV(l)->values[i][j] + epsilon < PRIV(r)->values[i][j] ||
                    PRIV(r)->values[i][j] + epsilon < PRIV(l)->values[i][j])
                return false;
    return true;
}

bool mul(Matrix *dst, const Matrix *l, const Matrix *r)
{
    if (l->col != r->row) {
        printf("Wrong matrix size!");
        return false;
    }    
    dst->row = l->row;
    dst->col = r->col;

    struct naive_priv *temp = malloc(sizeof(struct naive_priv));
    temp->values = (int **) malloc(dst->row * sizeof(int *));
    for (int i = 0; i < dst->row; ++i)
        temp->values[i] = (int *) malloc(dst->col * sizeof(int));
    dst->priv = temp;

    for (int i = 0; i < dst->row; i++)
        for (int j = 0; j < dst->col; j++)
            for (int k = 0; k < N; k++)
                PRIV(dst)->values[i][j] += PRIV(l)->values[i][k] *
                                           PRIV(r)->values[k][j];
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < P; j++) {
            printf("%d ",PRIV(dst)->values[i][j]);
        }
        printf("\n");
    }
    return true;
}

MatrixAlgo NaiveMatrixProvider = {
    .assign = assign,
    .equal = equal,
    .mul = mul,
};
