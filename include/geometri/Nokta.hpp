#ifndef GEOMETRI_NOKTA_HPP
#define GEOMETRI_NOKTA_HPP

#include <string>

namespace geometri {

class Nokta {
public:
    Nokta();
    explicit Nokta(double deger);
    Nokta(double x, double y);
    Nokta(const Nokta& diger);
    Nokta(const Nokta& diger, double xOfset, double yOfset);

    double getX() const;
    double getY() const;

    void setX(double x);
    void setY(double y);
    void set(double x, double y);
    void set(double deger);

    double uzaklik(const Nokta& diger) const;
    std::string toString() const;

private:
    double x_;
    double y_;
};

} // namespace geometri

#endif
