// Doohickey.cpp

#include "Doohickey.hpp"

Doohickey::Doohickey()
{
    setWeight(1);
}

void Doohickey::setWeight(int weightIn)
{
    weight = weightIn;
}

int Doohickey::getWeight()
{
    return weight;
}

int main()
{
	return 0;
}