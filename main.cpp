#include <iostream>
#include <list>
#include <iomanip>
#include "generateAirline.h"
#include "airlineStruct.h"
#include "AirLineList.h"
#include "menu.h"
using namespace std;

/*void generateAirlineData(int n, AirLineList &airlineList)
{
    generateAirline A(n);
    A.addAnyWeek();
    A.generateData();
    A.closeFile();
    A.DataInputIntoList(airlineList);
}*/

int main() {
    /*AirLineList airlinelist;
    generateAirlineData(20, airlinelist);
    airlinelist.Sort("ASC");
    airlinelist.Display();
    airlinelist.Delete(20);
    airlinelist.Display();*/
    menu m;
    m.MainMenu();
    return 0;
}
