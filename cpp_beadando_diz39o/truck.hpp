#pragma once

#include <iostream>
#include "vehicle.hpp"

using namespace std;

class Truck : public Vehicle
{
public:
    Truck(string lpn, string t, int yom, int c) : Vehicle(lpn, t, yom, c) {}
};
