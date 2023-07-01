#ifndef FINALPROGRAM2021_CUSTOMERLIST_H
#define FINALPROGRAM2021_CUSTOMERLIST_H

#include <iostream>
#include "CustomStruct.h"

class customerList {
public:
    customerList();//init化
    void push(string name0,int count0,string level0);//把数据放在最后一个node
    void Delete(string name0);//删除操作
    CustomStruct *getCur(string name0);//取得当前node
    CustomStruct *getHead();//取得第一个Node
private:
    CustomStruct *head;
    CustomStruct *tail;
};


#endif
