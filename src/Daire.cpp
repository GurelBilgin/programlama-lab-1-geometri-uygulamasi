#include "geometri/Daire.hpp"

#include <cmath>
#include <iomanip>
#include <sstream>
#include <stdexcept>

namespace geometri {

namespace {
constexpr double PI = 3.14159265358979323846;
constexpr double EPSILON = 1e-9;

bool esit(double a, double b) {
    return std::abs(a - b) < EPSILON;
}
}

Daire::Daire(const Nokta& merkez, double yaricap) : merkez_(merkez), yaricap_(yaricap) {
    if (yaricap < 0.0) {
        throw std::invalid_argument("Daire yaricapi negatif olamaz.");
    }
}

Daire::Daire(const Daire& diger) = default;

Daire::Daire(const Daire& diger, double olcek)
    : merkez_(diger.merkez_), yaricap_(diger.yaricap_ * olcek) {
    if (olcek < 0.0) {
        throw std::invalid_argument("Olcek degeri negatif olamaz.");
    }
}

const Nokta& Daire::getMerkez() const { return merkez_; }

double Daire::getYaricap() const { return yaricap_; }

void Daire::setMerkez(const Nokta& merkez) { merkez_ = merkez; }

void Daire::setYaricap(double yaricap) {
    if (yaricap < 0.0) {
        throw std::invalid_argument("Daire yaricapi negatif olamaz.");
    }
    yaricap_ = yaricap;
}

double Daire::alan() const { return PI * yaricap_ * yaricap_; }

double Daire::cevre() const { return 2.0 * PI * yaricap_; }

DaireKesisimDurumu Daire::kesisimDurumu(const Daire& diger) const {
    const double uzaklik = merkez_.uzaklik(diger.merkez_);
    const double toplamYaricap = yaricap_ + diger.yaricap_;
    const double farkYaricap = std::abs(yaricap_ - diger.yaricap_);

    if (esit(uzaklik, 0.0) && esit(yaricap_, diger.yaricap_)) {
        return DaireKesisimDurumu::Cakisik;
    }

    if (uzaklik > toplamYaricap) {
        return DaireKesisimDurumu::Ayrik;
    }

    if (uzaklik < farkYaricap) {
        return DaireKesisimDurumu::IcIceKesismez;
    }

    if (esit(uzaklik, toplamYaricap) || esit(uzaklik, farkYaricap)) {
        return DaireKesisimDurumu::Teget;
    }

    return DaireKesisimDurumu::IkiNoktadaKesisir;
}

int Daire::kesisimNoktasiSayisi(const Daire& diger) const {
    switch (kesisimDurumu(diger)) {
        case DaireKesisimDurumu::Ayrik:
        case DaireKesisimDurumu::IcIceKesismez:
            return 0;
        case DaireKesisimDurumu::Teget:
            return 1;
        case DaireKesisimDurumu::IkiNoktadaKesisir:
            return 2;
        case DaireKesisimDurumu::Cakisik:
            return -1;
    }
    return 0;
}

std::string Daire::toString() const {
    std::ostringstream oss;
    oss << "Merkez: " << merkez_.toString()
        << ", Yaricap: " << std::fixed << std::setprecision(2) << yaricap_;
    return oss.str();
}

std::string toString(DaireKesisimDurumu durum) {
    switch (durum) {
        case DaireKesisimDurumu::Ayrik:
            return "Ayrik";
        case DaireKesisimDurumu::Teget:
            return "Teget";
        case DaireKesisimDurumu::IkiNoktadaKesisir:
            return "Iki noktada kesisir";
        case DaireKesisimDurumu::IcIceKesismez:
            return "Ic ice, kesismez";
        case DaireKesisimDurumu::Cakisik:
            return "Cakisik";
    }
    return "Bilinmeyen";
}

} // namespace geometri
