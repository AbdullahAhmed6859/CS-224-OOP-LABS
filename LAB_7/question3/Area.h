#ifndef AREA_H
#define AREA_H

struct Distance {
    double feet, inches;
};

class Area {
    Distance length;
    Distance width;

public:
    Area(const Distance& l, const Distance& w);
    operator double() const;
};

#endif
