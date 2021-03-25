#include "mincode.h"

#include <future>

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

uint32_t minCode(uint32_t code) {
    uint32_t res = code;
    for (uint32_t i = 0; i < 5; ++i) {
        res = std::min(res, swap(code, i));
    }
    return res;
}

void applyToRange(std::vector<uint32_t>::iterator dest_begin,
    std::vector<uint32_t>::iterator dest_end,
    std::vector<uint32_t>::const_iterator src)
{
    for (auto it = dest_begin; it != dest_end; ++it) {
        *it = minCode(*src++);
    }
}

std::vector<uint32_t> computeMinCode(std::vector<uint32_t> codes) {
    constexpr uint32_t threadsQuantity = 2;
    const uint32_t chunkLength = (codes.size() + threadsQuantity - 1) / threadsQuantity;
    std::vector<uint32_t> res(codes.size());
    std::vector<std::future<void>> threads;
    for (uint32_t i = 0; i < threadsQuantity; ++i) {
        threads.push_back(std::async(
            applyToRange,
            res.begin() + i * chunkLength,
            std::min(res.begin() + (i + 1) * chunkLength, res.end()),
            codes.begin() + i * chunkLength
        ));
    }
    return res;
}
