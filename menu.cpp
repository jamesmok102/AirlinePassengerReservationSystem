#include "menu.h"
#include "generateAirline.h"
#include "AirLineList.h"
#include <iostream>
#include <iomanip>
using namespace std;

menu::menu() {
    A.DataInputIntoList(airlinelist);//把result.txt里的数据存入airlinelist
    A.CDataInputIntoList(airlinelist);//把airlinelist里的每个node所对应的乘客表里的每个乘客资料存入customerlist中
}

void menu::DisplayMenu() {
    cout << "================================================================" << endl;
    cout << "(1)随机生成航班数据" << endl;//随机生成航空表和乘客表，航班数量可自定义（测试用）
    cout << "(2)显示航班表" << endl;//显示航班表
    cout << "(3)升序排序航班表" << endl;//航班表升序排序
    cout << "(4)降序排序航班表" << endl;//航班表降序排序
    cout << "(5)增加新航班" << endl;//插入新航班
    cout << "(6)删除航班" << endl;//删除航班
    cout << "(7)根据目的地查询航班表" << endl;//根据目的地查询航班表
    cout << "(8)根据航班查询乘客表" << endl;//根据航班查询乘客表
    cout << "(9)乘客买票" << endl;//以航班为根据买票
    cout << "(10)乘客退票" << endl;//退票
    cout << "(11)乘客己持有航班机票" << endl;
    cout << "(12)保存数据" << endl;
    cout << "(13)退出" << endl;//退出
    cout << "================================================================" << endl;
    cout << "Which one? " << endl;
}

void menu::RAD() {
    A.getAnyData();
    A.inputCount();
    A.addAnyWeek();
    A.generateData();
    A.closeFile();
    A.DeleteAllCFile();
    airlinelist.DeleteAll();
    A.DataInputIntoList(airlinelist);
    A.closeFile();
    A.creatCustomerFile();
    A.addName();
    A.generateCustomerData();
    A.CDataInputIntoList(airlinelist);
}

void menu::DAD() {
    airlinelist.Display();
}

void menu::SAD(int choose = 3) {
    if(choose == 3)
        airlinelist.ASCQuickSort(airlinelist.getHead(),NULL);
    else if(choose == 4)
        airlinelist.DESCQuickSort(airlinelist.getHead(),NULL);
}

void menu::IAD() {
    int pos;
    cout << "What POS? ";
    cin >> pos;
    airlinelist.insert(pos);
}

void menu::DelAD() {
    int air;
    cout << "What Airline? ";
    cin >> air;
    airlinelist.Delete(air);
}

void menu::MainMenu() {
    DisplayMenu();
    int n;
    while(cin >> n)
    {
        if(n == 1)
            RAD();
        else if(n == 2)
            DAD();
        else if(n == 3)
            SAD(3);
        else if(n == 4)
            SAD(4);
        else if(n == 5)
            IAD();
        else if(n == 6)
            DelAD();
        else if(n == 7)
            CAD();
        else if(n == 8)
            SCL();
        else if(n == 9)
            BTA();
        else if(n == 10)
            RT();
        else if(n == 11)
            COT();
        else if(n == 12)
            SD();
        else if(n == 13)
            break;
        DisplayMenu();
    }
}

void menu::CAD() {
    airlinelist.checkDestination();
}

void menu::SCL() {
    airlinelist.searchCustomerList();
}

void menu::BT() {
    airlinelist.BuyTicket();
}

void menu::RT() {
    airlinelist.ReturnTicket();
}

void menu::SD() {
    A.SaveData(airlinelist);
}

void menu::BTA() {
    airlinelist.BuyTicket2();
}

void menu::COT() {
    airlinelist.CustomerOwnTickets();
}













