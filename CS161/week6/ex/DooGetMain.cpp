// the main method

#include <iostream>
#include "Widget.hpp"
#include "Doohickey.hpp"

int main ()
{
    Doohickey dh1;
    dh1.setWeight(1);
    Doohickey dh2;
    dh2.setWeight(5);
    Doohickey dh3;
    dh3.setWeight(2);
    Widget widget1(dh1, dh2, dh3);

    Doohickey dh4;
    dh4.setWeight(12);
    Doohickey dh5;
    dh5.setWeight(1);
    Doohickey dh6;
    dh6.setWeight(8);
    Widget widget2(dh4, dh5, dh6);

    if (widget1.isCompatibleWith(widget2))
        std::cout << "true" << std::endl;
    else
        std::cout << "false" << std::endl;

    return 0;
}
