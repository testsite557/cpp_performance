#!/usr/bin/python3


from time import time
import random
import mincode


def compute_min_code(sequence):
    return mincode.computeMinCode(sequence)


def main():
    seq = []
    for i in range(10000):
        seq.append(random.randint(0, (1 << 32) - 1))

    start = time()
    compute_min_code(seq)
    print('ctypes min_code was computing for {} ms'.format((time() - start) * 1000))


if __name__ == '__main__':
    main()
