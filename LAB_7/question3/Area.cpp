#include "Area.h"

Area::Area(const Distance& l, const Distance& w) : length(l), width(w) {}

Area::operator double() const {
    double lengthFeet = length.feet + length.inches / 12.0;
    double widthFeet = width.feet + width.inches / 12.0;
    return lengthFeet * widthFeet;
}
