#ifndef FINALPROGRAM2021_MENU_H
#define FINALPROGRAM2021_MENU_H

#include "AirLineList.h"
#include "generateAirline.h"

class menu {
public:
    menu();
    static void DisplayMenu();
    void RAD();
    void DAD();
    void SAD(int choose);
    void IAD();
    void DelAD();
    void CAD();
    void SCL();
    void BT();
    void RT();
    void SD();
    void BTA();
    void COT();
    void MainMenu();
private:
    AirLineList airlinelist;
    generateAirline A;
};


#endif //FINALPROGRAM2021_MENU_H
