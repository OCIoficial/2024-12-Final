import sys

n = int(sys.argv[2])

print(n)

print(" ".join([str(i) for i in range(n, 0, -1)]))
