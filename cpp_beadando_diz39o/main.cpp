#include <iostream>
#include <string>

#include "sm_main_manu.hpp"

using namespace std;

int main()
{
    Sm_main_menu MainManu;

    while (MainManu.getCurrentState() != Sm_main_menu::ST_EXIT)
    {
        MainManu.executeMainMenu();
    }

    return 0;
}
