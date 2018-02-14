#include <iostream>
#include <vector>
#include "matrix.hpp"

using namespace std;

int main() {
    vector< vector<int> > base1 = {
        {1,2,3},
        {4,5,6}
    };
    vector< vector<int> > base2 = {
        {7,8},
        {9,10},
        {11,12}
    };
    math::matrix<int> m1(base1);
    math::matrix<int> m2(base2);
    math::matrix<int> mprod = m1.multiply(m2);
    cout << mprod << endl;
}
