import sys

n = int(sys.argv[2])
k = int(sys.argv[3])
tooth_direction = int(sys.argv[4])
teeth_direction = int(sys.argv[5])

assert k < n
assert tooth_direction in [-1, 1]
assert teeth_direction in [-1, 1]

teeth_start_range = range(0, k) if teeth_direction == 1 else reversed(range(0, k))
tooth_values = lambda i: range(i, n, k) if tooth_direction == 1 else reversed(range(i, n, k))

print(n)

applauses = [
    applos
    for i in teeth_start_range
    for applos in tooth_values(i)
]

print(" ".join([str(i) for i in applauses]))
