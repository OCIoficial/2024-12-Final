# This script generates random n*m matrix
import random
import sys

# The argument in position 1 is the hidden seed.
random.seed(sys.argv[1])

N = int(sys.argv[2])
M = int(sys.argv[3])
K = int(sys.argv[4])

def generate_matrix(n, m, t):
    if t > n * m:
        raise ValueError("Number of zeroes cannot exceed the total number of elements in the matrix.")

    elements = [0] * t + [1] * (n * m - t)
    random.shuffle(elements)

    matrix = [elements[i * m:(i + 1) * m] for i in range(n)]
    return matrix

zeros = random.randint(K+1, N*M)
matrix = generate_matrix(N, M, zeros)
print(N, M, K)
for i in range(N):
    s = [str(x) for x in matrix[i]]
    print(" ".join(s))
