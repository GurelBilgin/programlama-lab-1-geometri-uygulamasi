#ifndef GEOMETRI_DAIRE_HPP
#define GEOMETRI_DAIRE_HPP

#include "geometri/Nokta.hpp"
#include <string>

namespace geometri {

enum class DaireKesisimDurumu {
    Ayrik = 0,
    Teget = 1,
    IkiNoktadaKesisir = 2,
    IcIceKesismez = 3,
    Cakisik = 4
};

class Daire {
public:
    Daire(const Nokta& merkez, double yaricap);
    Daire(const Daire& diger);
    Daire(const Daire& diger, double olcek);

    const Nokta& getMerkez() const;
    double getYaricap() const;

    void setMerkez(const Nokta& merkez);
    void setYaricap(double yaricap);

    double alan() const;
    double cevre() const;
    DaireKesisimDurumu kesisimDurumu(const Daire& diger) const;
    int kesisimNoktasiSayisi(const Daire& diger) const;
    std::string toString() const;

private:
    Nokta merkez_;
    double yaricap_;
};

std::string toString(DaireKesisimDurumu durum);

} // namespace geometri

#endif
