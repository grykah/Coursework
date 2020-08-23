// Widget.cpp  ---- error in here.

#include "Widget.hpp"

Widget::Widget(Doohickey thing1In, Doohickey thing2In, Doohickey thing3In)
{
    thing1 = thing1In;
    thing2 = thing2In;
    thing3 = thing3In;
}

bool Widget::isCompatibleWith(Widget otherWidget)
{
    int thisWidgetWeight = thing1.getWeight() + thing2.getWeight() + thing3.getWeight();
    int otherWidgetWeight = otherWidget.thing1.getWeight() + otherWidget.thing2.getWeight() + otherWidget.thing3.getWeight();

    return thisWidgetWeight == otherWidgetWeight;
}

int main()
{
	return 0;
}
