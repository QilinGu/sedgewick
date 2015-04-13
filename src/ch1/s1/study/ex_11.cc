#include "ch1/s1/ex_11.h"

#include <ostream>

namespace ch1 {
namespace s1 {
namespace ex11 {

// print matrix in one line: no delimiters, no new lines.  Row and col numbers
// are comma serapated.
std::ostream &operator <<(std::ostream &os, const BoolMatrix &matrix) {
    return os;
}

}  // namespace ex11
}  // namespace s1
}  // namespace ch1
