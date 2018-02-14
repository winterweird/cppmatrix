# C++ matrix

Made this during a lecture. Currently the matrix supports matrix multiplication.

## Usage

```cpp
#include "matrix.hpp"

//...

math::matrix<int> m1(iWidth, iHeight);
// or
math::matrix<int> m1(iWidth, iHeight, twoDimIntArray);
// or
math::matrix<int> m1(twoDimIntVector);

// to multiply two matrices:
// note that the width of m1 must be equal to the height of m2
// the template type must support addition and multiplication operators
math::matrix<int> mprod = m1.multiply(m2);

// to get a value:
int v = m1.get(iRow, iColumn);

// to set a value
m1.set(iRow, iColumn, value);

// to print the matrix:
// note: does not currently support proper alignment
// the matrix can be printed in this way to any ostream
std::cout << m1 << endl; // every row ends in a newline
```

An example of the usage of this program can be found in `src/main`.

### Compilation flags

The matrix class uses foreach-loops, and needs to be compiled with `-std=c++11`
or greater.

## On matrix multiplication

This is a very intuitive introduction to the subject of matrix multiplication:
https://www.mathsisfun.com/algebra/matrix-multiplying.html
