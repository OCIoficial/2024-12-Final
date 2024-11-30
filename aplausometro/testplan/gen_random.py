import random
import sys

# The argument in position 1 is the hidden seed.
random.seed(sys.argv[1])

n = int(sys.argv[2])

print(n)

print(" ".join([str(random.randint(0, int(1e9))) for _ in range(n)]))
