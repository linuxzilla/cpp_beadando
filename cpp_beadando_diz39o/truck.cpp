#include "truck.hpp"

#include <string>
#include <sstream>

using namespace std;

string Truck::getDataFromated()
{
    ostringstream stringStream;
    stringStream << "Truck - ";
    stringStream << "Licence plate number: ";
    stringStream << licensePlateNumber << " ";
    stringStream << "Model: ";
    stringStream << model << " ";
    stringStream << "Manufactured: ";
    stringStream << to_string(yearOfManufacture) << " ";
    stringStream << "Capacity: ";
    stringStream << to_string(capacity) << "t ";
    stringStream << "Usage: ";
    stringStream << to_string(usage) << " km/week";
    return stringStream.str();
}
