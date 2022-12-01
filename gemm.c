// Created by Vrindavan Sanap
//  All rights reserved

#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <immintrin.h>
#include <assert.h>
#define N 1024

float A[N][N];
float B[N][N];
float C[N][N];

__m256 *An = (__m256 *)A;
__m256 *Bn = (__m256 *)B;
__m256 *Cn = (__m256 *)C;

double nanos(void)
{
    struct timespec ts;

    if (timespec_get(&ts, TIME_UTC) != TIME_UTC)
    {
        fputs("timespec_get failed!", stderr);
        return 0;
    }
    return 1000000000.0 * ts.tv_sec + ts.tv_nsec;
}

#define BLOCK 4
int main()
{
    printf("Running \n");
    for (int itr = 0; itr < 10; itr++)
    {
        double st = nanos();
        for (int by = 0; by < N; by += BLOCK)
        {
            for (int bx = 0; bx < N; bx += BLOCK)
            {
                for (int y = by; y < by + BLOCK; y++)
                {
                    for (int x = bx; x < bx + BLOCK; x++)
                    {

                        float acc = 0;
                        for (int k = 0; k < N; k++)
                        {
                            acc += A[y][k] * B[x][k];
                        }
                        C[y][x] = acc;
                    }
                }
            }
        }
        double flops = N * N * 2.0 * N;
        double et = nanos();
        double s = ((et - st) * 1e-9);
        printf(" %f GFLOP/s \n", (flops / s) * 1e-9);
    }
    return 0;
}
