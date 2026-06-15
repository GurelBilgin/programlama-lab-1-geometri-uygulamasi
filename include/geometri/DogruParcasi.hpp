#ifndef GEOMETRI_DOGRUPARCASI_HPP
#define GEOMETRI_DOGRUPARCASI_HPP

#include "geometri/Nokta.hpp"
#include <string>

namespace geometri {

class DogruParcasi {
public:
    DogruParcasi(const Nokta& baslangic, const Nokta& bitis);
    DogruParcasi(const DogruParcasi& diger);
    DogruParcasi(const Nokta& baslangic, double uzunluk, double egimDerece);

    const Nokta& getBaslangic() const;
    const Nokta& getBitis() const;

    void setBaslangic(const Nokta& nokta);
    void setBitis(const Nokta& nokta);

    double uzunluk() const;
    Nokta ortaNokta() const;
    std::string toString() const;

private:
    Nokta baslangic_;
    Nokta bitis_;
};

} // namespace geometri

#endif
