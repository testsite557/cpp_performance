#pragma once

#include <vector>
#include <cstdint>

uint32_t swap(uint32_t code, uint32_t var);

uint32_t minCode(uint32_t code);

void applyToRange(
    std::vector<uint32_t>::iterator dest_begin,
    std::vector<uint32_t>::iterator dest_end,
    std::vector<uint32_t>::const_iterator src
);

std::vector<uint32_t> computeMinCode(std::vector<uint32_t> codes);
