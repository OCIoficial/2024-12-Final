# Este script genera el random con intersección, es decir, para todas las subtareas menos la 2.
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
    # The argument in position 1 is the hidden seed.

    ascensores = int(sys.argv[2])
    altura = int(sys.argv[3])

    randomizar_ascensores = int(sys.argv[4])

    if randomizar_ascensores:
        ascensores = random.randint(0, ascensores)


    print(ascensores, altura)

    for i in range(ascensores):
        a = 0
        b = 0
        while (a == b):
            a = random.randint(1, altura)
            b = random.randint(1, altura)
            if (a > b):
                tmp = a
                a = b
                b = tmp
        print(a,b)
    sys.stdout.write(FS)
