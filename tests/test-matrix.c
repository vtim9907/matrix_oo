#include "matrix.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <malloc.h>

MatrixAlgo *matrix_providers[] = {                                                                                                                
    &NaiveMatrixProvider,
};

int main()
{
    MatrixAlgo *algo = matrix_providers[0];
    Mat data1, data2;
    Matrix dst, m, n, fixed;

    srand(time(NULL));
    for (int i = 0; i < M; ++i)
        for (int j = 0; j < N; ++j)
            data1.values[i][j] = rand() % 100;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < P; ++j)
            data2.values[i][j] = rand() % 100;

    algo->assign(&m, M, N, data1);
    algo->assign(&n, N, P, data2);
    algo->mul(&dst, &m, &n);

    return 0;
}
