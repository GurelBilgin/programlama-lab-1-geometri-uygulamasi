#include "geometri/Daire.hpp"
#include "geometri/DogruParcasi.hpp"
#include "geometri/Nokta.hpp"
#include "geometri/Ucgen.hpp"

#include <iostream>

using geometri::Daire;
using geometri::DogruParcasi;
using geometri::Nokta;
using geometri::Ucgen;

int main() {
    std::cout << "Programlama Lab 1 - Odev 3 Geometri Uygulamasi\n\n";

    Nokta n1;
    Nokta n2(3.0, 4.0);
    Nokta n3(n2, 2.0, -1.0);

    std::cout << "Noktalar:\n";
    std::cout << "n1 = " << n1.toString() << '\n';
    std::cout << "n2 = " << n2.toString() << '\n';
    std::cout << "n3 = " << n3.toString() << "\n\n";

    DogruParcasi dogru(n1, n2);
    std::cout << "Dogru parcasi: " << dogru.toString() << '\n';
    std::cout << "Uzunluk: " << dogru.uzunluk() << '\n';
    std::cout << "Orta nokta: " << dogru.ortaNokta().toString() << "\n\n";

    Daire d1(Nokta(0.0, 0.0), 5.0);
    Daire d2(Nokta(8.0, 0.0), 5.0);
    std::cout << "Daire 1: " << d1.toString() << '\n';
    std::cout << "Alan: " << d1.alan() << '\n';
    std::cout << "Cevre: " << d1.cevre() << '\n';
    std::cout << "Daire 1 - Daire 2 kesisim durumu: " << toString(d1.kesisimDurumu(d2)) << "\n\n";

    Ucgen ucgen(Nokta(0.0, 0.0), Nokta(4.0, 0.0), Nokta(0.0, 3.0));
    const auto acilar = ucgen.acilar();
    std::cout << ucgen.toString() << '\n';
    std::cout << "Alan: " << ucgen.alan() << '\n';
    std::cout << "Cevre: " << ucgen.cevre() << '\n';
    std::cout << "Acilar: " << acilar[0] << ", " << acilar[1] << ", " << acilar[2] << '\n';

    return 0;
}
