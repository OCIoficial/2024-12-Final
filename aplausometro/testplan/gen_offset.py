import sys

n = int(sys.argv[2])
offset = int(sys.argv[3])

assert offset < n

print(n)

applauses = [*range(offset, n), *range(0, offset)]

print(" ".join([str(i) for i in applauses]))
