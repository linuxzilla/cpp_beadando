#include "bus.hpp"

#include <string>
#include <sstream>

using namespace std;

string Bus::getDataFromated()
{
    ostringstream stringStream;
    stringStream << "Bus - ";
    stringStream << "Licence plate number: ";
    stringStream << licensePlateNumber << " ";
    stringStream << "Model: ";
    stringStream << model << " ";
    stringStream << "Manufactured: ";
    stringStream << to_string(yearOfManufacture) << " ";
    stringStream << "Capacity: ";
    stringStream << to_string(capacity) << " passenger ";
    stringStream << "Usage: ";
    stringStream << to_string(usage) << " km/week";
    return stringStream.str();
}
