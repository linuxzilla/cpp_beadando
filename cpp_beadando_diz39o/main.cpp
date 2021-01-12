#include <iostream>
#include "bus.hpp"
#include <string>

using namespace std;

int main()
{
    Bus b("Nissan", "Leaf", 3,3);
    string asd = b.getType();
    cout << asd << endl;
    cout << "Hello world!" << endl;
    return 0;
}
