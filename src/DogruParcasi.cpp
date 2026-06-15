#include "geometri/DogruParcasi.hpp"

#include <cmath>
#include <sstream>
#include <stdexcept>

namespace geometri {

namespace {
constexpr double PI = 3.14159265358979323846;
}

DogruParcasi::DogruParcasi(const Nokta& baslangic, const Nokta& bitis)
    : baslangic_(baslangic), bitis_(bitis) {}

DogruParcasi::DogruParcasi(const DogruParcasi& diger) = default;

DogruParcasi::DogruParcasi(const Nokta& baslangic, double uzunluk, double egimDerece)
    : baslangic_(baslangic), bitis_(baslangic) {
    if (uzunluk < 0.0) {
        throw std::invalid_argument("Dogru parcasi uzunlugu negatif olamaz.");
    }

    const double radyan = egimDerece * PI / 180.0;
    bitis_.set(
        baslangic.getX() + uzunluk * std::cos(radyan),
        baslangic.getY() + uzunluk * std::sin(radyan)
    );
}

const Nokta& DogruParcasi::getBaslangic() const { return baslangic_; }

const Nokta& DogruParcasi::getBitis() const { return bitis_; }

void DogruParcasi::setBaslangic(const Nokta& nokta) { baslangic_ = nokta; }

void DogruParcasi::setBitis(const Nokta& nokta) { bitis_ = nokta; }

double DogruParcasi::uzunluk() const { return baslangic_.uzaklik(bitis_); }

Nokta DogruParcasi::ortaNokta() const {
    return Nokta(
        (baslangic_.getX() + bitis_.getX()) / 2.0,
        (baslangic_.getY() + bitis_.getY()) / 2.0
    );
}

std::string DogruParcasi::toString() const {
    std::ostringstream oss;
    oss << baslangic_.toString() << " -> " << bitis_.toString();
    return oss.str();
}

} // namespace geometri
