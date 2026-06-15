#include "geometri/Ucgen.hpp"

#include "geometri/DogruParcasi.hpp"

#include <algorithm>
#include <cmath>
#include <sstream>
#include <stdexcept>

namespace geometri {

namespace {
constexpr double PI = 3.14159265358979323846;
constexpr double EPSILON = 1e-9;

double dereceyeCevir(double radyan) {
    return radyan * 180.0 / PI;
}

double clamp(double deger) {
    return std::max(-1.0, std::min(1.0, deger));
}
}

Ucgen::Ucgen(const Nokta& a, const Nokta& b, const Nokta& c)
    : a_(a), b_(b), c_(c) {
    if (!gecerliMi()) {
        throw std::invalid_argument("Ucgen olusturmak icin noktalar dogrusal olmamali ve alan sifir olmamalidir.");
    }
}

const Nokta& Ucgen::getA() const { return a_; }

const Nokta& Ucgen::getB() const { return b_; }

const Nokta& Ucgen::getC() const { return c_; }

void Ucgen::setA(const Nokta& nokta) {
    const Nokta eski = a_;
    a_ = nokta;
    if (!gecerliMi()) {
        a_ = eski;
        throw std::invalid_argument("Yeni nokta gecersiz ucgen olusturuyor.");
    }
}

void Ucgen::setB(const Nokta& nokta) {
    const Nokta eski = b_;
    b_ = nokta;
    if (!gecerliMi()) {
        b_ = eski;
        throw std::invalid_argument("Yeni nokta gecersiz ucgen olusturuyor.");
    }
}

void Ucgen::setC(const Nokta& nokta) {
    const Nokta eski = c_;
    c_ = nokta;
    if (!gecerliMi()) {
        c_ = eski;
        throw std::invalid_argument("Yeni nokta gecersiz ucgen olusturuyor.");
    }
}

double Ucgen::alan() const {
    return std::abs(
        a_.getX() * (b_.getY() - c_.getY()) +
        b_.getX() * (c_.getY() - a_.getY()) +
        c_.getX() * (a_.getY() - b_.getY())
    ) / 2.0;
}

double Ucgen::cevre() const {
    return a_.uzaklik(b_) + b_.uzaklik(c_) + c_.uzaklik(a_);
}

std::array<double, 3> Ucgen::acilar() const {
    const double ab = a_.uzaklik(b_);
    const double bc = b_.uzaklik(c_);
    const double ca = c_.uzaklik(a_);

    const double aciA = dereceyeCevir(std::acos(clamp((ab * ab + ca * ca - bc * bc) / (2.0 * ab * ca))));
    const double aciB = dereceyeCevir(std::acos(clamp((ab * ab + bc * bc - ca * ca) / (2.0 * ab * bc))));
    const double aciC = 180.0 - aciA - aciB;

    return {aciA, aciB, aciC};
}

bool Ucgen::gecerliMi() const {
    return alan() > EPSILON;
}

std::string Ucgen::toString() const {
    std::ostringstream oss;
    oss << "Ucgen: " << a_.toString() << ", " << b_.toString() << ", " << c_.toString();
    return oss.str();
}

} // namespace geometri
