#!/usr/bin/python3


from time import time
from numba import njit, prange
import random


@njit
def swap(code, var):
    total_swaps = 1 << var
    length = 1 << (5 - var)
    mask = (1 << (length >> 1)) - 1
    res = 0
    for i in range(total_swaps):
        lhs = code & mask << (length * (total_swaps - 1 - i) + (length >> 1))
        rhs = code & mask << length * (total_swaps - 1 - i)
        res |= lhs >> (length >> 1) | rhs << (length >> 1)
    return res


@njit
def min_code(code):
    return min(code, min([swap(code, i) for i in range(5)]))


@njit
def apply_to_range(seq):
    return list(map(min_code, seq))


@njit(parallel=True)
def compute_min_code(sequence):
    for i in prange(2):
        sequence[i * len(sequence) // 2: (i + 1) * len(sequence) // 2] = apply_to_range(sequence[i * len(sequence) // 2: (i + 1) * len(sequence) // 2])
    return sequence


def main():
    seq = []
    for i in range(10000):
        seq.append(random.randint(0, (1 << 32) - 1))

    compute_min_code(seq)

    start = time()
    compute_min_code(seq)
    print('njit min_code was computing for {} ms'.format((time() - start) * 1000))


if __name__ == '__main__':
    main()
