# created by Vrindavan Sanap
# all rights reserved

import time
import numpy as np


N = 1024
arr = []
if __name__ == "__main__":
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

        s = (et-st)
        # print(f"{flops/1e9:.2f}:GFLOPS")
        # print(f"{s:.2f}:time")
        # print(f"{(flops/s)*1e-9:.2f} GFLOP/s")
        try:
            print(f"{(flops/s)*1e-9:.2f} GFLOP/s", f"{s:.5f}secs {i} ")
        except:
            pass
        arr.append(s)
    for i in range(20):
        matMul(N)
