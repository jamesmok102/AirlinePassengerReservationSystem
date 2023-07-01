#ifndef FINALPROGRAM2021_CUSTOMSTRUCT_H
#define FINALPROGRAM2021_CUSTOMSTRUCT_H

#include <iostream>
#include <string>
using namespace std;

class CustomStruct {
public:
    string name;//乘客名
    int count;//该乘客己买票数
    string level;//坐位等级
    CustomStruct *next;//下一位乘客
    CustomStruct *pre;//上一位乘客
};


#endif
