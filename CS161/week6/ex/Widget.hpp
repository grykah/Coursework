// Widget.hpp

#ifndef WIDGET_HPP
#define WIDGET_HPP

#include "Doohickey.hpp"

class Widget
{
private:
    Doohickey thing1;
    Doohickey thing2;
    Doohickey thing3;
public:
    Widget(Doohickey, Doohickey, Doohickey);
    bool isCompatibleWith(Widget);
};

#endif