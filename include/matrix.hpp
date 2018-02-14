#ifndef INCLUDE_MATRIX_HPP_HEADER_GUARD_59262631831472
#define INCLUDE_MATRIX_HPP_HEADER_GUARD_59262631831472

#include <iostream>
#include <string>
#include <vector>

namespace math {

    template <class T>
    class matrix {
       public:
        matrix(int width, int height) : w(width), h(height) {
            if (width < 1) throw std::runtime_error("matrix cannot be narrower than 1");
            if (height < 1) throw std::runtime_error("matrix cannot be shorter than 1");

            m.resize(height);
            for (auto& row : m) {
                row.resize(width);
            }
        }
        matrix(const std::vector<std::vector<T> >& m) {
            if (m.size() < 1)
                throw std::runtime_error("matrix cannot be shorter than 1");
            this->m.resize(m.size());
            size_t sz = m[0].size();
            if (sz < 1) throw std::runtime_error("matrix cannot be narrower than 1");

            h = m.size();
            w = sz;

            for (size_t i = 0; i < m.size(); i++) {
                auto row = m[i];
                if (row.size() != sz)
                    throw std::runtime_error("inconsistent row width: " + std::to_string(sz) +
                                        " vs " + std::to_string(row.size()));

                this->m[i] = row;
            }
        }
        matrix(int width, int height, const T** m) : w(width), h(height) {
            if (width < 1) throw std::runtime_error("matrix cannot be narrower than 1");
            if (height < 1) throw std::runtime_error("matrix cannot be shorter than 1");

            this->m.resize(height);
            for (int i = 0; i < height; i++) {
                this->m[i].resize(width);
                for (int j = 0; j < width; j++) {
                    this->m[i][j] = m[i][j];
                }
            }
        }

        matrix multiply(const matrix& other) const {
            if (w != other.h)
                throw std::runtime_error("incompatible matrix sizes: " + std::to_string(w) +
                                    "x" + std::to_string(h) + " vs " +
                                    std::to_string(other.w) + "x" + std::to_string(other.h));

            matrix ret(other.w, h);
            for (int i = 0; i < h; i++) {
                for (int j = 0; j < other.w; j++) {
                    T sum = m[i][0] * other.m[0][j];
                    for (int k = 1; k < other.h; k++) {
                        sum = sum + m[i][k] * other.m[k][j];
                    }
                    ret.m[i][j] = sum;
                }
            }
            return ret;
        }

        T get(int i, int j) const {
            if (i < 0 || i >= h)
                throw std::runtime_error("invalid row index: " + std::to_string(i));
            if (j < 0 || j > w)
                throw std::runtime_error("invalid column index: " + std::to_string(j));
            return m[i][j];
        }

        void set(int i, int j, T val) {
            if (i < 0 || i >= h)
                throw std::runtime_error("invalid row index: " + std::to_string(i));
            if (j < 0 || j >= w)
                throw std::runtime_error("invalid column index: " + std::to_string(j));
            m[i][j] = val;
        }

        int getWidth() const { return w; }

        int getHeight() const { return h; }

       private:
        int w, h;
        std::vector<std::vector<T> > m;
    };
}

template <class T>
std::ostream& operator<<(std::ostream& os, const math::matrix<T>& m) {
    for (int i = 0; i < m.getHeight(); i++) {
        for (int j = 0; j < m.getWidth(); j++) {
            os << m.get(i, j) << " ";
        }
        os << std::endl;
    }
    return os;
}

#endif /* INCLUDE_MATRIX_HPP_HEADER_GUARD_59262631831472 */
