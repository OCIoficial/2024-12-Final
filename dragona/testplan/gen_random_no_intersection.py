# Este script genera el random sin intersección y ordenando el output, es decir, está hecho para st2
# La entrada es:
# semilla, cantidad de ascensores, altura del edificio, randomizar
# Si randomizar es 1, entonces la cantidad de ascensores es random entre 1 y el límite impuesto. De lo contrario, es la cantidad impuesta.

import random
import sys

# We use the file separator control code to signal the end of a test case.
# https://en.wikipedia.org/wiki/C0_and_C1_control_codes#Field_separators
FS = chr(28)

random.seed(sys.argv[1])
cases = int(sys.argv[5])
for i in range(cases):

    ascensores = int(sys.argv[2])
    altura = int(sys.argv[3])

    # Condición necesaria para que exista un caso sin intersecciones
    assert ascensores <= altura//2

    randomizar_ascensores = int(sys.argv[4])

    if randomizar_ascensores:
        ascensores = random.randint(0, ascensores)

    ans = random.sample(range(1,altura+1), 2*ascensores)
    ans.sort()

    print(ascensores, altura)

    for i in range(0, len(ans), 2):
        print(ans[i], ans[i+1])
    sys.stdout.write(FS)
