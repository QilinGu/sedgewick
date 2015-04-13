#include "ch1/s1/ex_9.h"

namespace ch1 {
namespace s1 {
namespace ex9 {

std::string BinaryString(size_t value) {
    size_t max_bits {static_cast<size_t>(value ? 0 : 1)};
    for(size_t remainder {value}; remainder > 0; remainder >>= 1) {
        ++max_bits;
    }
    std::string result (max_bits, '0');
    for(size_t i {result.size() - 1}; value; value >>= 1, --i) {
        if (value & 1) {
            result[i] = '1';
        }
    }
    return std::move(result);
}

}  // namespace ex9
}  // namespace s1
}  // namespace ch1
