#!/usr/bin/python3


from time import time
import random
import ctypes
import os


def compute_min_code(sequence):
    mincode_lib = ctypes.cdll.LoadLibrary(os.path.abspath('libmincode.so'))
    mincode_lib.__c_style_computeMinCode.argtypes = [ctypes.c_uint64, ctypes.POINTER(ctypes.c_uint)]
    mincode_lib.__c_style_computeMinCode.restype = ctypes.POINTER(ctypes.c_uint)
    return mincode_lib.__c_style_computeMinCode(
        len(sequence),
        ctypes.cast(
            (ctypes.c_uint * len(sequence))(*sequence),
            ctypes.POINTER(ctypes.c_uint)
        )
    )[:len(sequence)]


def main():
    seq = []
    for i in range(10000):
        seq.append(random.randint(0, (1 << 32) - 1))

    start = time()
    compute_min_code(seq)
    print('ctypes min_code was computing for {} ms'.format((time() - start) * 1000))


if __name__ == '__main__':
    main()
