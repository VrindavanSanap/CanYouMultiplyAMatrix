# created by Vrindavan Sanap
# all rights reserved

import time
import art
import numpy as np

N = 4096
arr = []
if __name__ == "__main__":
    art.tprint("GPU go brrrr")

    def matMul(N):
        # N*N matrix
        A = np.random.randn(N, N).astype(np.float32)
        # N*N matrix
        B = np.random.randn(N, N).astype(np.float32)
        # flops=N^2 output cells with 2N compute each
        flops = N*N*2*N

        st = time.monotonic()
        C = A@B
        et = time.monotonic()
        time_taken = (et-st)
        g_flops = flops/1e9
        g_flops_per_sec = g_flops/time_taken
        return g_flops_per_sec
    g_flops_per_sec_arr = []
    for i in range(10):
        g_flops_per_sec = matMul(N)
        print(f"({i+1}/10) ,{g_flops_per_sec:.2f} GFlops/s")
        g_flops_per_sec_arr.append(g_flops_per_sec)
    g_flops_per_sec_arr = np.array(g_flops_per_sec_arr)
    print(f"Mean: {g_flops_per_sec_arr.mean():.2f} GFlops/s")
    print(f"Std: {g_flops_per_sec_arr.std():.2f} GFlops/s")
