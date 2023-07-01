#ifndef FINALPROGRAM2021_AIRLINESTRUCT_H
#define FINALPROGRAM2021_AIRLINESTRUCT_H

#include <string>
#include "customerList.h"
using namespace std;

class AirlineStruct
{
public:
    int airline;//航班号
    string flight;//飞机号
    string destination;//目的地
    string day;//星期
    int ticketCount;//剩余可售票数
    AirlineStruct *next;//下个node
    AirlineStruct *pre;//前个node
    customerList *cl;//指向该航空表的首个乘客
};

#endif //FINALPROGRAM2021_AIRLINESTRUCT_H
