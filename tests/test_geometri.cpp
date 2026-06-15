#include "geometri/Daire.hpp"
#include "geometri/DogruParcasi.hpp"
#include "geometri/Nokta.hpp"
#include "geometri/Ucgen.hpp"

#include <cassert>
#include <cmath>
#include <stdexcept>

using geometri::Daire;
using geometri::DaireKesisimDurumu;
using geometri::DogruParcasi;
using geometri::Nokta;
using geometri::Ucgen;

namespace {
constexpr double EPSILON = 1e-6;

bool yakin(double a, double b) {
    return std::abs(a - b) < EPSILON;
}
}

int main() {
    Nokta nokta(3.0, 4.0);
    assert(yakin(nokta.getX(), 3.0));
    assert(yakin(nokta.getY(), 4.0));
    assert(yakin(nokta.uzaklik(Nokta(0.0, 0.0)), 5.0));

    Nokta ofsetli(nokta, 1.0, -2.0);
    assert(yakin(ofsetli.getX(), 4.0));
    assert(yakin(ofsetli.getY(), 2.0));

    DogruParcasi dogru(Nokta(0.0, 0.0), Nokta(3.0, 4.0));
    assert(yakin(dogru.uzunluk(), 5.0));
    assert(yakin(dogru.ortaNokta().getX(), 1.5));
    assert(yakin(dogru.ortaNokta().getY(), 2.0));

    DogruParcasi acili(Nokta(0.0, 0.0), 10.0, 0.0);
    assert(yakin(acili.getBitis().getX(), 10.0));
    assert(yakin(acili.getBitis().getY(), 0.0));

    Daire daire(Nokta(0.0, 0.0), 5.0);
    assert(yakin(daire.alan(), 78.5398163397));
    assert(yakin(daire.cevre(), 31.4159265359));

    Daire ikiNoktada(Nokta(8.0, 0.0), 5.0);
    assert(daire.kesisimDurumu(ikiNoktada) == DaireKesisimDurumu::IkiNoktadaKesisir);
    assert(daire.kesisimNoktasiSayisi(ikiNoktada) == 2);

    Daire teget(Nokta(10.0, 0.0), 5.0);
    assert(daire.kesisimDurumu(teget) == DaireKesisimDurumu::Teget);
    assert(daire.kesisimNoktasiSayisi(teget) == 1);

    Ucgen ucgen(Nokta(0.0, 0.0), Nokta(4.0, 0.0), Nokta(0.0, 3.0));
    assert(yakin(ucgen.alan(), 6.0));
    assert(yakin(ucgen.cevre(), 12.0));

    const auto acilar = ucgen.acilar();
    assert(yakin(acilar[0], 90.0));
    assert(yakin(acilar[1], 36.8698976458));
    assert(yakin(acilar[2], 53.1301023542));

    bool hataAlindi = false;
    try {
        Ucgen gecersiz(Nokta(0.0, 0.0), Nokta(1.0, 1.0), Nokta(2.0, 2.0));
    } catch (const std::invalid_argument&) {
        hataAlindi = true;
    }
    assert(hataAlindi);

    return 0;
}
