//# created by Vrindavan Sanap
// All rights reserved
#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 1024
float A[N][N];
float B[N][N];
float C[N][N];
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

int main()
{
    printf("Running \n");
    for (int itr = 0; itr < 10; itr++)
    {
        double st = nanos();
        for (int y = 0; y < N; y++)
        {
            for (int x = 0; x < N; x++)
            {
                // printf("%d  %d \n", x, y);
                float acc = 0;
                for (int k = 0; k < N; k++)
                {
                    acc += A[y][k] * B[x][k];
                }
                C[y][x] = acc;
            }
        }
        double flops = N * N * 2.0 * N;
        double et = nanos();
        double s = ((et - st) * 1e-9); // * 1e-12;
        printf(" %f GFLOP/s \n", (flops / s) * 1e-9);
    }
    return 0;
}
