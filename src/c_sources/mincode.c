#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <pthread.h>

uint32_t swap(uint32_t code, uint32_t var) {
    const uint32_t total_swaps = 1 << var;
    const uint32_t length = 1 << (5 - var);
    const uint32_t mask = (1 << (length >> 1)) - 1;
    uint32_t res = 0;
    for (uint32_t i = 0, lhs, rhs; i < total_swaps; ++i) {
        lhs = code & mask << (length * (total_swaps - 1 - i) + (length >> 1));
        rhs = code & mask << length * (total_swaps - 1 - i);
        res |= lhs >> (length >> 1) | rhs << (length >> 1);
    }
    return res;
}

typedef struct {
    size_t size;
    uint32_t *dest;
    const uint32_t *src;
} arguments_t;

uint32_t __c_style_minCode(uint32_t code) {
    uint32_t res = code;
    for (uint32_t i = 0; i < 5; ++i) {
        uint32_t swap_res = swap(code, i);
        res = swap_res < res ? swap_res : res;
    }
    return res;
}

void* __c_style_applyToRange(void *ptr) {
    arguments_t *arg_ptr = (arguments_t*)ptr;
    for (size_t i = 0; i < arg_ptr->size; ++i) {
        *arg_ptr->dest++ = __c_style_minCode(*arg_ptr->src++);
    }
    return NULL;
}

uint32_t* __c_style_computeMinCode(size_t size, const uint32_t *ptr) {
    uint32_t *res = (uint32_t*)malloc(size * sizeof(*res));
    pthread_t thread;
    arguments_t* args_first_half = (arguments_t*)malloc(sizeof(*args_first_half));
    args_first_half->size = size / 2;
    args_first_half->dest = res;
    args_first_half->src = ptr;
    if (pthread_create(&thread, NULL, __c_style_applyToRange, args_first_half)) {
        fprintf(stderr, "couldnt create pthread\n");
        fflush(stderr);
        __c_style_applyToRange(args_first_half);
    }
    arguments_t args_second_half = { (size + 1) / 2, res + size / 2, ptr + size / 2 };
    __c_style_applyToRange(&args_second_half);
    int status_addr;
    if (pthread_join(thread, (void**)&status_addr)) {
        fprintf(stderr, "couldnt join pthread\n");
        fflush(stderr);
    }
    free(args_first_half);
    return res;
}
