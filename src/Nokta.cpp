#include "geometri/Nokta.hpp"

#include <cmath>
#include <iomanip>
#include <sstream>

namespace geometri {

Nokta::Nokta() : x_(0.0), y_(0.0) {}

Nokta::Nokta(double deger) : x_(deger), y_(deger) {}

Nokta::Nokta(double x, double y) : x_(x), y_(y) {}

Nokta::Nokta(const Nokta& diger) = default;

Nokta::Nokta(const Nokta& diger, double xOfset, double yOfset)
    : x_(diger.x_ + xOfset), y_(diger.y_ + yOfset) {}

double Nokta::getX() const { return x_; }

double Nokta::getY() const { return y_; }

void Nokta::setX(double x) { x_ = x; }

void Nokta::setY(double y) { y_ = y; }

void Nokta::set(double x, double y) {
    x_ = x;
    y_ = y;
}

void Nokta::set(double deger) {
    x_ = deger;
    y_ = deger;
}

double Nokta::uzaklik(const Nokta& diger) const {
    const double dx = x_ - diger.x_;
    const double dy = y_ - diger.y_;
    return std::sqrt(dx * dx + dy * dy);
}

std::string Nokta::toString() const {
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(2) << "(" << x_ << ", " << y_ << ")";
    return oss.str();
}

} // namespace geometri
