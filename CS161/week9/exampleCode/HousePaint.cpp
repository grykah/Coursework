#include <iostream>
#include "HousePaint.h"

HousePaint::HousePaint(Color sColor, Color tColor)
{
    setSiding(sColor);
    setTrim(tColor);
}

void HousePaint::setSiding(Color sColor)
{
    siding = sColor;
}

Color HousePaint::getSiding()
{
    return siding;
}

void HousePaint::setTrim(Color tColor)
{
    trim = tColor;
}

Color HousePaint::getTrim()
{
    return trim;
}

int main()
{
    HousePaint hp(cobalt, ivory);
    if (hp.getTrim() == ivory)
        std::cout << "trim is ivory" << std::endl;
}