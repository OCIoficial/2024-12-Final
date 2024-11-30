import random
import sys

# The argument in position 1 is the hidden seed.
random.seed(sys.argv[1])

n = int(sys.argv[2])
max_a = int(sys.argv[3])

print(n)

print(" ".join([str(random.randint(0, max_a)) for _ in range(n)]))
