#include <algorithm>
#include <iostream>
#include <vector>

template<typename T>
class MathVector {
private:
    std::vector<T> data;

public:
    explicit MathVector(size_t n) {
        data.resize(n);
    }

    template<typename Iter>
    MathVector(Iter first, Iter last) {
        while (first != last) {
            data.push_back(*first);
            ++first;
        }
    }

    size_t Dimension() const {
        return data.size();
    }

    T &operator[](size_t i) {
        return data[i];
    }

    const T &operator[](size_t i) const {
        return data[i];
    }
};

template<typename T>
std::ostream &operator<<(std::ostream &out, const MathVector<T> &v) {
    out << '(';
    if (v.Dimension() == 0) {
        out << ')';
        return out;
    }
    for (size_t i = 0; i != v.Dimension() - 1; ++i) {
        out << v[i] << ", ";
    }
    out << v[v.Dimension() - 1] << ')';
    return out;
}

template<typename T>
MathVector<T> &operator*=(MathVector<T> &v, const T &scalar) {
    for (size_t i = 0; i != v.Dimension(); ++i) {
        v[i] *= scalar;
    }
    return v;
}

template<typename T>
MathVector<T> operator*(const MathVector<T> &v, const T &scalar) {
    auto tmp(v);
    tmp *= scalar;
    return tmp;
}

template<typename T>
MathVector<T> operator*(const T &scalar, const MathVector<T> &v) {
    return v * scalar;
}

template<typename T>
MathVector<T> operator+(const MathVector<T> &v1, const MathVector<T> &v2) {
    MathVector<T> sum(v1.Dimension());
    for (size_t i = 0; i < v1.Dimension(); ++i) {
        sum[i] = v1[i] + v2[i];
    }
    return sum;
}

template<typename T>
MathVector<T> &operator+=(MathVector<T> &v1, const MathVector<T> &v2) {
    for (size_t i = 0; i < v1.Dimension(); ++i) {
        v1[i] = v1[i] + v2[i];
    }
    return v1;
}

int main() {
    std::vector<int> a = {1, 2, 3, 4, 5};
    std::vector<int> b = {1, 1, 2, 3, 3};
    std::vector<int> c = {1, 1, 2, 3, 3};
    int k = 3;
    MathVector<int> u(a.begin(), a.end());
    MathVector<int> w(b.begin(), b.end());
    MathVector<int> v(b.begin(), b.end());
    std::cout << ((u += 2 * w) *= 5) += v;
}
