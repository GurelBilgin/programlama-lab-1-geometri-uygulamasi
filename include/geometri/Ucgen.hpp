#ifndef GEOMETRI_UCGEN_HPP
#define GEOMETRI_UCGEN_HPP

#include "geometri/Nokta.hpp"
#include <array>
#include <string>

namespace geometri {

class Ucgen {
public:
    Ucgen(const Nokta& a, const Nokta& b, const Nokta& c);

    const Nokta& getA() const;
    const Nokta& getB() const;
    const Nokta& getC() const;

    void setA(const Nokta& nokta);
    void setB(const Nokta& nokta);
    void setC(const Nokta& nokta);

    double alan() const;
    double cevre() const;
    std::array<double, 3> acilar() const;
    bool gecerliMi() const;
    std::string toString() const;

private:
    Nokta a_;
    Nokta b_;
    Nokta c_;
};

} // namespace geometri

#endif
