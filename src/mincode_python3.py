#!/usr/bin/python3


from multiprocessing import Pool
from time import time
import random


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


def min_code(code):
    return min(code, min([swap(code, i) for i in range(5)]))


def main():
    pool = Pool(processes=2)

    seq = []
    for i in range(10000):
        seq.append(random.randint(0, (1 << 32) - 1))

    start = time()
    pool.map(min_code, seq)
    print('python3 min_code was computing for {} ms'.format((time() - start) * 1000))


if __name__ == '__main__':
    main()
