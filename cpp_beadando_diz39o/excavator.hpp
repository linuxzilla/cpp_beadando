#pragma once

#include <iostream>
#include "vehicle.hpp"

using namespace std;

class Excavator : public Vehicle
{
public:
    Excavator(string lpn, string t, int yom, int c) : Vehicle(lpn, t, yom, c) {}
};
