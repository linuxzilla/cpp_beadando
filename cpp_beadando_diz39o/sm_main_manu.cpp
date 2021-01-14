#include "sm_main_manu.hpp"

#include <string>
#include <array>
#include <iostream>
#include <cstdlib>
#include <typeinfo>

using namespace std;

void Sm_main_menu::executeMainMenu()
{
    string buffer;

    switch(currentSate)
    {
    case ST_DRAW_MAIN_MENU:

        cout << "Super-Menu system '70s dumb terminal style" << endl;
        cout << "1. Add new vehicle" << endl;
        cout << "2. List all vehicle" << endl;
        cout << "3. List vehicle by licenc plate" << endl;
        cout << "4. Calculate usage by category" << endl;
        cout << "5. Set usage limit" << endl;
        cout << "6. List overused vehicles" << endl;
        cout << "x. EXIT" << endl;
        cout << endl << "Vehicles: " << to_string(stateIndex) << endl;

        cin >> buffer;

        if(buffer[0] == '1')
            currentSate = ST_ADDNEW_VEHICLE;
        else if(buffer[0] == '2')
            currentSate = ST_LIST_VEHICLES_DATA;
        else if(buffer[0] == '3')
            currentSate = ST_LIST_VEHICLES_BY_ID;
        else if(buffer[0] == '4')
            currentSate = ST_USAGE_BY_CATEGORY;
        else if(buffer[0] == '5')
            currentSate = ST_SET_LIMIT_BY_CATEGORY;
        else if(buffer[0] == '6')
            currentSate = ST_LIST_VEGICLES_OVERUSED;
        else if(buffer[0] == 'x')
        {
            DeleteArray();
            currentSate = ST_EXIT;
        }

        break;
    case ST_ADDNEW_VEHICLE:
        cout << "Add new vehicle! " << endl;
        AddNewVehicle();
        currentSate = ST_DRAW_MAIN_MENU;
        break;
    case ST_LIST_VEHICLES_DATA:
        ListAllVehicle();
        currentSate = ST_DRAW_MAIN_MENU;
        break;
    case ST_LIST_VEHICLES_BY_ID:
        cin >> buffer;
        ListVehicleByLicence(buffer);
        currentSate = ST_DRAW_MAIN_MENU;
        break;
    case ST_USAGE_BY_CATEGORY:
        SumUsageByCategory();
        currentSate = ST_DRAW_MAIN_MENU;
        break;
    case ST_SET_LIMIT_BY_CATEGORY:
        SetUsageLimitByCategory();
        currentSate = ST_DRAW_MAIN_MENU;
        break;
    case ST_LIST_VEGICLES_OVERUSED:
        ListOverUsedVehicles();
        currentSate = ST_DRAW_MAIN_MENU;
        break;
    default:
        break;
    }
}

void Sm_main_menu::AddNewVehicle()
{
    NewVehicle tmpVehicle;
    AddNewVehicleStates tmpState(ST_LICENSE_PLATE_NUMBER);
    string tmpNewVehicleBuffer;

    cout << "x. Cancel, <. Back" << endl;

    while(tmpState != Sm_main_menu::ST_DONE)
    {
        switch(tmpState)
        {
        case ST_LICENSE_PLATE_NUMBER:
            cout << endl << "Licence palte number: ";
            cin >> tmpNewVehicleBuffer;
            if(tmpNewVehicleBuffer[0] == 'x')
            {
                tmpState = ST_DONE;
            }
            else if (tmpNewVehicleBuffer[0] == '<')
            {
                tmpState = ST_LICENSE_PLATE_NUMBER;
            }
            else
            {
                tmpVehicle.licencPlate = tmpNewVehicleBuffer;
                tmpState = ST_MODEL;
            }
            break;
        case ST_MODEL:
            cout << endl << "Vehicle model: ";
            cin >> tmpNewVehicleBuffer;
            if(tmpNewVehicleBuffer[0] == 'x')
            {
                tmpState = ST_DONE;
            }
            else if (tmpNewVehicleBuffer[0] == '<')
            {
                tmpState = ST_LICENSE_PLATE_NUMBER;
            }
            else
            {
                tmpVehicle.model = tmpNewVehicleBuffer;
                tmpState = ST_YEAR;
            }
            break;
        case ST_YEAR:
            cout << endl << "Manufacture year: ";
            cin >> tmpNewVehicleBuffer;
            if(tmpNewVehicleBuffer[0] == 'x')
            {
                tmpState = ST_DONE;
            }
            else if (tmpNewVehicleBuffer[0] == '<')
            {
                tmpState = ST_MODEL;
            }
            else
            {
                tmpVehicle.year = atoi(tmpNewVehicleBuffer.c_str());
                tmpState = ST_CAPACITY;
            }
            break;
        case ST_CAPACITY:
            cout << endl << "Capacity: ";
            cin >> tmpNewVehicleBuffer;
            if(tmpNewVehicleBuffer[0] == 'x')
            {
                tmpState = ST_DONE;
            }
            else if (tmpNewVehicleBuffer[0] == '<')
            {
                tmpState = ST_YEAR;
            }
            else
            {
                tmpVehicle.capacity = atoi(tmpNewVehicleBuffer.c_str());
                tmpState = ST_USAGE;
            }
            break;
        case ST_USAGE:
            cout << endl << "Current usage: ";
            cin >> tmpNewVehicleBuffer;
            if(tmpNewVehicleBuffer[0] == 'x')
            {
                tmpState = ST_DONE;
            }
            else if (tmpNewVehicleBuffer[0] == '<')
            {
                tmpState = ST_CAPACITY;
            }
            else
            {
                tmpVehicle.usage = stod(tmpNewVehicleBuffer.c_str());
                tmpState = ST_CATEGORY;
            }
            break;
        case ST_CATEGORY:
            cout << "Choose category" << endl;
            cout << "1. BUS" <<  endl;
            cout << "2. TRUCK" << endl;
            cout << "3. EXCAVATOR" << endl;
            cin >> tmpNewVehicleBuffer;
            if(tmpNewVehicleBuffer[0] == 'x')
            {
                tmpState = ST_DONE;
                break;
            }
            else if (tmpNewVehicleBuffer[0] == '<')
            {
                tmpState = ST_CAPACITY;
                break;
            }
            else if (tmpNewVehicleBuffer[0] == '1')
            {
                vehicles[stateIndex] = new Bus(tmpVehicle.licencPlate, tmpVehicle.model, tmpVehicle.year, tmpVehicle.capacity, tmpVehicle.usage);
            }
            else if (tmpNewVehicleBuffer[0] == '2')
            {
                vehicles[stateIndex] = new Truck(tmpVehicle.licencPlate, tmpVehicle.model, tmpVehicle.year, tmpVehicle.capacity, tmpVehicle.usage);
            }
            else if (tmpNewVehicleBuffer[0] == '3')
            {
                vehicles[stateIndex] = new Excavator(tmpVehicle.licencPlate, tmpVehicle.model, tmpVehicle.year, tmpVehicle.capacity, tmpVehicle.usage);
            }
            cout << vehicles[stateIndex]->getDataFromated() << endl;
            stateIndex++;
            tmpState = ST_LICENSE_PLATE_NUMBER;
            break;
        default:
            break;
        }
    }
}

void Sm_main_menu::ListAllVehicle()
{
    for (int i = 0; i < stateIndex; i++)
    {
        cout << vehicles[i]->getDataFromated() << endl;
    }
}

void Sm_main_menu::ListVehicleByLicence(string licence)
{
    for (int i = 0; i < stateIndex; i++)
    {
        if (vehicles[i]->getLicensePlateNumber() == licence)
            cout << vehicles[i]->getDataFromated() << endl;
        return;
    }
}

void Sm_main_menu::SumUsageByCategory()
{
    double bus, excavator, truck;
    for (int i = 0; i < stateIndex; i++)
    {
        if (typeid(Bus) == typeid(*vehicles[i]))
        {
            bus += vehicles[i]->getUsage();
        }
        else if (typeid(Excavator) == typeid(*vehicles[i]))
        {
            excavator += vehicles[i]->getUsage();
        }
        else if (typeid(Truck) == typeid(*vehicles[i]))
        {
            truck += vehicles[i]->getUsage();
        }
    }
    cout << "Weekly usage category"<< endl ;
    cout << "Buses: "<< to_string(bus) << "/km"<< endl ;
    cout << "Excavators: "<< to_string(excavator) << "/work hour"<< endl ;
    cout << "Trucks: "<< to_string(truck) << "/km"<< endl << endl ;
}

void Sm_main_menu::SetUsageLimitByCategory()
{
    string tmpBuffer;
    bool menuActive = true;

    while (!menuActive);
    {
        cout << "Set new limit" << endl;
        cout << "1. BUS " << limitBus <<"km"<< endl;
        cout << "2. TRUCK " << limitTruck << "km" << endl;
        cout << "3. EXCAVATOR " << limitExcavator << "hour" << endl;
        cout << "x. BACK" << endl;
        cin >> tmpBuffer;
        if(tmpBuffer[0] == 'x')
        {
            menuActive = false;
        }
        else if(tmpBuffer[0] == '1')
        {
            cout << endl << "BUS: ";
            cin >> tmpBuffer;
            limitBus = stod(tmpBuffer.c_str());
        }
        else if(tmpBuffer[0] == '2')
        {
            cout << endl << "TRUCK: ";
            cin >> tmpBuffer;
            limitTruck = stod(tmpBuffer.c_str());
        }
        else if(tmpBuffer[0] == '3')
        {
            cout << endl << "EXCAVATOR: ";
            cin >> tmpBuffer;
            limitExcavator = stod(tmpBuffer.c_str());
        }
        else
        {
            cout << "Invalid option" << endl;
        }
    }
}

void Sm_main_menu::ListOverUsedVehicles()
{
    for (int i = 0; i < stateIndex; i++)
    {
        if ((typeid(Bus) == typeid(*vehicles[i]) && vehicles[i]->getUsage() > limitBus) ||
                (typeid(Truck) == typeid(*vehicles[i]) && vehicles[i]->getUsage() > limitTruck) ||
                (typeid(Excavator) == typeid(*vehicles[i]) && vehicles[i]->getUsage() > limitExcavator))
            cout << vehicles[i]->getDataFromated() << endl;
    }
}

void Sm_main_menu::DeleteArray()
{
    for (int i = 0; i < stateIndex; i++)
    {
        delete vehicles[i];
    }
}

