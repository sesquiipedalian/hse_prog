#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>

class Rational {
private:
    int p = 0;
    int q = 1;

    void f() {
        int num = std::gcd(p, q);
        p /= num;
        q /= num;
        if (q < 0) {
            p *= -1;
            q *= -1;
        }
    }

public:
    Rational(int n = 0, int d = 1) {
        p = n;
        q = d;
        f();
    }

    Rational operator-() const {
        return Rational(-p, q);
    }

    Rational operator+() const {
        return *this;
    }

    bool operator==(const Rational &x) const {
        return (x.p == p && x.q == q);
    }

    bool operator!=(const Rational &x) const {
        return !(x.p == p && x.q == q);
    }

    [[nodiscard]] int Numerator() const {
        return p;
    }

    [[nodiscard]] int Denominator() const {
        return q;
    }

    Rational operator+(const Rational &x) const {
        return Rational(this->p * x.q + this->q * x.p, this->q * x.q);
    }

    Rational operator-(const Rational &x) const {
        return *this + (-x);
    }

    Rational operator*(const Rational &x) const {
        return Rational(p * x.p, q * x.q);
    }

    Rational operator/(const Rational &x) const {
        return Rational(p * x.q, q * x.p);
    }

    Rational &operator++() {
        p += q;
        f();
        return *this;
    }

    Rational operator++(int) {
        Rational copy = *this;
        p += q;
        f();
        return copy;
    }

    Rational &operator--() {
        p -= q;
        f();
        return *this;
    }

    Rational operator--(int) {
        Rational copy = *this;
        p -= q;
        f();
        return copy;
    }

    Rational &operator+=(const Rational &x) {
        *this = *this + x;
        return *this;
    }

    Rational &operator-=(const Rational &x) {
        *this += (-x);
        return *this;
    }

    Rational &operator*=(const Rational &x) {
        *this = *this * x;
        return *this;
    }

    Rational &operator/=(const Rational &x) {
        *this = *this / x;
        return *this;
    }
};

Rational operator-(double out, const Rational &x) {
    return Rational(out) - x;
}

Rational operator/(double out, const Rational &x) {
    return Rational(out) / x;
}

Rational operator*(double out, const Rational &x) {
    return Rational(out) * x;
}

Rational operator+(double out, const Rational &x) {
    return Rational(out) + x;
}


std::ostream &operator<<(std::ostream &out, const Rational &x) {
    out << x.Numerator();
    out << '/';
    out << x.Denominator();
    return out;
}

int main() {
    Rational m(-3);
    Rational n;
    Rational c(1, 3);
    Rational res(1, 3);
    n *= m;
    std::cout << "n *= m = " << n << '\n';
    m /= c;
    std::cout << "m /= c = " << m << '\n';
    std::cout << n.Numerator() << " " << n.Denominator() << "\n";
    std::cout << m.Numerator() << " " << m.Denominator() << "\n";
    std::cout << "-n = " << -n << '\n';
    std::cout << "+m = " << +m << '\n';


    Rational q(42, 1);
    const auto &Q = ++q;
    q += 1000;
    std::cout << q.Numerator() << " " << q.Denominator() << "\n";
    std::cout << Q.Numerator() << " " << Q.Denominator() << "\n";
    std::cout << n.Numerator() << " " << n.Denominator() << "\n";
    std::cout << m.Numerator() << " " << m.Denominator() << "\n";
}
