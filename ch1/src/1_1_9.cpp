#include "ch1/fwd.h"

std::string BinaryString(size_t value) {
    size_t size {static_cast<size_t>(value ? 0 : 1)};
    for(size_t t {value}; t > 0; t >>= 1) {
        ++size;
    }
    std::string result (size, '0');
    for(size_t i {result.size() - 1}; value; value >>= 1, --i) {
        if (value & 1) {
            result[i] = '1';
        }
    }
    return std::move(result);
}
