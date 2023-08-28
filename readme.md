# Can you multiply a matrix?

Based on a GeoHot stream "Can you multiply a matrix" 

Stream URL: https://www.youtube.com/watch?v=VgSQ1GOC86s

We are trying to implement the matrix multiplication algorithm in C thats
good enought to beat numpy for a 1024 by 1024 matrix

We will be using various techniques like Blocks to optimise cache use
and CPU intrinsics AVX instructions.

Instruction Set for Intel CPUs can be found on
https://www.intel.com/content/www/us/en/docs/intrinsics-guide/index.html

We also test performances of different frameworks that support matrix
multiplication

Benchmark: C = A @ B where both A and B are 4096 by 4096 float32
matrices