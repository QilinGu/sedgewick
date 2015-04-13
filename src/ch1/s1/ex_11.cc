#include "ch1/s1/ex_11.h"

#include <ostream>

namespace ch1 {
namespace s1 {
namespace ex11 {

// print matrix in one line: no delimiters, no new lines.  Row and col numbers
// are comma serapated.
std::ostream &operator <<(std::ostream &os, const BoolMatrix &matrix) {
    for(size_t row {0}; row < matrix.size(); ++row) {
        const auto &row_data = matrix[row];
        for(size_t col {0}; col < row_data.size(); ++col) {
            os << row << ',' << col;
            os << (row_data[col] ? '*' : ' ');
        }
    }
    return os;
}

}  // namespace ex11
}  // namespace s1
}  // namespace ch1
